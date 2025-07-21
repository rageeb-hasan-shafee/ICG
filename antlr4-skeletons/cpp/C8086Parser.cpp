
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


#include "C8086ParserListener.h"

#include "C8086Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C8086ParserStaticData final {
  C8086ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C8086ParserStaticData(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData(C8086ParserStaticData&&) = delete;
  C8086ParserStaticData& operator=(const C8086ParserStaticData&) = delete;
  C8086ParserStaticData& operator=(C8086ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c8086parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C8086ParserStaticData> c8086parserParserStaticData = nullptr;

void c8086parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c8086parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c8086parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C8086ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "declaration_list_err", 
      "type_specifier", "declaration_list", "statements", "statement", "case_statements", 
      "case_statement", "expression_statement", "variable", "expression", 
      "logic_expression", "rel_expression", "simple_expression", "simple_expression_err", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
      "'return'", "'int'", "'float'", "'void'", "'switch'", "'case'", "'default'", 
      "'break'", "'goto'", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", 
      "','", "':'", "", "", "", "'++'", "'--'", "'!'", "", "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "SWITCH", 
      "CASE", "DEFAULT", "BREAK", "GOTO", "LPAREN", "RPAREN", "LCURL", "RCURL", 
      "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", "COLON", "ADDOP", "SUBOP", 
      "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_INT", "CONST_FLOAT", "INVALID_CHAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,40,493,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,1,0,1,0,1,0,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,66,8,1,10,1,12,1,69,9,1,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,3,2,80,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,3,3,97,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,119,8,4,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,133,8,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,5,5,146,8,5,10,5,12,5,149,9,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,3,6,160,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	3,7,172,8,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,3,9,182,8,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,3,10,192,8,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,209,8,10,10,10,12,10,
  	212,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,233,8,11,10,11,12,11,236,9,11,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,318,8,12,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,5,13,328,8,13,10,13,12,13,331,9,13,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,3,14,348,8,14,1,15,1,15,1,15,1,15,1,15,1,15,3,15,356,8,15,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,366,8,16,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,3,17,377,8,17,1,18,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,3,18,387,8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,397,
  	8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,408,8,20,10,20,
  	12,20,411,9,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,5,22,427,8,22,10,22,12,22,430,9,22,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,443,8,23,1,24,1,24,1,24,1,24,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,24,471,8,24,1,25,1,25,1,25,
  	1,25,3,25,477,8,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,5,26,
  	488,8,26,10,26,12,26,491,9,26,1,26,0,8,2,10,20,22,26,40,44,52,27,0,2,
  	4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,
  	52,0,0,515,0,54,1,0,0,0,2,57,1,0,0,0,4,79,1,0,0,0,6,96,1,0,0,0,8,118,
  	1,0,0,0,10,132,1,0,0,0,12,159,1,0,0,0,14,171,1,0,0,0,16,173,1,0,0,0,18,
  	181,1,0,0,0,20,191,1,0,0,0,22,213,1,0,0,0,24,317,1,0,0,0,26,319,1,0,0,
  	0,28,347,1,0,0,0,30,355,1,0,0,0,32,365,1,0,0,0,34,376,1,0,0,0,36,386,
  	1,0,0,0,38,396,1,0,0,0,40,398,1,0,0,0,42,412,1,0,0,0,44,417,1,0,0,0,46,
  	442,1,0,0,0,48,470,1,0,0,0,50,476,1,0,0,0,52,478,1,0,0,0,54,55,3,2,1,
  	0,55,56,6,0,-1,0,56,1,1,0,0,0,57,58,6,1,-1,0,58,59,3,4,2,0,59,60,6,1,
  	-1,0,60,67,1,0,0,0,61,62,10,2,0,0,62,63,3,4,2,0,63,64,6,1,-1,0,64,66,
  	1,0,0,0,65,61,1,0,0,0,66,69,1,0,0,0,67,65,1,0,0,0,67,68,1,0,0,0,68,3,
  	1,0,0,0,69,67,1,0,0,0,70,71,3,14,7,0,71,72,6,2,-1,0,72,80,1,0,0,0,73,
  	74,3,6,3,0,74,75,6,2,-1,0,75,80,1,0,0,0,76,77,3,8,4,0,77,78,6,2,-1,0,
  	78,80,1,0,0,0,79,70,1,0,0,0,79,73,1,0,0,0,79,76,1,0,0,0,80,5,1,0,0,0,
  	81,82,3,18,9,0,82,83,5,37,0,0,83,84,5,19,0,0,84,85,3,10,5,0,85,86,5,20,
  	0,0,86,87,5,25,0,0,87,88,6,3,-1,0,88,97,1,0,0,0,89,90,3,18,9,0,90,91,
  	5,37,0,0,91,92,5,19,0,0,92,93,5,20,0,0,93,94,5,25,0,0,94,95,6,3,-1,0,
  	95,97,1,0,0,0,96,81,1,0,0,0,96,89,1,0,0,0,97,7,1,0,0,0,98,99,3,18,9,0,
  	99,100,5,37,0,0,100,101,6,4,-1,0,101,102,5,19,0,0,102,103,6,4,-1,0,103,
  	104,3,10,5,0,104,105,5,20,0,0,105,106,6,4,-1,0,106,107,3,12,6,0,107,108,
  	6,4,-1,0,108,119,1,0,0,0,109,110,3,18,9,0,110,111,5,37,0,0,111,112,6,
  	4,-1,0,112,113,5,19,0,0,113,114,5,20,0,0,114,115,6,4,-1,0,115,116,3,12,
  	6,0,116,117,6,4,-1,0,117,119,1,0,0,0,118,98,1,0,0,0,118,109,1,0,0,0,119,
  	9,1,0,0,0,120,121,6,5,-1,0,121,122,3,18,9,0,122,123,5,37,0,0,123,124,
  	6,5,-1,0,124,133,1,0,0,0,125,126,3,18,9,0,126,127,6,5,-1,0,127,133,1,
  	0,0,0,128,129,3,18,9,0,129,130,5,28,0,0,130,131,6,5,-1,0,131,133,1,0,
  	0,0,132,120,1,0,0,0,132,125,1,0,0,0,132,128,1,0,0,0,133,147,1,0,0,0,134,
  	135,10,5,0,0,135,136,5,26,0,0,136,137,3,18,9,0,137,138,5,37,0,0,138,139,
  	6,5,-1,0,139,146,1,0,0,0,140,141,10,4,0,0,141,142,5,26,0,0,142,143,3,
  	18,9,0,143,144,6,5,-1,0,144,146,1,0,0,0,145,134,1,0,0,0,145,140,1,0,0,
  	0,146,149,1,0,0,0,147,145,1,0,0,0,147,148,1,0,0,0,148,11,1,0,0,0,149,
  	147,1,0,0,0,150,151,5,21,0,0,151,152,6,6,-1,0,152,153,3,22,11,0,153,154,
  	5,22,0,0,154,155,6,6,-1,0,155,160,1,0,0,0,156,157,5,21,0,0,157,158,5,
  	22,0,0,158,160,6,6,-1,0,159,150,1,0,0,0,159,156,1,0,0,0,160,13,1,0,0,
  	0,161,162,3,18,9,0,162,163,3,20,10,0,163,164,5,25,0,0,164,165,6,7,-1,
  	0,165,172,1,0,0,0,166,167,3,18,9,0,167,168,3,16,8,0,168,169,5,25,0,0,
  	169,170,6,7,-1,0,170,172,1,0,0,0,171,161,1,0,0,0,171,166,1,0,0,0,172,
  	15,1,0,0,0,173,174,6,8,-1,0,174,17,1,0,0,0,175,176,5,11,0,0,176,182,6,
  	9,-1,0,177,178,5,12,0,0,178,182,6,9,-1,0,179,180,5,13,0,0,180,182,6,9,
  	-1,0,181,175,1,0,0,0,181,177,1,0,0,0,181,179,1,0,0,0,182,19,1,0,0,0,183,
  	184,6,10,-1,0,184,185,5,37,0,0,185,192,6,10,-1,0,186,187,5,37,0,0,187,
  	188,5,23,0,0,188,189,5,38,0,0,189,190,5,24,0,0,190,192,6,10,-1,0,191,
  	183,1,0,0,0,191,186,1,0,0,0,192,210,1,0,0,0,193,194,10,5,0,0,194,195,
  	5,26,0,0,195,196,5,37,0,0,196,209,6,10,-1,0,197,198,10,4,0,0,198,199,
  	5,26,0,0,199,200,5,37,0,0,200,201,5,23,0,0,201,202,5,38,0,0,202,203,5,
  	24,0,0,203,209,6,10,-1,0,204,205,10,1,0,0,205,206,5,28,0,0,206,207,5,
  	37,0,0,207,209,6,10,-1,0,208,193,1,0,0,0,208,197,1,0,0,0,208,204,1,0,
  	0,0,209,212,1,0,0,0,210,208,1,0,0,0,210,211,1,0,0,0,211,21,1,0,0,0,212,
  	210,1,0,0,0,213,214,6,11,-1,0,214,215,3,24,12,0,215,216,6,11,-1,0,216,
  	234,1,0,0,0,217,218,10,3,0,0,218,219,3,24,12,0,219,220,6,11,-1,0,220,
  	233,1,0,0,0,221,222,10,2,0,0,222,223,3,32,16,0,223,224,5,36,0,0,224,225,
  	3,42,21,0,225,226,6,11,-1,0,226,233,1,0,0,0,227,228,10,1,0,0,228,229,
  	3,34,17,0,229,230,5,40,0,0,230,231,6,11,-1,0,231,233,1,0,0,0,232,217,
  	1,0,0,0,232,221,1,0,0,0,232,227,1,0,0,0,233,236,1,0,0,0,234,232,1,0,0,
  	0,234,235,1,0,0,0,235,23,1,0,0,0,236,234,1,0,0,0,237,238,3,14,7,0,238,
  	239,6,12,-1,0,239,318,1,0,0,0,240,241,3,30,15,0,241,242,6,12,-1,0,242,
  	318,1,0,0,0,243,244,3,12,6,0,244,245,6,12,-1,0,245,318,1,0,0,0,246,247,
  	5,7,0,0,247,248,5,19,0,0,248,249,3,30,15,0,249,250,6,12,-1,0,250,251,
  	3,30,15,0,251,252,6,12,-1,0,252,253,3,34,17,0,253,254,5,20,0,0,254,255,
  	6,12,-1,0,255,256,3,24,12,0,256,257,6,12,-1,0,257,318,1,0,0,0,258,259,
  	5,5,0,0,259,260,5,19,0,0,260,261,6,12,-1,0,261,262,3,34,17,0,262,263,
  	5,20,0,0,263,264,6,12,-1,0,264,265,3,24,12,0,265,266,6,12,-1,0,266,318,
  	1,0,0,0,267,268,5,5,0,0,268,269,5,19,0,0,269,270,6,12,-1,0,270,271,3,
  	34,17,0,271,272,5,20,0,0,272,273,6,12,-1,0,273,274,3,24,12,0,274,275,
  	6,12,-1,0,275,276,5,6,0,0,276,277,6,12,-1,0,277,278,3,24,12,0,278,279,
  	6,12,-1,0,279,318,1,0,0,0,280,281,5,8,0,0,281,282,5,19,0,0,282,283,6,
  	12,-1,0,283,284,3,34,17,0,284,285,5,20,0,0,285,286,6,12,-1,0,286,287,
  	3,24,12,0,287,288,6,12,-1,0,288,318,1,0,0,0,289,290,5,9,0,0,290,291,5,
  	19,0,0,291,292,5,37,0,0,292,293,5,20,0,0,293,294,5,25,0,0,294,318,6,12,
  	-1,0,295,296,5,10,0,0,296,297,3,34,17,0,297,298,5,25,0,0,298,299,6,12,
  	-1,0,299,318,1,0,0,0,300,301,5,14,0,0,301,302,5,19,0,0,302,303,3,34,17,
  	0,303,304,5,20,0,0,304,305,6,12,-1,0,305,306,5,21,0,0,306,307,3,26,13,
  	0,307,308,5,22,0,0,308,309,6,12,-1,0,309,318,1,0,0,0,310,311,5,37,0,0,
  	311,312,5,27,0,0,312,318,6,12,-1,0,313,314,5,18,0,0,314,315,5,37,0,0,
  	315,316,5,25,0,0,316,318,6,12,-1,0,317,237,1,0,0,0,317,240,1,0,0,0,317,
  	243,1,0,0,0,317,246,1,0,0,0,317,258,1,0,0,0,317,267,1,0,0,0,317,280,1,
  	0,0,0,317,289,1,0,0,0,317,295,1,0,0,0,317,300,1,0,0,0,317,310,1,0,0,0,
  	317,313,1,0,0,0,318,25,1,0,0,0,319,320,6,13,-1,0,320,321,3,28,14,0,321,
  	322,6,13,-1,0,322,329,1,0,0,0,323,324,10,1,0,0,324,325,3,28,14,0,325,
  	326,6,13,-1,0,326,328,1,0,0,0,327,323,1,0,0,0,328,331,1,0,0,0,329,327,
  	1,0,0,0,329,330,1,0,0,0,330,27,1,0,0,0,331,329,1,0,0,0,332,333,5,15,0,
  	0,333,334,5,38,0,0,334,335,5,27,0,0,335,336,3,22,11,0,336,337,5,17,0,
  	0,337,338,5,25,0,0,338,339,6,14,-1,0,339,348,1,0,0,0,340,341,5,16,0,0,
  	341,342,5,27,0,0,342,343,3,22,11,0,343,344,5,17,0,0,344,345,5,25,0,0,
  	345,346,6,14,-1,0,346,348,1,0,0,0,347,332,1,0,0,0,347,340,1,0,0,0,348,
  	29,1,0,0,0,349,350,5,25,0,0,350,356,6,15,-1,0,351,352,3,34,17,0,352,353,
  	5,25,0,0,353,354,6,15,-1,0,354,356,1,0,0,0,355,349,1,0,0,0,355,351,1,
  	0,0,0,356,31,1,0,0,0,357,358,5,37,0,0,358,366,6,16,-1,0,359,360,5,37,
  	0,0,360,361,5,23,0,0,361,362,3,34,17,0,362,363,5,24,0,0,363,364,6,16,
  	-1,0,364,366,1,0,0,0,365,357,1,0,0,0,365,359,1,0,0,0,366,33,1,0,0,0,367,
  	368,3,36,18,0,368,369,6,17,-1,0,369,377,1,0,0,0,370,371,3,32,16,0,371,
  	372,5,36,0,0,372,373,6,17,-1,0,373,374,3,36,18,0,374,375,6,17,-1,0,375,
  	377,1,0,0,0,376,367,1,0,0,0,376,370,1,0,0,0,377,35,1,0,0,0,378,379,3,
  	38,19,0,379,380,6,18,-1,0,380,387,1,0,0,0,381,382,3,38,19,0,382,383,5,
  	35,0,0,383,384,3,38,19,0,384,385,6,18,-1,0,385,387,1,0,0,0,386,378,1,
  	0,0,0,386,381,1,0,0,0,387,37,1,0,0,0,388,389,3,40,20,0,389,390,6,19,-1,
  	0,390,397,1,0,0,0,391,392,3,40,20,0,392,393,5,34,0,0,393,394,3,40,20,
  	0,394,395,6,19,-1,0,395,397,1,0,0,0,396,388,1,0,0,0,396,391,1,0,0,0,397,
  	39,1,0,0,0,398,399,6,20,-1,0,399,400,3,44,22,0,400,401,6,20,-1,0,401,
  	409,1,0,0,0,402,403,10,1,0,0,403,404,5,28,0,0,404,405,3,44,22,0,405,406,
  	6,20,-1,0,406,408,1,0,0,0,407,402,1,0,0,0,408,411,1,0,0,0,409,407,1,0,
  	0,0,409,410,1,0,0,0,410,41,1,0,0,0,411,409,1,0,0,0,412,413,3,40,20,0,
  	413,414,5,28,0,0,414,415,5,36,0,0,415,416,6,21,-1,0,416,43,1,0,0,0,417,
  	418,6,22,-1,0,418,419,3,46,23,0,419,420,6,22,-1,0,420,428,1,0,0,0,421,
  	422,10,1,0,0,422,423,5,30,0,0,423,424,3,46,23,0,424,425,6,22,-1,0,425,
  	427,1,0,0,0,426,421,1,0,0,0,427,430,1,0,0,0,428,426,1,0,0,0,428,429,1,
  	0,0,0,429,45,1,0,0,0,430,428,1,0,0,0,431,432,5,28,0,0,432,433,3,46,23,
  	0,433,434,6,23,-1,0,434,443,1,0,0,0,435,436,5,33,0,0,436,437,3,46,23,
  	0,437,438,6,23,-1,0,438,443,1,0,0,0,439,440,3,48,24,0,440,441,6,23,-1,
  	0,441,443,1,0,0,0,442,431,1,0,0,0,442,435,1,0,0,0,442,439,1,0,0,0,443,
  	47,1,0,0,0,444,445,3,32,16,0,445,446,6,24,-1,0,446,471,1,0,0,0,447,448,
  	5,37,0,0,448,449,5,19,0,0,449,450,3,50,25,0,450,451,5,20,0,0,451,452,
  	6,24,-1,0,452,471,1,0,0,0,453,454,5,19,0,0,454,455,3,34,17,0,455,456,
  	5,20,0,0,456,457,6,24,-1,0,457,471,1,0,0,0,458,459,5,38,0,0,459,471,6,
  	24,-1,0,460,461,5,39,0,0,461,471,6,24,-1,0,462,463,3,32,16,0,463,464,
  	5,31,0,0,464,465,6,24,-1,0,465,471,1,0,0,0,466,467,3,32,16,0,467,468,
  	5,32,0,0,468,469,6,24,-1,0,469,471,1,0,0,0,470,444,1,0,0,0,470,447,1,
  	0,0,0,470,453,1,0,0,0,470,458,1,0,0,0,470,460,1,0,0,0,470,462,1,0,0,0,
  	470,466,1,0,0,0,471,49,1,0,0,0,472,473,3,52,26,0,473,474,6,25,-1,0,474,
  	477,1,0,0,0,475,477,6,25,-1,0,476,472,1,0,0,0,476,475,1,0,0,0,477,51,
  	1,0,0,0,478,479,6,26,-1,0,479,480,3,36,18,0,480,481,6,26,-1,0,481,489,
  	1,0,0,0,482,483,10,2,0,0,483,484,5,26,0,0,484,485,3,36,18,0,485,486,6,
  	26,-1,0,486,488,1,0,0,0,487,482,1,0,0,0,488,491,1,0,0,0,489,487,1,0,0,
  	0,489,490,1,0,0,0,490,53,1,0,0,0,491,489,1,0,0,0,29,67,79,96,118,132,
  	145,147,159,171,181,191,208,210,232,234,317,329,347,355,365,376,386,396,
  	409,428,442,470,476,489
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c8086parserParserStaticData = std::move(staticData);
}

}

