// Generated from /media/rageeb-hasan-shafee/New Volume/3-1/CSE 310/ICG/antlr4-skeletons/cpp/C8086Lexer.g4 by ANTLR 4.13.1

    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>

    extern std::ofstream lexLogFile;
    extern std::ofstream errorFile;
    extern std::ofstream parserLogFile;
    extern int syntaxErrorCount;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class C8086Lexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", "FOR", 
			"WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "SWITCH", "CASE", 
			"DEFAULT", "BREAK", "GOTO", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", 
			"RTHIRD", "SEMICOLON", "COMMA", "COLON", "ADDOP", "SUBOP", "MULOP", "INCOP", 
			"DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT", 
			"INVALID_CHAR"
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


	    void writeIntoLexLogFile(const std::string &message) {
	        if (!lexLogFile.is_open()) {
	            lexLogFile.open("lexLogFile.txt", std::ios::app);
	            if (!lexLogFile) {
	                std::cerr << "Error opening lexLogFile.txt" << std::endl;
	                return;
	            }
	        }
	        lexLogFile << message << std::endl;
	        lexLogFile.flush();
	    }


	public C8086Lexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "C8086Lexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 0:
			LINE_COMMENT_action((RuleContext)_localctx, actionIndex);
			break;
		case 1:
			BLOCK_COMMENT_action((RuleContext)_localctx, actionIndex);
			break;
		case 2:
			STRING_action((RuleContext)_localctx, actionIndex);
			break;
		case 4:
			IF_action((RuleContext)_localctx, actionIndex);
			break;
		case 5:
			ELSE_action((RuleContext)_localctx, actionIndex);
			break;
		case 6:
			FOR_action((RuleContext)_localctx, actionIndex);
			break;
		case 7:
			WHILE_action((RuleContext)_localctx, actionIndex);
			break;
		case 8:
			PRINTLN_action((RuleContext)_localctx, actionIndex);
			break;
		case 9:
			RETURN_action((RuleContext)_localctx, actionIndex);
			break;
		case 10:
			INT_action((RuleContext)_localctx, actionIndex);
			break;
		case 11:
			FLOAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 12:
			VOID_action((RuleContext)_localctx, actionIndex);
			break;
		case 13:
			SWITCH_action((RuleContext)_localctx, actionIndex);
			break;
		case 14:
			CASE_action((RuleContext)_localctx, actionIndex);
			break;
		case 15:
			DEFAULT_action((RuleContext)_localctx, actionIndex);
			break;
		case 16:
			BREAK_action((RuleContext)_localctx, actionIndex);
			break;
		case 17:
			GOTO_action((RuleContext)_localctx, actionIndex);
			break;
		case 18:
			LPAREN_action((RuleContext)_localctx, actionIndex);
			break;
		case 19:
			RPAREN_action((RuleContext)_localctx, actionIndex);
			break;
		case 20:
			LCURL_action((RuleContext)_localctx, actionIndex);
			break;
		case 21:
			RCURL_action((RuleContext)_localctx, actionIndex);
			break;
		case 22:
			LTHIRD_action((RuleContext)_localctx, actionIndex);
			break;
		case 23:
			RTHIRD_action((RuleContext)_localctx, actionIndex);
			break;
		case 24:
			SEMICOLON_action((RuleContext)_localctx, actionIndex);
			break;
		case 25:
			COMMA_action((RuleContext)_localctx, actionIndex);
			break;
		case 26:
			COLON_action((RuleContext)_localctx, actionIndex);
			break;
		case 27:
			ADDOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 28:
			SUBOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 29:
			MULOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 30:
			INCOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 31:
			DECOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 32:
			NOT_action((RuleContext)_localctx, actionIndex);
			break;
		case 33:
			RELOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 34:
			LOGICOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 35:
			ASSIGNOP_action((RuleContext)_localctx, actionIndex);
			break;
		case 36:
			ID_action((RuleContext)_localctx, actionIndex);
			break;
		case 37:
			CONST_INT_action((RuleContext)_localctx, actionIndex);
			break;
		case 38:
			CONST_FLOAT_action((RuleContext)_localctx, actionIndex);
			break;
		case 39:
			INVALID_CHAR_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void LINE_COMMENT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:

			        writeIntoLexLogFile(
			          "Line# " + std::to_string(getLine())
			          + ": Token <SINGLE LINE COMMENT> Lexeme "
			          + getText()
			        );
			    
			break;
		}
	}
	private void BLOCK_COMMENT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:

			      // extra braces create a new scope for your variables
			      {
			        std::string txt = getText();
			        std::string content = txt.substr(2, txt.size() - 4);
			        writeIntoLexLogFile(
			          "Line# " + std::to_string(getLine())
			          + ": Token <MULTI LINE COMMENT> Lexeme /*"
			          + content + "*/"
			        );
			      }
			    
			break;
		}
	}
	private void STRING_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:

			        writeIntoLexLogFile(
			          "Line# " + std::to_string(getLine())
			          + ": Token <STRING> Lexeme " + getText()
			        );
			    
			break;
		}
	}
	private void IF_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <IF> Lexeme " + getText()); 
			break;
		}
	}
	private void ELSE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ELSE> Lexeme " + getText()); 
			break;
		}
	}
	private void FOR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FOR> Lexeme " + getText()); 
			break;
		}
	}
	private void WHILE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <WHILE> Lexeme " + getText()); 
			break;
		}
	}
	private void PRINTLN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <PRINTLN> Lexeme " + getText()); 
			break;
		}
	}
	private void RETURN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 8:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RETURN> Lexeme " + getText()); 
			break;
		}
	}
	private void INT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 9:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INT> Lexeme " + getText()); 
			break;
		}
	}
	private void FLOAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 10:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <FLOAT> Lexeme " + getText()); 
			break;
		}
	}
	private void VOID_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 11:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <VOID> Lexeme " + getText()); 
			break;
		}
	}
	private void SWITCH_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 12:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SWITCH> Lexeme " + getText()); 
			break;
		}
	}
	private void CASE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 13:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CASE> Lexeme " + getText()); 
			break;
		}
	}
	private void DEFAULT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 14:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DEFAULT> Lexeme " + getText()); 
			break;
		}
	}
	private void BREAK_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 15:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <BREAK> Lexeme " + getText()); 
			break;
		}
	}
	private void GOTO_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 16:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <GOTO> Lexeme " + getText()); 
			break;
		}
	}
	private void LPAREN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 17:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LPAREN> Lexeme " + getText()); 
			break;
		}
	}
	private void RPAREN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 18:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RPAREN> Lexeme " + getText()); 
			break;
		}
	}
	private void LCURL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 19:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LCURL> Lexeme " + getText()); 
			break;
		}
	}
	private void RCURL_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 20:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RCURL> Lexeme " + getText()); 
			break;
		}
	}
	private void LTHIRD_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 21:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LTHIRD> Lexeme " + getText()); 
			break;
		}
	}
	private void RTHIRD_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 22:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RTHIRD> Lexeme " + getText()); 
			break;
		}
	}
	private void SEMICOLON_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 23:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SEMICOLON> Lexeme " + getText()); 
			break;
		}
	}
	private void COMMA_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 24:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <COMMA> Lexeme " + getText()); 
			break;
		}
	}
	private void COLON_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 25:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <COLON> Lexeme " + getText()); 
			break;
		}
	}
	private void ADDOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 26:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ADDOP> Lexeme " + getText()); 
			break;
		}
	}
	private void SUBOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 27:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <SUBOP> Lexeme " + getText()); 
			break;
		}
	}
	private void MULOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 28:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <MULOP> Lexeme " + getText()); 
			break;
		}
	}
	private void INCOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 29:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <INCOP> Lexeme " + getText()); 
			break;
		}
	}
	private void DECOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 30:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <DECOP> Lexeme " + getText()); 
			break;
		}
	}
	private void NOT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 31:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <NOT> Lexeme " + getText()); 
			break;
		}
	}
	private void RELOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 32:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <RELOP> Lexeme " + getText()); 
			break;
		}
	}
	private void LOGICOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 33:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <LOGICOP> Lexeme " + getText()); 
			break;
		}
	}
	private void ASSIGNOP_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 34:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ASSIGNOP> Lexeme " + getText()); 
			break;
		}
	}
	private void ID_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 35:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <ID> Lexeme " + getText()); 
			break;
		}
	}
	private void CONST_INT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 36:
			 writeIntoLexLogFile("Line# " + std::to_string(getLine()) + ": Token <CONST_INT> Lexeme " + getText()); 
			break;
		}
	}
	private void CONST_FLOAT_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 37:

			        writeIntoLexLogFile(
			          "Line# " + std::to_string(getLine())
			          + ": Token <CONST_FLOAT> Lexeme " + getText()
			        );
			    
			break;
		case 38:

			        writeIntoLexLogFile(
			          "Line# " + std::to_string(getLine())
			          + ": Token <CONST_FLOAT> Lexeme " + getText()
			        );
			    
			break;
		case 39:

			        writeIntoLexLogFile(
			          "Line# " + std::to_string(getLine())
			          + ": Token <CONST_FLOAT> Lexeme " + getText()
			        );
			    
			break;
		}
	}
	private void INVALID_CHAR_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 40:
			break;
		}
	}

	public static final String _serializedATN =
		"\u0004\u0000(\u0175\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002"+
		"\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002"+
		"\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002"+
		"\u0018\u0007\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002"+
		"\u001b\u0007\u001b\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002"+
		"\u001e\u0007\u001e\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007"+
		"!\u0002\"\u0007\"\u0002#\u0007#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007"+
		"&\u0002\'\u0007\'\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0005"+
		"\u0000V\b\u0000\n\u0000\f\u0000Y\t\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0005\u0001d\b\u0001\n\u0001\f\u0001g\t\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002t\b\u0002\n\u0002"+
		"\f\u0002w\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0003\u0004\u0003\u007f\b\u0003\u000b\u0003\f\u0003\u0080"+
		"\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010\u0001\u0010\u0001"+
		"\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0015\u0001\u0015\u0001\u0015\u0001"+
		"\u0016\u0001\u0016\u0001\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0001"+
		"\u0018\u0001\u0018\u0001\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u001a\u0001\u001a\u0001\u001a\u0001\u001b\u0001\u001b\u0001\u001b\u0001"+
		"\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d\u0001\u001d\u0001"+
		"\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001f\u0001"+
		"\u001f\u0001\u001f\u0001\u001f\u0001\u001f\u0001 \u0001 \u0001 \u0001"+
		"!\u0001!\u0001!\u0001!\u0001!\u0001!\u0001!\u0001!\u0001!\u0001!\u0001"+
		"!\u0003!\u012c\b!\u0001\"\u0001\"\u0001\"\u0001\"\u0001\"\u0001\"\u0003"+
		"\"\u0134\b\"\u0001#\u0001#\u0001#\u0001$\u0001$\u0005$\u013b\b$\n$\f$"+
		"\u013e\t$\u0001$\u0001$\u0001%\u0004%\u0143\b%\u000b%\f%\u0144\u0001%"+
		"\u0001%\u0001&\u0004&\u014a\b&\u000b&\f&\u014b\u0001&\u0001&\u0005&\u0150"+
		"\b&\n&\f&\u0153\t&\u0003&\u0155\b&\u0001&\u0001&\u0003&\u0159\b&\u0001"+
		"&\u0004&\u015c\b&\u000b&\f&\u015d\u0003&\u0160\b&\u0001&\u0001&\u0001"+
		"&\u0004&\u0165\b&\u000b&\f&\u0166\u0001&\u0001&\u0004&\u016b\b&\u000b"+
		"&\f&\u016c\u0001&\u0001&\u0003&\u0171\b&\u0001\'\u0001\'\u0001\'\u0001"+
		"e\u0000(\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b"+
		"\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b"+
		"\u000e\u001d\u000f\u001f\u0010!\u0011#\u0012%\u0013\'\u0014)\u0015+\u0016"+
		"-\u0017/\u00181\u00193\u001a5\u001b7\u001c9\u001d;\u001e=\u001f? A!C\""+
		"E#G$I%K&M\'O(\u0001\u0000\n\u0002\u0000\n\n\r\r\u0004\u0000\n\n\r\r\""+
		"\"\\\\\u0003\u0000\t\n\f\r  \u0002\u0000++--\u0003\u0000%%**//\u0002\u0000"+
		"<<>>\u0003\u0000AZ__az\u0004\u000009AZ__az\u0001\u000009\u0002\u0000E"+
		"Eee\u018b\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000"+
		"\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000"+
		"\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000"+
		"\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000"+
		"\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000"+
		"\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000"+
		"\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000\u0000"+
		"\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000\u0000"+
		"\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000%"+
		"\u0001\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000\u0000\u0000)\u0001"+
		"\u0000\u0000\u0000\u0000+\u0001\u0000\u0000\u0000\u0000-\u0001\u0000\u0000"+
		"\u0000\u0000/\u0001\u0000\u0000\u0000\u00001\u0001\u0000\u0000\u0000\u0000"+
		"3\u0001\u0000\u0000\u0000\u00005\u0001\u0000\u0000\u0000\u00007\u0001"+
		"\u0000\u0000\u0000\u00009\u0001\u0000\u0000\u0000\u0000;\u0001\u0000\u0000"+
		"\u0000\u0000=\u0001\u0000\u0000\u0000\u0000?\u0001\u0000\u0000\u0000\u0000"+
		"A\u0001\u0000\u0000\u0000\u0000C\u0001\u0000\u0000\u0000\u0000E\u0001"+
		"\u0000\u0000\u0000\u0000G\u0001\u0000\u0000\u0000\u0000I\u0001\u0000\u0000"+
		"\u0000\u0000K\u0001\u0000\u0000\u0000\u0000M\u0001\u0000\u0000\u0000\u0000"+
		"O\u0001\u0000\u0000\u0000\u0001Q\u0001\u0000\u0000\u0000\u0003^\u0001"+
		"\u0000\u0000\u0000\u0005o\u0001\u0000\u0000\u0000\u0007~\u0001\u0000\u0000"+
		"\u0000\t\u0084\u0001\u0000\u0000\u0000\u000b\u0089\u0001\u0000\u0000\u0000"+
		"\r\u0090\u0001\u0000\u0000\u0000\u000f\u0096\u0001\u0000\u0000\u0000\u0011"+
		"\u009e\u0001\u0000\u0000\u0000\u0013\u00a8\u0001\u0000\u0000\u0000\u0015"+
		"\u00b1\u0001\u0000\u0000\u0000\u0017\u00b7\u0001\u0000\u0000\u0000\u0019"+
		"\u00bf\u0001\u0000\u0000\u0000\u001b\u00c6\u0001\u0000\u0000\u0000\u001d"+
		"\u00cf\u0001\u0000\u0000\u0000\u001f\u00d6\u0001\u0000\u0000\u0000!\u00e0"+
		"\u0001\u0000\u0000\u0000#\u00e8\u0001\u0000\u0000\u0000%\u00ef\u0001\u0000"+
		"\u0000\u0000\'\u00f2\u0001\u0000\u0000\u0000)\u00f5\u0001\u0000\u0000"+
		"\u0000+\u00f8\u0001\u0000\u0000\u0000-\u00fb\u0001\u0000\u0000\u0000/"+
		"\u00fe\u0001\u0000\u0000\u00001\u0101\u0001\u0000\u0000\u00003\u0104\u0001"+
		"\u0000\u0000\u00005\u0107\u0001\u0000\u0000\u00007\u010a\u0001\u0000\u0000"+
		"\u00009\u010d\u0001\u0000\u0000\u0000;\u0110\u0001\u0000\u0000\u0000="+
		"\u0113\u0001\u0000\u0000\u0000?\u0118\u0001\u0000\u0000\u0000A\u011d\u0001"+
		"\u0000\u0000\u0000C\u012b\u0001\u0000\u0000\u0000E\u0133\u0001\u0000\u0000"+
		"\u0000G\u0135\u0001\u0000\u0000\u0000I\u0138\u0001\u0000\u0000\u0000K"+
		"\u0142\u0001\u0000\u0000\u0000M\u0170\u0001\u0000\u0000\u0000O\u0172\u0001"+
		"\u0000\u0000\u0000QR\u0005/\u0000\u0000RS\u0005/\u0000\u0000SW\u0001\u0000"+
		"\u0000\u0000TV\b\u0000\u0000\u0000UT\u0001\u0000\u0000\u0000VY\u0001\u0000"+
		"\u0000\u0000WU\u0001\u0000\u0000\u0000WX\u0001\u0000\u0000\u0000XZ\u0001"+
		"\u0000\u0000\u0000YW\u0001\u0000\u0000\u0000Z[\u0006\u0000\u0000\u0000"+
		"[\\\u0001\u0000\u0000\u0000\\]\u0006\u0000\u0001\u0000]\u0002\u0001\u0000"+
		"\u0000\u0000^_\u0005/\u0000\u0000_`\u0005*\u0000\u0000`e\u0001\u0000\u0000"+
		"\u0000ad\t\u0000\u0000\u0000bd\u0007\u0000\u0000\u0000ca\u0001\u0000\u0000"+
		"\u0000cb\u0001\u0000\u0000\u0000dg\u0001\u0000\u0000\u0000ef\u0001\u0000"+
		"\u0000\u0000ec\u0001\u0000\u0000\u0000fh\u0001\u0000\u0000\u0000ge\u0001"+
		"\u0000\u0000\u0000hi\u0005*\u0000\u0000ij\u0005/\u0000\u0000jk\u0001\u0000"+
		"\u0000\u0000kl\u0006\u0001\u0002\u0000lm\u0001\u0000\u0000\u0000mn\u0006"+
		"\u0001\u0001\u0000n\u0004\u0001\u0000\u0000\u0000ou\u0005\"\u0000\u0000"+
		"pq\u0005\\\u0000\u0000qt\t\u0000\u0000\u0000rt\b\u0001\u0000\u0000sp\u0001"+
		"\u0000\u0000\u0000sr\u0001\u0000\u0000\u0000tw\u0001\u0000\u0000\u0000"+
		"us\u0001\u0000\u0000\u0000uv\u0001\u0000\u0000\u0000vx\u0001\u0000\u0000"+
		"\u0000wu\u0001\u0000\u0000\u0000xy\u0005\"\u0000\u0000yz\u0006\u0002\u0003"+
		"\u0000z{\u0001\u0000\u0000\u0000{|\u0006\u0002\u0001\u0000|\u0006\u0001"+
		"\u0000\u0000\u0000}\u007f\u0007\u0002\u0000\u0000~}\u0001\u0000\u0000"+
		"\u0000\u007f\u0080\u0001\u0000\u0000\u0000\u0080~\u0001\u0000\u0000\u0000"+
		"\u0080\u0081\u0001\u0000\u0000\u0000\u0081\u0082\u0001\u0000\u0000\u0000"+
		"\u0082\u0083\u0006\u0003\u0001\u0000\u0083\b\u0001\u0000\u0000\u0000\u0084"+
		"\u0085\u0005i\u0000\u0000\u0085\u0086\u0005f\u0000\u0000\u0086\u0087\u0001"+
		"\u0000\u0000\u0000\u0087\u0088\u0006\u0004\u0004\u0000\u0088\n\u0001\u0000"+
		"\u0000\u0000\u0089\u008a\u0005e\u0000\u0000\u008a\u008b\u0005l\u0000\u0000"+
		"\u008b\u008c\u0005s\u0000\u0000\u008c\u008d\u0005e\u0000\u0000\u008d\u008e"+
		"\u0001\u0000\u0000\u0000\u008e\u008f\u0006\u0005\u0005\u0000\u008f\f\u0001"+
		"\u0000\u0000\u0000\u0090\u0091\u0005f\u0000\u0000\u0091\u0092\u0005o\u0000"+
		"\u0000\u0092\u0093\u0005r\u0000\u0000\u0093\u0094\u0001\u0000\u0000\u0000"+
		"\u0094\u0095\u0006\u0006\u0006\u0000\u0095\u000e\u0001\u0000\u0000\u0000"+
		"\u0096\u0097\u0005w\u0000\u0000\u0097\u0098\u0005h\u0000\u0000\u0098\u0099"+
		"\u0005i\u0000\u0000\u0099\u009a\u0005l\u0000\u0000\u009a\u009b\u0005e"+
		"\u0000\u0000\u009b\u009c\u0001\u0000\u0000\u0000\u009c\u009d\u0006\u0007"+
		"\u0007\u0000\u009d\u0010\u0001\u0000\u0000\u0000\u009e\u009f\u0005p\u0000"+
		"\u0000\u009f\u00a0\u0005r\u0000\u0000\u00a0\u00a1\u0005i\u0000\u0000\u00a1"+
		"\u00a2\u0005n\u0000\u0000\u00a2\u00a3\u0005t\u0000\u0000\u00a3\u00a4\u0005"+
		"l\u0000\u0000\u00a4\u00a5\u0005n\u0000\u0000\u00a5\u00a6\u0001\u0000\u0000"+
		"\u0000\u00a6\u00a7\u0006\b\b\u0000\u00a7\u0012\u0001\u0000\u0000\u0000"+
		"\u00a8\u00a9\u0005r\u0000\u0000\u00a9\u00aa\u0005e\u0000\u0000\u00aa\u00ab"+
		"\u0005t\u0000\u0000\u00ab\u00ac\u0005u\u0000\u0000\u00ac\u00ad\u0005r"+
		"\u0000\u0000\u00ad\u00ae\u0005n\u0000\u0000\u00ae\u00af\u0001\u0000\u0000"+
		"\u0000\u00af\u00b0\u0006\t\t\u0000\u00b0\u0014\u0001\u0000\u0000\u0000"+
		"\u00b1\u00b2\u0005i\u0000\u0000\u00b2\u00b3\u0005n\u0000\u0000\u00b3\u00b4"+
		"\u0005t\u0000\u0000\u00b4\u00b5\u0001\u0000\u0000\u0000\u00b5\u00b6\u0006"+
		"\n\n\u0000\u00b6\u0016\u0001\u0000\u0000\u0000\u00b7\u00b8\u0005f\u0000"+
		"\u0000\u00b8\u00b9\u0005l\u0000\u0000\u00b9\u00ba\u0005o\u0000\u0000\u00ba"+
		"\u00bb\u0005a\u0000\u0000\u00bb\u00bc\u0005t\u0000\u0000\u00bc\u00bd\u0001"+
		"\u0000\u0000\u0000\u00bd\u00be\u0006\u000b\u000b\u0000\u00be\u0018\u0001"+
		"\u0000\u0000\u0000\u00bf\u00c0\u0005v\u0000\u0000\u00c0\u00c1\u0005o\u0000"+
		"\u0000\u00c1\u00c2\u0005i\u0000\u0000\u00c2\u00c3\u0005d\u0000\u0000\u00c3"+
		"\u00c4\u0001\u0000\u0000\u0000\u00c4\u00c5\u0006\f\f\u0000\u00c5\u001a"+
		"\u0001\u0000\u0000\u0000\u00c6\u00c7\u0005s\u0000\u0000\u00c7\u00c8\u0005"+
		"w\u0000\u0000\u00c8\u00c9\u0005i\u0000\u0000\u00c9\u00ca\u0005t\u0000"+
		"\u0000\u00ca\u00cb\u0005c\u0000\u0000\u00cb\u00cc\u0005h\u0000\u0000\u00cc"+
		"\u00cd\u0001\u0000\u0000\u0000\u00cd\u00ce\u0006\r\r\u0000\u00ce\u001c"+
		"\u0001\u0000\u0000\u0000\u00cf\u00d0\u0005c\u0000\u0000\u00d0\u00d1\u0005"+
		"a\u0000\u0000\u00d1\u00d2\u0005s\u0000\u0000\u00d2\u00d3\u0005e\u0000"+
		"\u0000\u00d3\u00d4\u0001\u0000\u0000\u0000\u00d4\u00d5\u0006\u000e\u000e"+
		"\u0000\u00d5\u001e\u0001\u0000\u0000\u0000\u00d6\u00d7\u0005d\u0000\u0000"+
		"\u00d7\u00d8\u0005e\u0000\u0000\u00d8\u00d9\u0005f\u0000\u0000\u00d9\u00da"+
		"\u0005a\u0000\u0000\u00da\u00db\u0005u\u0000\u0000\u00db\u00dc\u0005l"+
		"\u0000\u0000\u00dc\u00dd\u0005t\u0000\u0000\u00dd\u00de\u0001\u0000\u0000"+
		"\u0000\u00de\u00df\u0006\u000f\u000f\u0000\u00df \u0001\u0000\u0000\u0000"+
		"\u00e0\u00e1\u0005b\u0000\u0000\u00e1\u00e2\u0005r\u0000\u0000\u00e2\u00e3"+
		"\u0005e\u0000\u0000\u00e3\u00e4\u0005a\u0000\u0000\u00e4\u00e5\u0005k"+
		"\u0000\u0000\u00e5\u00e6\u0001\u0000\u0000\u0000\u00e6\u00e7\u0006\u0010"+
		"\u0010\u0000\u00e7\"\u0001\u0000\u0000\u0000\u00e8\u00e9\u0005g\u0000"+
		"\u0000\u00e9\u00ea\u0005o\u0000\u0000\u00ea\u00eb\u0005t\u0000\u0000\u00eb"+
		"\u00ec\u0005o\u0000\u0000\u00ec\u00ed\u0001\u0000\u0000\u0000\u00ed\u00ee"+
		"\u0006\u0011\u0011\u0000\u00ee$\u0001\u0000\u0000\u0000\u00ef\u00f0\u0005"+
		"(\u0000\u0000\u00f0\u00f1\u0006\u0012\u0012\u0000\u00f1&\u0001\u0000\u0000"+
		"\u0000\u00f2\u00f3\u0005)\u0000\u0000\u00f3\u00f4\u0006\u0013\u0013\u0000"+
		"\u00f4(\u0001\u0000\u0000\u0000\u00f5\u00f6\u0005{\u0000\u0000\u00f6\u00f7"+
		"\u0006\u0014\u0014\u0000\u00f7*\u0001\u0000\u0000\u0000\u00f8\u00f9\u0005"+
		"}\u0000\u0000\u00f9\u00fa\u0006\u0015\u0015\u0000\u00fa,\u0001\u0000\u0000"+
		"\u0000\u00fb\u00fc\u0005[\u0000\u0000\u00fc\u00fd\u0006\u0016\u0016\u0000"+
		"\u00fd.\u0001\u0000\u0000\u0000\u00fe\u00ff\u0005]\u0000\u0000\u00ff\u0100"+
		"\u0006\u0017\u0017\u0000\u01000\u0001\u0000\u0000\u0000\u0101\u0102\u0005"+
		";\u0000\u0000\u0102\u0103\u0006\u0018\u0018\u0000\u01032\u0001\u0000\u0000"+
		"\u0000\u0104\u0105\u0005,\u0000\u0000\u0105\u0106\u0006\u0019\u0019\u0000"+
		"\u01064\u0001\u0000\u0000\u0000\u0107\u0108\u0005:\u0000\u0000\u0108\u0109"+
		"\u0006\u001a\u001a\u0000\u01096\u0001\u0000\u0000\u0000\u010a\u010b\u0007"+
		"\u0003\u0000\u0000\u010b\u010c\u0006\u001b\u001b\u0000\u010c8\u0001\u0000"+
		"\u0000\u0000\u010d\u010e\u0007\u0003\u0000\u0000\u010e\u010f\u0006\u001c"+
		"\u001c\u0000\u010f:\u0001\u0000\u0000\u0000\u0110\u0111\u0007\u0004\u0000"+
		"\u0000\u0111\u0112\u0006\u001d\u001d\u0000\u0112<\u0001\u0000\u0000\u0000"+
		"\u0113\u0114\u0005+\u0000\u0000\u0114\u0115\u0005+\u0000\u0000\u0115\u0116"+
		"\u0001\u0000\u0000\u0000\u0116\u0117\u0006\u001e\u001e\u0000\u0117>\u0001"+
		"\u0000\u0000\u0000\u0118\u0119\u0005-\u0000\u0000\u0119\u011a\u0005-\u0000"+
		"\u0000\u011a\u011b\u0001\u0000\u0000\u0000\u011b\u011c\u0006\u001f\u001f"+
		"\u0000\u011c@\u0001\u0000\u0000\u0000\u011d\u011e\u0005!\u0000\u0000\u011e"+
		"\u011f\u0006  \u0000\u011fB\u0001\u0000\u0000\u0000\u0120\u0121\u0005"+
		"<\u0000\u0000\u0121\u012c\u0005=\u0000\u0000\u0122\u0123\u0005=\u0000"+
		"\u0000\u0123\u012c\u0005=\u0000\u0000\u0124\u0125\u0005>\u0000\u0000\u0125"+
		"\u012c\u0005=\u0000\u0000\u0126\u012c\u0007\u0005\u0000\u0000\u0127\u0128"+
		"\u0005!\u0000\u0000\u0128\u0129\u0005=\u0000\u0000\u0129\u012a\u0001\u0000"+
		"\u0000\u0000\u012a\u012c\u0006!!\u0000\u012b\u0120\u0001\u0000\u0000\u0000"+
		"\u012b\u0122\u0001\u0000\u0000\u0000\u012b\u0124\u0001\u0000\u0000\u0000"+
		"\u012b\u0126\u0001\u0000\u0000\u0000\u012b\u0127\u0001\u0000\u0000\u0000"+
		"\u012cD\u0001\u0000\u0000\u0000\u012d\u012e\u0005&\u0000\u0000\u012e\u0134"+
		"\u0005&\u0000\u0000\u012f\u0130\u0005|\u0000\u0000\u0130\u0131\u0005|"+
		"\u0000\u0000\u0131\u0132\u0001\u0000\u0000\u0000\u0132\u0134\u0006\"\""+
		"\u0000\u0133\u012d\u0001\u0000\u0000\u0000\u0133\u012f\u0001\u0000\u0000"+
		"\u0000\u0134F\u0001\u0000\u0000\u0000\u0135\u0136\u0005=\u0000\u0000\u0136"+
		"\u0137\u0006##\u0000\u0137H\u0001\u0000\u0000\u0000\u0138\u013c\u0007"+
		"\u0006\u0000\u0000\u0139\u013b\u0007\u0007\u0000\u0000\u013a\u0139\u0001"+
		"\u0000\u0000\u0000\u013b\u013e\u0001\u0000\u0000\u0000\u013c\u013a\u0001"+
		"\u0000\u0000\u0000\u013c\u013d\u0001\u0000\u0000\u0000\u013d\u013f\u0001"+
		"\u0000\u0000\u0000\u013e\u013c\u0001\u0000\u0000\u0000\u013f\u0140\u0006"+
		"$$\u0000\u0140J\u0001\u0000\u0000\u0000\u0141\u0143\u0007\b\u0000\u0000"+
		"\u0142\u0141\u0001\u0000\u0000\u0000\u0143\u0144\u0001\u0000\u0000\u0000"+
		"\u0144\u0142\u0001\u0000\u0000\u0000\u0144\u0145\u0001\u0000\u0000\u0000"+
		"\u0145\u0146\u0001\u0000\u0000\u0000\u0146\u0147\u0006%%\u0000\u0147L"+
		"\u0001\u0000\u0000\u0000\u0148\u014a\u0007\b\u0000\u0000\u0149\u0148\u0001"+
		"\u0000\u0000\u0000\u014a\u014b\u0001\u0000\u0000\u0000\u014b\u0149\u0001"+
		"\u0000\u0000\u0000\u014b\u014c\u0001\u0000\u0000\u0000\u014c\u0154\u0001"+
		"\u0000\u0000\u0000\u014d\u0151\u0005.\u0000\u0000\u014e\u0150\u0007\b"+
		"\u0000\u0000\u014f\u014e\u0001\u0000\u0000\u0000\u0150\u0153\u0001\u0000"+
		"\u0000\u0000\u0151\u014f\u0001\u0000\u0000\u0000\u0151\u0152\u0001\u0000"+
		"\u0000\u0000\u0152\u0155\u0001\u0000\u0000\u0000\u0153\u0151\u0001\u0000"+
		"\u0000\u0000\u0154\u014d\u0001\u0000\u0000\u0000\u0154\u0155\u0001\u0000"+
		"\u0000\u0000\u0155\u015f\u0001\u0000\u0000\u0000\u0156\u0158\u0007\t\u0000"+
		"\u0000\u0157\u0159\u0007\u0003\u0000\u0000\u0158\u0157\u0001\u0000\u0000"+
		"\u0000\u0158\u0159\u0001\u0000\u0000\u0000\u0159\u015b\u0001\u0000\u0000"+
		"\u0000\u015a\u015c\u0007\b\u0000\u0000\u015b\u015a\u0001\u0000\u0000\u0000"+
		"\u015c\u015d\u0001\u0000\u0000\u0000\u015d\u015b\u0001\u0000\u0000\u0000"+
		"\u015d\u015e\u0001\u0000\u0000\u0000\u015e\u0160\u0001\u0000\u0000\u0000"+
		"\u015f\u0156\u0001\u0000\u0000\u0000\u015f\u0160\u0001\u0000\u0000\u0000"+
		"\u0160\u0161\u0001\u0000\u0000\u0000\u0161\u0171\u0006&&\u0000\u0162\u0164"+
		"\u0005.\u0000\u0000\u0163\u0165\u0007\b\u0000\u0000\u0164\u0163\u0001"+
		"\u0000\u0000\u0000\u0165\u0166\u0001\u0000\u0000\u0000\u0166\u0164\u0001"+
		"\u0000\u0000\u0000\u0166\u0167\u0001\u0000\u0000\u0000\u0167\u0168\u0001"+
		"\u0000\u0000\u0000\u0168\u0171\u0006&\'\u0000\u0169\u016b\u0007\b\u0000"+
		"\u0000\u016a\u0169\u0001\u0000\u0000\u0000\u016b\u016c\u0001\u0000\u0000"+
		"\u0000\u016c\u016a\u0001\u0000\u0000\u0000\u016c\u016d\u0001\u0000\u0000"+
		"\u0000\u016d\u016e\u0001\u0000\u0000\u0000\u016e\u016f\u0005.\u0000\u0000"+
		"\u016f\u0171\u0006&(\u0000\u0170\u0149\u0001\u0000\u0000\u0000\u0170\u0162"+
		"\u0001\u0000\u0000\u0000\u0170\u016a\u0001\u0000\u0000\u0000\u0171N\u0001"+
		"\u0000\u0000\u0000\u0172\u0173\t\u0000\u0000\u0000\u0173\u0174\u0006\'"+
		")\u0000\u0174P\u0001\u0000\u0000\u0000\u0014\u0000Wcesu\u0080\u012b\u0133"+
		"\u013c\u0144\u014b\u0151\u0154\u0158\u015d\u015f\u0166\u016c\u0170*\u0001"+
		"\u0000\u0000\u0006\u0000\u0000\u0001\u0001\u0001\u0001\u0002\u0002\u0001"+
		"\u0004\u0003\u0001\u0005\u0004\u0001\u0006\u0005\u0001\u0007\u0006\u0001"+
		"\b\u0007\u0001\t\b\u0001\n\t\u0001\u000b\n\u0001\f\u000b\u0001\r\f\u0001"+
		"\u000e\r\u0001\u000f\u000e\u0001\u0010\u000f\u0001\u0011\u0010\u0001\u0012"+
		"\u0011\u0001\u0013\u0012\u0001\u0014\u0013\u0001\u0015\u0014\u0001\u0016"+
		"\u0015\u0001\u0017\u0016\u0001\u0018\u0017\u0001\u0019\u0018\u0001\u001a"+
		"\u0019\u0001\u001b\u001a\u0001\u001c\u001b\u0001\u001d\u001c\u0001\u001e"+
		"\u001d\u0001\u001f\u001e\u0001 \u001f\u0001! \u0001\"!\u0001#\"\u0001"+
		"$#\u0001%$\u0001&%\u0001&&\u0001&\'\u0001\'(";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}