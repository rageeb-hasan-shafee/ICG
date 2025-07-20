// Generated from /media/rageeb-hasan-shafee/New Volume/3-1/CSE 310/ICG/antlr4-skeletons/cpp/C8086Parser.g4 by ANTLR 4.13.1

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

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class C8086Parser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, STRING=3, WS=4, IF=5, ELSE=6, FOR=7, 
		WHILE=8, PRINTLN=9, RETURN=10, INT=11, FLOAT=12, VOID=13, SWITCH=14, CASE=15, 
		DEFAULT=16, BREAK=17, GOTO=18, LPAREN=19, RPAREN=20, LCURL=21, RCURL=22, 
		LTHIRD=23, RTHIRD=24, SEMICOLON=25, COMMA=26, COLON=27, ADDOP=28, SUBOP=29, 
		MULOP=30, INCOP=31, DECOP=32, NOT=33, RELOP=34, LOGICOP=35, ASSIGNOP=36, 
		ID=37, CONST_INT=38, CONST_FLOAT=39, INVALID_CHAR=40;
	public static final int
		RULE_start = 0, RULE_program = 1, RULE_unit = 2, RULE_func_declaration = 3, 
		RULE_func_definition = 4, RULE_parameter_list = 5, RULE_compound_statement = 6, 
		RULE_var_declaration = 7, RULE_declaration_list_err = 8, RULE_type_specifier = 9, 
		RULE_declaration_list = 10, RULE_statements = 11, RULE_statement = 12, 
		RULE_case_statements = 13, RULE_case_statement = 14, RULE_expression_statement = 15, 
		RULE_variable = 16, RULE_expression = 17, RULE_logic_expression = 18, 
		RULE_rel_expression = 19, RULE_simple_expression = 20, RULE_simple_expression_err = 21, 
		RULE_term = 22, RULE_unary_expression = 23, RULE_factor = 24, RULE_argument_list = 25, 
		RULE_arguments = 26;
	private static String[] makeRuleNames() {
		return new String[] {
			"start", "program", "unit", "func_declaration", "func_definition", "parameter_list", 
			"compound_statement", "var_declaration", "declaration_list_err", "type_specifier", 
			"declaration_list", "statements", "statement", "case_statements", "case_statement", 
			"expression_statement", "variable", "expression", "logic_expression", 
			"rel_expression", "simple_expression", "simple_expression_err", "term", 
			"unary_expression", "factor", "argument_list", "arguments"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'if'", "'else'", "'for'", "'while'", "'println'", 
			"'return'", "'int'", "'float'", "'void'", "'switch'", "'case'", "'default'", 
			"'break'", "'goto'", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", 
			"','", "':'", null, null, null, "'++'", "'--'", "'!'", null, null, "'='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
			"FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "SWITCH", 
			"CASE", "DEFAULT", "BREAK", "GOTO", "LPAREN", "RPAREN", "LCURL", "RCURL", 
			"LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", "COLON", "ADDOP", "SUBOP", 
			"MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", "ID", 
			"CONST_INT", "CONST_FLOAT", "INVALID_CHAR"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "C8086Parser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


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
	    std::vector<std::string> currentFunctionParams;  // Track parameter names for current function
	    bool hasReturnStatement = false;  // Track if function has explicit return statement
	    bool inIfCondition = false;  // Track if we're in IF condition context
	    bool inLoopCondition = false; // Track if we're in FOR/WHILE condition context
	    bool inForIncrement = false;  // Track if we're in FOR increment context (suppress code generation)
	    bool inForCondition = false;  // Track if we're in FOR condition context (suppress code generation)
	    bool inAssignmentContext = false;  // Track if we're in assignment context (don't push results)
	    std::string currentIfFalseLabel = "";  // Store the false label for current IF
	    std::string currentIfEndLabel = "";    // Store the end label for current IF-ELSE
	    std::string currentLoopBodyLabel = "";  // Store the body label for current loop
	    std::string currentLoopExitLabel = "";  // Store the exit label for current loop
	    std::string currentContinueLabel = "";  // Store the continue label for current loop
	    std::vector<std::string> ifEndLabelStack;  // Stack for nested IF end labels

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
	        // First pass: Remove redundant labels and record them
	        for (size_t i = 0; i < asmCode.size(); i++) {
	            if (asmCode[i].find("GLOBAL_VAR:") != std::string::npos) continue;
	            std::string line = asmCode[i];

	            // (i) Remove redundant MOV AX, a / MOV a, AX
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

	            // (ii) Remove redundant PUSH/POP (allow comments/whitespace)
	            if (i + 1 < asmCode.size()) {
	                std::string next = asmCode[i+1];
	                std::regex pop_ax_re("^\\tPOP AX(\\s*;.*)?$");
	                if (line == "\tPUSH AX" && std::regex_match(next, pop_ax_re)) {
	                    i++;
	                    continue;
	                }
	            }

	            // (iii) Remove redundant operations
	            if (line.find("ADD AX, 0") != std::string::npos || line.find("MUL AX, 1") != std::string::npos) {
	                continue;
	            }

	            // (iv) Remove consecutive labels (keep only one)
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

	        // Second pass: Track label usage (jump targets)
	        std::regex jump_re("^\\t(JMP|JE|JNE|JG|JL|JGE|JLE|JZ|JNZ)\\s+([A-Za-z0-9_]+)(\\s*;.*)?$");
	        for (const auto& line : optimized) {
	            std::smatch jm;
	            if (std::regex_match(line, jm, jump_re)) {
	                usedLabels.insert(jm[2]);
	            }
	        }

	        // Third pass: Remove unused labels and their assignments (e.g., MOV AX, 0 after label)
	        std::vector<std::string> finalOptimized;
	        for (size_t i = 0; i < optimized.size(); i++) {
	            std::string line = optimized[i];
	            // Label line
	            if (line.length() > 0 && line.back() == ':' && line.find('\t') == std::string::npos) {
	                std::string label = line.substr(0, line.length() - 1);
	                // Remove label if not used anywhere
	                if (!usedLabels.count(label)) {
	                    // Also remove assignment immediately after label (e.g., MOV AX, 0)
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

	        // Fourth pass: Remove jump instructions to removed labels
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
	                    continue; // Remove jump to removed label
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

	public C8086Parser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StartContext extends ParserRuleContext {
		public ProgramContext program;
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public StartContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_start; }
	}

	public final StartContext start() throws RecognitionException {
		StartContext _localctx = new StartContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_start);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(54);
			((StartContext)_localctx).program = program(0);
			        
			        writeIntoparserLogFile("\nLine " + std::to_string((((StartContext)_localctx).program!=null?(((StartContext)_localctx).program.stop):null)->getLine()) + ": start : program\n");
			        
			        symb.printAllScopes(parserLogFile);
			        
			        writeIntoparserLogFile("\nTotal number of lines: " + std::to_string((((StartContext)_localctx).program!=null?(((StartContext)_localctx).program.stop):null)->getLine()));
			        writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));
			        
			        writeASMToFile();
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public str_list prog_list;
		public ProgramContext p;
		public UnitContext u;
		public UnitContext unit() {
			return getRuleContext(UnitContext.class,0);
		}
		public ProgramContext program() {
			return getRuleContext(ProgramContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		return program(0);
	}

	private ProgramContext program(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ProgramContext _localctx = new ProgramContext(_ctx, _parentState);
		ProgramContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_program, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(58);
			((ProgramContext)_localctx).u = unit();

			        _localctx.prog_list.add(((ProgramContext)_localctx).u.unit_val);
			        writeIntoparserLogFile("\nLine " + std::to_string((((ProgramContext)_localctx).u!=null?(((ProgramContext)_localctx).u.stop):null)->getLine()) + ": program : unit\n");
			        writeIntoparserLogFile(_localctx.prog_list.get_list_as_string() + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(67);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ProgramContext(_parentctx, _parentState);
					_localctx.p = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_program);
					setState(61);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(62);
					((ProgramContext)_localctx).u = unit();

					                  _localctx.prog_list.set_variables(((ProgramContext)_localctx).p.prog_list.get_variables());
					                  _localctx.prog_list.add(((ProgramContext)_localctx).u.unit_val);
					                  writeIntoparserLogFile("\nLine " + std::to_string((((ProgramContext)_localctx).u!=null?(((ProgramContext)_localctx).u.stop):null)->getLine()) + ": program : program unit\n");

					                  std::string output = _localctx.prog_list.get_list_as_string();
					                  std::istringstream stream(output);
					                  std::string line;
					                  std::string result;
					                  bool isFirstDeclarations = true;
					                  bool elseFound = false;
					                  
					                  while (std::getline(stream, line)) {
					                      // Trimmed whitespace
					                      line.erase(0, line.find_first_not_of(" \t\r\n"));
					                      line.erase(line.find_last_not_of(" \t\r\n") + 1);
					                      
					                      if (!line.empty()) {
					                          // Handle initial declarations differently
					                          if (isFirstDeclarations && line.find(";") != std::string::npos) {
					                              size_t pos = 0;
					                              while ((pos = line.find(";", pos)) != std::string::npos) {
					                                  std::string decl = line.substr(0, pos + 1);
					                                  result += decl + "\n\n";
					                                  line = line.substr(pos + 1);
					                                  // Skip whitespace
					                                  while (!line.empty() && (line[0] == ' ' || line[0] == '\t')) {
					                                      line = line.substr(1);
					                                  }
					                                  pos = 0;
					                              }
					                              isFirstDeclarations = false;
					                              continue;
					                          }
					                          
					                          result += line + "\n";
					                      }
					                  }

					                  writeIntoparserLogFile(result + "\n");
					              
					}
					} 
				}
				setState(69);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UnitContext extends ParserRuleContext {
		public std::string unit_val;
		public Var_declarationContext vd;
		public Func_declarationContext fd;
		public Func_definitionContext fdef;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_definitionContext func_definition() {
			return getRuleContext(Func_definitionContext.class,0);
		}
		public UnitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unit; }
	}

	public final UnitContext unit() throws RecognitionException {
		UnitContext _localctx = new UnitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_unit);
		try {
			setState(79);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(70);
				((UnitContext)_localctx).vd = var_declaration();

				        ((UnitContext)_localctx).unit_val =  ((UnitContext)_localctx).vd.var_decl;
				        writeIntoparserLogFile("Line " + std::to_string((((UnitContext)_localctx).vd!=null?(((UnitContext)_localctx).vd.start):null)->getLine()) + ": unit : var_declaration\n");
				        writeIntoparserLogFile(_localctx.unit_val );
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(73);
				((UnitContext)_localctx).fd = func_declaration();

				        ((UnitContext)_localctx).unit_val =  ((UnitContext)_localctx).fd.func_decl;
				        writeIntoparserLogFile("Line " + std::to_string((((UnitContext)_localctx).fd!=null?(((UnitContext)_localctx).fd.start):null)->getLine()) + ": unit : func_declaration\n");
				        writeIntoparserLogFile(_localctx.unit_val);
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(76);
				((UnitContext)_localctx).fdef = func_definition();

				        ((UnitContext)_localctx).unit_val =  ((UnitContext)_localctx).fdef.func_def;
				        writeIntoparserLogFile("Line " + std::to_string((((UnitContext)_localctx).fdef!=null?(((UnitContext)_localctx).fdef.stop):null)->getLine()) + ": unit : func_definition\n");
				        writeIntoparserLogFile(_localctx.unit_val);
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_declarationContext extends ParserRuleContext {
		public std::string func_decl;
		public Type_specifierContext t;
		public Token ID;
		public Parameter_listContext p;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_declaration);
		try {
			setState(96);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(81);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(82);
				((Func_declarationContext)_localctx).ID = match(ID);
				setState(83);
				match(LPAREN);
				setState(84);
				((Func_declarationContext)_localctx).p = parameter_list(0);
				setState(85);
				match(RPAREN);
				setState(86);
				match(SEMICOLON);

				        if (symb.getCurrentScope()->lookUp(parserLogFile, ((Func_declarationContext)_localctx).ID->getText()) == nullptr) {
				            SymbolInfo* funcSymbol = new SymbolInfo(((Func_declarationContext)_localctx).ID->getText(), "FUNCTION");
				            symb.insert(funcSymbol);
				        }

				        ((Func_declarationContext)_localctx).func_decl =  ((Func_declarationContext)_localctx).t.name_line + " " + ((Func_declarationContext)_localctx).ID->getText() + "(" + ((Func_declarationContext)_localctx).p.param_list + ");";

				        FunctionInfo fi;
				        fi.returnType = ((Func_declarationContext)_localctx).t.name_line;
				        fi.isDefined = false;
				        fi.paramTypes = ((Func_declarationContext)_localctx).p.param_types;
				        functionTable[((Func_declarationContext)_localctx).ID->getText()] = fi;
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Func_declarationContext)_localctx).ID->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.func_decl + "\n\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(89);
				((Func_declarationContext)_localctx).t = type_specifier();
				setState(90);
				((Func_declarationContext)_localctx).ID = match(ID);
				setState(91);
				match(LPAREN);
				setState(92);
				match(RPAREN);
				setState(93);
				match(SEMICOLON);

				        if (symb.getCurrentScope()->lookUp(parserLogFile, ((Func_declarationContext)_localctx).ID->getText()) == nullptr) {
				            SymbolInfo* funcSymbol = new SymbolInfo(((Func_declarationContext)_localctx).ID->getText(), "FUNCTION");  
				            symb.insert(funcSymbol);
				        }
				        ((Func_declarationContext)_localctx).func_decl =  ((Func_declarationContext)_localctx).t.name_line + " " + ((Func_declarationContext)_localctx).ID->getText() + "();";
				        
				        FunctionInfo fi;
				        fi.returnType = ((Func_declarationContext)_localctx).t.name_line;
				        fi.isDefined = false;
				        functionTable[((Func_declarationContext)_localctx).ID->getText()] = fi;
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Func_declarationContext)_localctx).ID->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.func_decl + "\n\n"); 

				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_definitionContext extends ParserRuleContext {
		public std::string func_def;
		public Type_specifierContext t;
		public Token ID;
		public Parameter_listContext p;
		public Compound_statementContext c;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public Func_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_definition; }
	}

	public final Func_definitionContext func_definition() throws RecognitionException {
		Func_definitionContext _localctx = new Func_definitionContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_definition);
		try {
			setState(118);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(98);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(99);
				((Func_definitionContext)_localctx).ID = match(ID);

				        currentFunction = ((Func_definitionContext)_localctx).ID->getText();
				        currentOffset = 0;
				        localVarOffset.clear();
				        currentFunctionParams.clear();  
				        hasReturnStatement = false;  
				        
				        // Generating function prologue
				        if (((Func_definitionContext)_localctx).ID->getText() == "main") {
				            emitCode("main PROC");
				            emitCode("MOV AX, @DATA");
				            emitCode("MOV DS, AX");
				            inMainFunction = true;
				        } else {
				            emitCode(((Func_definitionContext)_localctx).ID->getText() + " PROC");
				        }
				        emitCode("PUSH BP");
				        emitCode("MOV BP, SP");

				        if(functionTable.find(((Func_definitionContext)_localctx).ID->getText()) != functionTable.end()) {
				            FunctionInfo& existingFunc = functionTable[((Func_definitionContext)_localctx).ID->getText()];
				            if(existingFunc.returnType != ((Func_definitionContext)_localctx).t.name_line) {
				                syntaxErrorCount++;
				                writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				            }
				            if(existingFunc.isDefined) {
				                syntaxErrorCount++;
				                writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple definition of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple definition of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");                
				            }
				        }

				        SymbolInfo* found = symb.getCurrentScope()->lookUp(parserLogFile, ((Func_definitionContext)_localctx).ID->getText());
				        if(found != nullptr && found->getType() != "FUNCTION") {
				            syntaxErrorCount++;
				            writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");                
				        }

				        if(found == nullptr) {
				            SymbolInfo* funcSymbol = new SymbolInfo(((Func_definitionContext)_localctx).ID->getText(), "FUNCTION");
				            symb.insert(funcSymbol);
				        }
				    
				setState(101);
				match(LPAREN);

				        symb.enterScope();
				        scopeEntered = true;
				    
				setState(103);
				((Func_definitionContext)_localctx).p = parameter_list(0);
				setState(104);
				match(RPAREN);

				        int totalParams = ((Func_definitionContext)_localctx).p.param_types.size();
				        if (totalParams > 1) {
				            for (size_t i = 0; i < currentFunctionParams.size(); i++) {
				                int paramOffset = 4 + (totalParams - 1 - i) * 2;

				                localVarOffset[currentFunctionParams[i]] = -paramOffset;
				            }
				        }
				        
				        if(functionTable.find(((Func_definitionContext)_localctx).ID->getText()) != functionTable.end()) {
				            FunctionInfo& existingFunc = functionTable[((Func_definitionContext)_localctx).ID->getText()];
				            
				            if(!existingFunc.isDefined) { 
				                if(existingFunc.paramTypes.size() != ((Func_definitionContext)_localctx).p.param_types.size()) {
				                    syntaxErrorCount++;
				                    writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                    writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                }
				                else {
				                    for(size_t i = 0; i < existingFunc.paramTypes.size(); i++) {
				                        if(existingFunc.paramTypes[i] != ((Func_definitionContext)_localctx).p.param_types[i]) {
				                            syntaxErrorCount++;
				                            writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                            writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                        }
				                    }
				                }
				            }
				        }

				        FunctionInfo fi;
				        fi.returnType = ((Func_definitionContext)_localctx).t.name_line;
				        fi.isDefined = true;
				        fi.paramTypes = ((Func_definitionContext)_localctx).p.param_types;
				        functionTable[((Func_definitionContext)_localctx).ID->getText()] = fi;      
				    
				setState(106);
				((Func_definitionContext)_localctx).c = compound_statement();

				        ((Func_definitionContext)_localctx).func_def =  ((Func_definitionContext)_localctx).t.name_line + " " + ((Func_definitionContext)_localctx).ID->getText() + "(" + ((Func_definitionContext)_localctx).p.param_list + ")" + ((Func_definitionContext)_localctx).c.comp_stmt;
				        
				        if (inMainFunction) {
				            if (!returnLabel.empty()) {
				                emitCode(returnLabel + ":");  // Use stored L7
				            }

				            if (!hasReturnStatement) {
				                emitCode("ADD SP, " + std::to_string(currentOffset));
				                emitCode("POP BP");
				                emitCode("MOV AX,4CH");
				                emitCode("INT 21H");
				            }
				            emitCode("main ENDP");
				            inMainFunction = false;
				            returnLabel = "";  
				        } else {
				            if (!returnLabel.empty()) {
				                emitCode(returnLabel + ":");  
				            }

				            if (!hasReturnStatement) {
				                emitCode("POP BP");
				                
				                // Calculate bytes to clean up from stack (2 bytes per parameter)
				                int paramBytes = ((Func_definitionContext)_localctx).p.param_types.size() * 2;
				                if (paramBytes > 0) {
				                    emitCode("RET " + std::to_string(paramBytes));
				                } else {
				                    emitCode("RET");
				                }
				            }
				            emitCode(((Func_definitionContext)_localctx).ID->getText() + " ENDP");
				            returnLabel = "";  // Reset for next function
				        }

				        // Check void function return type error
				        if(functionTable.find(currentFunction) != functionTable.end()) {
				            FunctionInfo& currentFunc = functionTable[currentFunction];
				            if(currentFunc.returnType == "void" && ((Func_definitionContext)_localctx).c.comp_stmt.find("return") != std::string::npos) {
				                writeIntoErrorFile("Error at line " + std::to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
				                writeIntoparserLogFile("Error at line " + std::to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
				                syntaxErrorCount++;
				            }
				        }
				        
				        currentFunction = "";
				        symb.exitScope();
				        scopeEntered = false;
				        
				        writeIntoparserLogFile("Line " + std::to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");
				        writeIntoparserLogFile(_localctx.func_def + "\n\n");
				        
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(109);
				((Func_definitionContext)_localctx).t = type_specifier();
				setState(110);
				((Func_definitionContext)_localctx).ID = match(ID);

				        currentFunction = ((Func_definitionContext)_localctx).ID->getText();
				        currentOffset = 0;
				        localVarOffset.clear();
				        currentFunctionParams.clear();  // Clear parameter names for new function
				        hasReturnStatement = false;  // Reset return flag for new function
				        
				        // Generate function prologue
				        if (((Func_definitionContext)_localctx).ID->getText() == "main") {
				            emitCode("main PROC");
				            emitCode("MOV AX, @DATA");
				            emitCode("MOV DS, AX");
				            inMainFunction = true;
				        } else {
				            emitCode(((Func_definitionContext)_localctx).ID->getText() + " PROC");
				        }
				        emitCode("PUSH BP");
				        emitCode("MOV BP, SP");
				        
				        if(functionTable.find(((Func_definitionContext)_localctx).ID->getText()) != functionTable.end()) {
				            FunctionInfo& existingFunc = functionTable[((Func_definitionContext)_localctx).ID->getText()];
				            
				            if(existingFunc.returnType != ((Func_definitionContext)_localctx).t.name_line) {
				                syntaxErrorCount++;
				                writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Return type mismatch of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				            }
				            
				            if(existingFunc.isDefined) {
				                syntaxErrorCount++;
				                writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple definition of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple definition of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");                              
				            }
				        }

				        SymbolInfo* found = symb.getCurrentScope()->lookUp(parserLogFile, ((Func_definitionContext)_localctx).ID->getText());
				        if(found != nullptr && found->getType() != "FUNCTION") {
				            syntaxErrorCount++;
				            writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Func_definitionContext)_localctx).ID->getText() + "\n");                
				        }

				        if(found == nullptr) {
				            SymbolInfo* funcSymbol = new SymbolInfo(((Func_definitionContext)_localctx).ID->getText(), "FUNCTION");
				            symb.insert(funcSymbol);
				        }
				    
				setState(112);
				match(LPAREN);
				setState(113);
				match(RPAREN);

				        symb.enterScope();
				        scopeEntered = true;
				        
				        if(functionTable.find(((Func_definitionContext)_localctx).ID->getText()) != functionTable.end()) {
				            FunctionInfo& existingFunc = functionTable[((Func_definitionContext)_localctx).ID->getText()];
				            
				            if(!existingFunc.isDefined && !existingFunc.paramTypes.empty()) {
				                syntaxErrorCount++;
				                writeIntoErrorFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((Func_definitionContext)_localctx).ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((Func_definitionContext)_localctx).ID->getText() + "\n");
				            }
				        }
				        
				        FunctionInfo fi;
				        fi.returnType = ((Func_definitionContext)_localctx).t.name_line;
				        fi.isDefined = true;
				        functionTable[((Func_definitionContext)_localctx).ID->getText()] = fi;        
				    
				setState(115);
				((Func_definitionContext)_localctx).c = compound_statement();

				        ((Func_definitionContext)_localctx).func_def =  ((Func_definitionContext)_localctx).t.name_line + " " + ((Func_definitionContext)_localctx).ID->getText() + "()" + ((Func_definitionContext)_localctx).c.comp_stmt;
				        if (inMainFunction) {
				            if (!returnLabel.empty()) {
				                emitCode(returnLabel + ":");  // Use stored L7
				            }
				            // Only generate epilogue if no explicit return statement
				            if (!hasReturnStatement) {
				                emitCode("ADD SP, " + std::to_string(currentOffset));
				                emitCode("POP BP");
				                emitCode("MOV AX,4CH");
				                emitCode("INT 21H");
				            }
				            emitCode("main ENDP");
				            inMainFunction = false;
				            returnLabel = "";  // Reset for next function
				        } else {
				            if (!returnLabel.empty()) {
				                emitCode(returnLabel + ":");  // Use stored return label for non-main functions too
				            }
				            // Only generate epilogue if no explicit return statement
				            if (!hasReturnStatement) {
				                emitCode("POP BP");
				                emitCode("RET");
				            }
				            emitCode(((Func_definitionContext)_localctx).ID->getText() + " ENDP");
				            returnLabel = "";  // Reset for next function
				        }
				        
				        // Check void function return type error
				        if(functionTable.find(currentFunction) != functionTable.end()) {
				            FunctionInfo& currentFunc = functionTable[currentFunction];
				            if(currentFunc.returnType == "void" && ((Func_definitionContext)_localctx).c.comp_stmt.find("return") != std::string::npos) {
				                writeIntoErrorFile("Error at line " + std::to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
				                writeIntoparserLogFile("Error at line " + std::to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
				                syntaxErrorCount++;
				            }
				        }
				        
				        currentFunction = "";
				        symb.exitScope();
				        scopeEntered = false; 
				        
				        writeIntoparserLogFile("Line " + std::to_string((((Func_definitionContext)_localctx).c!=null?(((Func_definitionContext)_localctx).c.stop):null)->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");
				        writeIntoparserLogFile(_localctx.func_def + "\n\n");

				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Parameter_listContext extends ParserRuleContext {
		public std::string param_list;
		public std::vector<std::string> param_types;
		public Parameter_listContext p;
		public Type_specifierContext t;
		public Token ID;
		public Token ADDOP;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public Parameter_listContext parameter_list() {
			return getRuleContext(Parameter_listContext.class,0);
		}
		public Parameter_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter_list; }
	}

	public final Parameter_listContext parameter_list() throws RecognitionException {
		return parameter_list(0);
	}

	private Parameter_listContext parameter_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Parameter_listContext _localctx = new Parameter_listContext(_ctx, _parentState);
		Parameter_listContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_parameter_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(132);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(121);
				((Parameter_listContext)_localctx).t = type_specifier();
				setState(122);
				((Parameter_listContext)_localctx).ID = match(ID);

				        ((Parameter_listContext)_localctx).param_list =  ((Parameter_listContext)_localctx).t.name_line + " " + ((Parameter_listContext)_localctx).ID->getText() ;
				        _localctx.param_types.push_back(((Parameter_listContext)_localctx).t.name_line);

				        if(scopeEntered){
				            SymbolInfo* paramSymbol = new SymbolInfo(((Parameter_listContext)_localctx).ID->getText(), "ID");
				            symb.insert(paramSymbol);
				            
				            // Add to parameter tracking list  
				            currentFunctionParams.push_back(((Parameter_listContext)_localctx).ID->getText());
				            
				            // Set parameter offset (parameter will be at [BP+4] - will be adjusted later)
				            int initialOffset = 4;
				            localVarOffset[((Parameter_listContext)_localctx).ID->getText()] = -initialOffset;  // Store as negative to indicate parameter
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Parameter_listContext)_localctx).ID->getLine()) + ": parameter_list : type_specifier ID\n");
				        writeIntoparserLogFile(_localctx.param_list + "\n");
				    
				}
				break;
			case 2:
				{
				setState(125);
				((Parameter_listContext)_localctx).t = type_specifier();

				        ((Parameter_listContext)_localctx).param_list =  ((Parameter_listContext)_localctx).t.name_line ;
				        _localctx.param_types.push_back(((Parameter_listContext)_localctx).t.name_line);
				        
				        writeIntoparserLogFile("Line " + std::to_string((((Parameter_listContext)_localctx).t!=null?(((Parameter_listContext)_localctx).t.start):null)->getLine()) + ": parameter_list : type_specifier\n");
				        writeIntoparserLogFile(_localctx.param_list + "\n");
				    
				}
				break;
			case 3:
				{
				setState(128);
				((Parameter_listContext)_localctx).t = type_specifier();
				setState(129);
				((Parameter_listContext)_localctx).ADDOP = match(ADDOP);

				        ((Parameter_listContext)_localctx).param_list =  ((Parameter_listContext)_localctx).t.name_line ;
				        _localctx.param_types.push_back(((Parameter_listContext)_localctx).t.name_line);
				        writeIntoErrorFile("Error at line " + std::to_string(((Parameter_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
				        writeIntoparserLogFile("Error at line " + std::to_string(((Parameter_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");       
				        syntaxErrorCount++;
				        
				    
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(147);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(145);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.p = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(134);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(135);
						match(COMMA);
						setState(136);
						((Parameter_listContext)_localctx).t = type_specifier();
						setState(137);
						((Parameter_listContext)_localctx).ID = match(ID);

						                  if(symb.getCurrentScope()->lookUp(parserLogFile, ((Parameter_listContext)_localctx).ID->getText()) != nullptr){
						                      syntaxErrorCount++;
						                      writeIntoErrorFile("Error at line " + std::to_string(((Parameter_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Parameter_listContext)_localctx).ID->getText() + " in parameter\n");
						                      writeIntoparserLogFile("Error at line " + std::to_string(((Parameter_listContext)_localctx).ID->getLine()) + ": Multiple declaration of " + ((Parameter_listContext)_localctx).ID->getText() + " in parameter\n");
						                  }

						                  ((Parameter_listContext)_localctx).param_list =  ((Parameter_listContext)_localctx).p.param_list + "," + ((Parameter_listContext)_localctx).t.name_line + " " + ((Parameter_listContext)_localctx).ID->getText();
						                  ((Parameter_listContext)_localctx).param_types =  ((Parameter_listContext)_localctx).p.param_types;
						                  _localctx.param_types.push_back(((Parameter_listContext)_localctx).t.name_line);

						                  if (scopeEntered) {
						                      SymbolInfo* paramSymbol = new SymbolInfo(((Parameter_listContext)_localctx).ID->getText(), "ID");
						                      symb.insert(paramSymbol);
						                      
						                      // Add to parameter tracking list
						                      currentFunctionParams.push_back(((Parameter_listContext)_localctx).ID->getText());
						                      
						                      // Set parameter offset (parameters are at positive offsets from BP)
						                      // Initial assignment - will be corrected after parsing all parameters
						                      int totalParams = _localctx.param_types.size();            // Total parameters so far
						                      int paramOffset = 4 + (totalParams - 1) * 2;      // Temporary assignment
						                      localVarOffset[((Parameter_listContext)_localctx).ID->getText()] = -paramOffset;  // Store as negative to indicate positive offset
						                  }
						                  
						                  writeIntoparserLogFile("Line " + std::to_string(((Parameter_listContext)_localctx).ID->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n");
						                  writeIntoparserLogFile(_localctx.param_list + "\n");
						              
						}
						break;
					case 2:
						{
						_localctx = new Parameter_listContext(_parentctx, _parentState);
						_localctx.p = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_parameter_list);
						setState(140);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(141);
						match(COMMA);
						setState(142);
						((Parameter_listContext)_localctx).t = type_specifier();

						                  ((Parameter_listContext)_localctx).param_list =  ((Parameter_listContext)_localctx).p.param_list + "," + ((Parameter_listContext)_localctx).t.name_line + " " ;
						                  ((Parameter_listContext)_localctx).param_types =  ((Parameter_listContext)_localctx).p.param_types;
						                  _localctx.param_types.push_back(((Parameter_listContext)_localctx).t.name_line);
						                  
						                  writeIntoparserLogFile("Line " + std::to_string((((Parameter_listContext)_localctx).t!=null?(((Parameter_listContext)_localctx).t.start):null)->getLine()) + ": parameter_list : parameter_list COMMA type_specifier\n");
						                  writeIntoparserLogFile(_localctx.param_list + "\n");
						              
						}
						break;
					}
					} 
				}
				setState(149);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Compound_statementContext extends ParserRuleContext {
		public std::string comp_stmt;
		public StatementsContext s;
		public Token RCURL;
		public TerminalNode LCURL() { return getToken(C8086Parser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(C8086Parser.RCURL, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public Compound_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compound_statement; }
	}

	public final Compound_statementContext compound_statement() throws RecognitionException {
		Compound_statementContext _localctx = new Compound_statementContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_compound_statement);
		try {
			setState(159);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(150);
				match(LCURL);

				        if (!scopeEntered) {
				            symb.enterScope();
				            scopeEntered = true;
				        }        
				    
				setState(152);
				((Compound_statementContext)_localctx).s = statements(0);
				setState(153);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

				        ((Compound_statementContext)_localctx).comp_stmt =  "{\n" + ((Compound_statementContext)_localctx).s.stmt_list + "}\n";

				        writeIntoparserLogFile("Line " + std::to_string(((Compound_statementContext)_localctx).RCURL->getLine()) + ": compound_statement : LCURL statements RCURL\n");
				        writeIntoparserLogFile(_localctx.comp_stmt + "\n");
				        symb.printAllScopes(parserLogFile);
				        writeIntoparserLogFile("\n");

				        if (!scopeEntered) {
				            symb.exitScope();
				            scopeEntered = false;
				        }     
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(156);
				match(LCURL);
				setState(157);
				((Compound_statementContext)_localctx).RCURL = match(RCURL);

				        symb.enterScope();
				        ((Compound_statementContext)_localctx).comp_stmt =  "{\n}\n";
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Compound_statementContext)_localctx).RCURL->getLine()) + ": compound_statement : LCURL RCURL\n");
				        writeIntoparserLogFile(_localctx.comp_stmt + "\n");
				        symb.printAllScopes(parserLogFile);
				        writeIntoparserLogFile("\n");
				        
				        symb.exitScope();
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_declarationContext extends ParserRuleContext {
		public std::string var_decl;
		public Type_specifierContext t;
		public Declaration_listContext dl;
		public Token sm;
		public Declaration_list_errContext de;
		public Type_specifierContext type_specifier() {
			return getRuleContext(Type_specifierContext.class,0);
		}
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public Declaration_list_errContext declaration_list_err() {
			return getRuleContext(Declaration_list_errContext.class,0);
		}
		public Var_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_declaration; }
	}

	public final Var_declarationContext var_declaration() throws RecognitionException {
		Var_declarationContext _localctx = new Var_declarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_var_declaration);
		try {
			setState(171);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(161);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(162);
				((Var_declarationContext)_localctx).dl = declaration_list(0);
				setState(163);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        if(((Var_declarationContext)_localctx).t.name_line == "void"){
				            writeIntoErrorFile("Error at line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Variable type cannot be void\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Variable type cannot be void\n");
				            syntaxErrorCount++;        
				        }

				        // Generate assembly for variable declarations
				        std::string vars = ((Var_declarationContext)_localctx).dl.var_list.get_list_as_string();
				        std::istringstream varStream(vars);
				        std::string varEntry;
				        
				        while (std::getline(varStream, varEntry, ',')) {
				            varEntry.erase(0, varEntry.find_first_not_of(" \t"));
				            varEntry.erase(varEntry.find_last_not_of(" \t") + 1);
				            
				            std::string varName = varEntry;
				            std::string varType = ((Var_declarationContext)_localctx).t.name_line;
				            int varSize = 2;
				            
				            size_t bracketPos = varEntry.find("[");
				            if (bracketPos != std::string::npos) {
				                varName = varEntry.substr(0, bracketPos);
				                std::string sizeStr = varEntry.substr(bracketPos + 1);
				                sizeStr = sizeStr.substr(0, sizeStr.find("]"));
				                varSize = std::stoi(sizeStr) * 2;
				                varType = "ARRAY";
				            } else if (varType == "int") {
				                varType = "INT";
				            } else if (varType == "float") {
				                varType = "FLOAT";
				            }

				            if (symb.getCurrentScope()->lookUp(parserLogFile, varName) != nullptr ) {
				                writeIntoErrorFile("Error at line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Multiple declaration of " + varName + "\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": Multiple declaration of " + varName + "\n");
				                syntaxErrorCount++;
				                continue;
				            }
				            
				            SymbolInfo* newSymbol = new SymbolInfo(varName, varType);
				            if (!symb.insert(newSymbol)) {
				                delete newSymbol;
				            }
				            
				            // Generate assembly
				            if (currentFunction.empty()) {
				                // Global variable
				                emitCode("GLOBAL_VAR:" + varName + " DW 1 DUP (0000H)");
				                if (varSize > 2) {
				                    emitCode("GLOBAL_VAR:    DW " + std::to_string(varSize/2 - 1) + " DUP(0000H)");
				                }
				            } else {
				                // Local variable
				                currentOffset += varSize;
				                localVarOffset[varName] = currentOffset;
				                emitCode("SUB SP, " + std::to_string(varSize));
				            }
				        }

				        ((Var_declarationContext)_localctx).var_decl =  ((Var_declarationContext)_localctx).t.name_line + " " + ((Var_declarationContext)_localctx).dl.var_list.get_list_as_string() + ";";
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Var_declarationContext)_localctx).sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.var_decl + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(166);
				((Var_declarationContext)_localctx).t = type_specifier();
				setState(167);
				((Var_declarationContext)_localctx).de = declaration_list_err();
				setState(168);
				((Var_declarationContext)_localctx).sm = match(SEMICOLON);

				        syntaxErrorCount++;
				      
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_list_errContext extends ParserRuleContext {
		public std::string error_name;
		public Declaration_list_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list_err; }
	}

	public final Declaration_list_errContext declaration_list_err() throws RecognitionException {
		Declaration_list_errContext _localctx = new Declaration_list_errContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_declaration_list_err);
		try {
			enterOuterAlt(_localctx, 1);
			{

			        ((Declaration_list_errContext)_localctx).error_name =  "Error in declaration list";
			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_specifierContext extends ParserRuleContext {
		public std::string name_line;
		public Token INT;
		public Token FLOAT;
		public Token VOID;
		public TerminalNode INT() { return getToken(C8086Parser.INT, 0); }
		public TerminalNode FLOAT() { return getToken(C8086Parser.FLOAT, 0); }
		public TerminalNode VOID() { return getToken(C8086Parser.VOID, 0); }
		public Type_specifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_specifier; }
	}

	public final Type_specifierContext type_specifier() throws RecognitionException {
		Type_specifierContext _localctx = new Type_specifierContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_type_specifier);
		try {
			setState(181);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INT:
				enterOuterAlt(_localctx, 1);
				{
				setState(175);
				((Type_specifierContext)_localctx).INT = match(INT);

				        ((Type_specifierContext)_localctx).name_line =  ((Type_specifierContext)_localctx).INT->getText();
				        writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).INT->getLine()) + ": type_specifier : INT\n");
				        writeIntoparserLogFile(_localctx.name_line + "\n");
				    
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(177);
				((Type_specifierContext)_localctx).FLOAT = match(FLOAT);

				        ((Type_specifierContext)_localctx).name_line =  ((Type_specifierContext)_localctx).FLOAT->getText();
				        writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).FLOAT->getLine()) + ": type_specifier : FLOAT\n");
				        writeIntoparserLogFile(_localctx.name_line + "\n");
				    
				}
				break;
			case VOID:
				enterOuterAlt(_localctx, 3);
				{
				setState(179);
				((Type_specifierContext)_localctx).VOID = match(VOID);

				        ((Type_specifierContext)_localctx).name_line =  ((Type_specifierContext)_localctx).VOID->getText();
				        writeIntoparserLogFile("Line " + std::to_string(((Type_specifierContext)_localctx).VOID->getLine()) + ": type_specifier : VOID\n");
				        writeIntoparserLogFile(_localctx.name_line + "\n");
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Declaration_listContext extends ParserRuleContext {
		public str_list var_list;
		public Declaration_listContext dl;
		public Token ID;
		public Token CONST_INT;
		public Token ADDOP;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C8086Parser.LTHIRD, 0); }
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode RTHIRD() { return getToken(C8086Parser.RTHIRD, 0); }
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public Declaration_listContext declaration_list() {
			return getRuleContext(Declaration_listContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public Declaration_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration_list; }
	}

	public final Declaration_listContext declaration_list() throws RecognitionException {
		return declaration_list(0);
	}

	private Declaration_listContext declaration_list(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Declaration_listContext _localctx = new Declaration_listContext(_ctx, _parentState);
		Declaration_listContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_declaration_list, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(191);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				{
				setState(184);
				((Declaration_listContext)_localctx).ID = match(ID);

				        _localctx.var_list.add(((Declaration_listContext)_localctx).ID->getText());
				        writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : ID\n");
				        writeIntoparserLogFile(((Declaration_listContext)_localctx).ID->getText() + "\n");
				    
				}
				break;
			case 2:
				{
				setState(186);
				((Declaration_listContext)_localctx).ID = match(ID);
				setState(187);
				match(LTHIRD);
				setState(188);
				((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
				setState(189);
				match(RTHIRD);

				        _localctx.var_list.add(((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]");
				        writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
				        writeIntoparserLogFile(((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]\n");
				    
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(210);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(208);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
					case 1:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(193);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(194);
						match(COMMA);
						setState(195);
						((Declaration_listContext)_localctx).ID = match(ID);

						                  ((Declaration_listContext)_localctx).var_list =  ((Declaration_listContext)_localctx).dl.var_list;
						                  _localctx.var_list.add(((Declaration_listContext)_localctx).ID->getText());
						                  writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : declaration_list COMMA ID\n");
						                  writeIntoparserLogFile(_localctx.var_list.get_list_as_string() + "\n");
						              
						}
						break;
					case 2:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(197);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(198);
						match(COMMA);
						setState(199);
						((Declaration_listContext)_localctx).ID = match(ID);
						setState(200);
						match(LTHIRD);
						setState(201);
						((Declaration_listContext)_localctx).CONST_INT = match(CONST_INT);
						setState(202);
						match(RTHIRD);

						                  ((Declaration_listContext)_localctx).var_list =  ((Declaration_listContext)_localctx).dl.var_list;
						                  _localctx.var_list.add(((Declaration_listContext)_localctx).ID->getText() + "[" + ((Declaration_listContext)_localctx).CONST_INT->getText() + "]");
						                  writeIntoparserLogFile("Line " + std::to_string(((Declaration_listContext)_localctx).ID->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
						                  writeIntoparserLogFile(_localctx.var_list.get_list_as_string() + "\n");
						              
						}
						break;
					case 3:
						{
						_localctx = new Declaration_listContext(_parentctx, _parentState);
						_localctx.dl = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_declaration_list);
						setState(204);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(205);
						((Declaration_listContext)_localctx).ADDOP = match(ADDOP);
						setState(206);
						((Declaration_listContext)_localctx).ID = match(ID);

						                  ((Declaration_listContext)_localctx).var_list =  ((Declaration_listContext)_localctx).dl.var_list;
						                  syntaxErrorCount++;
						                  writeIntoErrorFile("Error at line " + std::to_string(((Declaration_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
						                  writeIntoparserLogFile("Error at line " + std::to_string(((Declaration_listContext)_localctx).ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
						              
						}
						break;
					}
					} 
				}
				setState(212);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public std::string stmt_list;
		public StatementsContext st;
		public StatementContext s;
		public Token INVALID_CHAR;
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public Simple_expression_errContext simple_expression_err() {
			return getRuleContext(Simple_expression_errContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode INVALID_CHAR() { return getToken(C8086Parser.INVALID_CHAR, 0); }
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		return statements(0);
	}

	private StatementsContext statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StatementsContext _localctx = new StatementsContext(_ctx, _parentState);
		StatementsContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(214);
			((StatementsContext)_localctx).s = statement();

			        ((StatementsContext)_localctx).stmt_list =  ((StatementsContext)_localctx).s.stmt_val;
			        writeIntoparserLogFile("Line " + std::to_string((((StatementsContext)_localctx).s!=null?(((StatementsContext)_localctx).s.start):null)->getLine()) + ": statements : statement\n");
			        writeIntoparserLogFile(_localctx.stmt_list + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(234);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(232);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
					case 1:
						{
						_localctx = new StatementsContext(_parentctx, _parentState);
						_localctx.st = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_statements);
						setState(217);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(218);
						((StatementsContext)_localctx).s = statement();

						                  ((StatementsContext)_localctx).stmt_list =  ((StatementsContext)_localctx).st.stmt_list.substr(0, ((StatementsContext)_localctx).st.stmt_list.length()) + ((StatementsContext)_localctx).s.stmt_val;
						                  writeIntoparserLogFile("Line " + std::to_string((((StatementsContext)_localctx).s!=null?(((StatementsContext)_localctx).s.stop):null)->getLine()) + ": statements : statements statement\n");
						                  writeIntoparserLogFile(_localctx.stmt_list + "\n");
						              
						}
						break;
					case 2:
						{
						_localctx = new StatementsContext(_parentctx, _parentState);
						_localctx.st = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_statements);
						setState(221);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(222);
						variable();
						setState(223);
						match(ASSIGNOP);
						setState(224);
						simple_expression_err();

						                  ((StatementsContext)_localctx).stmt_list =  ((StatementsContext)_localctx).st.stmt_list.substr(0, ((StatementsContext)_localctx).st.stmt_list.length());
						              
						}
						break;
					case 3:
						{
						_localctx = new StatementsContext(_parentctx, _parentState);
						_localctx.st = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_statements);
						setState(227);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(228);
						expression();
						setState(229);
						((StatementsContext)_localctx).INVALID_CHAR = match(INVALID_CHAR);

						                  ((StatementsContext)_localctx).stmt_list =  ((StatementsContext)_localctx).st.stmt_list.substr(0, ((StatementsContext)_localctx).st.stmt_list.length());
						                  syntaxErrorCount++;
						                  writeIntoErrorFile("Error at line " + std::to_string(((StatementsContext)_localctx).INVALID_CHAR->getLine()) + ": Unrecognized character " + ((StatementsContext)_localctx).INVALID_CHAR->getText() + "\n");
						                  writeIntoparserLogFile("Error at line " + std::to_string(((StatementsContext)_localctx).INVALID_CHAR->getLine()) + ": Unrecognized character " + ((StatementsContext)_localctx).INVALID_CHAR->getText() + "\n");                            
						              
						}
						break;
					}
					} 
				}
				setState(236);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementContext extends ParserRuleContext {
		public std::string stmt_val;
		public Var_declarationContext vd;
		public Expression_statementContext es;
		public Compound_statementContext c;
		public Expression_statementContext es1;
		public Expression_statementContext es2;
		public ExpressionContext e;
		public StatementContext s;
		public StatementContext s1;
		public StatementContext s2;
		public Token ID;
		public Case_statementsContext cases;
		public Var_declarationContext var_declaration() {
			return getRuleContext(Var_declarationContext.class,0);
		}
		public List<Expression_statementContext> expression_statement() {
			return getRuleContexts(Expression_statementContext.class);
		}
		public Expression_statementContext expression_statement(int i) {
			return getRuleContext(Expression_statementContext.class,i);
		}
		public Compound_statementContext compound_statement() {
			return getRuleContext(Compound_statementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(C8086Parser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode IF() { return getToken(C8086Parser.IF, 0); }
		public TerminalNode ELSE() { return getToken(C8086Parser.ELSE, 0); }
		public TerminalNode WHILE() { return getToken(C8086Parser.WHILE, 0); }
		public TerminalNode PRINTLN() { return getToken(C8086Parser.PRINTLN, 0); }
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public TerminalNode RETURN() { return getToken(C8086Parser.RETURN, 0); }
		public TerminalNode SWITCH() { return getToken(C8086Parser.SWITCH, 0); }
		public TerminalNode LCURL() { return getToken(C8086Parser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(C8086Parser.RCURL, 0); }
		public Case_statementsContext case_statements() {
			return getRuleContext(Case_statementsContext.class,0);
		}
		public TerminalNode COLON() { return getToken(C8086Parser.COLON, 0); }
		public TerminalNode GOTO() { return getToken(C8086Parser.GOTO, 0); }
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_statement);
		try {
			setState(317);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(237);
				((StatementContext)_localctx).vd = var_declaration();

				        ((StatementContext)_localctx).stmt_val =  ((StatementContext)_localctx).vd.var_decl + "\n";
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).vd!=null?(((StatementContext)_localctx).vd.start):null)->getLine()) + ": statement : var_declaration\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(240);
				((StatementContext)_localctx).es = expression_statement();

				        ((StatementContext)_localctx).stmt_val =  ((StatementContext)_localctx).es.expr_stmt + "\n";
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).es!=null?(((StatementContext)_localctx).es.start):null)->getLine()) + ": statement : expression_statement\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(243);
				((StatementContext)_localctx).c = compound_statement();

				        ((StatementContext)_localctx).stmt_val =  ((StatementContext)_localctx).c.comp_stmt + "\n";
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).c!=null?(((StatementContext)_localctx).c.stop):null)->getLine()) + ": statement : compound_statement\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(246);
				match(FOR);
				setState(247);
				match(LPAREN);
				setState(248);
				((StatementContext)_localctx).es1 = expression_statement();

				        // FOR loop structure: for(init; condition; increment)
				        // Save current loop labels for nested loops
				        std::string savedLoopBodyLabel = currentLoopBodyLabel;
				        std::string savedContinueLabel = currentContinueLabel;
				        std::string savedLoopExitLabel = currentLoopExitLabel;
				        
				        currentLoopBodyLabel = newLabel();
				        currentContinueLabel = newLabel();
				        currentLoopExitLabel = newLabel();
				        
				        // The initialization (es1) is already processed above
				        // Jump to condition check first
				        emitCode("JMP " + currentContinueLabel);
				        
				        // Loop body label
				        emitCode(currentLoopBodyLabel + ":");
				        symb.enterScope();
				        
				        // Set flags BEFORE parsing condition to suppress code generation
				        inForCondition = true;
				        inForIncrement = true;
				    
				setState(250);
				((StatementContext)_localctx).es2 = expression_statement();

				        // Store the condition for manual processing later
				        // Flags are already set above
				    
				setState(252);
				((StatementContext)_localctx).e = expression();
				setState(253);
				match(RPAREN);

				        // Reset flags after processing increment expression
				        inForCondition = false;
				        inForIncrement = false;
				    
				setState(255);
				((StatementContext)_localctx).s = statement();

				        symb.exitScope();
				        
				        // After loop body, manually generate the increment operation
				        // Parse the increment expression to get the variable name
				        std::string incrementExpr = ((StatementContext)_localctx).e.expr_val;
				        std::string varName = incrementExpr.substr(0, incrementExpr.find_first_of("+-"));
				        
				        if (incrementExpr.find("++") != std::string::npos) {
				            emitCode("MOV AX, " + getVarOffset(varName) + "");
				            emitCode("INC AX");
				            emitCode("MOV " + getVarOffset(varName) + ", AX");
				        } else if (incrementExpr.find("--") != std::string::npos) {
				            emitCode("MOV AX, " + getVarOffset(varName) + "");
				            emitCode("DEC AX");
				            emitCode("MOV " + getVarOffset(varName) + ", AX");
				        }
				        
				        // Condition check label - this is where we jump from the start and after each iteration
				        emitCode(currentContinueLabel + ":");
				        
				        // Parse and generate the condition check dynamically
				        std::string conditionExpr = ((StatementContext)_localctx).es2.expr_stmt;
				        size_t pos = conditionExpr.find(';');
				        if (pos != std::string::npos) {
				            conditionExpr = conditionExpr.substr(0, pos);
				        }
				        conditionExpr.erase(0, conditionExpr.find_first_not_of(" \t"));
				        conditionExpr.erase(conditionExpr.find_last_not_of(" \t") + 1);
				        
				        // Parse condition: variable < value or variable > value, etc.
				        std::string leftVar, rightValue, op;
				        if (conditionExpr.find("<=") != std::string::npos) {
				            size_t opPos = conditionExpr.find("<=");
				            leftVar = conditionExpr.substr(0, opPos);
				            rightValue = conditionExpr.substr(opPos + 2);
				            op = "<=";
				        } else if (conditionExpr.find(">=") != std::string::npos) {
				            size_t opPos = conditionExpr.find(">=");
				            leftVar = conditionExpr.substr(0, opPos);
				            rightValue = conditionExpr.substr(opPos + 2);
				            op = ">=";
				        } else if (conditionExpr.find("<") != std::string::npos) {
				            size_t opPos = conditionExpr.find("<");
				            leftVar = conditionExpr.substr(0, opPos);
				            rightValue = conditionExpr.substr(opPos + 1);
				            op = "<";
				        } else if (conditionExpr.find(">") != std::string::npos) {
				            size_t opPos = conditionExpr.find(">");
				            leftVar = conditionExpr.substr(0, opPos);
				            rightValue = conditionExpr.substr(opPos + 1);
				            op = ">";
				        }
				        
				        // Trim whitespace
				        leftVar.erase(0, leftVar.find_first_not_of(" \t"));
				        leftVar.erase(leftVar.find_last_not_of(" \t") + 1);
				        rightValue.erase(0, rightValue.find_first_not_of(" \t"));
				        rightValue.erase(rightValue.find_last_not_of(" \t") + 1);
				        
				        // Generate the condition check
				        emitCode("MOV AX, " + getVarOffset(leftVar) + "");
				        emitCode("CMP AX, " + rightValue);
				        
				        if (op == "<") {
				            emitCode("JL " + currentLoopBodyLabel);
				        } else if (op == ">") {
				            emitCode("JG " + currentLoopBodyLabel);
				        } else if (op == "<=") {
				            emitCode("JLE " + currentLoopBodyLabel);
				        } else if (op == ">=") {
				            emitCode("JGE " + currentLoopBodyLabel);
				        }
				        
				        // Jump to exit if condition fails
				        emitCode("JMP " + currentLoopExitLabel);
				        
				        // Exit label
				        emitCode(currentLoopExitLabel + ":");
				        
				        // Restore previous loop labels
				        currentLoopBodyLabel = savedLoopBodyLabel;
				        currentContinueLabel = savedContinueLabel;
				        currentLoopExitLabel = savedLoopExitLabel;
				        
				        ((StatementContext)_localctx).stmt_val =  "for(" + ((StatementContext)_localctx).es1.expr_stmt + ((StatementContext)_localctx).es2.expr_stmt + ((StatementContext)_localctx).e.expr_val + ")" + ((StatementContext)_localctx).s.stmt_val;
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).s!=null?(((StatementContext)_localctx).s.stop):null)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(258);
				match(IF);
				setState(259);
				match(LPAREN);

				        // Save current IF labels for nested IF handling
				        std::string savedIfFalseLabel = currentIfFalseLabel;
				        std::string savedIfEndLabel = currentIfEndLabel;
				        
				        // Set context for IF condition and generate false label
				        inIfCondition = true;
				        currentIfFalseLabel = newLabel();
				        
				        // Store saved labels for restoration later
				        if (!savedIfFalseLabel.empty()) {
				            ifEndLabelStack.push_back(savedIfFalseLabel);
				        }
				        if (!savedIfEndLabel.empty()) {
				            ifEndLabelStack.push_back(savedIfEndLabel);
				        }
				    
				setState(261);
				((StatementContext)_localctx).e = expression();
				setState(262);
				match(RPAREN);

				        symb.enterScope();
				        inIfCondition = false;  // Reset context after expression
				    
				setState(264);
				((StatementContext)_localctx).s = statement();

				        ((StatementContext)_localctx).stmt_val =  "if(" + ((StatementContext)_localctx).e.expr_val + ")" + ((StatementContext)_localctx).s.stmt_val;
				        
				        // Place the false label after the IF block
				        emitCode(currentIfFalseLabel + ":");
				        
				        // Restore previous IF labels for nested structure
				        if (ifEndLabelStack.size() >= 2) {
				            currentIfEndLabel = ifEndLabelStack.back();
				            ifEndLabelStack.pop_back();
				            currentIfFalseLabel = ifEndLabelStack.back();
				            ifEndLabelStack.pop_back();
				        } else if (ifEndLabelStack.size() == 1) {
				            currentIfFalseLabel = ifEndLabelStack.back();
				            ifEndLabelStack.pop_back();
				            currentIfEndLabel = "";
				        } else {
				            currentIfFalseLabel = "";
				            currentIfEndLabel = "";
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).s!=null?(((StatementContext)_localctx).s.stop):null)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				        
				        symb.exitScope();
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(267);
				match(IF);
				setState(268);
				match(LPAREN);

				        // Save current IF labels for nested IF handling
				        std::string savedIfFalseLabel = currentIfFalseLabel;
				        std::string savedIfEndLabel = currentIfEndLabel;
				        
				        // Set context for IF condition and generate labels
				        inIfCondition = true;
				        currentIfFalseLabel = newLabel();
				        currentIfEndLabel = newLabel();
				        
				        // Store saved labels for restoration later
				        if (!savedIfFalseLabel.empty()) {
				            ifEndLabelStack.push_back(savedIfFalseLabel);
				        }
				        if (!savedIfEndLabel.empty()) {
				            ifEndLabelStack.push_back(savedIfEndLabel);
				        }
				    
				setState(270);
				((StatementContext)_localctx).e = expression();
				setState(271);
				match(RPAREN);

				        symb.enterScope();
				        inIfCondition = false;  // Reset context after expression
				    
				setState(273);
				((StatementContext)_localctx).s1 = statement();

				        symb.exitScope();
				        
				        // Jump to end after true block
				        emitCode("JMP " + currentIfEndLabel);
				        
				        // Place false label for else block
				        emitCode(currentIfFalseLabel + ":");
				    
				setState(275);
				match(ELSE);

				        symb.enterScope();  
				    
				setState(277);
				((StatementContext)_localctx).s2 = statement();

				        ((StatementContext)_localctx).stmt_val =  "if(" + ((StatementContext)_localctx).e.expr_val + ")" + ((StatementContext)_localctx).s1.stmt_val + "else " + ((StatementContext)_localctx).s2.stmt_val;
				        
				        // Place end label after else block
				        emitCode(currentIfEndLabel + ":");
				        
				        // Restore previous IF labels for nested structure
				        if (ifEndLabelStack.size() >= 2) {
				            currentIfEndLabel = ifEndLabelStack.back();
				            ifEndLabelStack.pop_back();
				            currentIfFalseLabel = ifEndLabelStack.back();
				            ifEndLabelStack.pop_back();
				        } else if (ifEndLabelStack.size() == 1) {
				            currentIfFalseLabel = ifEndLabelStack.back();
				            ifEndLabelStack.pop_back();
				            currentIfEndLabel = "";
				        } else {
				            currentIfFalseLabel = "";
				            currentIfEndLabel = "";
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).s2!=null?(((StatementContext)_localctx).s2.stop):null)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				        
				        symb.exitScope();
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(280);
				match(WHILE);
				setState(281);
				match(LPAREN);

				        // Save current loop labels for nested loops
				        std::string savedLoopBodyLabel = currentLoopBodyLabel;
				        std::string savedContinueLabel = currentContinueLabel;
				        std::string savedLoopExitLabel = currentLoopExitLabel;
				        
				        // Generate WHILE loop labels in the correct order
				        std::string conditionLabel = newLabel();  // Condition check label
				        std::string bodyLabel = newLabel();       // Loop body label
				        std::string exitLabel = newLabel();       // Exit label
				        
				        // Start with condition check
				        emitCode(conditionLabel + ":");
				        
				        // Set context for WHILE loop condition
				        inLoopCondition = true;
				        currentLoopBodyLabel = bodyLabel;
				        currentLoopExitLabel = exitLabel;
				    
				setState(283);
				((StatementContext)_localctx).e = expression();
				setState(284);
				match(RPAREN);

				        inLoopCondition = false;  // Reset context after condition
				        
				        // Body label comes before the statement
				        emitCode(bodyLabel + ":");
				        
				        symb.enterScope();  
				    
				setState(286);
				((StatementContext)_localctx).s = statement();

				        // After body execution, jump back to condition check
				        emitCode("JMP " + conditionLabel);
				        
				        // Place exit label
				        emitCode(exitLabel + ":");
				        
				        // Restore previous loop labels
				        currentLoopBodyLabel = savedLoopBodyLabel;
				        currentContinueLabel = savedContinueLabel;
				        currentLoopExitLabel = savedLoopExitLabel;
				        
				        ((StatementContext)_localctx).stmt_val =  "while(" + ((StatementContext)_localctx).e.expr_val + ")" + ((StatementContext)_localctx).s.stmt_val;
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).s!=null?(((StatementContext)_localctx).s.stop):null)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				        
				        symb.exitScope();
				    
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(289);
				match(PRINTLN);
				setState(290);
				match(LPAREN);
				setState(291);
				((StatementContext)_localctx).ID = match(ID);
				setState(292);
				match(RPAREN);
				setState(293);
				match(SEMICOLON);

				        ((StatementContext)_localctx).stmt_val =  "println(" + ((StatementContext)_localctx).ID->getText() + ");\n";

				        // Generate proper assembly for variable access
				        std::string varName = ((StatementContext)_localctx).ID->getText();
				        if (currentFunction.empty()) {
				            emitCode("MOV AX, " + varName + "       ; Line " + std::to_string(((StatementContext)_localctx).ID->getLine()));
				        } else {
				            if (localVarOffset.find(varName) != localVarOffset.end()) {
				                emitCode("MOV AX, " + getVarOffset(varName) + "       ; Line " + std::to_string(((StatementContext)_localctx).ID->getLine()));
				            } else {
				                emitCode("MOV AX, " + varName + "       ; Line " + std::to_string(((StatementContext)_localctx).ID->getLine()));
				            }
				        }
				        
				        emitCode("CALL print_output");
				        emitCode("CALL new_line");

				        InsertResult result = symb.lookupWithPosition(((StatementContext)_localctx).ID->getText());
				        if(!result.found) {
				            writeIntoErrorFile("Error at line " + std::to_string(((StatementContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(((StatementContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((StatementContext)_localctx).ID->getText() + "\n");
				            syntaxErrorCount++;
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).ID->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				    
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(295);
				match(RETURN);
				setState(296);
				((StatementContext)_localctx).e = expression();
				setState(297);
				match(SEMICOLON);

				        ((StatementContext)_localctx).stmt_val =  "return " + ((StatementContext)_localctx).e.expr_val + ";\n";
				        hasReturnStatement = true;  // Mark that this function has a return statement
				        
				        // Handle the return expression evaluation first
				        std::string exprStr = ((StatementContext)_localctx).e.expr_val;
				        bool isSimpleConstant = (exprStr.find_first_not_of("0123456789") == std::string::npos);
				        bool isSimpleVar = (exprStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
				        
				        // Load return value into AX
				        if (isSimpleConstant) {
				            emitCode("MOV AX, " + exprStr);
				        } else if (isSimpleVar) {
				            // For simple variables, load directly since factor rule no longer pushes
				            if (currentFunction.empty() || localVarOffset.find(exprStr) == localVarOffset.end()) {
				                emitCode("MOV AX, " + exprStr);
				            } else {
				                int offset = localVarOffset[exprStr];
				                if (offset < 0) {
				                    emitCode("MOV AX, [BP+" + std::to_string(-offset) + "]");
				                } else {
				                    emitCode("MOV AX, [BP-" + std::to_string(offset) + "]");
				                }
				            }
				        } else {
				            // Complex expression - check if result is already in AX or needs to be popped
				            // For simple additions like "a+1", the result is already in AX from optimized operations
				            // Only pop if we're dealing with truly complex expressions that use the stack
				            bool needsPop = (exprStr.find("*") != std::string::npos) ||
				                           (exprStr.find("/") != std::string::npos) ||
				                           (exprStr.find("%") != std::string::npos) ||
				                           (exprStr.find("+") != std::string::npos) ||
				                           (exprStr.find("-") != std::string::npos) ||
				                           (exprStr.find("&&") != std::string::npos) ||
				                           (exprStr.find("||") != std::string::npos) ||
				                           (exprStr.find("(") != std::string::npos);
				            
				            if (needsPop) {
				                emitCode("POP AX");
				            }
				            // For simple arithmetic like "a+1", "a-1", etc., the result is already in AX
				        }
				        
				        // Function epilogue
				        if (!currentFunction.empty()) {
				            if (currentFunction == "main") {
				                // Main function termination
				                emitCode("ADD SP, " + std::to_string(currentOffset));
				                emitCode("POP BP");
				                emitCode("MOV AX,4CH");
				                emitCode("INT 21H");
				            } else {
				                // Regular function epilogue
				                // Local variables cleanup
				                if (currentOffset > 0) {
				                    emitCode("ADD SP, " + std::to_string(currentOffset));
				                }
				                emitCode("POP BP");
				                
				                // Return and clean up parameters
				                int paramCount = currentFunctionParams.size();
				                if (paramCount > 0) {
				                    emitCode("RET " + std::to_string(paramCount * 2));
				                } else {
				                    emitCode("RET");
				                }
				            }
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).e!=null?(((StatementContext)_localctx).e.stop):null)->getLine()) + ": statement : RETURN expression SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				    
				}
				break;
			case 10:
				enterOuterAlt(_localctx, 10);
				{
				setState(300);
				match(SWITCH);
				setState(301);
				match(LPAREN);
				setState(302);
				((StatementContext)_localctx).e = expression();
				setState(303);
				match(RPAREN);

				        symb.enterScope();
				    
				setState(305);
				match(LCURL);
				setState(306);
				((StatementContext)_localctx).cases = case_statements(0);
				setState(307);
				match(RCURL);

				        ((StatementContext)_localctx).stmt_val =  "switch(" + ((StatementContext)_localctx).e.expr_val + "){\n" + ((StatementContext)_localctx).cases.case_stmts + "}\n";
				        
				        writeIntoparserLogFile("Line " + std::to_string((((StatementContext)_localctx).cases!=null?(((StatementContext)_localctx).cases.stop):null)->getLine()) + ": statement : SWITCH LPAREN expression RPAREN LCURL case_statements RCURL\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				        
				        symb.exitScope();
				    
				}
				break;
			case 11:
				enterOuterAlt(_localctx, 11);
				{
				setState(310);
				((StatementContext)_localctx).ID = match(ID);
				setState(311);
				match(COLON);

				        ((StatementContext)_localctx).stmt_val =  ((StatementContext)_localctx).ID->getText() + ":\n";
				        calledLabel = true;
				        
				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).ID->getLine()) + ": statement : ID COLON\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				    
				}
				break;
			case 12:
				enterOuterAlt(_localctx, 12);
				{
				setState(313);
				match(GOTO);
				setState(314);
				((StatementContext)_localctx).ID = match(ID);
				setState(315);
				match(SEMICOLON);

				        if(calledLabel == true){
				            ((StatementContext)_localctx).stmt_val =  "goto " + ((StatementContext)_localctx).ID->getText() + ";\n";
				            calledLabel = false;
				        }
				        else{
				            syntaxErrorCount++;
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((StatementContext)_localctx).ID->getLine()) + ": statement : GOTO ID SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.stmt_val + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Case_statementsContext extends ParserRuleContext {
		public std::string case_stmts;
		public Case_statementsContext cs;
		public Case_statementContext c;
		public Case_statementContext case_statement() {
			return getRuleContext(Case_statementContext.class,0);
		}
		public Case_statementsContext case_statements() {
			return getRuleContext(Case_statementsContext.class,0);
		}
		public Case_statementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_statements; }
	}

	public final Case_statementsContext case_statements() throws RecognitionException {
		return case_statements(0);
	}

	private Case_statementsContext case_statements(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Case_statementsContext _localctx = new Case_statementsContext(_ctx, _parentState);
		Case_statementsContext _prevctx = _localctx;
		int _startState = 26;
		enterRecursionRule(_localctx, 26, RULE_case_statements, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(320);
			((Case_statementsContext)_localctx).c = case_statement();

			        ((Case_statementsContext)_localctx).case_stmts =  ((Case_statementsContext)_localctx).c.case_stmt;
			        
			        writeIntoparserLogFile("Line " + std::to_string((((Case_statementsContext)_localctx).c!=null?(((Case_statementsContext)_localctx).c.start):null)->getLine()) + ": case_statements : case_statement\n");
			        writeIntoparserLogFile(_localctx.case_stmts + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(329);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Case_statementsContext(_parentctx, _parentState);
					_localctx.cs = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_case_statements);
					setState(323);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(324);
					((Case_statementsContext)_localctx).c = case_statement();

					                  ((Case_statementsContext)_localctx).case_stmts =  ((Case_statementsContext)_localctx).cs.case_stmts + ((Case_statementsContext)_localctx).c.case_stmt;
					                  
					                  writeIntoparserLogFile("Line " + std::to_string((((Case_statementsContext)_localctx).c!=null?(((Case_statementsContext)_localctx).c.stop):null)->getLine()) + ": case_statements : case_statements case_statement\n");
					                  writeIntoparserLogFile(_localctx.case_stmts + "\n");
					              
					}
					} 
				}
				setState(331);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Case_statementContext extends ParserRuleContext {
		public std::string case_stmt;
		public Token CONST_INT;
		public StatementsContext s;
		public Token SEMICOLON;
		public TerminalNode CASE() { return getToken(C8086Parser.CASE, 0); }
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode COLON() { return getToken(C8086Parser.COLON, 0); }
		public TerminalNode BREAK() { return getToken(C8086Parser.BREAK, 0); }
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public TerminalNode DEFAULT() { return getToken(C8086Parser.DEFAULT, 0); }
		public Case_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_case_statement; }
	}

	public final Case_statementContext case_statement() throws RecognitionException {
		Case_statementContext _localctx = new Case_statementContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_case_statement);
		try {
			setState(347);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CASE:
				enterOuterAlt(_localctx, 1);
				{
				setState(332);
				match(CASE);
				setState(333);
				((Case_statementContext)_localctx).CONST_INT = match(CONST_INT);
				setState(334);
				match(COLON);
				setState(335);
				((Case_statementContext)_localctx).s = statements(0);
				setState(336);
				match(BREAK);
				setState(337);
				((Case_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Case_statementContext)_localctx).case_stmt =  "case " + ((Case_statementContext)_localctx).CONST_INT->getText() + ":\n" + ((Case_statementContext)_localctx).s.stmt_list + "break;\n";
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Case_statementContext)_localctx).SEMICOLON->getLine()) + ": case_statement : CASE CONST_INT COLON statements BREAK SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.case_stmt + "\n");
				    
				}
				break;
			case DEFAULT:
				enterOuterAlt(_localctx, 2);
				{
				setState(340);
				match(DEFAULT);
				setState(341);
				match(COLON);
				setState(342);
				((Case_statementContext)_localctx).s = statements(0);
				setState(343);
				match(BREAK);
				setState(344);
				((Case_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Case_statementContext)_localctx).case_stmt =  "default:\n" + ((Case_statementContext)_localctx).s.stmt_list + "break;\n";
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Case_statementContext)_localctx).SEMICOLON->getLine()) + ": case_statement : DEFAULT COLON statements BREAK SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.case_stmt + "\n");
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expression_statementContext extends ParserRuleContext {
		public std::string expr_stmt;
		public Token SEMICOLON;
		public ExpressionContext e;
		public TerminalNode SEMICOLON() { return getToken(C8086Parser.SEMICOLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Expression_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression_statement; }
	}

	public final Expression_statementContext expression_statement() throws RecognitionException {
		Expression_statementContext _localctx = new Expression_statementContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_expression_statement);
		try {
			setState(355);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SEMICOLON:
				enterOuterAlt(_localctx, 1);
				{
				setState(349);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).expr_stmt =  ";\n";
				        writeIntoparserLogFile("Line " + std::to_string(((Expression_statementContext)_localctx).SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.expr_stmt + "\n");
				    
				}
				break;
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 2);
				{
				setState(351);
				((Expression_statementContext)_localctx).e = expression();
				setState(352);
				((Expression_statementContext)_localctx).SEMICOLON = match(SEMICOLON);

				        ((Expression_statementContext)_localctx).expr_stmt =  ((Expression_statementContext)_localctx).e.expr_val + ";\n";
				        writeIntoparserLogFile("Line " + std::to_string(((Expression_statementContext)_localctx).SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n");
				        writeIntoparserLogFile(_localctx.expr_stmt + "\n");
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public std::string var_name;
		public Token ID;
		public ExpressionContext e;
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LTHIRD() { return getToken(C8086Parser.LTHIRD, 0); }
		public TerminalNode RTHIRD() { return getToken(C8086Parser.RTHIRD, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_variable);
		try {
			setState(365);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(357);
				((VariableContext)_localctx).ID = match(ID);

				        ((VariableContext)_localctx).var_name =  ((VariableContext)_localctx).ID->getText();

				        InsertResult result = symb.lookupWithPosition(((VariableContext)_localctx).ID->getText());
				        SymbolInfo* varInfo = symb.getCurrentScope()->lookUp(parserLogFile, ((VariableContext)_localctx).ID->getText());

				        if(!result.found){
				            writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).ID->getText() + "\n");
				            syntaxErrorCount++;            
				        }

				        if(varInfo != nullptr){
				            if(varInfo->getType() == "ARRAY" && _localctx->parent->getText().find("[") == std::string::npos){
				                writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Type mismatch, " + ((VariableContext)_localctx).ID->getText() + " is an array\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Type mismatch, " + ((VariableContext)_localctx).ID->getText() + " is an array\n");
				                syntaxErrorCount++;            
				            }
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID\n");
				        writeIntoparserLogFile(_localctx.var_name + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(359);
				((VariableContext)_localctx).ID = match(ID);
				setState(360);
				match(LTHIRD);
				setState(361);
				((VariableContext)_localctx).e = expression();
				setState(362);
				match(RTHIRD);

				        ((VariableContext)_localctx).var_name =  ((VariableContext)_localctx).ID->getText() + "[" + ((VariableContext)_localctx).e.expr_val + "]";

				        InsertResult result = symb.lookupWithPosition(((VariableContext)_localctx).ID->getText());
				        if(!result.found) {
				            writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Undeclared variable " + ((VariableContext)_localctx).ID->getText() + "\n");
				            syntaxErrorCount++;
				        }
				        else {
				            SymbolInfo* varInfo = symb.getCurrentScope()->lookUp(parserLogFile, ((VariableContext)_localctx).ID->getText());

				            if(varInfo != nullptr && varInfo->getType() != "ARRAY") {
				                writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": " + ((VariableContext)_localctx).ID->getText() + " not an array\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": " + ((VariableContext)_localctx).ID->getText() + " not an array\n");
				                syntaxErrorCount++;
				            }
				        }

				        if(((VariableContext)_localctx).e.expr_val.find(".") != std::string::npos){
				            writeIntoErrorFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Expression inside third brackets not an integer\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": Expression inside third brackets not an integer\n"); 
				            syntaxErrorCount++;          
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((VariableContext)_localctx).ID->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
				        writeIntoparserLogFile(_localctx.var_name + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public std::string expr_val;
		public Logic_expressionContext l;
		public VariableContext v;
		public Token ASSIGNOP;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_expression);
		try {
			setState(376);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(367);
				((ExpressionContext)_localctx).l = logic_expression();

				        ((ExpressionContext)_localctx).expr_val =  ((ExpressionContext)_localctx).l.logic_val;
				        writeIntoparserLogFile("Line " + std::to_string((((ExpressionContext)_localctx).l!=null?(((ExpressionContext)_localctx).l.start):null)->getLine()) + ": expression : logic_expression\n");
				        writeIntoparserLogFile(_localctx.expr_val + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(370);
				((ExpressionContext)_localctx).v = variable();
				setState(371);
				((ExpressionContext)_localctx).ASSIGNOP = match(ASSIGNOP);

				        inAssignmentContext = true;  // Set assignment context flag
				    
				setState(373);
				((ExpressionContext)_localctx).l = logic_expression();

				        inAssignmentContext = false;  
				        ((ExpressionContext)_localctx).expr_val =  ((ExpressionContext)_localctx).v.var_name + ((ExpressionContext)_localctx).ASSIGNOP->getText() + ((ExpressionContext)_localctx).l.logic_val;

				        std::string logicStr = ((ExpressionContext)_localctx).l.logic_val;
				        bool isSimpleConstant = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("0123456789") == std::string::npos);

				        bool isOptimizedLogicalExpr = (logicStr.find("||") != std::string::npos || logicStr.find("&&") != std::string::npos);

				        bool isOptimizedArithmeticExpr = false;
				        if (logicStr.find("+") != std::string::npos || logicStr.find("-") != std::string::npos) {
				            size_t opPos = logicStr.find_first_of("+-");
				            if (opPos != std::string::npos) {
				                std::string leftPart = logicStr.substr(0, opPos);
				                std::string rightPart = logicStr.substr(opPos + 1);

				                leftPart.erase(0, leftPart.find_first_not_of(" \t"));
				                leftPart.erase(leftPart.find_last_not_of(" \t") + 1);
				                rightPart.erase(0, rightPart.find_first_not_of(" \t"));
				                rightPart.erase(rightPart.find_last_not_of(" \t") + 1);
				                
				                bool isLeftVar = (leftPart.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
				                bool isRightConst = (rightPart.find_first_not_of("0123456789") == std::string::npos);
				                
				                isOptimizedArithmeticExpr = (isLeftVar && isRightConst);
				            }
				        }

				        bool isOptimizedUnaryExpr = (logicStr.find("-") == 0 && logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.substr(1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

				        bool isSimpleVariable = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find("[") == std::string::npos && logicStr.find("]") == std::string::npos && logicStr.find("&&") == std::string::npos && logicStr.find("||") == std::string::npos && logicStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

				        bool isSimpleArrayAccess = (logicStr.find("[") != std::string::npos && 
				                                   logicStr.find("]") != std::string::npos &&
				                                   logicStr.find("*") == std::string::npos && 
				                                   logicStr.find("+") == std::string::npos && 
				                                   logicStr.find("-") == std::string::npos &&
				                                   logicStr.find("/") == std::string::npos &&
				                                   logicStr.find("%") == std::string::npos &&
				                                   logicStr.find("(") == std::string::npos);
				        
				        if (isSimpleConstant) {
				            emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((((ExpressionContext)_localctx).l!=null?(((ExpressionContext)_localctx).l.start):null)->getLine()));
				        } else if (isSimpleVariable) {
				            if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
				                emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((((ExpressionContext)_localctx).l!=null?(((ExpressionContext)_localctx).l.start):null)->getLine()));
				            } else {
				                emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string((((ExpressionContext)_localctx).l!=null?(((ExpressionContext)_localctx).l.start):null)->getLine()));
				            }
				        } else if (isOptimizedLogicalExpr || isOptimizedArithmeticExpr) {

				        } else if (isOptimizedUnaryExpr) {

				        } else if (isSimpleArrayAccess) {

				        } else {
				            bool isSimpleArithmetic = false;
				            if (logicStr.find("+") != std::string::npos || logicStr.find("-") != std::string::npos) {
				                int opCount = 0;
				                for (char c : logicStr) {
				                    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
				                        opCount++;
				                    }
				                }
				                isSimpleArithmetic = (opCount == 1 && 
				                                     logicStr.find("(") == std::string::npos &&
				                                     logicStr.find("&&") == std::string::npos &&
				                                     logicStr.find("||") == std::string::npos);
				            }
				            
				            bool isModulusResult = (logicStr.find("%") != std::string::npos);
				            
				            if (isSimpleArithmetic || isModulusResult) {

				            } else {
				                emitCode("POP AX       ; Line " + std::to_string((((ExpressionContext)_localctx).l!=null?(((ExpressionContext)_localctx).l.start):null)->getLine()));
				            }
				        }
				        
				        std::string varName = ((ExpressionContext)_localctx).v.var_name;

				        size_t bracketPos = varName.find("[");
				        if (bracketPos != std::string::npos) {
				            std::string arrayName = varName.substr(0, bracketPos);
				            std::string indexStr = varName.substr(bracketPos + 1);
				            indexStr = indexStr.substr(0, indexStr.find("]"));

				            if (currentFunction.empty() || localVarOffset.find(arrayName) == localVarOffset.end()) {
				                if (indexStr.find_first_not_of("0123456789") == std::string::npos) {
				                    int index = std::stoi(indexStr);
				                    emitCode("MOV " + arrayName + "[" + std::to_string(index * 2) + "], AX");
				                } else {
				                    emitCode("MOV BX, " + indexStr);
				                    emitCode("SHL BX, 1");  // Multiply by 2 for word size
				                    emitCode("MOV " + arrayName + "[BX], AX");
				                }
				            } else {
				                int baseOffset = localVarOffset[arrayName];
				                if (indexStr.find_first_not_of("0123456789") == std::string::npos) {
				                    int index = std::stoi(indexStr);
				                    int actualOffset = baseOffset + (index * 2);
				                    emitCode("MOV [BP-" + std::to_string(actualOffset) + "], AX");
				                } else {              
				                    emitCode("MOV BX, " + indexStr);
				                    emitCode("SHL BX, 1");  
				                    emitCode("MOV CX, " + std::to_string(baseOffset));
				                    emitCode("ADD BX, CX");
				                    emitCode("NEG BX");
				                    emitCode("MOV [BP+BX], AX");
				                }
				            }
				        } else {
				            if (currentFunction.empty()) {
				                emitCode("MOV " + varName + ", AX");
				            } else {
				                if (localVarOffset.find(varName) != localVarOffset.end()) {
				                    int offset = localVarOffset[varName];
				                    if (offset < 0) {
				                        emitCode("MOV [BP+" + std::to_string(-offset) + "], AX");
				                    } else {
				                        emitCode("MOV [BP-" + std::to_string(offset) + "], AX");
				                    }
				                } else {
				                    emitCode("MOV " + varName + ", AX");
				                }
				            }
				        }

				        std::string varName2 = ((ExpressionContext)_localctx).v.var_name;
				        size_t bracketPos2 = varName2.find("[");

				        if(bracketPos2 != std::string::npos){
				            varName2 = varName2.substr(0, bracketPos2);
				        }

				        SymbolInfo* symbol = symb.getCurrentScope()->lookUp(parserLogFile, ((ExpressionContext)_localctx).v.var_name);

				        bool isModulusOp = ((ExpressionContext)_localctx).l.logic_val.find("%") != std::string::npos;
				        bool isFloatValue = ((ExpressionContext)_localctx).l.logic_val.find(".") != std::string::npos;

				        if(!isModulusOp) {
				            SymbolInfo* symbol = symb.getCurrentScope()->lookUp(parserLogFile, varName2);
				            if(symbol != nullptr) {
				                if(symbol->getType() == "ARRAY" && isFloatValue) {
				                    writeIntoErrorFile("Error at line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.start):null)->getLine()) + ": Type Mismatch\n");
				                    writeIntoparserLogFile("Error at line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.start):null)->getLine()) + ": Type Mismatch\n");
				                    syntaxErrorCount++;
				                }
				                else if(symbol->getType() == "INT" && isFloatValue) {
				                    writeIntoErrorFile("Error at line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.start):null)->getLine()) + ": Type Mismatch\n");
				                    writeIntoparserLogFile("Error at line " + std::to_string((((ExpressionContext)_localctx).v!=null?(((ExpressionContext)_localctx).v.start):null)->getLine()) + ": Type Mismatch\n");
				                    syntaxErrorCount++;
				                }
				            }
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string((((ExpressionContext)_localctx).l!=null?(((ExpressionContext)_localctx).l.start):null)->getLine()) + ": expression : variable ASSIGNOP logic_expression\n");
				        writeIntoparserLogFile(_localctx.expr_val + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Logic_expressionContext extends ParserRuleContext {
		public std::string logic_val;
		public Rel_expressionContext r;
		public Rel_expressionContext r1;
		public Token LOGICOP;
		public Rel_expressionContext r2;
		public List<Rel_expressionContext> rel_expression() {
			return getRuleContexts(Rel_expressionContext.class);
		}
		public Rel_expressionContext rel_expression(int i) {
			return getRuleContext(Rel_expressionContext.class,i);
		}
		public TerminalNode LOGICOP() { return getToken(C8086Parser.LOGICOP, 0); }
		public Logic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic_expression; }
	}

	public final Logic_expressionContext logic_expression() throws RecognitionException {
		Logic_expressionContext _localctx = new Logic_expressionContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_logic_expression);
		try {
			setState(386);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(378);
				((Logic_expressionContext)_localctx).r = rel_expression();

				        ((Logic_expressionContext)_localctx).logic_val =  ((Logic_expressionContext)_localctx).r.rel_val;
				        writeIntoparserLogFile("Line " + std::to_string((((Logic_expressionContext)_localctx).r!=null?(((Logic_expressionContext)_localctx).r.start):null)->getLine()) + ": logic_expression : rel_expression\n");
				        writeIntoparserLogFile(_localctx.logic_val + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(381);
				((Logic_expressionContext)_localctx).r1 = rel_expression();
				setState(382);
				((Logic_expressionContext)_localctx).LOGICOP = match(LOGICOP);
				setState(383);
				((Logic_expressionContext)_localctx).r2 = rel_expression();

				        ((Logic_expressionContext)_localctx).logic_val =  ((Logic_expressionContext)_localctx).r1.rel_val + ((Logic_expressionContext)_localctx).LOGICOP->getText() + ((Logic_expressionContext)_localctx).r2.rel_val;

				        std::string rel1Str = ((Logic_expressionContext)_localctx).r1.rel_val;
				        std::string rel2Str = ((Logic_expressionContext)_localctx).r2.rel_val;
				        
				        bool isSimpleVar1 = (rel1Str.find("*") == std::string::npos && rel1Str.find("+") == std::string::npos && rel1Str.find("-") == std::string::npos && rel1Str.find("/") == std::string::npos && rel1Str.find("%") == std::string::npos && rel1Str.find("(") == std::string::npos && rel1Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

				        bool isSimpleVar2 = (rel2Str.find("*") == std::string::npos && rel2Str.find("+") == std::string::npos && rel2Str.find("-") == std::string::npos && rel2Str.find("/") == std::string::npos && rel2Str.find("%") == std::string::npos && rel2Str.find("(") == std::string::npos && rel2Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

				        std::string label1 = newLabel();  
				        std::string label2 = newLabel();   
				        std::string label3 = newLabel();  
				        std::string label4 = newLabel();  
				        
				        if (isSimpleVar1 && isSimpleVar2 && (((Logic_expressionContext)_localctx).LOGICOP->getText() == "||")) {
				            if (currentFunction.empty() || localVarOffset.find(rel1Str) == localVarOffset.end()) {
				                emitCode("MOV AX, " + rel1Str + "       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            } else {
				                emitCode("MOV AX, " + getVarOffset(rel1Str) + "       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            }
				            emitCode("CMP AX, 0");
				            emitCode("JNE " + label1);  
				            emitCode("JMP " + label3);  
				            
				            emitCode(label3 + ":");     

				            if (currentFunction.empty() || localVarOffset.find(rel2Str) == localVarOffset.end()) {
				                emitCode("MOV AX, " + rel2Str + "       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            } else {
				                emitCode("MOV AX, " + getVarOffset(rel2Str) + "       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            }
				            emitCode("CMP AX, 0");
				            emitCode("JNE " + label1);  
				            emitCode("JMP " + label2); 
				            
				            emitCode(label1 + ":");     
				            emitCode("MOV AX, 1       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            emitCode("JMP " + label4); 
				            emitCode(label2 + ":");     
				            emitCode("MOV AX, 0");
				            emitCode(label4 + ":");     
				        } 
				        
				        else if (isSimpleVar1 && isSimpleVar2 && (((Logic_expressionContext)_localctx).LOGICOP->getText() == "&&")) {
				            if (currentFunction.empty() || localVarOffset.find(rel1Str) == localVarOffset.end()) {
				                emitCode("MOV AX, " + rel1Str + "       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            } else {
				                emitCode("MOV AX, " + getVarOffset(rel1Str) + "       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            }
				            emitCode("CMP AX, 0");
				            emitCode("JE " + label2);   
				            
				            if (currentFunction.empty() || localVarOffset.find(rel2Str) == localVarOffset.end()) {
				                emitCode("MOV AX, " + rel2Str + "       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            } else {
				                emitCode("MOV AX, " + getVarOffset(rel2Str) + "       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            }
				            emitCode("CMP AX, 0");
				            emitCode("JE " + label2);   

				            emitCode("MOV AX, 1       ; Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()));
				            emitCode("JMP " + label4); 
				            emitCode(label2 + ":");    
				            emitCode("MOV AX, 0");
				            emitCode(label4 + ":");     
				        } else {
				            if (((Logic_expressionContext)_localctx).LOGICOP->getText() == "||") {
				                emitCode("POP AX          ; First operand");
				                emitCode("CMP AX, 0");
				                emitCode("JNE " + label1);
				                emitCode("POP AX          ; Second operand"); 
				                emitCode("CMP AX, 0");
				                emitCode("JNE " + label1);
				                emitCode("MOV AX, 0");
				                emitCode("JMP " + label2);
				                emitCode(label1 + ":");
				                emitCode("MOV AX, 1");
				                emitCode(label2 + ":");
				                emitCode("PUSH AX");
				            } else if (((Logic_expressionContext)_localctx).LOGICOP->getText() == "&&") {
				                emitCode("POP BX          ; Second operand");
				                emitCode("POP AX          ; First operand");
				                emitCode("CMP AX, 0");
				                emitCode("JE " + label1);
				                emitCode("CMP BX, 0");
				                emitCode("JE " + label1);
				                emitCode("MOV AX, 1");
				                emitCode("JMP " + label2);
				                emitCode(label1 + ":");
				                emitCode("MOV AX, 0");
				                emitCode(label2 + ":");
				                emitCode("PUSH AX");
				            }
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Logic_expressionContext)_localctx).LOGICOP->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n");
				        writeIntoparserLogFile(_localctx.logic_val + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rel_expressionContext extends ParserRuleContext {
		public std::string rel_val;
		public Simple_expressionContext s;
		public Simple_expressionContext s1;
		public Token RELOP;
		public Simple_expressionContext s2;
		public List<Simple_expressionContext> simple_expression() {
			return getRuleContexts(Simple_expressionContext.class);
		}
		public Simple_expressionContext simple_expression(int i) {
			return getRuleContext(Simple_expressionContext.class,i);
		}
		public TerminalNode RELOP() { return getToken(C8086Parser.RELOP, 0); }
		public Rel_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rel_expression; }
	}

	public final Rel_expressionContext rel_expression() throws RecognitionException {
		Rel_expressionContext _localctx = new Rel_expressionContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_rel_expression);
		try {
			setState(396);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(388);
				((Rel_expressionContext)_localctx).s = simple_expression(0);

				        ((Rel_expressionContext)_localctx).rel_val =  ((Rel_expressionContext)_localctx).s.simple_val;
				        writeIntoparserLogFile("Line " + std::to_string((((Rel_expressionContext)_localctx).s!=null?(((Rel_expressionContext)_localctx).s.start):null)->getLine()) + ": rel_expression : simple_expression\n");
				        writeIntoparserLogFile(_localctx.rel_val + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(391);
				((Rel_expressionContext)_localctx).s1 = simple_expression(0);
				setState(392);
				((Rel_expressionContext)_localctx).RELOP = match(RELOP);
				setState(393);
				((Rel_expressionContext)_localctx).s2 = simple_expression(0);

				        ((Rel_expressionContext)_localctx).rel_val =  ((Rel_expressionContext)_localctx).s1.simple_val + ((Rel_expressionContext)_localctx).RELOP->getText() + ((Rel_expressionContext)_localctx).s2.simple_val;
				        std::string simple1Str = ((Rel_expressionContext)_localctx).s1.simple_val;
				        std::string simple2Str = ((Rel_expressionContext)_localctx).s2.simple_val;
				        
				        bool isSimpleVar1 = (simple1Str.find("*") == std::string::npos && simple1Str.find("+") == std::string::npos && simple1Str.find("-") == std::string::npos && simple1Str.find("/") == std::string::npos && simple1Str.find("%") == std::string::npos && simple1Str.find("(") == std::string::npos && simple1Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

				        bool isSimpleVar2 = (simple2Str.find("*") == std::string::npos && simple2Str.find("+") == std::string::npos && simple2Str.find("-") == std::string::npos && simple2Str.find("/") == std::string::npos && simple2Str.find("%") == std::string::npos && simple2Str.find("(") == std::string::npos && simple2Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

				        std::string label1 = newLabel();
				        std::string label2 = newLabel();
				        std::string label3 = newLabel();

				        if (!inForCondition) {
				            if (isSimpleVar1 && isSimpleVar2) {
				                if (currentFunction.empty() || localVarOffset.find(simple1Str) == localVarOffset.end()) {
				                    emitCode("MOV AX, " + simple1Str + "       ; Line " + std::to_string(((Rel_expressionContext)_localctx).RELOP->getLine()));
				                } else {
				                    emitCode("MOV AX, " + getVarOffset(simple1Str) + "       ; Line " + std::to_string(((Rel_expressionContext)_localctx).RELOP->getLine()));
				                }

				                if (currentFunction.empty() || localVarOffset.find(simple2Str) == localVarOffset.end()) {
				                    emitCode("CMP AX, " + simple2Str);
				                } else {
				                    emitCode("CMP AX, " + getVarOffset(simple2Str));
				                }
				            } 
				            
				            else if (!isSimpleVar1 && isSimpleVar2) {
				                emitCode("POP AX          ; First operand from stack");
				                emitCode("CMP AX, " + simple2Str);
				            } 
				            
				            else if (isSimpleVar1 && !isSimpleVar2) {
				                emitCode("POP BX          ; Second operand from stack");
				                if (currentFunction.empty() || localVarOffset.find(simple1Str) == localVarOffset.end()) {
				                    emitCode("MOV AX, " + simple1Str + "       ; Line " + std::to_string(((Rel_expressionContext)_localctx).RELOP->getLine()));
				                } else {
				                    emitCode("MOV AX, " + getVarOffset(simple1Str) + "       ; Line " + std::to_string(((Rel_expressionContext)_localctx).RELOP->getLine()));
				                }
				                emitCode("CMP AX, BX");
				            } 
				            
				            else {
				                emitCode("POP BX          ; Second operand");
				                emitCode("POP AX          ; First operand");
				                emitCode("CMP AX, BX");
				            }
				        
				            if (inIfCondition) {
				                if (((Rel_expressionContext)_localctx).RELOP->getText() == "<") {
				                    emitCode("JGE " + currentIfFalseLabel);  // Jump to false if NOT less than
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "<=") {
				                    emitCode("JG " + currentIfFalseLabel);   // Jump to false if NOT less than or equal
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == ">") {
				                    emitCode("JLE " + currentIfFalseLabel);  // Jump to false if NOT greater than
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == ">=") {
				                    emitCode("JL " + currentIfFalseLabel);   // Jump to false if NOT greater than or equal
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "==") {
				                    emitCode("JNE " + currentIfFalseLabel);  // Jump to false if NOT equal
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "!=") {
				                    emitCode("JE " + currentIfFalseLabel);   // Jump to false if equal
				                }
				            } 
				            
				            else if (inLoopCondition) {
				                if (((Rel_expressionContext)_localctx).RELOP->getText() == "<") {
				                    emitCode("JL " + currentLoopBodyLabel);   // Jump to body if less than
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "<=") {
				                    emitCode("JLE " + currentLoopBodyLabel);  // Jump to body if less than or equal
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == ">") {
				                    emitCode("JG " + currentLoopBodyLabel);   // Jump to body if greater than
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == ">=") {
				                    emitCode("JGE " + currentLoopBodyLabel);  // Jump to body if greater than or equal
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "==") {
				                    emitCode("JE " + currentLoopBodyLabel);   // Jump to body if equal
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "!=") {
				                    emitCode("JNE " + currentLoopBodyLabel);  // Jump to body if not equal
				                }
				                emitCode("JMP " + currentLoopExitLabel);      // Jump to exit if condition fails
				            } 
				            
				            else {
				                std::string label1 = newLabel();
				                std::string label2 = newLabel();
				                std::string label3 = newLabel();
				                
				                if (((Rel_expressionContext)_localctx).RELOP->getText() == "<") {
				                    emitCode("JL " + label1);
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "<=") {
				                    emitCode("JLE " + label1);
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == ">") {
				                    emitCode("JG " + label1);
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == ">=") {
				                    emitCode("JGE " + label1);
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "==") {
				                    emitCode("JE " + label1);
				                } else if (((Rel_expressionContext)_localctx).RELOP->getText() == "!=") {
				                    emitCode("JNE " + label1);
				                }
				                
				                emitCode("JMP " + label3);
				                emitCode(label1 + ":");
				                emitCode("MOV AX, 1       ; Line " + std::to_string(((Rel_expressionContext)_localctx).RELOP->getLine()));
				                emitCode("JMP " + label2);
				                emitCode(label3 + ":");
				                emitCode("MOV AX, 0");
				                emitCode(label2 + ":");
				                emitCode("PUSH AX");
				            }
				        }  
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Rel_expressionContext)_localctx).RELOP->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n");
				        writeIntoparserLogFile(_localctx.rel_val + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expressionContext extends ParserRuleContext {
		public std::string simple_val;
		public Simple_expressionContext s;
		public TermContext t;
		public Token ADDOP;
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public Simple_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression; }
	}

	public final Simple_expressionContext simple_expression() throws RecognitionException {
		return simple_expression(0);
	}

	private Simple_expressionContext simple_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Simple_expressionContext _localctx = new Simple_expressionContext(_ctx, _parentState);
		Simple_expressionContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_simple_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(399);
			((Simple_expressionContext)_localctx).t = term(0);

			        ((Simple_expressionContext)_localctx).simple_val =  ((Simple_expressionContext)_localctx).t.term_val;
			        writeIntoparserLogFile("Line " + std::to_string((((Simple_expressionContext)_localctx).t!=null?(((Simple_expressionContext)_localctx).t.start):null)->getLine()) + ": simple_expression : term\n");
			        writeIntoparserLogFile(_localctx.simple_val + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(409);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new Simple_expressionContext(_parentctx, _parentState);
					_localctx.s = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_simple_expression);
					setState(402);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(403);
					((Simple_expressionContext)_localctx).ADDOP = match(ADDOP);
					setState(404);
					((Simple_expressionContext)_localctx).t = term(0);

					                  ((Simple_expressionContext)_localctx).simple_val =  ((Simple_expressionContext)_localctx).s.simple_val + ((Simple_expressionContext)_localctx).ADDOP->getText() + ((Simple_expressionContext)_localctx).t.term_val;

					                  std::string simpleStr = ((Simple_expressionContext)_localctx).s.simple_val;
					                  std::string termStr = ((Simple_expressionContext)_localctx).t.term_val;
					                  
					                  bool isSimpleConst1 = (simpleStr.find("*") == std::string::npos &&  simpleStr.find("+") == std::string::npos &&  simpleStr.find("-") == std::string::npos && simpleStr.find("/") == std::string::npos && simpleStr.find("%") == std::string::npos && simpleStr.find("(") == std::string::npos && simpleStr.find_first_not_of("0123456789") == std::string::npos);

					                  bool isSimpleConst2 = (termStr.find("*") == std::string::npos &&  termStr.find("+") == std::string::npos && termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos && termStr.find_first_not_of("0123456789") == std::string::npos);

					                  bool isSimpleVar = (simpleStr.find("*") == std::string::npos && simpleStr.find("+") == std::string::npos &&  simpleStr.find("-") == std::string::npos && simpleStr.find("/") == std::string::npos && simpleStr.find("%") == std::string::npos && simpleStr.find("(") == std::string::npos);

					                  bool isSimpleVar2 = (termStr.find("*") == std::string::npos && termStr.find("+") == std::string::npos &&  termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos && termStr.find_first_not_of("0123456789") != std::string::npos);
					                  
					                  if (isSimpleConst1 && isSimpleConst2) {
					                      emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      emitCode("MOV DX, AX");
					                      emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      
					                      if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {
					                          emitCode("ADD AX, DX");
					                      } else {
					                          emitCode("SUB AX, DX");
					                      }
					                  } 
					                  
					                  else if (isSimpleVar && isSimpleVar2) {
					                      if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
					                          emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      } else {
					                          emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      }
					                      emitCode("MOV DX, AX");

					                      if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
					                          emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      } else {
					                          emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      }
					                      
					                      if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {
					                          emitCode("ADD AX, DX");
					                      } else {
					                          emitCode("SUB AX, DX");
					                      }

					                      if (!inAssignmentContext) {
					                          emitCode("PUSH AX");
					                      }
					                  } else if (isSimpleVar && isSimpleConst2) {
					                      emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      emitCode("MOV DX, AX");
					                      
					                      if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
					                          emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      } else {
					                          emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      }
					                      
					                      if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {
					                          emitCode("ADD AX, DX");
					                      } else {
					                          emitCode("SUB AX, DX");
					                      }

					                      if (!inAssignmentContext) {
					                          emitCode("PUSH AX");
					                      }
					                  } else if (isSimpleVar) {
					                      emitCode("POP AX       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      emitCode("MOV DX, AX");
					                      
					                      if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
					                          emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      } else {
					                          emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      }
					                      
					                      if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {
					                          emitCode("ADD AX, DX");
					                      } else {
					                          emitCode("SUB AX, DX");
					                      }
					                  } else if (isSimpleVar2) {
					                      if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
					                          emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      } else {
					                          emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      }
					                      emitCode("PUSH AX");

					                      emitCode("POP BX          ; Second operand (term)");
					                      emitCode("POP AX          ; First operand (simple_expression)");
					                      
					                      if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {
					                          emitCode("ADD AX, BX");
					                      } else {
					                          emitCode("SUB AX, BX");
					                      }
					                      emitCode("PUSH AX");
					                  } else if (!isSimpleConst1 && !isSimpleVar && isSimpleConst2) {
					                      emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      emitCode("MOV DX, AX");
					                      emitCode("POP AX       ; Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()));
					                      
					                      if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {
					                          emitCode("ADD AX, DX");
					                      } else {
					                          emitCode("SUB AX, DX");
					                      }
					                      emitCode("PUSH AX");
					                  } else {
					                      emitCode("POP DX          ; Second operand (term)");
					                      emitCode("POP AX          ; First operand (simple_expression)");
					                      if (((Simple_expressionContext)_localctx).ADDOP->getText() == "+") {
					                          emitCode("ADD AX, DX");
					                      } else {
					                          emitCode("SUB AX, DX");
					                      }
					                  }
					                  
					                  if (!(isSimpleConst1 && isSimpleConst2) && !(isSimpleVar && isSimpleConst2) && !isSimpleVar2 && !(!isSimpleConst1 && !isSimpleVar && isSimpleConst2)) {
					                      emitCode("PUSH AX");
					                  }
					                  
					                  writeIntoparserLogFile("Line " + std::to_string(((Simple_expressionContext)_localctx).ADDOP->getLine()) + ": simple_expression : simple_expression ADDOP term\n");
					                  writeIntoparserLogFile(_localctx.simple_val + "\n");
					              
					}
					} 
				}
				setState(411);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Simple_expression_errContext extends ParserRuleContext {
		public Simple_expressionContext s;
		public Token ASSIGNOP;
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public TerminalNode ASSIGNOP() { return getToken(C8086Parser.ASSIGNOP, 0); }
		public Simple_expressionContext simple_expression() {
			return getRuleContext(Simple_expressionContext.class,0);
		}
		public Simple_expression_errContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_simple_expression_err; }
	}

	public final Simple_expression_errContext simple_expression_err() throws RecognitionException {
		Simple_expression_errContext _localctx = new Simple_expression_errContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_simple_expression_err);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(412);
			((Simple_expression_errContext)_localctx).s = simple_expression(0);
			setState(413);
			match(ADDOP);
			setState(414);
			((Simple_expression_errContext)_localctx).ASSIGNOP = match(ASSIGNOP);
			 
			        writeIntoErrorFile("Error at line " + std::to_string(((Simple_expression_errContext)_localctx).ASSIGNOP->getLine()) + 
			                         ": syntax error, unexpected ASSIGNOP\n");
			        writeIntoparserLogFile("Error at line " + std::to_string(((Simple_expression_errContext)_localctx).ASSIGNOP->getLine()) + 
			                             ": syntax error, unexpected ASSIGNOP\n");
			        syntaxErrorCount++;       

			    
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public std::string term_val;
		public TermContext t;
		public Unary_expressionContext u;
		public Token MULOP;
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode MULOP() { return getToken(C8086Parser.MULOP, 0); }
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		return term(0);
	}

	private TermContext term(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TermContext _localctx = new TermContext(_ctx, _parentState);
		TermContext _prevctx = _localctx;
		int _startState = 44;
		enterRecursionRule(_localctx, 44, RULE_term, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(418);
			((TermContext)_localctx).u = unary_expression();

			        ((TermContext)_localctx).term_val =  ((TermContext)_localctx).u.unary_val;
			        writeIntoparserLogFile("Line " + std::to_string((((TermContext)_localctx).u!=null?(((TermContext)_localctx).u.start):null)->getLine()) + ": term : unary_expression\n");
			        writeIntoparserLogFile(_localctx.term_val + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(428);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new TermContext(_parentctx, _parentState);
					_localctx.t = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_term);
					setState(421);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(422);
					((TermContext)_localctx).MULOP = match(MULOP);
					setState(423);
					((TermContext)_localctx).u = unary_expression();

					                  ((TermContext)_localctx).term_val =  ((TermContext)_localctx).t.term_val + ((TermContext)_localctx).MULOP->getText() + ((TermContext)_localctx).u.unary_val;

					                  std::string termStr = ((TermContext)_localctx).t.term_val;
					                  std::string unaryStr = ((TermContext)_localctx).u.unary_val;

					                  bool isSimpleTerm = (termStr.find("*") == std::string::npos && termStr.find("+") == std::string::npos &&  termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos);

					                  bool isSimpleUnary = (unaryStr.find("*") == std::string::npos &&  unaryStr.find("+") == std::string::npos &&  unaryStr.find("-") == std::string::npos && unaryStr.find("/") == std::string::npos && unaryStr.find("%") == std::string::npos && unaryStr.find("(") == std::string::npos);
					                  
					                  if (isSimpleTerm && isSimpleUnary) { 
					                      if (currentFunction.empty() || localVarOffset.find(unaryStr) == localVarOffset.end()) {
					                          emitCode("MOV AX, " + unaryStr + "       ; Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()));
					                      } else {
					                          emitCode("MOV AX, " + getVarOffset(unaryStr) + "       ; Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()));
					                      }
					                      emitCode("MOV CX, AX");

					                      if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
					                          emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()));
					                      } else {
					                          emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()));
					                      }
					                  } else if (isSimpleTerm && !isSimpleUnary) {
					                      emitCode("POP AX       ; Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()));
					                      emitCode("MOV CX, AX");
					                      emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()));
					                  } else if (!isSimpleTerm && isSimpleUnary) {
					                      emitCode("POP AX       ; Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()));
					                      emitCode("MOV CX, " + unaryStr + "       ; Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()));
					                  } else {
					                      emitCode("POP CX          ; Second operand (unary_expression)");
					                      emitCode("POP AX          ; First operand (term)");
					                  }
					                  
					                  if (((TermContext)_localctx).MULOP->getText() == "*") {
					                      emitCode("CWD");
					                      emitCode("MUL CX");
					                  } else if (((TermContext)_localctx).MULOP->getText() == "/") {
					                      emitCode("CWD");
					                      emitCode("DIV CX");
					                  } else if (((TermContext)_localctx).MULOP->getText() == "%") {
					                      emitCode("CWD");
					                      emitCode("DIV CX");
					                      emitCode("MOV AX, DX");
					                  }
					                  emitCode("PUSH AX");
					                 
					                  if(((TermContext)_localctx).MULOP->getText() == "%" && (((TermContext)_localctx).u.unary_val.find(".") != std::string::npos || ((TermContext)_localctx).t.term_val.find(".") != std::string::npos)){
					                      writeIntoErrorFile("Error at line " + std::to_string((((TermContext)_localctx).t!=null?(((TermContext)_localctx).t.start):null)->getLine()) + ": Non-Integer operand on modulus operator\n");
					                      writeIntoparserLogFile("Error at line " + std::to_string((((TermContext)_localctx).t!=null?(((TermContext)_localctx).t.start):null)->getLine()) + ": Non-Integer operand on modulus operator\n");
					                      syntaxErrorCount++;            
					                  }

					                  if((((TermContext)_localctx).MULOP->getText() == "%" || ((TermContext)_localctx).MULOP->getText() == "/") && ((TermContext)_localctx).u.unary_val == "0") {
					                      writeIntoErrorFile("Error at line " + std::to_string((((TermContext)_localctx).t!=null?(((TermContext)_localctx).t.start):null)->getLine()) + ": Modulus by Zero\n");
					                      writeIntoparserLogFile("Error at line " + std::to_string((((TermContext)_localctx).t!=null?(((TermContext)_localctx).t.start):null)->getLine()) + ": Modulus by Zero\n");
					                      syntaxErrorCount++;
					                  }
					                  
					                  writeIntoparserLogFile("Line " + std::to_string(((TermContext)_localctx).MULOP->getLine()) + ": term : term MULOP unary_expression\n");
					                  writeIntoparserLogFile(_localctx.term_val + "\n");
					              
					}
					} 
				}
				setState(430);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_expressionContext extends ParserRuleContext {
		public std::string unary_val;
		public Token ADDOP;
		public Unary_expressionContext u;
		public Token NOT;
		public FactorContext f;
		public TerminalNode ADDOP() { return getToken(C8086Parser.ADDOP, 0); }
		public Unary_expressionContext unary_expression() {
			return getRuleContext(Unary_expressionContext.class,0);
		}
		public TerminalNode NOT() { return getToken(C8086Parser.NOT, 0); }
		public FactorContext factor() {
			return getRuleContext(FactorContext.class,0);
		}
		public Unary_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_expression; }
	}

	public final Unary_expressionContext unary_expression() throws RecognitionException {
		Unary_expressionContext _localctx = new Unary_expressionContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_unary_expression);
		try {
			setState(442);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADDOP:
				enterOuterAlt(_localctx, 1);
				{
				setState(431);
				((Unary_expressionContext)_localctx).ADDOP = match(ADDOP);
				setState(432);
				((Unary_expressionContext)_localctx).u = unary_expression();

				        ((Unary_expressionContext)_localctx).unary_val =  ((Unary_expressionContext)_localctx).ADDOP->getText() + ((Unary_expressionContext)_localctx).u.unary_val;

				        std::string unaryStr = ((Unary_expressionContext)_localctx).u.unary_val;
				        bool isSimpleVar = (unaryStr.find("*") == std::string::npos && unaryStr.find("+") == std::string::npos && unaryStr.find("-") == std::string::npos && unaryStr.find("/") == std::string::npos && unaryStr.find("%") == std::string::npos && unaryStr.find("(") == std::string::npos && unaryStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
				        
				        if (isSimpleVar && ((Unary_expressionContext)_localctx).ADDOP->getText() == "-") {
				            if (currentFunction.empty() || localVarOffset.find(unaryStr) == localVarOffset.end()) {
				                emitCode("MOV AX, " + unaryStr + "       ; Line " + std::to_string(((Unary_expressionContext)_localctx).ADDOP->getLine()));
				            } else {
				                emitCode("MOV AX, " + getVarOffset(unaryStr) + "       ; Line " + std::to_string(((Unary_expressionContext)_localctx).ADDOP->getLine()));
				            }
				            emitCode("NEG AX");
				        } else {
				            emitCode("POP AX          ; Get operand");
				            if (((Unary_expressionContext)_localctx).ADDOP->getText() == "-") {
				                emitCode("NEG AX");
				            }
				            emitCode("PUSH AX");
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Unary_expressionContext)_localctx).ADDOP->getLine()) + ": unary_expression : ADDOP unary_expression\n");
				        writeIntoparserLogFile(_localctx.unary_val + "\n");
				    
				}
				break;
			case NOT:
				enterOuterAlt(_localctx, 2);
				{
				setState(435);
				((Unary_expressionContext)_localctx).NOT = match(NOT);
				setState(436);
				((Unary_expressionContext)_localctx).u = unary_expression();

				        ((Unary_expressionContext)_localctx).unary_val =  "!" + ((Unary_expressionContext)_localctx).u.unary_val;

				        std::string label1 = newLabel();
				        std::string label2 = newLabel();
				        
				        emitCode("POP AX          ; Get operand");
				        emitCode("CMP AX, 0");
				        emitCode("JE " + label1);
				        emitCode("MOV AX, 0");
				        emitCode("JMP " + label2);
				        emitCode(label1 + ":");
				        emitCode("MOV AX, 1");
				        emitCode(label2 + ":");
				        emitCode("PUSH AX");
				        
				        writeIntoparserLogFile("Line " + std::to_string(((Unary_expressionContext)_localctx).NOT->getLine()) + ": unary_expression : NOT unary_expression\n");
				        writeIntoparserLogFile(_localctx.unary_val + "\n");
				    
				}
				break;
			case LPAREN:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 3);
				{
				setState(439);
				((Unary_expressionContext)_localctx).f = factor();

				        ((Unary_expressionContext)_localctx).unary_val =  ((Unary_expressionContext)_localctx).f.factor_val;
				        writeIntoparserLogFile("Line " + std::to_string((((Unary_expressionContext)_localctx).f!=null?(((Unary_expressionContext)_localctx).f.start):null)->getLine()) + ": unary_expression : factor\n");
				        writeIntoparserLogFile(_localctx.unary_val + "\n");
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FactorContext extends ParserRuleContext {
		public std::string factor_val;
		public VariableContext v;
		public Token ID;
		public Argument_listContext a;
		public Token LPAREN;
		public ExpressionContext e;
		public Token CONST_INT;
		public Token CONST_FLOAT;
		public Token INCOP;
		public Token DECOP;
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode ID() { return getToken(C8086Parser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(C8086Parser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(C8086Parser.RPAREN, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode CONST_INT() { return getToken(C8086Parser.CONST_INT, 0); }
		public TerminalNode CONST_FLOAT() { return getToken(C8086Parser.CONST_FLOAT, 0); }
		public TerminalNode INCOP() { return getToken(C8086Parser.INCOP, 0); }
		public TerminalNode DECOP() { return getToken(C8086Parser.DECOP, 0); }
		public FactorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_factor; }
	}

	public final FactorContext factor() throws RecognitionException {
		FactorContext _localctx = new FactorContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_factor);
		try {
			setState(470);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(444);
				((FactorContext)_localctx).v = variable();

				        ((FactorContext)_localctx).factor_val =  ((FactorContext)_localctx).v.var_name;

				        std::string varName = ((FactorContext)_localctx).v.var_name;

				        size_t bracketPos = varName.find("[");
				        if (bracketPos != std::string::npos) {
				            std::string arrayName = varName.substr(0, bracketPos);
				            std::string indexStr = varName.substr(bracketPos + 1);
				            indexStr = indexStr.substr(0, indexStr.find("]"));

				            if (currentFunction.empty() || localVarOffset.find(arrayName) == localVarOffset.end()) {
				                if (indexStr.find_first_not_of("0123456789") == std::string::npos) {
				                    int index = std::stoi(indexStr);
				                    emitCode("MOV AX, " + arrayName + "[" + std::to_string(index * 2) + "]");
				                } else {
				                    emitCode("MOV BX, " + indexStr);
				                    emitCode("SHL BX, 1");  
				                    emitCode("MOV AX, " + arrayName + "[BX]");
				                }
				            } else {
				                int baseOffset = localVarOffset[arrayName];
				                if (indexStr.find_first_not_of("0123456789") == std::string::npos) {
				                    int index = std::stoi(indexStr);
				                    int actualOffset = baseOffset + (index * 2);
				                    emitCode("MOV AX, [BP-" + std::to_string(actualOffset) + "]");
				                } else {
				                    emitCode("MOV BX, " + indexStr);
				                    emitCode("SHL BX, 1");  
				                    emitCode("MOV CX, " + std::to_string(baseOffset));
				                    emitCode("ADD BX, CX");
				                    emitCode("NEG BX");
				                    emitCode("MOV AX, [BP+BX]");
				                }
				            }
				        } else {
				            if (currentFunction.empty() || localVarOffset.find(varName) == localVarOffset.end()) {
				                emitCode("MOV AX, " + varName);
				            } else {
				                emitCode("MOV AX, " + getVarOffset(varName));
				            }
				        }

				        writeIntoparserLogFile("Line " + std::to_string((((FactorContext)_localctx).v!=null?(((FactorContext)_localctx).v.start):null)->getLine()) + ": factor : variable\n");
				        writeIntoparserLogFile(_localctx.factor_val + "\n");
				    
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(447);
				((FactorContext)_localctx).ID = match(ID);
				setState(448);
				match(LPAREN);
				setState(449);
				((FactorContext)_localctx).a = argument_list();
				setState(450);
				match(RPAREN);

				        ((FactorContext)_localctx).factor_val =  ((FactorContext)_localctx).ID->getText() + "(" + ((FactorContext)_localctx).a.arg_list + ")";

				        if(functionTable.find(((FactorContext)_localctx).ID->getText()) == functionTable.end()){
				            writeIntoErrorFile("Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": Undefined function " + ((FactorContext)_localctx).ID->getText() + "\n");
				            writeIntoparserLogFile("Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": Undefined function " + ((FactorContext)_localctx).ID->getText() + "\n");       
				            syntaxErrorCount++;
				        }
				        else{
				            FunctionInfo& func = functionTable[((FactorContext)_localctx).ID->getText()];

				            if(func.returnType == "void"){
				                writeIntoErrorFile("Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": Void function used in expression\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": Void function used in expression\n");
				                syntaxErrorCount++;
				            }

				            std::vector<std::string> providedArgs;
				            std::istringstream argStream(((FactorContext)_localctx).a.arg_list);
				            std::string arg;

				            while(std::getline(argStream, arg, ',')){
				                if(!arg.empty()){
				                    providedArgs.push_back(arg);
				                }
				            }

				            if(providedArgs.size() != func.paramTypes.size()){
				                writeIntoErrorFile("Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				                writeIntoparserLogFile("Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				                syntaxErrorCount++;
				            }
				            else{
				                for(size_t i = 0; i < providedArgs.size(); i++){
				                    if(func.paramTypes[i] == "int" && providedArgs[i].find(".") != std::string::npos){
				                        writeIntoErrorFile("Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				                        writeIntoparserLogFile("Error at line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + ((FactorContext)_localctx).ID->getText() + "\n");
				                        syntaxErrorCount++;
				                        break;
				                    }
				                }
				            }

				            emitCode("CALL " + ((FactorContext)_localctx).ID->getText() + "       ; Line " + std::to_string(((FactorContext)_localctx).ID->getLine()));
				            
				            if(func.returnType != "void") {
				                emitCode("PUSH AX");
				            } else {
				                emitCode("PUSH AX");
				            }
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((FactorContext)_localctx).ID->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n");
				        writeIntoparserLogFile(_localctx.factor_val + "\n");
				    
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(453);
				((FactorContext)_localctx).LPAREN = match(LPAREN);
				setState(454);
				((FactorContext)_localctx).e = expression();
				setState(455);
				match(RPAREN);

				        ((FactorContext)_localctx).factor_val =  "(" + ((FactorContext)_localctx).e.expr_val + ")";
				        std::string exprStr = ((FactorContext)_localctx).e.expr_val;

				        bool isSimpleArithmetic = (exprStr.find("*") == std::string::npos && exprStr.find("/") == std::string::npos && exprStr.find("%") == std::string::npos && exprStr.find("(") == std::string::npos && exprStr.find("&&") == std::string::npos && exprStr.find("||") == std::string::npos && (exprStr.find("+") != std::string::npos || exprStr.find("-") != std::string::npos));
				        
				        if (isSimpleArithmetic) {
				            emitCode("PUSH AX       ; Push parenthesized expression result");
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((FactorContext)_localctx).LPAREN->getLine()) + ": factor : LPAREN expression RPAREN\n");
				        writeIntoparserLogFile(_localctx.factor_val + "\n");
				    
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(458);
				((FactorContext)_localctx).CONST_INT = match(CONST_INT);

				        ((FactorContext)_localctx).factor_val =  ((FactorContext)_localctx).CONST_INT->getText();       
				        writeIntoparserLogFile("Line " + std::to_string(((FactorContext)_localctx).CONST_INT->getLine()) + ": factor : CONST_INT\n");
				        writeIntoparserLogFile(_localctx.factor_val + "\n");
				    
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(460);
				((FactorContext)_localctx).CONST_FLOAT = match(CONST_FLOAT);

				        ((FactorContext)_localctx).factor_val =  ((FactorContext)_localctx).CONST_FLOAT->getText();
				        emitCode("MOV AX, " + ((FactorContext)_localctx).CONST_FLOAT->getText().substr(0, ((FactorContext)_localctx).CONST_FLOAT->getText().find(".")));
				        emitCode("PUSH AX");
				        
				        writeIntoparserLogFile("Line " + std::to_string(((FactorContext)_localctx).CONST_FLOAT->getLine()) + ": factor : CONST_FLOAT\n");
				        writeIntoparserLogFile(_localctx.factor_val + "\n");
				    
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(462);
				((FactorContext)_localctx).v = variable();
				setState(463);
				((FactorContext)_localctx).INCOP = match(INCOP);

				        ((FactorContext)_localctx).factor_val =  ((FactorContext)_localctx).v.var_name + "++";

				        if (!inForIncrement) {
				            std::string varName = ((FactorContext)_localctx).v.var_name;

				            size_t bracketPos = varName.find("[");
				            if (bracketPos != std::string::npos) {
				                std::string arrayName = varName.substr(0, bracketPos);
				                std::string indexStr = varName.substr(bracketPos + 1);
				                indexStr = indexStr.substr(0, indexStr.find("]"));
				                
				                if (currentFunction.empty() || localVarOffset.find(arrayName) == localVarOffset.end()) {
				                    if (indexStr.find_first_not_of("0123456789") == std::string::npos) {
				                        int index = std::stoi(indexStr);
				                        emitCode("MOV AX, " + arrayName + "[" + std::to_string(index * 2) + "]       ; Line " + std::to_string(((FactorContext)_localctx).INCOP->getLine()));
				                        emitCode("PUSH AX");
				                        emitCode("INC AX");
				                        emitCode("MOV " + arrayName + "[" + std::to_string(index * 2) + "], AX");
				                        emitCode("POP AX");
				                    } else {
				                        emitCode("MOV BX, " + indexStr);
				                        emitCode("SHL BX, 1");  // Multiply by 2 for word size
				                        emitCode("MOV AX, " + arrayName + "[BX]       ; Line " + std::to_string(((FactorContext)_localctx).INCOP->getLine()));
				                        emitCode("PUSH AX");
				                        emitCode("INC AX");
				                        emitCode("MOV " + arrayName + "[BX], AX");
				                        emitCode("POP AX");
				                    }
				                } 
				                
				                else {
				                    int baseOffset = localVarOffset[arrayName];
				                    if (indexStr.find_first_not_of("0123456789") == std::string::npos) {
				                        int index = std::stoi(indexStr);
				                        int actualOffset = baseOffset + (index * 2);
				                        emitCode("MOV AX, [BP-" + std::to_string(actualOffset) + "]       ; Line " + std::to_string(((FactorContext)_localctx).INCOP->getLine()));
				                        emitCode("PUSH AX");
				                        emitCode("INC AX");
				                        emitCode("MOV [BP-" + std::to_string(actualOffset) + "], AX");
				                        emitCode("POP AX");
				                    } else {
				                        emitCode("MOV BX, " + indexStr);
				                        emitCode("SHL BX, 1");  
				                        emitCode("MOV CX, " + std::to_string(baseOffset));
				                        emitCode("ADD BX, CX");
				                        emitCode("NEG BX");
				                        emitCode("MOV AX, [BP+BX]       ; Line " + std::to_string(((FactorContext)_localctx).INCOP->getLine()));
				                        emitCode("PUSH AX");
				                        emitCode("INC AX");
				                        emitCode("MOV [BP+BX], AX");
				                        emitCode("POP AX");
				                    }
				                }
				            } else {
				                // Regular variable (not array)
				                if (currentFunction.empty()) {
				                    emitCode("MOV AX, " + varName + "       ; Line " + std::to_string(((FactorContext)_localctx).INCOP->getLine()));
				                    emitCode("PUSH AX");
				                    emitCode("INC AX");
				                    emitCode("MOV " + varName + ", AX");
				                    emitCode("POP AX");
				                } else {
				                    if (localVarOffset.find(varName) != localVarOffset.end()) {
				                        emitCode("MOV AX, " + getVarOffset(varName) + "       ; Line " + std::to_string(((FactorContext)_localctx).INCOP->getLine()));
				                        emitCode("PUSH AX");
				                        emitCode("INC AX");
				                        emitCode("MOV " + getVarOffset(varName) + ", AX");
				                        emitCode("POP AX");
				                    }
				                }
				            }
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((FactorContext)_localctx).INCOP->getLine()) + ": factor : variable INCOP\n");
				        writeIntoparserLogFile(_localctx.factor_val + "\n");
				    
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(466);
				((FactorContext)_localctx).v = variable();
				setState(467);
				((FactorContext)_localctx).DECOP = match(DECOP);

				        ((FactorContext)_localctx).factor_val =  ((FactorContext)_localctx).v.var_name + "--";

				        std::string varName = ((FactorContext)_localctx).v.var_name;
				        if (inLoopCondition) {
				            if (currentFunction.empty()) {
				                emitCode("MOV AX, " + varName);
				                emitCode("DEC AX");              
				                emitCode("MOV " + varName + ", AX");
				                emitCode("ADD AX, 1");           
				                emitCode("CMP AX, 0");
				                emitCode("JE " + currentLoopExitLabel);  
				            } else {
				                if (localVarOffset.find(varName) != localVarOffset.end()) {
				                    emitCode("MOV AX, " + getVarOffset(varName) + "");
				                    emitCode("DEC AX");          
				                    emitCode("MOV " + getVarOffset(varName) + ", AX");
				                    emitCode("ADD AX, 1");       
				                    emitCode("CMP AX, 0");
				                    emitCode("JE " + currentLoopExitLabel);  
				                }
				            }
				        } else {
				            if (currentFunction.empty()) {
				                emitCode("MOV AX, " + varName);
				                emitCode("PUSH AX         ; Push old value");
				                emitCode("DEC AX");
				                emitCode("MOV " + varName + ", AX");
				                emitCode("POP AX");
				            } else {
				                if (localVarOffset.find(varName) != localVarOffset.end()) {
				                    emitCode("MOV AX, " + getVarOffset(varName) + "");
				                    emitCode("PUSH AX         ; Push old value");
				                    emitCode("DEC AX");
				                    emitCode("MOV " + getVarOffset(varName) + ", AX");
				                    emitCode("POP AX");
				                }
				            }
				        }
				        
				        writeIntoparserLogFile("Line " + std::to_string(((FactorContext)_localctx).DECOP->getLine()) + ": factor : variable DECOP\n");
				        writeIntoparserLogFile(_localctx.factor_val + "\n");
				    
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public std::string arg_list;
		public ArgumentsContext a;
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_argument_list);
		try {
			setState(476);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAREN:
			case ADDOP:
			case NOT:
			case ID:
			case CONST_INT:
			case CONST_FLOAT:
				enterOuterAlt(_localctx, 1);
				{
				setState(472);
				((Argument_listContext)_localctx).a = arguments(0);

				        ((Argument_listContext)_localctx).arg_list =  ((Argument_listContext)_localctx).a.args_val;
				        writeIntoparserLogFile("Line " + std::to_string((((Argument_listContext)_localctx).a!=null?(((Argument_listContext)_localctx).a.start):null)->getLine()) + ": argument_list : arguments\n");
				        writeIntoparserLogFile(_localctx.arg_list + "\n");
				    
				}
				break;
			case RPAREN:
				enterOuterAlt(_localctx, 2);
				{

				        ((Argument_listContext)_localctx).arg_list =  "";
				        writeIntoparserLogFile("argument_list : <empty>\n");
				        writeIntoparserLogFile("\n");
				    
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentsContext extends ParserRuleContext {
		public std::string args_val;
		public ArgumentsContext a;
		public Logic_expressionContext l;
		public Logic_expressionContext logic_expression() {
			return getRuleContext(Logic_expressionContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(C8086Parser.COMMA, 0); }
		public ArgumentsContext arguments() {
			return getRuleContext(ArgumentsContext.class,0);
		}
		public ArgumentsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments; }
	}

	public final ArgumentsContext arguments() throws RecognitionException {
		return arguments(0);
	}

	private ArgumentsContext arguments(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ArgumentsContext _localctx = new ArgumentsContext(_ctx, _parentState);
		ArgumentsContext _prevctx = _localctx;
		int _startState = 52;
		enterRecursionRule(_localctx, 52, RULE_arguments, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(479);
			((ArgumentsContext)_localctx).l = logic_expression();

			        ((ArgumentsContext)_localctx).args_val =  ((ArgumentsContext)_localctx).l.logic_val;

			        std::string logicStr = ((ArgumentsContext)_localctx).l.logic_val;
			        bool isSimpleConstant = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("0123456789") == std::string::npos);
			        
			        bool isSimpleVar = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
			        
			        if (isSimpleConstant) {
			            emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()));
			            emitCode("PUSH AX");
			        } 
			        
			        else if (isSimpleVar) {
			            if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
			                emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()));
			            } else {
			                emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()));
			            }
			            emitCode("PUSH AX");
			        } 
			        
			        else {
			            emitCode("POP AX       ; Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()));
			            emitCode("PUSH AX");
			        }
			        
			        writeIntoparserLogFile("Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()) + ": arguments : logic_expression\n");
			        writeIntoparserLogFile(_localctx.args_val + "\n");
			    
			}
			_ctx.stop = _input.LT(-1);
			setState(489);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArgumentsContext(_parentctx, _parentState);
					_localctx.a = _prevctx;
					pushNewRecursionContext(_localctx, _startState, RULE_arguments);
					setState(482);
					if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
					setState(483);
					match(COMMA);
					setState(484);
					((ArgumentsContext)_localctx).l = logic_expression();

					                  ((ArgumentsContext)_localctx).args_val =  ((ArgumentsContext)_localctx).a.args_val + "," + ((ArgumentsContext)_localctx).l.logic_val;
					                  
					                  std::string logicStr = ((ArgumentsContext)_localctx).l.logic_val;
					                  bool isSimpleConstant = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("0123456789") == std::string::npos);
					                  
					                  bool isSimpleVar = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
					                  
					                  if (isSimpleConstant) {
					                      emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()));
					                      emitCode("PUSH AX");
					                  } 
					                  
					                  else if (isSimpleVar) {
					                      if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
					                          emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()));
					                      } else {
					                          emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()));
					                      }
					                      emitCode("PUSH AX");
					                  } else {
					                      emitCode("POP AX       ; Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()));
					                      emitCode("PUSH AX");
					                  }
					                  
					                  writeIntoparserLogFile("Line " + std::to_string((((ArgumentsContext)_localctx).l!=null?(((ArgumentsContext)_localctx).l.start):null)->getLine()) + ": arguments : arguments COMMA logic_expression\n");
					                  writeIntoparserLogFile(_localctx.args_val + "\n");
					              
					}
					} 
				}
				setState(491);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return program_sempred((ProgramContext)_localctx, predIndex);
		case 5:
			return parameter_list_sempred((Parameter_listContext)_localctx, predIndex);
		case 10:
			return declaration_list_sempred((Declaration_listContext)_localctx, predIndex);
		case 11:
			return statements_sempred((StatementsContext)_localctx, predIndex);
		case 13:
			return case_statements_sempred((Case_statementsContext)_localctx, predIndex);
		case 20:
			return simple_expression_sempred((Simple_expressionContext)_localctx, predIndex);
		case 22:
			return term_sempred((TermContext)_localctx, predIndex);
		case 26:
			return arguments_sempred((ArgumentsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean program_sempred(ProgramContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean parameter_list_sempred(Parameter_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 5);
		case 2:
			return precpred(_ctx, 4);
		}
		return true;
	}
	private boolean declaration_list_sempred(Declaration_listContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 5);
		case 4:
			return precpred(_ctx, 4);
		case 5:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean statements_sempred(StatementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 3);
		case 7:
			return precpred(_ctx, 2);
		case 8:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean case_statements_sempred(Case_statementsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 9:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean simple_expression_sempred(Simple_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 10:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean term_sempred(TermContext _localctx, int predIndex) {
		switch (predIndex) {
		case 11:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean arguments_sempred(ArgumentsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 12:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001(\u01ed\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001B\b\u0001\n\u0001\f\u0001"+
		"E\t\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002P\b\u0002"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003a\b\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0003\u0004w\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005\u0085\b\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005\u0092\b\u0005"+
		"\n\u0005\f\u0005\u0095\t\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003"+
		"\u0006\u00a0\b\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003"+
		"\u0007\u00ac\b\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0003\t\u00b6\b\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0003\n\u00c0\b\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0005\n\u00d1\b\n\n\n\f\n\u00d4\t\n\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b"+
		"\u00e9\b\u000b\n\u000b\f\u000b\u00ec\t\u000b\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0003\f\u013e\b\f\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0005\r\u0148\b\r\n\r\f\r\u014b"+
		"\t\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u015c\b\u000e\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0003"+
		"\u000f\u0164\b\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0003\u0010\u016e\b\u0010\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0003\u0011\u0179\b\u0011\u0001\u0012\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001"+
		"\u0012\u0003\u0012\u0183\b\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0003\u0013\u018d"+
		"\b\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0005\u0014\u0198\b\u0014\n"+
		"\u0014\f\u0014\u019b\t\u0014\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001"+
		"\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0005\u0016\u01ab"+
		"\b\u0016\n\u0016\f\u0016\u01ae\t\u0016\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0001\u0017\u0001\u0017\u0003\u0017\u01bb\b\u0017\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0003\u0018\u01d7\b\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019"+
		"\u0003\u0019\u01dd\b\u0019\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a"+
		"\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0005\u001a"+
		"\u01e8\b\u001a\n\u001a\f\u001a\u01eb\t\u001a\u0001\u001a\u0000\b\u0002"+
		"\n\u0014\u0016\u001a(,4\u001b\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010"+
		"\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.024\u0000\u0000\u0203"+
		"\u00006\u0001\u0000\u0000\u0000\u00029\u0001\u0000\u0000\u0000\u0004O"+
		"\u0001\u0000\u0000\u0000\u0006`\u0001\u0000\u0000\u0000\bv\u0001\u0000"+
		"\u0000\u0000\n\u0084\u0001\u0000\u0000\u0000\f\u009f\u0001\u0000\u0000"+
		"\u0000\u000e\u00ab\u0001\u0000\u0000\u0000\u0010\u00ad\u0001\u0000\u0000"+
		"\u0000\u0012\u00b5\u0001\u0000\u0000\u0000\u0014\u00bf\u0001\u0000\u0000"+
		"\u0000\u0016\u00d5\u0001\u0000\u0000\u0000\u0018\u013d\u0001\u0000\u0000"+
		"\u0000\u001a\u013f\u0001\u0000\u0000\u0000\u001c\u015b\u0001\u0000\u0000"+
		"\u0000\u001e\u0163\u0001\u0000\u0000\u0000 \u016d\u0001\u0000\u0000\u0000"+
		"\"\u0178\u0001\u0000\u0000\u0000$\u0182\u0001\u0000\u0000\u0000&\u018c"+
		"\u0001\u0000\u0000\u0000(\u018e\u0001\u0000\u0000\u0000*\u019c\u0001\u0000"+
		"\u0000\u0000,\u01a1\u0001\u0000\u0000\u0000.\u01ba\u0001\u0000\u0000\u0000"+
		"0\u01d6\u0001\u0000\u0000\u00002\u01dc\u0001\u0000\u0000\u00004\u01de"+
		"\u0001\u0000\u0000\u000067\u0003\u0002\u0001\u000078\u0006\u0000\uffff"+
		"\uffff\u00008\u0001\u0001\u0000\u0000\u00009:\u0006\u0001\uffff\uffff"+
		"\u0000:;\u0003\u0004\u0002\u0000;<\u0006\u0001\uffff\uffff\u0000<C\u0001"+
		"\u0000\u0000\u0000=>\n\u0002\u0000\u0000>?\u0003\u0004\u0002\u0000?@\u0006"+
		"\u0001\uffff\uffff\u0000@B\u0001\u0000\u0000\u0000A=\u0001\u0000\u0000"+
		"\u0000BE\u0001\u0000\u0000\u0000CA\u0001\u0000\u0000\u0000CD\u0001\u0000"+
		"\u0000\u0000D\u0003\u0001\u0000\u0000\u0000EC\u0001\u0000\u0000\u0000"+
		"FG\u0003\u000e\u0007\u0000GH\u0006\u0002\uffff\uffff\u0000HP\u0001\u0000"+
		"\u0000\u0000IJ\u0003\u0006\u0003\u0000JK\u0006\u0002\uffff\uffff\u0000"+
		"KP\u0001\u0000\u0000\u0000LM\u0003\b\u0004\u0000MN\u0006\u0002\uffff\uffff"+
		"\u0000NP\u0001\u0000\u0000\u0000OF\u0001\u0000\u0000\u0000OI\u0001\u0000"+
		"\u0000\u0000OL\u0001\u0000\u0000\u0000P\u0005\u0001\u0000\u0000\u0000"+
		"QR\u0003\u0012\t\u0000RS\u0005%\u0000\u0000ST\u0005\u0013\u0000\u0000"+
		"TU\u0003\n\u0005\u0000UV\u0005\u0014\u0000\u0000VW\u0005\u0019\u0000\u0000"+
		"WX\u0006\u0003\uffff\uffff\u0000Xa\u0001\u0000\u0000\u0000YZ\u0003\u0012"+
		"\t\u0000Z[\u0005%\u0000\u0000[\\\u0005\u0013\u0000\u0000\\]\u0005\u0014"+
		"\u0000\u0000]^\u0005\u0019\u0000\u0000^_\u0006\u0003\uffff\uffff\u0000"+
		"_a\u0001\u0000\u0000\u0000`Q\u0001\u0000\u0000\u0000`Y\u0001\u0000\u0000"+
		"\u0000a\u0007\u0001\u0000\u0000\u0000bc\u0003\u0012\t\u0000cd\u0005%\u0000"+
		"\u0000de\u0006\u0004\uffff\uffff\u0000ef\u0005\u0013\u0000\u0000fg\u0006"+
		"\u0004\uffff\uffff\u0000gh\u0003\n\u0005\u0000hi\u0005\u0014\u0000\u0000"+
		"ij\u0006\u0004\uffff\uffff\u0000jk\u0003\f\u0006\u0000kl\u0006\u0004\uffff"+
		"\uffff\u0000lw\u0001\u0000\u0000\u0000mn\u0003\u0012\t\u0000no\u0005%"+
		"\u0000\u0000op\u0006\u0004\uffff\uffff\u0000pq\u0005\u0013\u0000\u0000"+
		"qr\u0005\u0014\u0000\u0000rs\u0006\u0004\uffff\uffff\u0000st\u0003\f\u0006"+
		"\u0000tu\u0006\u0004\uffff\uffff\u0000uw\u0001\u0000\u0000\u0000vb\u0001"+
		"\u0000\u0000\u0000vm\u0001\u0000\u0000\u0000w\t\u0001\u0000\u0000\u0000"+
		"xy\u0006\u0005\uffff\uffff\u0000yz\u0003\u0012\t\u0000z{\u0005%\u0000"+
		"\u0000{|\u0006\u0005\uffff\uffff\u0000|\u0085\u0001\u0000\u0000\u0000"+
		"}~\u0003\u0012\t\u0000~\u007f\u0006\u0005\uffff\uffff\u0000\u007f\u0085"+
		"\u0001\u0000\u0000\u0000\u0080\u0081\u0003\u0012\t\u0000\u0081\u0082\u0005"+
		"\u001c\u0000\u0000\u0082\u0083\u0006\u0005\uffff\uffff\u0000\u0083\u0085"+
		"\u0001\u0000\u0000\u0000\u0084x\u0001\u0000\u0000\u0000\u0084}\u0001\u0000"+
		"\u0000\u0000\u0084\u0080\u0001\u0000\u0000\u0000\u0085\u0093\u0001\u0000"+
		"\u0000\u0000\u0086\u0087\n\u0005\u0000\u0000\u0087\u0088\u0005\u001a\u0000"+
		"\u0000\u0088\u0089\u0003\u0012\t\u0000\u0089\u008a\u0005%\u0000\u0000"+
		"\u008a\u008b\u0006\u0005\uffff\uffff\u0000\u008b\u0092\u0001\u0000\u0000"+
		"\u0000\u008c\u008d\n\u0004\u0000\u0000\u008d\u008e\u0005\u001a\u0000\u0000"+
		"\u008e\u008f\u0003\u0012\t\u0000\u008f\u0090\u0006\u0005\uffff\uffff\u0000"+
		"\u0090\u0092\u0001\u0000\u0000\u0000\u0091\u0086\u0001\u0000\u0000\u0000"+
		"\u0091\u008c\u0001\u0000\u0000\u0000\u0092\u0095\u0001\u0000\u0000\u0000"+
		"\u0093\u0091\u0001\u0000\u0000\u0000\u0093\u0094\u0001\u0000\u0000\u0000"+
		"\u0094\u000b\u0001\u0000\u0000\u0000\u0095\u0093\u0001\u0000\u0000\u0000"+
		"\u0096\u0097\u0005\u0015\u0000\u0000\u0097\u0098\u0006\u0006\uffff\uffff"+
		"\u0000\u0098\u0099\u0003\u0016\u000b\u0000\u0099\u009a\u0005\u0016\u0000"+
		"\u0000\u009a\u009b\u0006\u0006\uffff\uffff\u0000\u009b\u00a0\u0001\u0000"+
		"\u0000\u0000\u009c\u009d\u0005\u0015\u0000\u0000\u009d\u009e\u0005\u0016"+
		"\u0000\u0000\u009e\u00a0\u0006\u0006\uffff\uffff\u0000\u009f\u0096\u0001"+
		"\u0000\u0000\u0000\u009f\u009c\u0001\u0000\u0000\u0000\u00a0\r\u0001\u0000"+
		"\u0000\u0000\u00a1\u00a2\u0003\u0012\t\u0000\u00a2\u00a3\u0003\u0014\n"+
		"\u0000\u00a3\u00a4\u0005\u0019\u0000\u0000\u00a4\u00a5\u0006\u0007\uffff"+
		"\uffff\u0000\u00a5\u00ac\u0001\u0000\u0000\u0000\u00a6\u00a7\u0003\u0012"+
		"\t\u0000\u00a7\u00a8\u0003\u0010\b\u0000\u00a8\u00a9\u0005\u0019\u0000"+
		"\u0000\u00a9\u00aa\u0006\u0007\uffff\uffff\u0000\u00aa\u00ac\u0001\u0000"+
		"\u0000\u0000\u00ab\u00a1\u0001\u0000\u0000\u0000\u00ab\u00a6\u0001\u0000"+
		"\u0000\u0000\u00ac\u000f\u0001\u0000\u0000\u0000\u00ad\u00ae\u0006\b\uffff"+
		"\uffff\u0000\u00ae\u0011\u0001\u0000\u0000\u0000\u00af\u00b0\u0005\u000b"+
		"\u0000\u0000\u00b0\u00b6\u0006\t\uffff\uffff\u0000\u00b1\u00b2\u0005\f"+
		"\u0000\u0000\u00b2\u00b6\u0006\t\uffff\uffff\u0000\u00b3\u00b4\u0005\r"+
		"\u0000\u0000\u00b4\u00b6\u0006\t\uffff\uffff\u0000\u00b5\u00af\u0001\u0000"+
		"\u0000\u0000\u00b5\u00b1\u0001\u0000\u0000\u0000\u00b5\u00b3\u0001\u0000"+
		"\u0000\u0000\u00b6\u0013\u0001\u0000\u0000\u0000\u00b7\u00b8\u0006\n\uffff"+
		"\uffff\u0000\u00b8\u00b9\u0005%\u0000\u0000\u00b9\u00c0\u0006\n\uffff"+
		"\uffff\u0000\u00ba\u00bb\u0005%\u0000\u0000\u00bb\u00bc\u0005\u0017\u0000"+
		"\u0000\u00bc\u00bd\u0005&\u0000\u0000\u00bd\u00be\u0005\u0018\u0000\u0000"+
		"\u00be\u00c0\u0006\n\uffff\uffff\u0000\u00bf\u00b7\u0001\u0000\u0000\u0000"+
		"\u00bf\u00ba\u0001\u0000\u0000\u0000\u00c0\u00d2\u0001\u0000\u0000\u0000"+
		"\u00c1\u00c2\n\u0005\u0000\u0000\u00c2\u00c3\u0005\u001a\u0000\u0000\u00c3"+
		"\u00c4\u0005%\u0000\u0000\u00c4\u00d1\u0006\n\uffff\uffff\u0000\u00c5"+
		"\u00c6\n\u0004\u0000\u0000\u00c6\u00c7\u0005\u001a\u0000\u0000\u00c7\u00c8"+
		"\u0005%\u0000\u0000\u00c8\u00c9\u0005\u0017\u0000\u0000\u00c9\u00ca\u0005"+
		"&\u0000\u0000\u00ca\u00cb\u0005\u0018\u0000\u0000\u00cb\u00d1\u0006\n"+
		"\uffff\uffff\u0000\u00cc\u00cd\n\u0001\u0000\u0000\u00cd\u00ce\u0005\u001c"+
		"\u0000\u0000\u00ce\u00cf\u0005%\u0000\u0000\u00cf\u00d1\u0006\n\uffff"+
		"\uffff\u0000\u00d0\u00c1\u0001\u0000\u0000\u0000\u00d0\u00c5\u0001\u0000"+
		"\u0000\u0000\u00d0\u00cc\u0001\u0000\u0000\u0000\u00d1\u00d4\u0001\u0000"+
		"\u0000\u0000\u00d2\u00d0\u0001\u0000\u0000\u0000\u00d2\u00d3\u0001\u0000"+
		"\u0000\u0000\u00d3\u0015\u0001\u0000\u0000\u0000\u00d4\u00d2\u0001\u0000"+
		"\u0000\u0000\u00d5\u00d6\u0006\u000b\uffff\uffff\u0000\u00d6\u00d7\u0003"+
		"\u0018\f\u0000\u00d7\u00d8\u0006\u000b\uffff\uffff\u0000\u00d8\u00ea\u0001"+
		"\u0000\u0000\u0000\u00d9\u00da\n\u0003\u0000\u0000\u00da\u00db\u0003\u0018"+
		"\f\u0000\u00db\u00dc\u0006\u000b\uffff\uffff\u0000\u00dc\u00e9\u0001\u0000"+
		"\u0000\u0000\u00dd\u00de\n\u0002\u0000\u0000\u00de\u00df\u0003 \u0010"+
		"\u0000\u00df\u00e0\u0005$\u0000\u0000\u00e0\u00e1\u0003*\u0015\u0000\u00e1"+
		"\u00e2\u0006\u000b\uffff\uffff\u0000\u00e2\u00e9\u0001\u0000\u0000\u0000"+
		"\u00e3\u00e4\n\u0001\u0000\u0000\u00e4\u00e5\u0003\"\u0011\u0000\u00e5"+
		"\u00e6\u0005(\u0000\u0000\u00e6\u00e7\u0006\u000b\uffff\uffff\u0000\u00e7"+
		"\u00e9\u0001\u0000\u0000\u0000\u00e8\u00d9\u0001\u0000\u0000\u0000\u00e8"+
		"\u00dd\u0001\u0000\u0000\u0000\u00e8\u00e3\u0001\u0000\u0000\u0000\u00e9"+
		"\u00ec\u0001\u0000\u0000\u0000\u00ea\u00e8\u0001\u0000\u0000\u0000\u00ea"+
		"\u00eb\u0001\u0000\u0000\u0000\u00eb\u0017\u0001\u0000\u0000\u0000\u00ec"+
		"\u00ea\u0001\u0000\u0000\u0000\u00ed\u00ee\u0003\u000e\u0007\u0000\u00ee"+
		"\u00ef\u0006\f\uffff\uffff\u0000\u00ef\u013e\u0001\u0000\u0000\u0000\u00f0"+
		"\u00f1\u0003\u001e\u000f\u0000\u00f1\u00f2\u0006\f\uffff\uffff\u0000\u00f2"+
		"\u013e\u0001\u0000\u0000\u0000\u00f3\u00f4\u0003\f\u0006\u0000\u00f4\u00f5"+
		"\u0006\f\uffff\uffff\u0000\u00f5\u013e\u0001\u0000\u0000\u0000\u00f6\u00f7"+
		"\u0005\u0007\u0000\u0000\u00f7\u00f8\u0005\u0013\u0000\u0000\u00f8\u00f9"+
		"\u0003\u001e\u000f\u0000\u00f9\u00fa\u0006\f\uffff\uffff\u0000\u00fa\u00fb"+
		"\u0003\u001e\u000f\u0000\u00fb\u00fc\u0006\f\uffff\uffff\u0000\u00fc\u00fd"+
		"\u0003\"\u0011\u0000\u00fd\u00fe\u0005\u0014\u0000\u0000\u00fe\u00ff\u0006"+
		"\f\uffff\uffff\u0000\u00ff\u0100\u0003\u0018\f\u0000\u0100\u0101\u0006"+
		"\f\uffff\uffff\u0000\u0101\u013e\u0001\u0000\u0000\u0000\u0102\u0103\u0005"+
		"\u0005\u0000\u0000\u0103\u0104\u0005\u0013\u0000\u0000\u0104\u0105\u0006"+
		"\f\uffff\uffff\u0000\u0105\u0106\u0003\"\u0011\u0000\u0106\u0107\u0005"+
		"\u0014\u0000\u0000\u0107\u0108\u0006\f\uffff\uffff\u0000\u0108\u0109\u0003"+
		"\u0018\f\u0000\u0109\u010a\u0006\f\uffff\uffff\u0000\u010a\u013e\u0001"+
		"\u0000\u0000\u0000\u010b\u010c\u0005\u0005\u0000\u0000\u010c\u010d\u0005"+
		"\u0013\u0000\u0000\u010d\u010e\u0006\f\uffff\uffff\u0000\u010e\u010f\u0003"+
		"\"\u0011\u0000\u010f\u0110\u0005\u0014\u0000\u0000\u0110\u0111\u0006\f"+
		"\uffff\uffff\u0000\u0111\u0112\u0003\u0018\f\u0000\u0112\u0113\u0006\f"+
		"\uffff\uffff\u0000\u0113\u0114\u0005\u0006\u0000\u0000\u0114\u0115\u0006"+
		"\f\uffff\uffff\u0000\u0115\u0116\u0003\u0018\f\u0000\u0116\u0117\u0006"+
		"\f\uffff\uffff\u0000\u0117\u013e\u0001\u0000\u0000\u0000\u0118\u0119\u0005"+
		"\b\u0000\u0000\u0119\u011a\u0005\u0013\u0000\u0000\u011a\u011b\u0006\f"+
		"\uffff\uffff\u0000\u011b\u011c\u0003\"\u0011\u0000\u011c\u011d\u0005\u0014"+
		"\u0000\u0000\u011d\u011e\u0006\f\uffff\uffff\u0000\u011e\u011f\u0003\u0018"+
		"\f\u0000\u011f\u0120\u0006\f\uffff\uffff\u0000\u0120\u013e\u0001\u0000"+
		"\u0000\u0000\u0121\u0122\u0005\t\u0000\u0000\u0122\u0123\u0005\u0013\u0000"+
		"\u0000\u0123\u0124\u0005%\u0000\u0000\u0124\u0125\u0005\u0014\u0000\u0000"+
		"\u0125\u0126\u0005\u0019\u0000\u0000\u0126\u013e\u0006\f\uffff\uffff\u0000"+
		"\u0127\u0128\u0005\n\u0000\u0000\u0128\u0129\u0003\"\u0011\u0000\u0129"+
		"\u012a\u0005\u0019\u0000\u0000\u012a\u012b\u0006\f\uffff\uffff\u0000\u012b"+
		"\u013e\u0001\u0000\u0000\u0000\u012c\u012d\u0005\u000e\u0000\u0000\u012d"+
		"\u012e\u0005\u0013\u0000\u0000\u012e\u012f\u0003\"\u0011\u0000\u012f\u0130"+
		"\u0005\u0014\u0000\u0000\u0130\u0131\u0006\f\uffff\uffff\u0000\u0131\u0132"+
		"\u0005\u0015\u0000\u0000\u0132\u0133\u0003\u001a\r\u0000\u0133\u0134\u0005"+
		"\u0016\u0000\u0000\u0134\u0135\u0006\f\uffff\uffff\u0000\u0135\u013e\u0001"+
		"\u0000\u0000\u0000\u0136\u0137\u0005%\u0000\u0000\u0137\u0138\u0005\u001b"+
		"\u0000\u0000\u0138\u013e\u0006\f\uffff\uffff\u0000\u0139\u013a\u0005\u0012"+
		"\u0000\u0000\u013a\u013b\u0005%\u0000\u0000\u013b\u013c\u0005\u0019\u0000"+
		"\u0000\u013c\u013e\u0006\f\uffff\uffff\u0000\u013d\u00ed\u0001\u0000\u0000"+
		"\u0000\u013d\u00f0\u0001\u0000\u0000\u0000\u013d\u00f3\u0001\u0000\u0000"+
		"\u0000\u013d\u00f6\u0001\u0000\u0000\u0000\u013d\u0102\u0001\u0000\u0000"+
		"\u0000\u013d\u010b\u0001\u0000\u0000\u0000\u013d\u0118\u0001\u0000\u0000"+
		"\u0000\u013d\u0121\u0001\u0000\u0000\u0000\u013d\u0127\u0001\u0000\u0000"+
		"\u0000\u013d\u012c\u0001\u0000\u0000\u0000\u013d\u0136\u0001\u0000\u0000"+
		"\u0000\u013d\u0139\u0001\u0000\u0000\u0000\u013e\u0019\u0001\u0000\u0000"+
		"\u0000\u013f\u0140\u0006\r\uffff\uffff\u0000\u0140\u0141\u0003\u001c\u000e"+
		"\u0000\u0141\u0142\u0006\r\uffff\uffff\u0000\u0142\u0149\u0001\u0000\u0000"+
		"\u0000\u0143\u0144\n\u0001\u0000\u0000\u0144\u0145\u0003\u001c\u000e\u0000"+
		"\u0145\u0146\u0006\r\uffff\uffff\u0000\u0146\u0148\u0001\u0000\u0000\u0000"+
		"\u0147\u0143\u0001\u0000\u0000\u0000\u0148\u014b\u0001\u0000\u0000\u0000"+
		"\u0149\u0147\u0001\u0000\u0000\u0000\u0149\u014a\u0001\u0000\u0000\u0000"+
		"\u014a\u001b\u0001\u0000\u0000\u0000\u014b\u0149\u0001\u0000\u0000\u0000"+
		"\u014c\u014d\u0005\u000f\u0000\u0000\u014d\u014e\u0005&\u0000\u0000\u014e"+
		"\u014f\u0005\u001b\u0000\u0000\u014f\u0150\u0003\u0016\u000b\u0000\u0150"+
		"\u0151\u0005\u0011\u0000\u0000\u0151\u0152\u0005\u0019\u0000\u0000\u0152"+
		"\u0153\u0006\u000e\uffff\uffff\u0000\u0153\u015c\u0001\u0000\u0000\u0000"+
		"\u0154\u0155\u0005\u0010\u0000\u0000\u0155\u0156\u0005\u001b\u0000\u0000"+
		"\u0156\u0157\u0003\u0016\u000b\u0000\u0157\u0158\u0005\u0011\u0000\u0000"+
		"\u0158\u0159\u0005\u0019\u0000\u0000\u0159\u015a\u0006\u000e\uffff\uffff"+
		"\u0000\u015a\u015c\u0001\u0000\u0000\u0000\u015b\u014c\u0001\u0000\u0000"+
		"\u0000\u015b\u0154\u0001\u0000\u0000\u0000\u015c\u001d\u0001\u0000\u0000"+
		"\u0000\u015d\u015e\u0005\u0019\u0000\u0000\u015e\u0164\u0006\u000f\uffff"+
		"\uffff\u0000\u015f\u0160\u0003\"\u0011\u0000\u0160\u0161\u0005\u0019\u0000"+
		"\u0000\u0161\u0162\u0006\u000f\uffff\uffff\u0000\u0162\u0164\u0001\u0000"+
		"\u0000\u0000\u0163\u015d\u0001\u0000\u0000\u0000\u0163\u015f\u0001\u0000"+
		"\u0000\u0000\u0164\u001f\u0001\u0000\u0000\u0000\u0165\u0166\u0005%\u0000"+
		"\u0000\u0166\u016e\u0006\u0010\uffff\uffff\u0000\u0167\u0168\u0005%\u0000"+
		"\u0000\u0168\u0169\u0005\u0017\u0000\u0000\u0169\u016a\u0003\"\u0011\u0000"+
		"\u016a\u016b\u0005\u0018\u0000\u0000\u016b\u016c\u0006\u0010\uffff\uffff"+
		"\u0000\u016c\u016e\u0001\u0000\u0000\u0000\u016d\u0165\u0001\u0000\u0000"+
		"\u0000\u016d\u0167\u0001\u0000\u0000\u0000\u016e!\u0001\u0000\u0000\u0000"+
		"\u016f\u0170\u0003$\u0012\u0000\u0170\u0171\u0006\u0011\uffff\uffff\u0000"+
		"\u0171\u0179\u0001\u0000\u0000\u0000\u0172\u0173\u0003 \u0010\u0000\u0173"+
		"\u0174\u0005$\u0000\u0000\u0174\u0175\u0006\u0011\uffff\uffff\u0000\u0175"+
		"\u0176\u0003$\u0012\u0000\u0176\u0177\u0006\u0011\uffff\uffff\u0000\u0177"+
		"\u0179\u0001\u0000\u0000\u0000\u0178\u016f\u0001\u0000\u0000\u0000\u0178"+
		"\u0172\u0001\u0000\u0000\u0000\u0179#\u0001\u0000\u0000\u0000\u017a\u017b"+
		"\u0003&\u0013\u0000\u017b\u017c\u0006\u0012\uffff\uffff\u0000\u017c\u0183"+
		"\u0001\u0000\u0000\u0000\u017d\u017e\u0003&\u0013\u0000\u017e\u017f\u0005"+
		"#\u0000\u0000\u017f\u0180\u0003&\u0013\u0000\u0180\u0181\u0006\u0012\uffff"+
		"\uffff\u0000\u0181\u0183\u0001\u0000\u0000\u0000\u0182\u017a\u0001\u0000"+
		"\u0000\u0000\u0182\u017d\u0001\u0000\u0000\u0000\u0183%\u0001\u0000\u0000"+
		"\u0000\u0184\u0185\u0003(\u0014\u0000\u0185\u0186\u0006\u0013\uffff\uffff"+
		"\u0000\u0186\u018d\u0001\u0000\u0000\u0000\u0187\u0188\u0003(\u0014\u0000"+
		"\u0188\u0189\u0005\"\u0000\u0000\u0189\u018a\u0003(\u0014\u0000\u018a"+
		"\u018b\u0006\u0013\uffff\uffff\u0000\u018b\u018d\u0001\u0000\u0000\u0000"+
		"\u018c\u0184\u0001\u0000\u0000\u0000\u018c\u0187\u0001\u0000\u0000\u0000"+
		"\u018d\'\u0001\u0000\u0000\u0000\u018e\u018f\u0006\u0014\uffff\uffff\u0000"+
		"\u018f\u0190\u0003,\u0016\u0000\u0190\u0191\u0006\u0014\uffff\uffff\u0000"+
		"\u0191\u0199\u0001\u0000\u0000\u0000\u0192\u0193\n\u0001\u0000\u0000\u0193"+
		"\u0194\u0005\u001c\u0000\u0000\u0194\u0195\u0003,\u0016\u0000\u0195\u0196"+
		"\u0006\u0014\uffff\uffff\u0000\u0196\u0198\u0001\u0000\u0000\u0000\u0197"+
		"\u0192\u0001\u0000\u0000\u0000\u0198\u019b\u0001\u0000\u0000\u0000\u0199"+
		"\u0197\u0001\u0000\u0000\u0000\u0199\u019a\u0001\u0000\u0000\u0000\u019a"+
		")\u0001\u0000\u0000\u0000\u019b\u0199\u0001\u0000\u0000\u0000\u019c\u019d"+
		"\u0003(\u0014\u0000\u019d\u019e\u0005\u001c\u0000\u0000\u019e\u019f\u0005"+
		"$\u0000\u0000\u019f\u01a0\u0006\u0015\uffff\uffff\u0000\u01a0+\u0001\u0000"+
		"\u0000\u0000\u01a1\u01a2\u0006\u0016\uffff\uffff\u0000\u01a2\u01a3\u0003"+
		".\u0017\u0000\u01a3\u01a4\u0006\u0016\uffff\uffff\u0000\u01a4\u01ac\u0001"+
		"\u0000\u0000\u0000\u01a5\u01a6\n\u0001\u0000\u0000\u01a6\u01a7\u0005\u001e"+
		"\u0000\u0000\u01a7\u01a8\u0003.\u0017\u0000\u01a8\u01a9\u0006\u0016\uffff"+
		"\uffff\u0000\u01a9\u01ab\u0001\u0000\u0000\u0000\u01aa\u01a5\u0001\u0000"+
		"\u0000\u0000\u01ab\u01ae\u0001\u0000\u0000\u0000\u01ac\u01aa\u0001\u0000"+
		"\u0000\u0000\u01ac\u01ad\u0001\u0000\u0000\u0000\u01ad-\u0001\u0000\u0000"+
		"\u0000\u01ae\u01ac\u0001\u0000\u0000\u0000\u01af\u01b0\u0005\u001c\u0000"+
		"\u0000\u01b0\u01b1\u0003.\u0017\u0000\u01b1\u01b2\u0006\u0017\uffff\uffff"+
		"\u0000\u01b2\u01bb\u0001\u0000\u0000\u0000\u01b3\u01b4\u0005!\u0000\u0000"+
		"\u01b4\u01b5\u0003.\u0017\u0000\u01b5\u01b6\u0006\u0017\uffff\uffff\u0000"+
		"\u01b6\u01bb\u0001\u0000\u0000\u0000\u01b7\u01b8\u00030\u0018\u0000\u01b8"+
		"\u01b9\u0006\u0017\uffff\uffff\u0000\u01b9\u01bb\u0001\u0000\u0000\u0000"+
		"\u01ba\u01af\u0001\u0000\u0000\u0000\u01ba\u01b3\u0001\u0000\u0000\u0000"+
		"\u01ba\u01b7\u0001\u0000\u0000\u0000\u01bb/\u0001\u0000\u0000\u0000\u01bc"+
		"\u01bd\u0003 \u0010\u0000\u01bd\u01be\u0006\u0018\uffff\uffff\u0000\u01be"+
		"\u01d7\u0001\u0000\u0000\u0000\u01bf\u01c0\u0005%\u0000\u0000\u01c0\u01c1"+
		"\u0005\u0013\u0000\u0000\u01c1\u01c2\u00032\u0019\u0000\u01c2\u01c3\u0005"+
		"\u0014\u0000\u0000\u01c3\u01c4\u0006\u0018\uffff\uffff\u0000\u01c4\u01d7"+
		"\u0001\u0000\u0000\u0000\u01c5\u01c6\u0005\u0013\u0000\u0000\u01c6\u01c7"+
		"\u0003\"\u0011\u0000\u01c7\u01c8\u0005\u0014\u0000\u0000\u01c8\u01c9\u0006"+
		"\u0018\uffff\uffff\u0000\u01c9\u01d7\u0001\u0000\u0000\u0000\u01ca\u01cb"+
		"\u0005&\u0000\u0000\u01cb\u01d7\u0006\u0018\uffff\uffff\u0000\u01cc\u01cd"+
		"\u0005\'\u0000\u0000\u01cd\u01d7\u0006\u0018\uffff\uffff\u0000\u01ce\u01cf"+
		"\u0003 \u0010\u0000\u01cf\u01d0\u0005\u001f\u0000\u0000\u01d0\u01d1\u0006"+
		"\u0018\uffff\uffff\u0000\u01d1\u01d7\u0001\u0000\u0000\u0000\u01d2\u01d3"+
		"\u0003 \u0010\u0000\u01d3\u01d4\u0005 \u0000\u0000\u01d4\u01d5\u0006\u0018"+
		"\uffff\uffff\u0000\u01d5\u01d7\u0001\u0000\u0000\u0000\u01d6\u01bc\u0001"+
		"\u0000\u0000\u0000\u01d6\u01bf\u0001\u0000\u0000\u0000\u01d6\u01c5\u0001"+
		"\u0000\u0000\u0000\u01d6\u01ca\u0001\u0000\u0000\u0000\u01d6\u01cc\u0001"+
		"\u0000\u0000\u0000\u01d6\u01ce\u0001\u0000\u0000\u0000\u01d6\u01d2\u0001"+
		"\u0000\u0000\u0000\u01d71\u0001\u0000\u0000\u0000\u01d8\u01d9\u00034\u001a"+
		"\u0000\u01d9\u01da\u0006\u0019\uffff\uffff\u0000\u01da\u01dd\u0001\u0000"+
		"\u0000\u0000\u01db\u01dd\u0006\u0019\uffff\uffff\u0000\u01dc\u01d8\u0001"+
		"\u0000\u0000\u0000\u01dc\u01db\u0001\u0000\u0000\u0000\u01dd3\u0001\u0000"+
		"\u0000\u0000\u01de\u01df\u0006\u001a\uffff\uffff\u0000\u01df\u01e0\u0003"+
		"$\u0012\u0000\u01e0\u01e1\u0006\u001a\uffff\uffff\u0000\u01e1\u01e9\u0001"+
		"\u0000\u0000\u0000\u01e2\u01e3\n\u0002\u0000\u0000\u01e3\u01e4\u0005\u001a"+
		"\u0000\u0000\u01e4\u01e5\u0003$\u0012\u0000\u01e5\u01e6\u0006\u001a\uffff"+
		"\uffff\u0000\u01e6\u01e8\u0001\u0000\u0000\u0000\u01e7\u01e2\u0001\u0000"+
		"\u0000\u0000\u01e8\u01eb\u0001\u0000\u0000\u0000\u01e9\u01e7\u0001\u0000"+
		"\u0000\u0000\u01e9\u01ea\u0001\u0000\u0000\u0000\u01ea5\u0001\u0000\u0000"+
		"\u0000\u01eb\u01e9\u0001\u0000\u0000\u0000\u001dCO`v\u0084\u0091\u0093"+
		"\u009f\u00ab\u00b5\u00bf\u00d0\u00d2\u00e8\u00ea\u013d\u0149\u015b\u0163"+
		"\u016d\u0178\u0182\u018c\u0199\u01ac\u01ba\u01d6\u01dc\u01e9";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}