C8086Parser::C8086Parser(TokenStream *input) : C8086Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C8086Parser::C8086Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C8086Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c8086parserParserStaticData->atn, c8086parserParserStaticData->decisionToDFA, c8086parserParserStaticData->sharedContextCache, options);
}

C8086Parser::~C8086Parser() {
  delete _interpreter;
}

const atn::ATN& C8086Parser::getATN() const {
  return *c8086parserParserStaticData->atn;
}

std::string C8086Parser::getGrammarFileName() const {
  return "C8086Parser.g4";
}

const std::vector<std::string>& C8086Parser::getRuleNames() const {
  return c8086parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C8086Parser::getVocabulary() const {
  return c8086parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C8086Parser::getSerializedATN() const {
  return c8086parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C8086Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ProgramContext* C8086Parser::StartContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::StartContext::getRuleIndex() const {
  return C8086Parser::RuleStart;
}

void C8086Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C8086Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C8086Parser::StartContext* C8086Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C8086Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    antlrcpp::downCast<StartContext *>(_localctx)->programContext = program(0);
            
            writeIntoparserLogFile("\nLine " + std::to_string((antlrcpp::downCast<StartContext *>(_localctx)->programContext != nullptr ? (antlrcpp::downCast<StartContext *>(_localctx)->programContext->stop) : nullptr)->getLine()) + ": start : program\n");
            
            symb.printAllScopes(parserLogFile);
            
            writeIntoparserLogFile("\nTotal number of lines: " + std::to_string((antlrcpp::downCast<StartContext *>(_localctx)->programContext != nullptr ? (antlrcpp::downCast<StartContext *>(_localctx)->programContext->stop) : nullptr)->getLine()));
            writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));
            
            writeASMToFile();
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C8086Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::UnitContext* C8086Parser::ProgramContext::unit() {
  return getRuleContext<C8086Parser::UnitContext>(0);
}

C8086Parser::ProgramContext* C8086Parser::ProgramContext::program() {
  return getRuleContext<C8086Parser::ProgramContext>(0);
}


size_t C8086Parser::ProgramContext::getRuleIndex() const {
  return C8086Parser::RuleProgram;
}

void C8086Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C8086Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C8086Parser::ProgramContext* C8086Parser::program() {
   return program(0);
}

C8086Parser::ProgramContext* C8086Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C8086Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C8086Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(58);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

            _localctx->prog_list.add(antlrcpp::downCast<ProgramContext *>(_localctx)->u->unit_val);
            writeIntoparserLogFile("\nLine " + std::to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) + ": program : unit\n");
            writeIntoparserLogFile(_localctx->prog_list.get_list_as_string() + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(67);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(61);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(62);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                          _localctx->prog_list.set_variables(antlrcpp::downCast<ProgramContext *>(_localctx)->p->prog_list.get_variables());
                          _localctx->prog_list.add(antlrcpp::downCast<ProgramContext *>(_localctx)->u->unit_val);
                          writeIntoparserLogFile("\nLine " + std::to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) + ": program : program unit\n");

                          std::string output = _localctx->prog_list.get_list_as_string();
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
                                  if (isFirstDeclarations && line.find(";") != std::string::npos) {
                                      size_t pos = 0;
                                      while ((pos = line.find(";", pos)) != std::string::npos) {
                                          std::string decl = line.substr(0, pos + 1);
                                          result += decl + "\n\n";
                                          line = line.substr(pos + 1);

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
      setState(69);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C8086Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::UnitContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

C8086Parser::Func_declarationContext* C8086Parser::UnitContext::func_declaration() {
  return getRuleContext<C8086Parser::Func_declarationContext>(0);
}

C8086Parser::Func_definitionContext* C8086Parser::UnitContext::func_definition() {
  return getRuleContext<C8086Parser::Func_definitionContext>(0);
}


size_t C8086Parser::UnitContext::getRuleIndex() const {
  return C8086Parser::RuleUnit;
}

void C8086Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C8086Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C8086Parser::UnitContext* C8086Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C8086Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(70);
      antlrcpp::downCast<UnitContext *>(_localctx)->vd = var_declaration();

              antlrcpp::downCast<UnitContext *>(_localctx)->unit_val =  antlrcpp::downCast<UnitContext *>(_localctx)->vd->var_decl;
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->vd != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->vd->start) : nullptr)->getLine()) + ": unit : var_declaration\n");
              writeIntoparserLogFile(_localctx->unit_val );
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      antlrcpp::downCast<UnitContext *>(_localctx)->fd = func_declaration();

              antlrcpp::downCast<UnitContext *>(_localctx)->unit_val =  antlrcpp::downCast<UnitContext *>(_localctx)->fd->func_decl;
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->fd != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->fd->start) : nullptr)->getLine()) + ": unit : func_declaration\n");
              writeIntoparserLogFile(_localctx->unit_val);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(76);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdef = func_definition();

              antlrcpp::downCast<UnitContext *>(_localctx)->unit_val =  antlrcpp::downCast<UnitContext *>(_localctx)->fdef->func_def;
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->fdef != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->fdef->stop) : nullptr)->getLine()) + ": unit : func_definition\n");
              writeIntoparserLogFile(_localctx->unit_val);
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C8086Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Func_declarationContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}


size_t C8086Parser::Func_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_declaration;
}

void C8086Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C8086Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C8086Parser::Func_declarationContext* C8086Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C8086Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(96);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(81);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(82);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(83);
      match(C8086Parser::LPAREN);
      setState(84);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->p = parameter_list(0);
      setState(85);
      match(C8086Parser::RPAREN);
      setState(86);
      match(C8086Parser::SEMICOLON);

              if (symb.getCurrentScope()->lookUp(parserLogFile, antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText()) == nullptr) {
                  SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), "FUNCTION");
                  symb.insert(funcSymbol);
              }

              antlrcpp::downCast<Func_declarationContext *>(_localctx)->func_decl =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->name_line + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_declarationContext *>(_localctx)->p->param_list + ");";

              FunctionInfo fi;
              fi.returnType = antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->name_line;
              fi.isDefined = false;
              fi.paramTypes = antlrcpp::downCast<Func_declarationContext *>(_localctx)->p->param_types;
              functionTable[antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText()] = fi;
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
              writeIntoparserLogFile(_localctx->func_decl + "\n\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(89);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(90);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(91);
      match(C8086Parser::LPAREN);
      setState(92);
      match(C8086Parser::RPAREN);
      setState(93);
      match(C8086Parser::SEMICOLON);

              if (symb.getCurrentScope()->lookUp(parserLogFile, antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText()) == nullptr) {
                  SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText(), "FUNCTION");  
                  symb.insert(funcSymbol);
              }
              antlrcpp::downCast<Func_declarationContext *>(_localctx)->func_decl =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->name_line + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText() + "();";
              
              FunctionInfo fi;
              fi.returnType = antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->name_line;
              fi.isDefined = false;
              functionTable[antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getText()] = fi;
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->idToken->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");
              writeIntoparserLogFile(_localctx->func_decl + "\n\n"); 

          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C8086Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Func_definitionContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::Func_definitionContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Parameter_listContext* C8086Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}

