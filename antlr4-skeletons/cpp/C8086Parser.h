
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <sstream>  
    #include <cstdlib>
    #include <regex>
    #include <set>
    #include "C8086Lexer.h"
    #include "str_list.cpp"
    #include "2105175_Symbol_Table.hpp"
    
    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;
    extern int syntaxErrorCount;


// Generated from C8086Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C8086Parser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, SWITCH = 14, CASE = 15, DEFAULT = 16, BREAK = 17, GOTO = 18, 
    LPAREN = 19, RPAREN = 20, LCURL = 21, RCURL = 22, LTHIRD = 23, RTHIRD = 24, 
    SEMICOLON = 25, COMMA = 26, COLON = 27, ADDOP = 28, SUBOP = 29, MULOP = 30, 
    INCOP = 31, DECOP = 32, NOT = 33, RELOP = 34, LOGICOP = 35, ASSIGNOP = 36, 
    ID = 37, CONST_INT = 38, CONST_FLOAT = 39, INVALID_CHAR = 40
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleParameter_list = 5, RuleCompound_statement = 6, 
    RuleVar_declaration = 7, RuleDeclaration_list_err = 8, RuleType_specifier = 9, 
    RuleDeclaration_list = 10, RuleStatements = 11, RuleStatement = 12, 
    RuleCase_statements = 13, RuleCase_statement = 14, RuleExpression_statement = 15, 
    RuleVariable = 16, RuleExpression = 17, RuleLogic_expression = 18, RuleRel_expression = 19, 
    RuleSimple_expression = 20, RuleSimple_expression_err = 21, RuleTerm = 22, 
    RuleUnary_expression = 23, RuleFactor = 24, RuleArgument_list = 25, 
    RuleArguments = 26
  };

  explicit C8086Parser(antlr4::TokenStream *input);

  C8086Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C8086Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


      SymbolTable symb{7};
      bool scopeEntered = false;
      bool calledLabel = false;

      std::ofstream asmFile;
      std::ofstream optimizedAsmFile;

      void writeIntoparserLogFile(const std::string message) {
          if (!parserLogFile) {
              std::cout << "Error opening parserLogFile.txt" << std::endl;
              return;
          }

          parserLogFile << message << std::endl;
          parserLogFile.flush();
      }

      void writeIntoErrorFile(const std::string message) {
          if (!errorFile) {
              std::cout << "Error opening errorFile.txt" << std::endl;
              return;
          }
          errorFile << message << std::endl;
          errorFile.flush();
      }

      int labelCount = 1;  
      std::string currentFunction = "";
      std::map<std::string, int> localVarOffset;
      std::map<std::string, int> globalVarOffset;
      int currentOffset = 0;
      bool inMainFunction = false;
      std::vector<std::string> asmCode;
      std::string returnLabel = "";
      std::vector<std::string> currentFunctionParams; 
      bool hasReturnStatement = false;  
      bool inIfCondition = false;  
      bool inLoopCondition = false; 
      bool inForIncrement = false;  
      bool inForCondition = false;  
      bool inAssignmentContext = false;  
      std::string currentIfFalseLabel = "";  
      std::string currentIfEndLabel = "";    
      std::string currentLoopBodyLabel = "";  
      std::string currentLoopExitLabel = "";  
      std::string currentContinueLabel = "";  
      std::vector<std::string> ifEndLabelStack;  

      std::string newLabel(){
          return "L" + std::to_string(labelCount++);
      }
      
      std::string getVarOffset(const std::string& varName) {
          if (localVarOffset.find(varName) != localVarOffset.end()) {
              int offset = localVarOffset[varName];
              if (offset < 0) {
                  // Parameter: stored as negative, using positive offset
                  return "[BP+" + std::to_string(-offset) + "]";
              } else {
                  // Local variable: using negative offset
                  return "[BP-" + std::to_string(offset) + "]";
              }
          }
          return varName;  
      }

      void emitCode(const std::string& code){
          if (code.back() == ':' || code.find(" PROC") != std::string::npos || code.find(" ENDP") != std::string::npos) {
              asmCode.push_back(code);
          } else {
              asmCode.push_back("\t" + code);
          }
      }

      void writeASMToFile(){
          asmFile.open("output/code.asm");
          asmFile << ".MODEL SMALL\n.STACK 1000H\n.DATA\n";
          asmFile << "\tnumber DB \"00000$\"\n";

          for(const auto& line : asmCode){
              if(line.find("GLOBAL_VAR:") != std::string::npos){  
                  size_t pos = line.find("GLOBAL_VAR:");
                  std::string varDecl = line.substr(pos + 11);  
                  asmFile << "\t" << varDecl << "\n";
              }
          }

          asmFile << ".CODE\n";

          for(const auto& line : asmCode){
              if(line.find("GLOBAL_VAR:") == std::string::npos){  
                  asmFile << line << "\n";
              }
          }

          asmFile << ";-------------------------------\n";
          asmFile << ";         print library         \n";
          asmFile << ";-------------------------------\n";
          asmFile << "print_output proc\n";
          asmFile << "    push ax\n";
          asmFile << "    push bx\n";
          asmFile << "    push cx\n";
          asmFile << "    push dx\n";
          asmFile << "    push si\n";
          asmFile << "    lea si, number\n";
          asmFile << "    mov bx, 10\n";
          asmFile << "    add si, 4\n";
          asmFile << "    cmp ax, 0\n";
          asmFile << "    jnge negate\n";
          asmFile << "    print_loop:\n";
          asmFile << "        xor dx, dx\n";
          asmFile << "        div bx\n";
          asmFile << "        mov [si], dl\n";
          asmFile << "        add [si], 48\n";
          asmFile << "        dec si\n";
          asmFile << "        cmp ax, 0\n";
          asmFile << "        jne print_loop\n";
          asmFile << "        inc si\n";
          asmFile << "        jmp print_output2\n";
          asmFile << "    negate:\n";
          asmFile << "        neg ax\n";
          asmFile << "        print_loop2:\n";
          asmFile << "            xor dx, dx\n";
          asmFile << "            div bx\n";
          asmFile << "            mov [si], dl\n";
          asmFile << "            add [si], 48\n";
          asmFile << "            dec si\n";
          asmFile << "            cmp ax, 0\n";
          asmFile << "            jne print_loop2\n";
          asmFile << "        mov [si], 45\n";
          asmFile << "        jmp print_output2\n";
          asmFile << "    print_output2:\n";
          asmFile << "        lea dx, si\n";
          asmFile << "        mov ah, 9\n";
          asmFile << "        int 21h\n";
          asmFile << "        pop si\n";
          asmFile << "        pop dx\n";
          asmFile << "        pop cx\n";
          asmFile << "        pop bx\n";
          asmFile << "        pop ax\n";
          asmFile << "        ret\n";
          asmFile << "print_output endp\n";
          asmFile << "\n";
          asmFile << "new_line proc\n";
          asmFile << "    push ax\n";
          asmFile << "    push dx\n";
          asmFile << "    mov ah, 2\n";
          asmFile << "    mov dl, 10\n";
          asmFile << "    int 21h\n";
          asmFile << "    mov dl, 13\n";
          asmFile << "    int 21h\n";
          asmFile << "    pop dx\n";
          asmFile << "    pop ax\n";
          asmFile << "    ret\n";
          asmFile << "new_line endp\n";
          asmFile << ";-------------------------------\n";
          asmFile << "END main\n";
          asmFile.close();

          optimizeCode();
      }

      void optimizeCode(){
          optimizedAsmFile.open("output/optimized_code.asm");
          
          optimizedAsmFile << ".MODEL SMALL\n.STACK 1000H\n.DATA\n";
          optimizedAsmFile << "\tnumber DB \"00000$\"\n";
          
          for(const auto& line : asmCode){
              if(line.find("GLOBAL_VAR:") != std::string::npos){
                  size_t pos = line.find("GLOBAL_VAR:");
                  std::string varDecl = line.substr(pos + 11);  
                  optimizedAsmFile << "\t" << varDecl << "\n";
              }
          }
          
          optimizedAsmFile << ".CODE\n";
          
          std::vector<std::string> optimized;
          std::set<std::string> removedLabels;
          std::set<std::string> usedLabels;
          
          // Removing redundant labels and record them
          for (size_t i = 0; i < asmCode.size(); i++) {
              if (asmCode[i].find("GLOBAL_VAR:") != std::string::npos) continue;
              std::string line = asmCode[i];

              if (i + 1 < asmCode.size()) {
                  std::string next = asmCode[i+1];
                  std::smatch m1, m2;
                  std::regex mov_ax_re("^\\tMOV AX, ([\\w\\[\\]-]+)");
                  std::regex mov_var_re("^\\tMOV ([\\w\\[\\]-]+), AX");
                  if (std::regex_search(line, m1, mov_ax_re) && std::regex_search(next, m2, mov_var_re) && m1[1] == m2[1]) {
                      optimized.push_back(line);
                      i++;
                      continue;
                  }
              }

              //Removing redundant PUSH/POP (allow comments/whitespace)
              if (i + 1 < asmCode.size()) {
                  std::string next = asmCode[i+1];
                  std::regex pop_ax_re("^\\tPOP AX(\\s*;.*)?$");
                  if (line == "\tPUSH AX" && std::regex_match(next, pop_ax_re)) {
                      i++;
                      continue;
                  }
              }

              // Removing redundant operations
              if (line.find("ADD AX, 0") != std::string::npos || line.find("MUL AX, 1") != std::string::npos) {
                  continue;
              }

              // Removing consecutive labels
              if (line.length() > 0 && line.back() == ':' && line.find('\t') == std::string::npos) {
                  size_t j = i + 1;
                  while (j < asmCode.size() && asmCode[j].length() > 0 && asmCode[j].back() == ':' && asmCode[j].find('\t') == std::string::npos) {
                      removedLabels.insert(asmCode[j].substr(0, asmCode[j].length() - 1));
                      j++;
                  }
                  optimized.push_back(line);
                  i = j - 1;
                  continue;
              }

              // Existing optimization: MOV-PUSH-Label-POP pattern for constants
              if (line.find("\tMOV AX, ") == 0 && line.find("; Line") != std::string::npos && i + 3 < asmCode.size() && asmCode[i+1] == "\tPUSH AX" && asmCode[i+2].length() > 0 && asmCode[i+2].back() == ':' && asmCode[i+2].find('\t') == std::string::npos) {
                  std::regex pop_ax_re("^\\tPOP AX(\\s*;.*)?$");
                  if (std::regex_match(asmCode[i+3], pop_ax_re)) {
                      optimized.push_back(asmCode[i+2]);
                      optimized.push_back(line);
                      i += 3;
                      continue;
                  }
              }

              optimized.push_back(line);
          }

          // Tracking label usage (jump targets)
          std::regex jump_re("^\\t(JMP|JE|JNE|JG|JL|JGE|JLE|JZ|JNZ)\\s+([A-Za-z0-9_]+)(\\s*;.*)?$");
          for (const auto& line : optimized) {
              std::smatch jm;
              if (std::regex_match(line, jm, jump_re)) {
                  usedLabels.insert(jm[2]);
              }
          }

          // Removing unused labels and their assignments (e.g., MOV AX, 0 after label)
          std::vector<std::string> finalOptimized;
          for (size_t i = 0; i < optimized.size(); i++) {
              std::string line = optimized[i];

              if (line.length() > 0 && line.back() == ':' && line.find('\t') == std::string::npos) {
                  std::string label = line.substr(0, line.length() - 1);

                  if (!usedLabels.count(label)) {
                      if (i + 1 < optimized.size()) {
                          std::regex mov_ax_zero_re("^\\tMOV AX, 0(\\s*;.*)?$");
                          if (std::regex_match(optimized[i+1], mov_ax_zero_re)) {
                              i++;
                          }
                      }
                      continue;
                  }
              }
              finalOptimized.push_back(line);
          }

          // Removing jump instructions to removed labels
          std::regex jump_re2("^\\t(JMP|JE|JNE|JG|JL|JGE|JLE|JZ|JNZ)\\s+([A-Za-z0-9_]+)(\\s*;.*)?$");
          std::set<std::string> allLabels;
          for (const auto& line : finalOptimized) {
              if (line.length() > 0 && line.back() == ':' && line.find('\t') == std::string::npos) {
                  allLabels.insert(line.substr(0, line.length() - 1));
              }
          }
          std::vector<std::string> reallyFinal;
          for (const auto& line : finalOptimized) {
              std::smatch jm;
              if (std::regex_match(line, jm, jump_re2)) {
                  std::string target = jm[2];
                  if (!allLabels.count(target)) {
                      continue; 
                  }
              }
              reallyFinal.push_back(line);
          }

          for (const auto& line : reallyFinal) {
              optimizedAsmFile << line << "\n";
          }
          optimizedAsmFile << ";-------------------------------\n";
          optimizedAsmFile << ";         print library         \n";
          optimizedAsmFile << ";-------------------------------\n";
          optimizedAsmFile << "print_output proc\n";
          optimizedAsmFile << "    push ax\n";
          optimizedAsmFile << "    push bx\n";
          optimizedAsmFile << "    push cx\n";
          optimizedAsmFile << "    push dx\n";
          optimizedAsmFile << "    push si\n";
          optimizedAsmFile << "    lea si, number\n";
          optimizedAsmFile << "    mov bx, 10\n";
          optimizedAsmFile << "    add si, 4\n";
          optimizedAsmFile << "    cmp ax, 0\n";
          optimizedAsmFile << "    jnge negate\n";
          optimizedAsmFile << "    print_loop:\n";
          optimizedAsmFile << "        xor dx, dx\n";
          optimizedAsmFile << "        div bx\n";
          optimizedAsmFile << "        mov [si], dl\n";
          optimizedAsmFile << "        add [si], 48\n";
          optimizedAsmFile << "        dec si\n";
          optimizedAsmFile << "        cmp ax, 0\n";
          optimizedAsmFile << "        jne print_loop\n";
          optimizedAsmFile << "        inc si\n";
          optimizedAsmFile << "        jmp print_output2\n";
          optimizedAsmFile << "    negate:\n";
          optimizedAsmFile << "        neg ax\n";
          optimizedAsmFile << "        print_loop2:\n";
          optimizedAsmFile << "            xor dx, dx\n";
          optimizedAsmFile << "            div bx\n";
          optimizedAsmFile << "            mov [si], dl\n";
          optimizedAsmFile << "            add [si], 48\n";
          optimizedAsmFile << "            dec si\n";
          optimizedAsmFile << "            cmp ax, 0\n";
          optimizedAsmFile << "            jne print_loop2\n";
          optimizedAsmFile << "        mov [si], 45\n";
          optimizedAsmFile << "        jmp print_output2\n";
          optimizedAsmFile << "    print_output2:\n";
          optimizedAsmFile << "        lea dx, si\n";
          optimizedAsmFile << "        mov ah, 9\n";
          optimizedAsmFile << "        int 21h\n";
          optimizedAsmFile << "        pop si\n";
          optimizedAsmFile << "        pop dx\n";
          optimizedAsmFile << "        pop cx\n";
          optimizedAsmFile << "        pop bx\n";
          optimizedAsmFile << "        pop ax\n";
          optimizedAsmFile << "        ret\n";
          optimizedAsmFile << "print_output endp\n";
          optimizedAsmFile << "\n";
          optimizedAsmFile << "new_line proc\n";
          optimizedAsmFile << "    push ax\n";
          optimizedAsmFile << "    push dx\n";
          optimizedAsmFile << "    mov ah, 2\n";
          optimizedAsmFile << "    mov dl, 10\n";
          optimizedAsmFile << "    int 21h\n";
          optimizedAsmFile << "    mov dl, 13\n";
          optimizedAsmFile << "    int 21h\n";
          optimizedAsmFile << "    pop dx\n";
          optimizedAsmFile << "    pop ax\n";
          optimizedAsmFile << "    ret\n";
          optimizedAsmFile << "new_line endp\n";
          optimizedAsmFile << ";-------------------------------\n";
          optimizedAsmFile << "END main\n";
          optimizedAsmFile.close();        
      }

      struct FunctionInfo{
          std::string returnType;
          std::vector<std::string> paramTypes;
          bool isDefined;
      };

      std::map<std::string, FunctionInfo> functionTable;    


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_listContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Declaration_list_errContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class StatementsContext;
  class StatementContext;
  class Case_statementsContext;
  class Case_statementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class Simple_expression_errContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    C8086Parser::ProgramContext *programContext = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    str_list prog_list;
    C8086Parser::ProgramContext *p = nullptr;
    C8086Parser::UnitContext *u = nullptr;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    std::string unit_val;
    C8086Parser::Var_declarationContext *vd = nullptr;
    C8086Parser::Func_declarationContext *fd = nullptr;
    C8086Parser::Func_definitionContext *fdef = nullptr;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    std::string func_decl;
    C8086Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Parameter_listContext *p = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();
    Type_specifierContext *type_specifier();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    std::string func_def;
    C8086Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Parameter_listContext *p = nullptr;
    C8086Parser::Compound_statementContext *c = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Type_specifierContext *type_specifier();
    Parameter_listContext *parameter_list();
    Compound_statementContext *compound_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_definitionContext* func_definition();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    std::string param_list;
    std::vector<std::string> param_types;
    C8086Parser::Parameter_listContext *p = nullptr;
    C8086Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *addopToken = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *COMMA();
    Parameter_listContext *parameter_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    std::string comp_stmt;
    C8086Parser::StatementsContext *s = nullptr;
    antlr4::Token *rcurlToken = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    std::string var_decl;
    C8086Parser::Type_specifierContext *t = nullptr;
    C8086Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    C8086Parser::Declaration_list_errContext *de = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();
    Declaration_list_errContext *declaration_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Declaration_list_errContext : public antlr4::ParserRuleContext {
  public:
    std::string error_name;
    Declaration_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_list_errContext* declaration_list_err();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    std::string name_line;
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *voidToken = nullptr;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    str_list var_list;
    C8086Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *idToken = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *addopToken = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *COMMA();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    std::string stmt_list;
    C8086Parser::StatementsContext *st = nullptr;
    C8086Parser::StatementContext *s = nullptr;
    antlr4::Token *invalid_charToken = nullptr;
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGNOP();
    Simple_expression_errContext *simple_expression_err();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *INVALID_CHAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    std::string stmt_val;
    C8086Parser::Var_declarationContext *vd = nullptr;
    C8086Parser::Expression_statementContext *es = nullptr;
    C8086Parser::Compound_statementContext *c = nullptr;
    C8086Parser::Expression_statementContext *es1 = nullptr;
    C8086Parser::Expression_statementContext *es2 = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    C8086Parser::StatementContext *s = nullptr;
    C8086Parser::StatementContext *s1 = nullptr;
    C8086Parser::StatementContext *s2 = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Case_statementsContext *cases = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SWITCH();
    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();
    Case_statementsContext *case_statements();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *GOTO();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Case_statementsContext : public antlr4::ParserRuleContext {
  public:
    std::string case_stmts;
    C8086Parser::Case_statementsContext *cs = nullptr;
    C8086Parser::Case_statementContext *c = nullptr;
    Case_statementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Case_statementContext *case_statement();
    Case_statementsContext *case_statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Case_statementsContext* case_statements();
  Case_statementsContext* case_statements(int precedence);
  class  Case_statementContext : public antlr4::ParserRuleContext {
  public:
    std::string case_stmt;
    antlr4::Token *const_intToken = nullptr;
    C8086Parser::StatementsContext *s = nullptr;
    antlr4::Token *semicolonToken = nullptr;
    Case_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *SEMICOLON();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *DEFAULT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Case_statementContext* case_statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    std::string expr_stmt;
    antlr4::Token *semicolonToken = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    std::string var_name;
    antlr4::Token *idToken = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    std::string expr_val;
    C8086Parser::Logic_expressionContext *l = nullptr;
    C8086Parser::VariableContext *v = nullptr;
    antlr4::Token *assignopToken = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *ASSIGNOP();
    VariableContext *variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string logic_val;
    C8086Parser::Rel_expressionContext *r = nullptr;
    C8086Parser::Rel_expressionContext *r1 = nullptr;
    antlr4::Token *logicopToken = nullptr;
    C8086Parser::Rel_expressionContext *r2 = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string rel_val;
    C8086Parser::Simple_expressionContext *s = nullptr;
    C8086Parser::Simple_expressionContext *s1 = nullptr;
    antlr4::Token *relopToken = nullptr;
    C8086Parser::Simple_expressionContext *s2 = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string simple_val;
    C8086Parser::Simple_expressionContext *s = nullptr;
    C8086Parser::TermContext *t = nullptr;
    antlr4::Token *addopToken = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    antlr4::tree::TerminalNode *ADDOP();
    Simple_expressionContext *simple_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  Simple_expression_errContext : public antlr4::ParserRuleContext {
  public:
    C8086Parser::Simple_expressionContext *s = nullptr;
    antlr4::Token *assignopToken = nullptr;
    Simple_expression_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *ASSIGNOP();
    Simple_expressionContext *simple_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expression_errContext* simple_expression_err();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    std::string term_val;
    C8086Parser::TermContext *t = nullptr;
    C8086Parser::Unary_expressionContext *u = nullptr;
    antlr4::Token *mulopToken = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *MULOP();
    TermContext *term();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string unary_val;
    antlr4::Token *addopToken = nullptr;
    C8086Parser::Unary_expressionContext *u = nullptr;
    antlr4::Token *notToken = nullptr;
    C8086Parser::FactorContext *f = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    std::string factor_val;
    C8086Parser::VariableContext *v = nullptr;
    antlr4::Token *idToken = nullptr;
    C8086Parser::Argument_listContext *a = nullptr;
    antlr4::Token *lparenToken = nullptr;
    C8086Parser::ExpressionContext *e = nullptr;
    antlr4::Token *const_intToken = nullptr;
    antlr4::Token *const_floatToken = nullptr;
    antlr4::Token *incopToken = nullptr;
    antlr4::Token *decopToken = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Argument_listContext *argument_list();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    std::string arg_list;
    C8086Parser::ArgumentsContext *a = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    std::string args_val;
    C8086Parser::ArgumentsContext *a = nullptr;
    C8086Parser::Logic_expressionContext *l = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool case_statementsSempred(Case_statementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