C8086Parser::Compound_statementContext* C8086Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}


size_t C8086Parser::Func_definitionContext::getRuleIndex() const {
  return C8086Parser::RuleFunc_definition;
}

void C8086Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C8086Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C8086Parser::Func_definitionContext* C8086Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C8086Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(99);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);

              currentFunction = antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
              currentOffset = 0;
              localVarOffset.clear();
              currentFunctionParams.clear();  
              hasReturnStatement = false;  
              
              // Generating function prologue
              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() == "main") {
                  emitCode("main PROC");
                  emitCode("MOV AX, @DATA");
                  emitCode("MOV DS, AX");
                  inMainFunction = true;
              } else {
                  emitCode(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC");
              }
              emitCode("PUSH BP");
              emitCode("MOV BP, SP");

              if(functionTable.find(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()) != functionTable.end()) {
                  FunctionInfo& existingFunc = functionTable[antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()];
                  if(existingFunc.returnType != antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->name_line) {
                      syntaxErrorCount++;
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                  }
                  if(existingFunc.isDefined) {
                      syntaxErrorCount++;
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple definition of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple definition of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");                
                  }
              }

              SymbolInfo* found = symb.getCurrentScope()->lookUp(parserLogFile, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              if(found != nullptr && found->getType() != "FUNCTION") {
                  syntaxErrorCount++;
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");                
              }

              if(found == nullptr) {
                  SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), "FUNCTION");
                  symb.insert(funcSymbol);
              }
          
      setState(101);
      match(C8086Parser::LPAREN);

              symb.enterScope();
              scopeEntered = true;
          
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->p = parameter_list(0);
      setState(104);
      match(C8086Parser::RPAREN);

              int totalParams = antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->param_types.size();
              if (totalParams > 1) {
                  for (size_t i = 0; i < currentFunctionParams.size(); i++) {
                      int paramOffset = 4 + (totalParams - 1 - i) * 2;

                      localVarOffset[currentFunctionParams[i]] = -paramOffset;
                  }
              }
              
              if(functionTable.find(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()) != functionTable.end()) {
                  FunctionInfo& existingFunc = functionTable[antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()];
                  
                  if(!existingFunc.isDefined) { 
                      if(existingFunc.paramTypes.size() != antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->param_types.size()) {
                          syntaxErrorCount++;
                          writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                          writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                      }
                      else {
                          for(size_t i = 0; i < existingFunc.paramTypes.size(); i++) {
                              if(existingFunc.paramTypes[i] != antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->param_types[i]) {
                                  syntaxErrorCount++;
                                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                              }
                          }
                      }
                  }
              }

              FunctionInfo fi;
              fi.returnType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->name_line;
              fi.isDefined = true;
              fi.paramTypes = antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->param_types;
              functionTable[antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()] = fi;      
          
      setState(106);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement();

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->func_def =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->name_line + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->param_list + ")" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->comp_stmt;
              
              if (inMainFunction) {
                  if (!returnLabel.empty()) {
                      emitCode(returnLabel + ":");  
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
                      int paramBytes = antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->param_types.size() * 2;
                      if (paramBytes > 0) {
                          emitCode("RET " + std::to_string(paramBytes));
                      } else {
                          emitCode("RET");
                      }
                  }
                  emitCode(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " ENDP");
                  returnLabel = "";  
              }

              if(functionTable.find(currentFunction) != functionTable.end()) {
                  FunctionInfo& currentFunc = functionTable[currentFunction];
                  if(currentFunc.returnType == "void" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->comp_stmt.find("return") != std::string::npos) {
                      writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
                      writeIntoparserLogFile("Error at line " + std::to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
                      syntaxErrorCount++;
                  }
              }
              
              currentFunction = "";
              symb.exitScope();
              scopeEntered = false;
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");
              writeIntoparserLogFile(_localctx->func_def + "\n\n");
              
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(109);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(110);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken = match(C8086Parser::ID);

              currentFunction = antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText();
              currentOffset = 0;
              localVarOffset.clear();
              currentFunctionParams.clear();  
              hasReturnStatement = false;  

              if (antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() == "main") {
                  emitCode("main PROC");
                  emitCode("MOV AX, @DATA");
                  emitCode("MOV DS, AX");
                  inMainFunction = true;
              } else {
                  emitCode(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " PROC");
              }
              emitCode("PUSH BP");
              emitCode("MOV BP, SP");
              
              if(functionTable.find(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()) != functionTable.end()) {
                  FunctionInfo& existingFunc = functionTable[antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()];
                  
                  if(existingFunc.returnType != antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->name_line) {
                      syntaxErrorCount++;
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Return type mismatch of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                  }
                  
                  if(existingFunc.isDefined) {
                      syntaxErrorCount++;
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple definition of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple definition of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");                              
                  }
              }

              SymbolInfo* found = symb.getCurrentScope()->lookUp(parserLogFile, antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText());
              if(found != nullptr && found->getType() != "FUNCTION") {
                  syntaxErrorCount++;
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");                
              }

              if(found == nullptr) {
                  SymbolInfo* funcSymbol = new SymbolInfo(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText(), "FUNCTION");
                  symb.insert(funcSymbol);
              }
          
      setState(112);
      match(C8086Parser::LPAREN);
      setState(113);
      match(C8086Parser::RPAREN);

              symb.enterScope();
              scopeEntered = true;
              
              if(functionTable.find(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()) != functionTable.end()) {
                  FunctionInfo& existingFunc = functionTable[antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()];
                  
                  if(!existingFunc.isDefined && !existingFunc.paramTypes.empty()) {
                      syntaxErrorCount++;
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "\n");
                  }
              }
              
              FunctionInfo fi;
              fi.returnType = antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->name_line;
              fi.isDefined = true;
              functionTable[antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText()] = fi;        
          
      setState(115);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement();

              antlrcpp::downCast<Func_definitionContext *>(_localctx)->func_def =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->name_line + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + "()" + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->comp_stmt;
              if (inMainFunction) {
                  if (!returnLabel.empty()) {
                      emitCode(returnLabel + ":");  
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
                  // Only generate epilogue if no explicit return statement
                  if (!hasReturnStatement) {
                      emitCode("POP BP");
                      emitCode("RET");
                  }
                  emitCode(antlrcpp::downCast<Func_definitionContext *>(_localctx)->idToken->getText() + " ENDP");
                  returnLabel = "";  
              }

              if(functionTable.find(currentFunction) != functionTable.end()) {
                  FunctionInfo& currentFunc = functionTable[currentFunction];
                  if(currentFunc.returnType == "void" && antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->comp_stmt.find("return") != std::string::npos) {
                      writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
                      writeIntoparserLogFile("Error at line " + std::to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
                      syntaxErrorCount++;
                  }
              }
              
              currentFunction = "";
              symb.exitScope();
              scopeEntered = false; 
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");
              writeIntoparserLogFile(_localctx->func_def + "\n\n");

          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C8086Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Parameter_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

C8086Parser::Type_specifierContext* C8086Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

tree::TerminalNode* C8086Parser::Parameter_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::Parameter_listContext* C8086Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C8086Parser::Parameter_listContext>(0);
}


size_t C8086Parser::Parameter_listContext::getRuleIndex() const {
  return C8086Parser::RuleParameter_list;
}

void C8086Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C8086Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C8086Parser::Parameter_listContext* C8086Parser::parameter_list() {
   return parameter_list(0);
}

C8086Parser::Parameter_listContext* C8086Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C8086Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C8086Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(121);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(122);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->param_list =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText() ;
              _localctx->param_types.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line);

              if(scopeEntered){
                  SymbolInfo* paramSymbol = new SymbolInfo(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText(), "ID");
                  symb.insert(paramSymbol);
                  
                  // Adding to parameter tracking list  
                  currentFunctionParams.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText());
                  
                  // Setting parameter offset (parameter will be at [BP+4] - will be adjusted later)
                  int initialOffset = 4;
                  localVarOffset[antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()] = -initialOffset;  // Store as negative to indicate parameter
              }
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine()) + ": parameter_list : type_specifier ID\n");
              writeIntoparserLogFile(_localctx->param_list + "\n");
          
      break;
    }

    case 2: {
      setState(125);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->param_list =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line ;
              _localctx->param_types.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line);
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": parameter_list : type_specifier\n");
              writeIntoparserLogFile(_localctx->param_list + "\n");
          
      break;
    }

    case 3: {
      setState(128);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(129);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);

              antlrcpp::downCast<Parameter_listContext *>(_localctx)->param_list =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line ;
              _localctx->param_types.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line);
              writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
              writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");       
              syntaxErrorCount++;
              
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(147);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(145);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->p = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(134);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(135);
          match(C8086Parser::COMMA);
          setState(136);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
          setState(137);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

                            if(symb.getCurrentScope()->lookUp(parserLogFile, antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()) != nullptr){
                                syntaxErrorCount++;
                                writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText() + " in parameter\n");
                                writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText() + " in parameter\n");
                            }

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->param_list =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->p->param_list + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText();
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->param_types =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->p->param_types;
                            _localctx->param_types.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line);

                            if (scopeEntered) {
                                SymbolInfo* paramSymbol = new SymbolInfo(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText(), "ID");
                                symb.insert(paramSymbol);
                                
                                // Adding to parameter tracking list
                                currentFunctionParams.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText());
                                
                                // Seting parameter offset (parameters are at positive offsets from BP)
                                // Initial assignment - will be corrected after parsing all parameters
                                int totalParams = _localctx->param_types.size();            
                                int paramOffset = 4 + (totalParams - 1) * 2;      
                                localVarOffset[antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getText()] = -paramOffset;  
                            }
                            
                            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->idToken->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n");
                            writeIntoparserLogFile(_localctx->param_list + "\n");
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->p = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(140);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(141);
          match(C8086Parser::COMMA);
          setState(142);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();

                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->param_list =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->p->param_list + "," + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line + " " ;
                            antlrcpp::downCast<Parameter_listContext *>(_localctx)->param_types =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->p->param_types;
                            _localctx->param_types.push_back(antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->name_line);
                            
                            writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": parameter_list : parameter_list COMMA type_specifier\n");
                            writeIntoparserLogFile(_localctx->param_list + "\n");
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(149);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C8086Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Compound_statementContext::LCURL() {
  return getToken(C8086Parser::LCURL, 0);
}

tree::TerminalNode* C8086Parser::Compound_statementContext::RCURL() {
  return getToken(C8086Parser::RCURL, 0);
}

C8086Parser::StatementsContext* C8086Parser::Compound_statementContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}


size_t C8086Parser::Compound_statementContext::getRuleIndex() const {
  return C8086Parser::RuleCompound_statement;
}

void C8086Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C8086Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C8086Parser::Compound_statementContext* C8086Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, C8086Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(150);
      match(C8086Parser::LCURL);

              if (!scopeEntered) {
                  symb.enterScope();
                  scopeEntered = true;
              }        
          
      setState(152);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->s = statements(0);
      setState(153);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C8086Parser::RCURL);

              antlrcpp::downCast<Compound_statementContext *>(_localctx)->comp_stmt =  "{\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->s->stmt_list + "}\n";

              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) + ": compound_statement : LCURL statements RCURL\n");
              writeIntoparserLogFile(_localctx->comp_stmt + "\n");
              symb.printAllScopes(parserLogFile);
              writeIntoparserLogFile("\n");

              if (!scopeEntered) {
                  symb.exitScope();
                  scopeEntered = false;
              }     
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(156);
      match(C8086Parser::LCURL);
      setState(157);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken = match(C8086Parser::RCURL);

              symb.enterScope();
              antlrcpp::downCast<Compound_statementContext *>(_localctx)->comp_stmt =  "{\n}\n";
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->rcurlToken->getLine()) + ": compound_statement : LCURL RCURL\n");
              writeIntoparserLogFile(_localctx->comp_stmt + "\n");
              symb.printAllScopes(parserLogFile);
              writeIntoparserLogFile("\n");
              
              symb.exitScope();
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C8086Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Type_specifierContext* C8086Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C8086Parser::Type_specifierContext>(0);
}

C8086Parser::Declaration_listContext* C8086Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C8086Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::Declaration_list_errContext* C8086Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C8086Parser::Declaration_list_errContext>(0);
}


size_t C8086Parser::Var_declarationContext::getRuleIndex() const {
  return C8086Parser::RuleVar_declaration;
}

void C8086Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C8086Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C8086Parser::Var_declarationContext* C8086Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, C8086Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(161);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(162);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(163);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

              if(antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->name_line == "void"){
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Variable type cannot be void\n");
                  syntaxErrorCount++;        
              }

              // Generating assembly for variable declarations
              std::string vars = antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->var_list.get_list_as_string();
              std::istringstream varStream(vars);
              std::string varEntry;
              
              while (std::getline(varStream, varEntry, ',')) {
                  varEntry.erase(0, varEntry.find_first_not_of(" \t"));
                  varEntry.erase(varEntry.find_last_not_of(" \t") + 1);
                  
                  std::string varName = varEntry;
                  std::string varType = antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->name_line;
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
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Multiple declaration of " + varName + "\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": Multiple declaration of " + varName + "\n");
                      syntaxErrorCount++;
                      continue;
                  }
                  
                  SymbolInfo* newSymbol = new SymbolInfo(varName, varType);
                  if (!symb.insert(newSymbol)) {
                      delete newSymbol;
                  }
                  
                  // Generating assembly
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

              antlrcpp::downCast<Var_declarationContext *>(_localctx)->var_decl =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->name_line + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->var_list.get_list_as_string() + ";";
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n");
              writeIntoparserLogFile(_localctx->var_decl + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(166);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(167);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(168);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C8086Parser::SEMICOLON);

              syntaxErrorCount++;
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C8086Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C8086Parser::Declaration_list_errContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list_err;
}

void C8086Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C8086Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C8086Parser::Declaration_list_errContext* C8086Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 16, C8086Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->error_name =  "Error in declaration list";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C8086Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Type_specifierContext::INT() {
  return getToken(C8086Parser::INT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::FLOAT() {
  return getToken(C8086Parser::FLOAT, 0);
}

tree::TerminalNode* C8086Parser::Type_specifierContext::VOID() {
  return getToken(C8086Parser::VOID, 0);
}


size_t C8086Parser::Type_specifierContext::getRuleIndex() const {
  return C8086Parser::RuleType_specifier;
}

void C8086Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C8086Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C8086Parser::Type_specifierContext* C8086Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 18, C8086Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(175);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C8086Parser::INT);

                antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : INT\n");
                writeIntoparserLogFile(_localctx->name_line + "\n");
            
        break;
      }

      case C8086Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(177);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C8086Parser::FLOAT);

                antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : FLOAT\n");
                writeIntoparserLogFile(_localctx->name_line + "\n");
            
        break;
      }

      case C8086Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(179);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C8086Parser::VOID);

                antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText();
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine()) + ": type_specifier : VOID\n");
                writeIntoparserLogFile(_localctx->name_line + "\n");
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C8086Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Declaration_listContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::Declaration_listContext* C8086Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C8086Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C8086Parser::Declaration_listContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}


size_t C8086Parser::Declaration_listContext::getRuleIndex() const {
  return C8086Parser::RuleDeclaration_list;
}

void C8086Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C8086Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C8086Parser::Declaration_listContext* C8086Parser::declaration_list() {
   return declaration_list(0);
}

C8086Parser::Declaration_listContext* C8086Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C8086Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C8086Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(191);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(184);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

              _localctx->var_list.add(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText());
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID\n");
              writeIntoparserLogFile(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "\n");
          
      break;
    }

    case 2: {
      setState(186);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(187);
      match(C8086Parser::LTHIRD);
      setState(188);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
      setState(189);
      match(C8086Parser::RTHIRD);

              _localctx->var_list.add(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]");
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
              writeIntoparserLogFile(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]\n");
          
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(210);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(208);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(193);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(194);
          match(C8086Parser::COMMA);
          setState(195);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->var_list =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->var_list;
                            _localctx->var_list.add(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText());
                            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID\n");
                            writeIntoparserLogFile(_localctx->var_list.get_list_as_string() + "\n");
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(197);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(198);
          match(C8086Parser::COMMA);
          setState(199);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);
          setState(200);
          match(C8086Parser::LTHIRD);
          setState(201);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
          setState(202);
          match(C8086Parser::RTHIRD);

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->var_list =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->var_list;
                            _localctx->var_list.add(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->const_intToken->getText() + "]");
                            writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
                            writeIntoparserLogFile(_localctx->var_list.get_list_as_string() + "\n");
                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(204);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(205);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
          setState(206);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->idToken = match(C8086Parser::ID);

                            antlrcpp::downCast<Declaration_listContext *>(_localctx)->var_list =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->var_list;
                            syntaxErrorCount++;
                            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
                            writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->addopToken->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(212);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C8086Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::StatementContext* C8086Parser::StatementsContext::statement() {
  return getRuleContext<C8086Parser::StatementContext>(0);
}

C8086Parser::StatementsContext* C8086Parser::StatementsContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}

C8086Parser::VariableContext* C8086Parser::StatementsContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}

tree::TerminalNode* C8086Parser::StatementsContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}

C8086Parser::Simple_expression_errContext* C8086Parser::StatementsContext::simple_expression_err() {
  return getRuleContext<C8086Parser::Simple_expression_errContext>(0);
}

C8086Parser::ExpressionContext* C8086Parser::StatementsContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::StatementsContext::INVALID_CHAR() {
  return getToken(C8086Parser::INVALID_CHAR, 0);
}


size_t C8086Parser::StatementsContext::getRuleIndex() const {
  return C8086Parser::RuleStatements;
}

void C8086Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C8086Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C8086Parser::StatementsContext* C8086Parser::statements() {
   return statements(0);
}

C8086Parser::StatementsContext* C8086Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C8086Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C8086Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(214);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

            antlrcpp::downCast<StatementsContext *>(_localctx)->stmt_list =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->stmt_val;
            writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->start) : nullptr)->getLine()) + ": statements : statement\n");
            writeIntoparserLogFile(_localctx->stmt_list + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(232);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
          _localctx->st = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleStatements);
          setState(217);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(218);
          antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                            antlrcpp::downCast<StatementsContext *>(_localctx)->stmt_list =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->stmt_list.substr(0, antlrcpp::downCast<StatementsContext *>(_localctx)->st->stmt_list.length()) + antlrcpp::downCast<StatementsContext *>(_localctx)->s->stmt_val;
                            writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statements : statements statement\n");
                            writeIntoparserLogFile(_localctx->stmt_list + "\n");
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
          _localctx->st = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleStatements);
          setState(221);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(222);
          variable();
          setState(223);
          match(C8086Parser::ASSIGNOP);
          setState(224);
          simple_expression_err();

                            antlrcpp::downCast<StatementsContext *>(_localctx)->stmt_list =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->stmt_list.substr(0, antlrcpp::downCast<StatementsContext *>(_localctx)->st->stmt_list.length());
                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
          _localctx->st = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleStatements);
          setState(227);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(228);
          expression();
          setState(229);
          antlrcpp::downCast<StatementsContext *>(_localctx)->invalid_charToken = match(C8086Parser::INVALID_CHAR);

                            antlrcpp::downCast<StatementsContext *>(_localctx)->stmt_list =  antlrcpp::downCast<StatementsContext *>(_localctx)->st->stmt_list.substr(0, antlrcpp::downCast<StatementsContext *>(_localctx)->st->stmt_list.length());
                            syntaxErrorCount++;
                            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->invalid_charToken->getLine()) + ": Unrecognized character " + antlrcpp::downCast<StatementsContext *>(_localctx)->invalid_charToken->getText() + "\n");
                            writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<StatementsContext *>(_localctx)->invalid_charToken->getLine()) + ": Unrecognized character " + antlrcpp::downCast<StatementsContext *>(_localctx)->invalid_charToken->getText() + "\n");                            
                        
          break;
        }

        default:
          break;
        } 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C8086Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Var_declarationContext* C8086Parser::StatementContext::var_declaration() {
  return getRuleContext<C8086Parser::Var_declarationContext>(0);
}

std::vector<C8086Parser::Expression_statementContext *> C8086Parser::StatementContext::expression_statement() {
  return getRuleContexts<C8086Parser::Expression_statementContext>();
}

C8086Parser::Expression_statementContext* C8086Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C8086Parser::Expression_statementContext>(i);
}

C8086Parser::Compound_statementContext* C8086Parser::StatementContext::compound_statement() {
  return getRuleContext<C8086Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C8086Parser::StatementContext::FOR() {
  return getToken(C8086Parser::FOR, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::ExpressionContext* C8086Parser::StatementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

std::vector<C8086Parser::StatementContext *> C8086Parser::StatementContext::statement() {
  return getRuleContexts<C8086Parser::StatementContext>();
}

C8086Parser::StatementContext* C8086Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C8086Parser::StatementContext>(i);
}

tree::TerminalNode* C8086Parser::StatementContext::IF() {
  return getToken(C8086Parser::IF, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ELSE() {
  return getToken(C8086Parser::ELSE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::WHILE() {
  return getToken(C8086Parser::WHILE, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::PRINTLN() {
  return getToken(C8086Parser::PRINTLN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RETURN() {
  return getToken(C8086Parser::RETURN, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::SWITCH() {
  return getToken(C8086Parser::SWITCH, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::LCURL() {
  return getToken(C8086Parser::LCURL, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::RCURL() {
  return getToken(C8086Parser::RCURL, 0);
}

C8086Parser::Case_statementsContext* C8086Parser::StatementContext::case_statements() {
  return getRuleContext<C8086Parser::Case_statementsContext>(0);
}

tree::TerminalNode* C8086Parser::StatementContext::COLON() {
  return getToken(C8086Parser::COLON, 0);
}

tree::TerminalNode* C8086Parser::StatementContext::GOTO() {
  return getToken(C8086Parser::GOTO, 0);
}


size_t C8086Parser::StatementContext::getRuleIndex() const {
  return C8086Parser::RuleStatement;
}

void C8086Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C8086Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C8086Parser::StatementContext* C8086Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, C8086Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(237);
      antlrcpp::downCast<StatementContext *>(_localctx)->vd = var_declaration();

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  antlrcpp::downCast<StatementContext *>(_localctx)->vd->var_decl + "\n";
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->vd != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->vd->start) : nullptr)->getLine()) + ": statement : var_declaration\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(240);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  antlrcpp::downCast<StatementContext *>(_localctx)->es->expr_stmt + "\n";
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->es != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->es->start) : nullptr)->getLine()) + ": statement : expression_statement\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(243);
      antlrcpp::downCast<StatementContext *>(_localctx)->c = compound_statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  antlrcpp::downCast<StatementContext *>(_localctx)->c->comp_stmt + "\n";
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": statement : compound_statement\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(246);
      match(C8086Parser::FOR);
      setState(247);
      match(C8086Parser::LPAREN);
      setState(248);
      antlrcpp::downCast<StatementContext *>(_localctx)->es1 = expression_statement();

              std::string savedLoopBodyLabel = currentLoopBodyLabel;
              std::string savedContinueLabel = currentContinueLabel;
              std::string savedLoopExitLabel = currentLoopExitLabel;
              
              currentLoopBodyLabel = newLabel();
              currentContinueLabel = newLabel();
              currentLoopExitLabel = newLabel();

              emitCode("JMP " + currentContinueLabel);

              emitCode(currentLoopBodyLabel + ":");
              symb.enterScope();

              inForCondition = true;
              inForIncrement = true;
          
      setState(250);
      antlrcpp::downCast<StatementContext *>(_localctx)->es2 = expression_statement();


          
      setState(252);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(253);
      match(C8086Parser::RPAREN);

              inForCondition = false;
              inForIncrement = false;
          
      setState(255);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              symb.exitScope();

              std::string incrementExpr = antlrcpp::downCast<StatementContext *>(_localctx)->e->expr_val;
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

              emitCode(currentContinueLabel + ":");

              std::string conditionExpr = antlrcpp::downCast<StatementContext *>(_localctx)->es2->expr_stmt;
              size_t pos = conditionExpr.find(';');
              if (pos != std::string::npos) {
                  conditionExpr = conditionExpr.substr(0, pos);
              }
              conditionExpr.erase(0, conditionExpr.find_first_not_of(" \t"));
              conditionExpr.erase(conditionExpr.find_last_not_of(" \t") + 1);

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
              
              // Trimmed whitespace
              leftVar.erase(0, leftVar.find_first_not_of(" \t"));
              leftVar.erase(leftVar.find_last_not_of(" \t") + 1);
              rightValue.erase(0, rightValue.find_first_not_of(" \t"));
              rightValue.erase(rightValue.find_last_not_of(" \t") + 1);

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

              emitCode("JMP " + currentLoopExitLabel);

              emitCode(currentLoopExitLabel + ":");

              currentLoopBodyLabel = savedLoopBodyLabel;
              currentContinueLabel = savedContinueLabel;
              currentLoopExitLabel = savedLoopExitLabel;
              
              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  "for(" + antlrcpp::downCast<StatementContext *>(_localctx)->es1->expr_stmt + antlrcpp::downCast<StatementContext *>(_localctx)->es2->expr_stmt + antlrcpp::downCast<StatementContext *>(_localctx)->e->expr_val + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->stmt_val;
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(258);
      match(C8086Parser::IF);
      setState(259);
      match(C8086Parser::LPAREN);

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
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(262);
      match(C8086Parser::RPAREN);

              symb.enterScope();
              inIfCondition = false;  // Reset context after expression
          
      setState(264);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  "if(" + antlrcpp::downCast<StatementContext *>(_localctx)->e->expr_val + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->stmt_val;
              
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
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
              
              symb.exitScope();
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(267);
      match(C8086Parser::IF);
      setState(268);
      match(C8086Parser::LPAREN);

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
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(271);
      match(C8086Parser::RPAREN);

              symb.enterScope();
              inIfCondition = false;  // Reset context after expression
          
      setState(273);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();

              symb.exitScope();
              
              // Jump to end after true block
              emitCode("JMP " + currentIfEndLabel);
              
              // Place false label for else block
              emitCode(currentIfFalseLabel + ":");
          
      setState(275);
      match(C8086Parser::ELSE);

              symb.enterScope();  
          
      setState(277);
      antlrcpp::downCast<StatementContext *>(_localctx)->s2 = statement();

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  "if(" + antlrcpp::downCast<StatementContext *>(_localctx)->e->expr_val + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s1->stmt_val + "else " + antlrcpp::downCast<StatementContext *>(_localctx)->s2->stmt_val;
              
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
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s2 != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s2->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
              
              symb.exitScope();
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(280);
      match(C8086Parser::WHILE);
      setState(281);
      match(C8086Parser::LPAREN);

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
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(284);
      match(C8086Parser::RPAREN);

              inLoopCondition = false;  // Reset context after condition
              
              // Body label comes before the statement
              emitCode(bodyLabel + ":");
              
              symb.enterScope();  
          
      setState(286);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

              // After body execution, jump back to condition check
              emitCode("JMP " + conditionLabel);
              
              // Place exit label
              emitCode(exitLabel + ":");
              
              // Restore previous loop labels
              currentLoopBodyLabel = savedLoopBodyLabel;
              currentContinueLabel = savedContinueLabel;
              currentLoopExitLabel = savedLoopExitLabel;
              
              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  "while(" + antlrcpp::downCast<StatementContext *>(_localctx)->e->expr_val + ")" + antlrcpp::downCast<StatementContext *>(_localctx)->s->stmt_val;
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
              
              symb.exitScope();
          
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(289);
      match(C8086Parser::PRINTLN);
      setState(290);
      match(C8086Parser::LPAREN);
      setState(291);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(292);
      match(C8086Parser::RPAREN);
      setState(293);
      match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  "println(" + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + ");\n";

              // Generate proper assembly for variable access
              std::string varName = antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText();
              if (currentFunction.empty()) {
                  emitCode("MOV AX, " + varName + "       ; Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()));
              } else {
                  if (localVarOffset.find(varName) != localVarOffset.end()) {
                      emitCode("MOV AX, " + getVarOffset(varName) + "       ; Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()));
                  } else {
                      emitCode("MOV AX, " + varName + "       ; Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()));
                  }
              }
              
              emitCode("CALL print_output");
              emitCode("CALL new_line");

              InsertResult result = symb.lookupWithPosition(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText());
              if(!result.found) {
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + "\n");
                  syntaxErrorCount++;
              }
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
          
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(295);
      match(C8086Parser::RETURN);
      setState(296);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(297);
      match(C8086Parser::SEMICOLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  "return " + antlrcpp::downCast<StatementContext *>(_localctx)->e->expr_val + ";\n";
              hasReturnStatement = true;  // Mark that this function has a return statement
              
              // Handle the return expression evaluation first
              std::string exprStr = antlrcpp::downCast<StatementContext *>(_localctx)->e->expr_val;
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
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->e != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->e->stop) : nullptr)->getLine()) + ": statement : RETURN expression SEMICOLON\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
          
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(300);
      match(C8086Parser::SWITCH);
      setState(301);
      match(C8086Parser::LPAREN);
      setState(302);
      antlrcpp::downCast<StatementContext *>(_localctx)->e = expression();
      setState(303);
      match(C8086Parser::RPAREN);

              symb.enterScope();
          
      setState(305);
      match(C8086Parser::LCURL);
      setState(306);
      antlrcpp::downCast<StatementContext *>(_localctx)->cases = case_statements(0);
      setState(307);
      match(C8086Parser::RCURL);

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  "switch(" + antlrcpp::downCast<StatementContext *>(_localctx)->e->expr_val + "){\n" + antlrcpp::downCast<StatementContext *>(_localctx)->cases->case_stmts + "}\n";
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->cases != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->cases->stop) : nullptr)->getLine()) + ": statement : SWITCH LPAREN expression RPAREN LCURL case_statements RCURL\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
              
              symb.exitScope();
          
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(310);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(311);
      match(C8086Parser::COLON);

              antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + ":\n";
              calledLabel = true;
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": statement : ID COLON\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
          
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(313);
      match(C8086Parser::GOTO);
      setState(314);
      antlrcpp::downCast<StatementContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(315);
      match(C8086Parser::SEMICOLON);

              if(calledLabel == true){
                  antlrcpp::downCast<StatementContext *>(_localctx)->stmt_val =  "goto " + antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getText() + ";\n";
                  calledLabel = false;
              }
              else{
                  syntaxErrorCount++;
              }
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->idToken->getLine()) + ": statement : GOTO ID SEMICOLON\n");
              writeIntoparserLogFile(_localctx->stmt_val + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_statementsContext ------------------------------------------------------------------

C8086Parser::Case_statementsContext::Case_statementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Case_statementContext* C8086Parser::Case_statementsContext::case_statement() {
  return getRuleContext<C8086Parser::Case_statementContext>(0);
}

C8086Parser::Case_statementsContext* C8086Parser::Case_statementsContext::case_statements() {
  return getRuleContext<C8086Parser::Case_statementsContext>(0);
}


size_t C8086Parser::Case_statementsContext::getRuleIndex() const {
  return C8086Parser::RuleCase_statements;
}

void C8086Parser::Case_statementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_statements(this);
}

void C8086Parser::Case_statementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_statements(this);
}


C8086Parser::Case_statementsContext* C8086Parser::case_statements() {
   return case_statements(0);
}

C8086Parser::Case_statementsContext* C8086Parser::case_statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Case_statementsContext *_localctx = _tracker.createInstance<Case_statementsContext>(_ctx, parentState);
  C8086Parser::Case_statementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, C8086Parser::RuleCase_statements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(320);
    antlrcpp::downCast<Case_statementsContext *>(_localctx)->c = case_statement();

            antlrcpp::downCast<Case_statementsContext *>(_localctx)->case_stmts =  antlrcpp::downCast<Case_statementsContext *>(_localctx)->c->case_stmt;
            
            writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Case_statementsContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Case_statementsContext *>(_localctx)->c->start) : nullptr)->getLine()) + ": case_statements : case_statement\n");
            writeIntoparserLogFile(_localctx->case_stmts + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(329);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Case_statementsContext>(parentContext, parentState);
        _localctx->cs = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleCase_statements);
        setState(323);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(324);
        antlrcpp::downCast<Case_statementsContext *>(_localctx)->c = case_statement();

                          antlrcpp::downCast<Case_statementsContext *>(_localctx)->case_stmts =  antlrcpp::downCast<Case_statementsContext *>(_localctx)->cs->case_stmts + antlrcpp::downCast<Case_statementsContext *>(_localctx)->c->case_stmt;
                          
                          writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Case_statementsContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Case_statementsContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": case_statements : case_statements case_statement\n");
                          writeIntoparserLogFile(_localctx->case_stmts + "\n");
                       
      }
      setState(331);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Case_statementContext ------------------------------------------------------------------

C8086Parser::Case_statementContext::Case_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Case_statementContext::CASE() {
  return getToken(C8086Parser::CASE, 0);
}

tree::TerminalNode* C8086Parser::Case_statementContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::Case_statementContext::COLON() {
  return getToken(C8086Parser::COLON, 0);
}

tree::TerminalNode* C8086Parser::Case_statementContext::BREAK() {
  return getToken(C8086Parser::BREAK, 0);
}

tree::TerminalNode* C8086Parser::Case_statementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::StatementsContext* C8086Parser::Case_statementContext::statements() {
  return getRuleContext<C8086Parser::StatementsContext>(0);
}

tree::TerminalNode* C8086Parser::Case_statementContext::DEFAULT() {
  return getToken(C8086Parser::DEFAULT, 0);
}


size_t C8086Parser::Case_statementContext::getRuleIndex() const {
  return C8086Parser::RuleCase_statement;
}

void C8086Parser::Case_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_statement(this);
}

void C8086Parser::Case_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_statement(this);
}

C8086Parser::Case_statementContext* C8086Parser::case_statement() {
  Case_statementContext *_localctx = _tracker.createInstance<Case_statementContext>(_ctx, getState());
  enterRule(_localctx, 28, C8086Parser::RuleCase_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(347);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(332);
        match(C8086Parser::CASE);
        setState(333);
        antlrcpp::downCast<Case_statementContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);
        setState(334);
        match(C8086Parser::COLON);
        setState(335);
        antlrcpp::downCast<Case_statementContext *>(_localctx)->s = statements(0);
        setState(336);
        match(C8086Parser::BREAK);
        setState(337);
        antlrcpp::downCast<Case_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

                antlrcpp::downCast<Case_statementContext *>(_localctx)->case_stmt =  "case " + antlrcpp::downCast<Case_statementContext *>(_localctx)->const_intToken->getText() + ":\n" + antlrcpp::downCast<Case_statementContext *>(_localctx)->s->stmt_list + "break;\n";
                
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Case_statementContext *>(_localctx)->semicolonToken->getLine()) + ": case_statement : CASE CONST_INT COLON statements BREAK SEMICOLON\n");
                writeIntoparserLogFile(_localctx->case_stmt + "\n");
            
        break;
      }

      case C8086Parser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(340);
        match(C8086Parser::DEFAULT);
        setState(341);
        match(C8086Parser::COLON);
        setState(342);
        antlrcpp::downCast<Case_statementContext *>(_localctx)->s = statements(0);
        setState(343);
        match(C8086Parser::BREAK);
        setState(344);
        antlrcpp::downCast<Case_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

                antlrcpp::downCast<Case_statementContext *>(_localctx)->case_stmt =  "default:\n" + antlrcpp::downCast<Case_statementContext *>(_localctx)->s->stmt_list + "break;\n";
                
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Case_statementContext *>(_localctx)->semicolonToken->getLine()) + ": case_statement : DEFAULT COLON statements BREAK SEMICOLON\n");
                writeIntoparserLogFile(_localctx->case_stmt + "\n");
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C8086Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C8086Parser::SEMICOLON, 0);
}

C8086Parser::ExpressionContext* C8086Parser::Expression_statementContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}


size_t C8086Parser::Expression_statementContext::getRuleIndex() const {
  return C8086Parser::RuleExpression_statement;
}

void C8086Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C8086Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C8086Parser::Expression_statementContext* C8086Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 30, C8086Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(349);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

                antlrcpp::downCast<Expression_statementContext *>(_localctx)->expr_stmt =  ";\n";
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : SEMICOLON\n");
                writeIntoparserLogFile(_localctx->expr_stmt + "\n");
            
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(351);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(352);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken = match(C8086Parser::SEMICOLON);

                antlrcpp::downCast<Expression_statementContext *>(_localctx)->expr_stmt =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->expr_val + ";\n";
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->semicolonToken->getLine()) + ": expression_statement : expression SEMICOLON\n");
                writeIntoparserLogFile(_localctx->expr_stmt + "\n");
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C8086Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::VariableContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::LTHIRD() {
  return getToken(C8086Parser::LTHIRD, 0);
}

tree::TerminalNode* C8086Parser::VariableContext::RTHIRD() {
  return getToken(C8086Parser::RTHIRD, 0);
}

C8086Parser::ExpressionContext* C8086Parser::VariableContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}


size_t C8086Parser::VariableContext::getRuleIndex() const {
  return C8086Parser::RuleVariable;
}

void C8086Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C8086Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C8086Parser::VariableContext* C8086Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 32, C8086Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(357);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);

              antlrcpp::downCast<VariableContext *>(_localctx)->var_name =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText();

              InsertResult result = symb.lookupWithPosition(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
              SymbolInfo* varInfo = symb.getCurrentScope()->lookUp(parserLogFile, antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());

              if(!result.found){
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");
                  syntaxErrorCount++;            
              }

              if(varInfo != nullptr){
                  if(varInfo->getType() == "ARRAY" && _localctx->parent->getText().find("[") == std::string::npos){
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Type mismatch, " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is an array\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Type mismatch, " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " is an array\n");
                      syntaxErrorCount++;            
                  }
              }
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID\n");
              writeIntoparserLogFile(_localctx->var_name + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(359);
      antlrcpp::downCast<VariableContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(360);
      match(C8086Parser::LTHIRD);
      setState(361);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(362);
      match(C8086Parser::RTHIRD);

              antlrcpp::downCast<VariableContext *>(_localctx)->var_name =  antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "[" + antlrcpp::downCast<VariableContext *>(_localctx)->e->expr_val + "]";

              InsertResult result = symb.lookupWithPosition(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());
              if(!result.found) {
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Undeclared variable " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + "\n");
                  syntaxErrorCount++;
              }
              else {
                  SymbolInfo* varInfo = symb.getCurrentScope()->lookUp(parserLogFile, antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText());

                  if(varInfo != nullptr && varInfo->getType() != "ARRAY") {
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " not an array\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": " + antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getText() + " not an array\n");
                      syntaxErrorCount++;
                  }
              }

              if(antlrcpp::downCast<VariableContext *>(_localctx)->e->expr_val.find(".") != std::string::npos){
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Expression inside third brackets not an integer\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": Expression inside third brackets not an integer\n"); 
                  syntaxErrorCount++;          
              }
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->idToken->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
              writeIntoparserLogFile(_localctx->var_name + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C8086Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}

C8086Parser::VariableContext* C8086Parser::ExpressionContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}


size_t C8086Parser::ExpressionContext::getRuleIndex() const {
  return C8086Parser::RuleExpression;
}

void C8086Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C8086Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C8086Parser::ExpressionContext* C8086Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C8086Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(367);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();

              antlrcpp::downCast<ExpressionContext *>(_localctx)->expr_val =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l->logic_val;
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->l->start) : nullptr)->getLine()) + ": expression : logic_expression\n");
              writeIntoparserLogFile(_localctx->expr_val + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(370);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(371);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken = match(C8086Parser::ASSIGNOP);

              inAssignmentContext = true;  // Set assignment context flag
          
      setState(373);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();

              inAssignmentContext = false;  
              antlrcpp::downCast<ExpressionContext *>(_localctx)->expr_val =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->var_name + antlrcpp::downCast<ExpressionContext *>(_localctx)->assignopToken->getText() + antlrcpp::downCast<ExpressionContext *>(_localctx)->l->logic_val;

              std::string logicStr = antlrcpp::downCast<ExpressionContext *>(_localctx)->l->logic_val;
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
                  emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->l->start) : nullptr)->getLine()));
              } else if (isSimpleVariable) {
                  if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
                      emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->l->start) : nullptr)->getLine()));
                  } else {
                      emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->l->start) : nullptr)->getLine()));
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
                      emitCode("POP AX       ; Line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->l->start) : nullptr)->getLine()));
                  }
              }
              
              std::string varName = antlrcpp::downCast<ExpressionContext *>(_localctx)->v->var_name;

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

              std::string varName2 = antlrcpp::downCast<ExpressionContext *>(_localctx)->v->var_name;
              size_t bracketPos2 = varName2.find("[");

              if(bracketPos2 != std::string::npos){
                  varName2 = varName2.substr(0, bracketPos2);
              }

              SymbolInfo* symbol = symb.getCurrentScope()->lookUp(parserLogFile, antlrcpp::downCast<ExpressionContext *>(_localctx)->v->var_name);

              bool isModulusOp = antlrcpp::downCast<ExpressionContext *>(_localctx)->l->logic_val.find("%") != std::string::npos;
              bool isFloatValue = antlrcpp::downCast<ExpressionContext *>(_localctx)->l->logic_val.find(".") != std::string::npos;

              if(!isModulusOp) {
                  SymbolInfo* symbol = symb.getCurrentScope()->lookUp(parserLogFile, varName2);
                  if(symbol != nullptr) {
                      if(symbol->getType() == "ARRAY" && isFloatValue) {
                          writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": Type Mismatch\n");
                          writeIntoparserLogFile("Error at line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": Type Mismatch\n");
                          syntaxErrorCount++;
                      }
                      else if(symbol->getType() == "INT" && isFloatValue) {
                          writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": Type Mismatch\n");
                          writeIntoparserLogFile("Error at line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": Type Mismatch\n");
                          syntaxErrorCount++;
                      }
                  }
              }
              
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->l->start) : nullptr)->getLine()) + ": expression : variable ASSIGNOP logic_expression\n");
              writeIntoparserLogFile(_localctx->expr_val + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C8086Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Rel_expressionContext *> C8086Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C8086Parser::Rel_expressionContext>();
}

C8086Parser::Rel_expressionContext* C8086Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C8086Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C8086Parser::LOGICOP, 0);
}


size_t C8086Parser::Logic_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleLogic_expression;
}

void C8086Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C8086Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C8086Parser::Logic_expressionContext* C8086Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, C8086Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(378);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logic_val =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->rel_val;
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r != nullptr ? (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->start) : nullptr)->getLine()) + ": logic_expression : rel_expression\n");
              writeIntoparserLogFile(_localctx->logic_val + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(381);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1 = rel_expression();
      setState(382);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken = match(C8086Parser::LOGICOP);
      setState(383);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2 = rel_expression();

              antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logic_val =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->rel_val + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2->rel_val;

              std::string rel1Str = antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->rel_val;
              std::string rel2Str = antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2->rel_val;
              
              bool isSimpleVar1 = (rel1Str.find("*") == std::string::npos && rel1Str.find("+") == std::string::npos && rel1Str.find("-") == std::string::npos && rel1Str.find("/") == std::string::npos && rel1Str.find("%") == std::string::npos && rel1Str.find("(") == std::string::npos && rel1Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

              bool isSimpleVar2 = (rel2Str.find("*") == std::string::npos && rel2Str.find("+") == std::string::npos && rel2Str.find("-") == std::string::npos && rel2Str.find("/") == std::string::npos && rel2Str.find("%") == std::string::npos && rel2Str.find("(") == std::string::npos && rel2Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

              std::string label1 = newLabel();  
              std::string label2 = newLabel();   
              std::string label3 = newLabel();  
              std::string label4 = newLabel();  
              
              if (isSimpleVar1 && isSimpleVar2 && (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "||")) {
                  if (currentFunction.empty() || localVarOffset.find(rel1Str) == localVarOffset.end()) {
                      emitCode("MOV AX, " + rel1Str + "       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  } else {
                      emitCode("MOV AX, " + getVarOffset(rel1Str) + "       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  }
                  emitCode("CMP AX, 0");
                  emitCode("JNE " + label1);  
                  emitCode("JMP " + label3);  
                  
                  emitCode(label3 + ":");     

                  if (currentFunction.empty() || localVarOffset.find(rel2Str) == localVarOffset.end()) {
                      emitCode("MOV AX, " + rel2Str + "       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  } else {
                      emitCode("MOV AX, " + getVarOffset(rel2Str) + "       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  }
                  emitCode("CMP AX, 0");
                  emitCode("JNE " + label1);  
                  emitCode("JMP " + label2); 
                  
                  emitCode(label1 + ":");     
                  emitCode("MOV AX, 1       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  emitCode("JMP " + label4); 
                  emitCode(label2 + ":");     
                  emitCode("MOV AX, 0");
                  emitCode(label4 + ":");     
              } 
              
              else if (isSimpleVar1 && isSimpleVar2 && (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "&&")) {
                  if (currentFunction.empty() || localVarOffset.find(rel1Str) == localVarOffset.end()) {
                      emitCode("MOV AX, " + rel1Str + "       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  } else {
                      emitCode("MOV AX, " + getVarOffset(rel1Str) + "       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  }
                  emitCode("CMP AX, 0");
                  emitCode("JE " + label2);   
                  
                  if (currentFunction.empty() || localVarOffset.find(rel2Str) == localVarOffset.end()) {
                      emitCode("MOV AX, " + rel2Str + "       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  } else {
                      emitCode("MOV AX, " + getVarOffset(rel2Str) + "       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  }
                  emitCode("CMP AX, 0");
                  emitCode("JE " + label2);   

                  emitCode("MOV AX, 1       ; Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()));
                  emitCode("JMP " + label4); 
                  emitCode(label2 + ":");    
                  emitCode("MOV AX, 0");
                  emitCode(label4 + ":");     
              } else {
                  if (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "||") {
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
                  } else if (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getText() == "&&") {
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
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Logic_expressionContext *>(_localctx)->logicopToken->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n");
              writeIntoparserLogFile(_localctx->logic_val + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C8086Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C8086Parser::Simple_expressionContext *> C8086Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C8086Parser::Simple_expressionContext>();
}

C8086Parser::Simple_expressionContext* C8086Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C8086Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C8086Parser::Rel_expressionContext::RELOP() {
  return getToken(C8086Parser::RELOP, 0);
}


size_t C8086Parser::Rel_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleRel_expression;
}

void C8086Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C8086Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C8086Parser::Rel_expressionContext* C8086Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, C8086Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(396);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(388);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->rel_val =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->simple_val;
              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->start) : nullptr)->getLine()) + ": rel_expression : simple_expression\n");
              writeIntoparserLogFile(_localctx->rel_val + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(391);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1 = simple_expression(0);
      setState(392);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken = match(C8086Parser::RELOP);
      setState(393);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2 = simple_expression(0);

              antlrcpp::downCast<Rel_expressionContext *>(_localctx)->rel_val =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1->simple_val + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2->simple_val;
              std::string simple1Str = antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1->simple_val;
              std::string simple2Str = antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2->simple_val;
              
              bool isSimpleVar1 = (simple1Str.find("*") == std::string::npos && simple1Str.find("+") == std::string::npos && simple1Str.find("-") == std::string::npos && simple1Str.find("/") == std::string::npos && simple1Str.find("%") == std::string::npos && simple1Str.find("(") == std::string::npos && simple1Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

              bool isSimpleVar2 = (simple2Str.find("*") == std::string::npos && simple2Str.find("+") == std::string::npos && simple2Str.find("-") == std::string::npos && simple2Str.find("/") == std::string::npos && simple2Str.find("%") == std::string::npos && simple2Str.find("(") == std::string::npos && simple2Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

              std::string label1 = newLabel();
              std::string label2 = newLabel();
              std::string label3 = newLabel();

              if (!inForCondition) {
                  if (isSimpleVar1 && isSimpleVar2) {
                      if (currentFunction.empty() || localVarOffset.find(simple1Str) == localVarOffset.end()) {
                          emitCode("MOV AX, " + simple1Str + "       ; Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine()));
                      } else {
                          emitCode("MOV AX, " + getVarOffset(simple1Str) + "       ; Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine()));
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
                          emitCode("MOV AX, " + simple1Str + "       ; Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine()));
                      } else {
                          emitCode("MOV AX, " + getVarOffset(simple1Str) + "       ; Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine()));
                      }
                      emitCode("CMP AX, BX");
                  } 
                  
                  else {
                      emitCode("POP BX          ; Second operand");
                      emitCode("POP AX          ; First operand");
                      emitCode("CMP AX, BX");
                  }
              
                  if (inIfCondition) {
                      if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<") {
                          emitCode("JGE " + currentIfFalseLabel);  // Jump to false if NOT less than
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<=") {
                          emitCode("JG " + currentIfFalseLabel);   // Jump to false if NOT less than or equal
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">") {
                          emitCode("JLE " + currentIfFalseLabel);  // Jump to false if NOT greater than
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">=") {
                          emitCode("JL " + currentIfFalseLabel);   // Jump to false if NOT greater than or equal
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "==") {
                          emitCode("JNE " + currentIfFalseLabel);  // Jump to false if NOT equal
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "!=") {
                          emitCode("JE " + currentIfFalseLabel);   // Jump to false if equal
                      }
                  } 
                  
                  else if (inLoopCondition) {
                      if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<") {
                          emitCode("JL " + currentLoopBodyLabel);   // Jump to body if less than
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<=") {
                          emitCode("JLE " + currentLoopBodyLabel);  // Jump to body if less than or equal
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">") {
                          emitCode("JG " + currentLoopBodyLabel);   // Jump to body if greater than
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">=") {
                          emitCode("JGE " + currentLoopBodyLabel);  // Jump to body if greater than or equal
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "==") {
                          emitCode("JE " + currentLoopBodyLabel);   // Jump to body if equal
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "!=") {
                          emitCode("JNE " + currentLoopBodyLabel);  // Jump to body if not equal
                      }
                      emitCode("JMP " + currentLoopExitLabel);      // Jump to exit if condition fails
                  } 
                  
                  else {
                      std::string label1 = newLabel();
                      std::string label2 = newLabel();
                      std::string label3 = newLabel();
                      
                      if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<") {
                          emitCode("JL " + label1);
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "<=") {
                          emitCode("JLE " + label1);
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">") {
                          emitCode("JG " + label1);
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == ">=") {
                          emitCode("JGE " + label1);
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "==") {
                          emitCode("JE " + label1);
                      } else if (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getText() == "!=") {
                          emitCode("JNE " + label1);
                      }
                      
                      emitCode("JMP " + label3);
                      emitCode(label1 + ":");
                      emitCode("MOV AX, 1       ; Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine()));
                      emitCode("JMP " + label2);
                      emitCode(label3 + ":");
                      emitCode("MOV AX, 0");
                      emitCode(label2 + ":");
                      emitCode("PUSH AX");
                  }
              }  
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Rel_expressionContext *>(_localctx)->relopToken->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n");
              writeIntoparserLogFile(_localctx->rel_val + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C8086Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::TermContext* C8086Parser::Simple_expressionContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}

tree::TerminalNode* C8086Parser::Simple_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Simple_expressionContext* C8086Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C8086Parser::Simple_expressionContext>(0);
}


size_t C8086Parser::Simple_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleSimple_expression;
}

void C8086Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C8086Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C8086Parser::Simple_expressionContext* C8086Parser::simple_expression() {
   return simple_expression(0);
}

C8086Parser::Simple_expressionContext* C8086Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C8086Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, C8086Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(399);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

            antlrcpp::downCast<Simple_expressionContext *>(_localctx)->simple_val =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->term_val;
            writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": simple_expression : term\n");
            writeIntoparserLogFile(_localctx->simple_val + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(409);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->s = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(402);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(403);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
        setState(404);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                          antlrcpp::downCast<Simple_expressionContext *>(_localctx)->simple_val =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->simple_val + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->term_val;

                          std::string simpleStr = antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->simple_val;
                          std::string termStr = antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->term_val;
                          
                          bool isSimpleConst1 = (simpleStr.find("*") == std::string::npos &&  simpleStr.find("+") == std::string::npos &&  simpleStr.find("-") == std::string::npos && simpleStr.find("/") == std::string::npos && simpleStr.find("%") == std::string::npos && simpleStr.find("(") == std::string::npos && simpleStr.find_first_not_of("0123456789") == std::string::npos);

                          bool isSimpleConst2 = (termStr.find("*") == std::string::npos &&  termStr.find("+") == std::string::npos && termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos && termStr.find_first_not_of("0123456789") == std::string::npos);

                          bool isSimpleVar = (simpleStr.find("*") == std::string::npos && simpleStr.find("+") == std::string::npos &&  simpleStr.find("-") == std::string::npos && simpleStr.find("/") == std::string::npos && simpleStr.find("%") == std::string::npos && simpleStr.find("(") == std::string::npos);

                          bool isSimpleVar2 = (termStr.find("*") == std::string::npos && termStr.find("+") == std::string::npos &&  termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos && termStr.find_first_not_of("0123456789") != std::string::npos);
                          
                          if (isSimpleConst1 && isSimpleConst2) {
                              emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              emitCode("MOV DX, AX");
                              emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                                  emitCode("ADD AX, DX");
                              } else {
                                  emitCode("SUB AX, DX");
                              }
                          } 
                          
                          else if (isSimpleVar && isSimpleVar2) {
                              if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
                                  emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              } else {
                                  emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              }
                              emitCode("MOV DX, AX");

                              if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
                                  emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              } else {
                                  emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              }
                              
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                                  emitCode("ADD AX, DX");
                              } else {
                                  emitCode("SUB AX, DX");
                              }

                              if (!inAssignmentContext) {
                                  emitCode("PUSH AX");
                              }
                          } else if (isSimpleVar && isSimpleConst2) {
                              emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              emitCode("MOV DX, AX");
                              
                              if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
                                  emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              } else {
                                  emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              }
                              
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                                  emitCode("ADD AX, DX");
                              } else {
                                  emitCode("SUB AX, DX");
                              }

                              if (!inAssignmentContext) {
                                  emitCode("PUSH AX");
                              }
                          } else if (isSimpleVar) {
                              emitCode("POP AX       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              emitCode("MOV DX, AX");
                              
                              if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
                                  emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              } else {
                                  emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              }
                              
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                                  emitCode("ADD AX, DX");
                              } else {
                                  emitCode("SUB AX, DX");
                              }
                          } else if (isSimpleVar2) {
                              if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
                                  emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              } else {
                                  emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              }
                              emitCode("PUSH AX");

                              emitCode("POP BX          ; Second operand (term)");
                              emitCode("POP AX          ; First operand (simple_expression)");
                              
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                                  emitCode("ADD AX, BX");
                              } else {
                                  emitCode("SUB AX, BX");
                              }
                              emitCode("PUSH AX");
                          } else if (!isSimpleConst1 && !isSimpleVar && isSimpleConst2) {
                              emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              emitCode("MOV DX, AX");
                              emitCode("POP AX       ; Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()));
                              
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                                  emitCode("ADD AX, DX");
                              } else {
                                  emitCode("SUB AX, DX");
                              }
                              emitCode("PUSH AX");
                          } else {
                              emitCode("POP DX          ; Second operand (term)");
                              emitCode("POP AX          ; First operand (simple_expression)");
                              if (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getText() == "+") {
                                  emitCode("ADD AX, DX");
                              } else {
                                  emitCode("SUB AX, DX");
                              }
                          }
                          
                          if (!(isSimpleConst1 && isSimpleConst2) && !(isSimpleVar && isSimpleConst2) && !isSimpleVar2 && !(!isSimpleConst1 && !isSimpleVar && isSimpleConst2)) {
                              emitCode("PUSH AX");
                          }
                          
                          writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Simple_expressionContext *>(_localctx)->addopToken->getLine()) + ": simple_expression : simple_expression ADDOP term\n");
                          writeIntoparserLogFile(_localctx->simple_val + "\n");
                       
      }
      setState(411);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Simple_expression_errContext ------------------------------------------------------------------

C8086Parser::Simple_expression_errContext::Simple_expression_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Simple_expression_errContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

tree::TerminalNode* C8086Parser::Simple_expression_errContext::ASSIGNOP() {
  return getToken(C8086Parser::ASSIGNOP, 0);
}

C8086Parser::Simple_expressionContext* C8086Parser::Simple_expression_errContext::simple_expression() {
  return getRuleContext<C8086Parser::Simple_expressionContext>(0);
}


size_t C8086Parser::Simple_expression_errContext::getRuleIndex() const {
  return C8086Parser::RuleSimple_expression_err;
}

void C8086Parser::Simple_expression_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression_err(this);
}

void C8086Parser::Simple_expression_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression_err(this);
}

C8086Parser::Simple_expression_errContext* C8086Parser::simple_expression_err() {
  Simple_expression_errContext *_localctx = _tracker.createInstance<Simple_expression_errContext>(_ctx, getState());
  enterRule(_localctx, 42, C8086Parser::RuleSimple_expression_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    antlrcpp::downCast<Simple_expression_errContext *>(_localctx)->s = simple_expression(0);
    setState(413);
    match(C8086Parser::ADDOP);
    setState(414);
    antlrcpp::downCast<Simple_expression_errContext *>(_localctx)->assignopToken = match(C8086Parser::ASSIGNOP);
     
            writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Simple_expression_errContext *>(_localctx)->assignopToken->getLine()) + 
                             ": syntax error, unexpected ASSIGNOP\n");
            writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<Simple_expression_errContext *>(_localctx)->assignopToken->getLine()) + 
                                 ": syntax error, unexpected ASSIGNOP\n");
            syntaxErrorCount++;       

        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C8086Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Unary_expressionContext* C8086Parser::TermContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::TermContext::MULOP() {
  return getToken(C8086Parser::MULOP, 0);
}

C8086Parser::TermContext* C8086Parser::TermContext::term() {
  return getRuleContext<C8086Parser::TermContext>(0);
}


size_t C8086Parser::TermContext::getRuleIndex() const {
  return C8086Parser::RuleTerm;
}

void C8086Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C8086Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C8086Parser::TermContext* C8086Parser::term() {
   return term(0);
}

C8086Parser::TermContext* C8086Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C8086Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, C8086Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(418);
    antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

            antlrcpp::downCast<TermContext *>(_localctx)->term_val =  antlrcpp::downCast<TermContext *>(_localctx)->u->unary_val;
            writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->u->start) : nullptr)->getLine()) + ": term : unary_expression\n");
            writeIntoparserLogFile(_localctx->term_val + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(428);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(421);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(422);
        antlrcpp::downCast<TermContext *>(_localctx)->mulopToken = match(C8086Parser::MULOP);
        setState(423);
        antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

                          antlrcpp::downCast<TermContext *>(_localctx)->term_val =  antlrcpp::downCast<TermContext *>(_localctx)->t->term_val + antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() + antlrcpp::downCast<TermContext *>(_localctx)->u->unary_val;

                          std::string termStr = antlrcpp::downCast<TermContext *>(_localctx)->t->term_val;
                          std::string unaryStr = antlrcpp::downCast<TermContext *>(_localctx)->u->unary_val;

                          bool isSimpleTerm = (termStr.find("*") == std::string::npos && termStr.find("+") == std::string::npos &&  termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos);

                          bool isSimpleUnary = (unaryStr.find("*") == std::string::npos &&  unaryStr.find("+") == std::string::npos &&  unaryStr.find("-") == std::string::npos && unaryStr.find("/") == std::string::npos && unaryStr.find("%") == std::string::npos && unaryStr.find("(") == std::string::npos);
                          
                          if (isSimpleTerm && isSimpleUnary) { 
                              if (currentFunction.empty() || localVarOffset.find(unaryStr) == localVarOffset.end()) {
                                  emitCode("MOV AX, " + unaryStr + "       ; Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()));
                              } else {
                                  emitCode("MOV AX, " + getVarOffset(unaryStr) + "       ; Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()));
                              }
                              emitCode("MOV CX, AX");

                              if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
                                  emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()));
                              } else {
                                  emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()));
                              }
                          } else if (isSimpleTerm && !isSimpleUnary) {
                              emitCode("POP AX       ; Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()));
                              emitCode("MOV CX, AX");
                              emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()));
                          } else if (!isSimpleTerm && isSimpleUnary) {
                              emitCode("POP AX       ; Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()));
                              emitCode("MOV CX, " + unaryStr + "       ; Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()));
                          } else {
                              emitCode("POP CX          ; Second operand (unary_expression)");
                              emitCode("POP AX          ; First operand (term)");
                          }
                          
                          if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "*") {
                              emitCode("CWD");
                              emitCode("MUL CX");
                          } else if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "/") {
                              emitCode("CWD");
                              emitCode("DIV CX");
                          } else if (antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "%") {
                              emitCode("CWD");
                              emitCode("DIV CX");
                              emitCode("MOV AX, DX");
                          }
                          emitCode("PUSH AX");
                         
                          if(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "%" && (antlrcpp::downCast<TermContext *>(_localctx)->u->unary_val.find(".") != std::string::npos || antlrcpp::downCast<TermContext *>(_localctx)->t->term_val.find(".") != std::string::npos)){
                              writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": Non-Integer operand on modulus operator\n");
                              writeIntoparserLogFile("Error at line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": Non-Integer operand on modulus operator\n");
                              syntaxErrorCount++;            
                          }

                          if((antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "%" || antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getText() == "/") && antlrcpp::downCast<TermContext *>(_localctx)->u->unary_val == "0") {
                              writeIntoErrorFile("Error at line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": Modulus by Zero\n");
                              writeIntoparserLogFile("Error at line " + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": Modulus by Zero\n");
                              syntaxErrorCount++;
                          }
                          
                          writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<TermContext *>(_localctx)->mulopToken->getLine()) + ": term : term MULOP unary_expression\n");
                          writeIntoparserLogFile(_localctx->term_val + "\n");
                       
      }
      setState(430);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C8086Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::ADDOP() {
  return getToken(C8086Parser::ADDOP, 0);
}

C8086Parser::Unary_expressionContext* C8086Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C8086Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::Unary_expressionContext::NOT() {
  return getToken(C8086Parser::NOT, 0);
}

C8086Parser::FactorContext* C8086Parser::Unary_expressionContext::factor() {
  return getRuleContext<C8086Parser::FactorContext>(0);
}


size_t C8086Parser::Unary_expressionContext::getRuleIndex() const {
  return C8086Parser::RuleUnary_expression;
}

void C8086Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C8086Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C8086Parser::Unary_expressionContext* C8086Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 46, C8086Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(442);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(431);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken = match(C8086Parser::ADDOP);
        setState(432);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u = unary_expression();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_val =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->unary_val;

                std::string unaryStr = antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->unary_val;
                bool isSimpleVar = (unaryStr.find("*") == std::string::npos && unaryStr.find("+") == std::string::npos && unaryStr.find("-") == std::string::npos && unaryStr.find("/") == std::string::npos && unaryStr.find("%") == std::string::npos && unaryStr.find("(") == std::string::npos && unaryStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
                
                if (isSimpleVar && antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() == "-") {
                    if (currentFunction.empty() || localVarOffset.find(unaryStr) == localVarOffset.end()) {
                        emitCode("MOV AX, " + unaryStr + "       ; Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getLine()));
                    } else {
                        emitCode("MOV AX, " + getVarOffset(unaryStr) + "       ; Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getLine()));
                    }
                    emitCode("NEG AX");
                } else {
                    emitCode("POP AX          ; Get operand");
                    if (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getText() == "-") {
                        emitCode("NEG AX");
                    }
                    emitCode("PUSH AX");
                }
                
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->addopToken->getLine()) + ": unary_expression : ADDOP unary_expression\n");
                writeIntoparserLogFile(_localctx->unary_val + "\n");
            
        break;
      }

      case C8086Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(435);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken = match(C8086Parser::NOT);
        setState(436);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u = unary_expression();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_val =  "!" + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->unary_val;

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
                
                writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->notToken->getLine()) + ": unary_expression : NOT unary_expression\n");
                writeIntoparserLogFile(_localctx->unary_val + "\n");
            
        break;
      }

      case C8086Parser::LPAREN:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(439);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

                antlrcpp::downCast<Unary_expressionContext *>(_localctx)->unary_val =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->factor_val;
                writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f != nullptr ? (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->start) : nullptr)->getLine()) + ": unary_expression : factor\n");
                writeIntoparserLogFile(_localctx->unary_val + "\n");
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C8086Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::VariableContext* C8086Parser::FactorContext::variable() {
  return getRuleContext<C8086Parser::VariableContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::ID() {
  return getToken(C8086Parser::ID, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::LPAREN() {
  return getToken(C8086Parser::LPAREN, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::RPAREN() {
  return getToken(C8086Parser::RPAREN, 0);
}

C8086Parser::Argument_listContext* C8086Parser::FactorContext::argument_list() {
  return getRuleContext<C8086Parser::Argument_listContext>(0);
}

C8086Parser::ExpressionContext* C8086Parser::FactorContext::expression() {
  return getRuleContext<C8086Parser::ExpressionContext>(0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_INT() {
  return getToken(C8086Parser::CONST_INT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::CONST_FLOAT() {
  return getToken(C8086Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::INCOP() {
  return getToken(C8086Parser::INCOP, 0);
}

tree::TerminalNode* C8086Parser::FactorContext::DECOP() {
  return getToken(C8086Parser::DECOP, 0);
}


size_t C8086Parser::FactorContext::getRuleIndex() const {
  return C8086Parser::RuleFactor;
}

void C8086Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C8086Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C8086Parser::FactorContext* C8086Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 48, C8086Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(470);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(444);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

              antlrcpp::downCast<FactorContext *>(_localctx)->factor_val =  antlrcpp::downCast<FactorContext *>(_localctx)->v->var_name;

              std::string varName = antlrcpp::downCast<FactorContext *>(_localctx)->v->var_name;

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

              writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<FactorContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<FactorContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": factor : variable\n");
              writeIntoparserLogFile(_localctx->factor_val + "\n");
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(447);
      antlrcpp::downCast<FactorContext *>(_localctx)->idToken = match(C8086Parser::ID);
      setState(448);
      match(C8086Parser::LPAREN);
      setState(449);
      antlrcpp::downCast<FactorContext *>(_localctx)->a = argument_list();
      setState(450);
      match(C8086Parser::RPAREN);

              antlrcpp::downCast<FactorContext *>(_localctx)->factor_val =  antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "(" + antlrcpp::downCast<FactorContext *>(_localctx)->a->arg_list + ")";

              if(functionTable.find(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText()) == functionTable.end()){
                  writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                  writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": Undefined function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");       
                  syntaxErrorCount++;
              }
              else{
                  FunctionInfo& func = functionTable[antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText()];

                  if(func.returnType == "void"){
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": Void function used in expression\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": Void function used in expression\n");
                      syntaxErrorCount++;
                  }

                  std::vector<std::string> providedArgs;
                  std::istringstream argStream(antlrcpp::downCast<FactorContext *>(_localctx)->a->arg_list);
                  std::string arg;

                  while(std::getline(argStream, arg, ',')){
                      if(!arg.empty()){
                          providedArgs.push_back(arg);
                      }
                  }

                  if(providedArgs.size() != func.paramTypes.size()){
                      writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                      writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": Total number of arguments mismatch with declaration in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                      syntaxErrorCount++;
                  }
                  else{
                      for(size_t i = 0; i < providedArgs.size(); i++){
                          if(func.paramTypes[i] == "int" && providedArgs[i].find(".") != std::string::npos){
                              writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                              writeIntoparserLogFile("Error at line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "\n");
                              syntaxErrorCount++;
                              break;
                          }
                      }
                  }

                  emitCode("CALL " + antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getText() + "       ; Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()));
                  
                  if(func.returnType != "void") {
                      emitCode("PUSH AX");
                  } else {
                      emitCode("PUSH AX");
                  }
              }
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->idToken->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n");
              writeIntoparserLogFile(_localctx->factor_val + "\n");
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(453);
      antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken = match(C8086Parser::LPAREN);
      setState(454);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(455);
      match(C8086Parser::RPAREN);

              antlrcpp::downCast<FactorContext *>(_localctx)->factor_val =  "(" + antlrcpp::downCast<FactorContext *>(_localctx)->e->expr_val + ")";
              std::string exprStr = antlrcpp::downCast<FactorContext *>(_localctx)->e->expr_val;

              bool isSimpleArithmetic = (exprStr.find("*") == std::string::npos && exprStr.find("/") == std::string::npos && exprStr.find("%") == std::string::npos && exprStr.find("(") == std::string::npos && exprStr.find("&&") == std::string::npos && exprStr.find("||") == std::string::npos && (exprStr.find("+") != std::string::npos || exprStr.find("-") != std::string::npos));
              
              if (isSimpleArithmetic) {
                  emitCode("PUSH AX       ; Push parenthesized expression result");
              }
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->lparenToken->getLine()) + ": factor : LPAREN expression RPAREN\n");
              writeIntoparserLogFile(_localctx->factor_val + "\n");
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(458);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken = match(C8086Parser::CONST_INT);

              antlrcpp::downCast<FactorContext *>(_localctx)->factor_val =  antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getText();       
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->const_intToken->getLine()) + ": factor : CONST_INT\n");
              writeIntoparserLogFile(_localctx->factor_val + "\n");
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(460);
      antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken = match(C8086Parser::CONST_FLOAT);

              antlrcpp::downCast<FactorContext *>(_localctx)->factor_val =  antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText();
              emitCode("MOV AX, " + antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText().substr(0, antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getText().find(".")));
              emitCode("PUSH AX");
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->const_floatToken->getLine()) + ": factor : CONST_FLOAT\n");
              writeIntoparserLogFile(_localctx->factor_val + "\n");
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(462);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(463);
      antlrcpp::downCast<FactorContext *>(_localctx)->incopToken = match(C8086Parser::INCOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->factor_val =  antlrcpp::downCast<FactorContext *>(_localctx)->v->var_name + "++";

              if (!inForIncrement) {
                  std::string varName = antlrcpp::downCast<FactorContext *>(_localctx)->v->var_name;

                  size_t bracketPos = varName.find("[");
                  if (bracketPos != std::string::npos) {
                      std::string arrayName = varName.substr(0, bracketPos);
                      std::string indexStr = varName.substr(bracketPos + 1);
                      indexStr = indexStr.substr(0, indexStr.find("]"));
                      
                      if (currentFunction.empty() || localVarOffset.find(arrayName) == localVarOffset.end()) {
                          if (indexStr.find_first_not_of("0123456789") == std::string::npos) {
                              int index = std::stoi(indexStr);
                              emitCode("MOV AX, " + arrayName + "[" + std::to_string(index * 2) + "]       ; Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine()));
                              emitCode("PUSH AX");
                              emitCode("INC AX");
                              emitCode("MOV " + arrayName + "[" + std::to_string(index * 2) + "], AX");
                              emitCode("POP AX");
                          } else {
                              emitCode("MOV BX, " + indexStr);
                              emitCode("SHL BX, 1");  // Multiply by 2 for word size
                              emitCode("MOV AX, " + arrayName + "[BX]       ; Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine()));
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
                              emitCode("MOV AX, [BP-" + std::to_string(actualOffset) + "]       ; Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine()));
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
                              emitCode("MOV AX, [BP+BX]       ; Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine()));
                              emitCode("PUSH AX");
                              emitCode("INC AX");
                              emitCode("MOV [BP+BX], AX");
                              emitCode("POP AX");
                          }
                      }
                  } else {
                      // Regular variable (not array)
                      if (currentFunction.empty()) {
                          emitCode("MOV AX, " + varName + "       ; Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine()));
                          emitCode("PUSH AX");
                          emitCode("INC AX");
                          emitCode("MOV " + varName + ", AX");
                          emitCode("POP AX");
                      } else {
                          if (localVarOffset.find(varName) != localVarOffset.end()) {
                              emitCode("MOV AX, " + getVarOffset(varName) + "       ; Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine()));
                              emitCode("PUSH AX");
                              emitCode("INC AX");
                              emitCode("MOV " + getVarOffset(varName) + ", AX");
                              emitCode("POP AX");
                          }
                      }
                  }
              }
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->incopToken->getLine()) + ": factor : variable INCOP\n");
              writeIntoparserLogFile(_localctx->factor_val + "\n");
          
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(466);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(467);
      antlrcpp::downCast<FactorContext *>(_localctx)->decopToken = match(C8086Parser::DECOP);

              antlrcpp::downCast<FactorContext *>(_localctx)->factor_val =  antlrcpp::downCast<FactorContext *>(_localctx)->v->var_name + "--";

              std::string varName = antlrcpp::downCast<FactorContext *>(_localctx)->v->var_name;
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
              
              writeIntoparserLogFile("Line " + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->decopToken->getLine()) + ": factor : variable DECOP\n");
              writeIntoparserLogFile(_localctx->factor_val + "\n");
          
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C8086Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::ArgumentsContext* C8086Parser::Argument_listContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}


size_t C8086Parser::Argument_listContext::getRuleIndex() const {
  return C8086Parser::RuleArgument_list;
}

void C8086Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C8086Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C8086Parser::Argument_listContext* C8086Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 50, C8086Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(476);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C8086Parser::LPAREN:
      case C8086Parser::ADDOP:
      case C8086Parser::NOT:
      case C8086Parser::ID:
      case C8086Parser::CONST_INT:
      case C8086Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(472);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);

                antlrcpp::downCast<Argument_listContext *>(_localctx)->arg_list =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->args_val;
                writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<Argument_listContext *>(_localctx)->a != nullptr ? (antlrcpp::downCast<Argument_listContext *>(_localctx)->a->start) : nullptr)->getLine()) + ": argument_list : arguments\n");
                writeIntoparserLogFile(_localctx->arg_list + "\n");
            
        break;
      }

      case C8086Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

                antlrcpp::downCast<Argument_listContext *>(_localctx)->arg_list =  "";
                writeIntoparserLogFile("argument_list : <empty>\n");
                writeIntoparserLogFile("\n");
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C8086Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C8086Parser::Logic_expressionContext* C8086Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C8086Parser::Logic_expressionContext>(0);
}

tree::TerminalNode* C8086Parser::ArgumentsContext::COMMA() {
  return getToken(C8086Parser::COMMA, 0);
}

C8086Parser::ArgumentsContext* C8086Parser::ArgumentsContext::arguments() {
  return getRuleContext<C8086Parser::ArgumentsContext>(0);
}


size_t C8086Parser::ArgumentsContext::getRuleIndex() const {
  return C8086Parser::RuleArguments;
}

void C8086Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C8086Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C8086ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C8086Parser::ArgumentsContext* C8086Parser::arguments() {
   return arguments(0);
}

C8086Parser::ArgumentsContext* C8086Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C8086Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C8086Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, C8086Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(479);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();

            antlrcpp::downCast<ArgumentsContext *>(_localctx)->args_val =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->logic_val;

            std::string logicStr = antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->logic_val;
            bool isSimpleConstant = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("0123456789") == std::string::npos);
            
            bool isSimpleVar = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
            
            if (isSimpleConstant) {
                emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()));
                emitCode("PUSH AX");
            } 
            
            else if (isSimpleVar) {
                if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
                    emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()));
                } else {
                    emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()));
                }
                emitCode("PUSH AX");
            } 
            
            else {
                emitCode("POP AX       ; Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()));
                emitCode("PUSH AX");
            }
            
            writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()) + ": arguments : logic_expression\n");
            writeIntoparserLogFile(_localctx->args_val + "\n");
        
    _ctx->stop = _input->LT(-1);
    setState(489);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->a = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(482);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(483);
        match(C8086Parser::COMMA);
        setState(484);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();

                          antlrcpp::downCast<ArgumentsContext *>(_localctx)->args_val =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->args_val + "," + antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->logic_val;
                          
                          std::string logicStr = antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->logic_val;
                          bool isSimpleConstant = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("0123456789") == std::string::npos);
                          
                          bool isSimpleVar = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
                          
                          if (isSimpleConstant) {
                              emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()));
                              emitCode("PUSH AX");
                          } 
                          
                          else if (isSimpleVar) {
                              if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
                                  emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()));
                              } else {
                                  emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()));
                              }
                              emitCode("PUSH AX");
                          } else {
                              emitCode("POP AX       ; Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()));
                              emitCode("PUSH AX");
                          }
                          
                          writeIntoparserLogFile("Line " + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()) + ": arguments : arguments COMMA logic_expression\n");
                          writeIntoparserLogFile(_localctx->args_val + "\n");
                       
      }
      setState(491);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C8086Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 10: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 11: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 13: return case_statementsSempred(antlrcpp::downCast<Case_statementsContext *>(context), predicateIndex);
    case 20: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 22: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 26: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C8086Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C8086Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool C8086Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 3);
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::case_statementsSempred(Case_statementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C8086Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C8086Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c8086parserParserInitialize();
#else
  ::antlr4::internal::call_once(c8086parserParserOnceFlag, c8086parserParserInitialize);
#endif
}
