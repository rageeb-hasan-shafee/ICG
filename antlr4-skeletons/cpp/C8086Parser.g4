parser grammar C8086Parser;

options {
    tokenVocab = C8086Lexer;
}

@parser::header {
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
}

@parser::members {
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
}

start : program
    {        
        writeIntoparserLogFile("\nLine " + std::to_string($program.stop->getLine()) + ": start : program\n");
        
        symb.printAllScopes(parserLogFile);
        
        writeIntoparserLogFile("\nTotal number of lines: " + std::to_string($program.stop->getLine()));
        writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));
        
        writeASMToFile();
    }
    ;

program returns [str_list prog_list] 
    : p=program u=unit
    {
        $prog_list.set_variables($p.prog_list.get_variables());
        $prog_list.add($u.unit_val);
        writeIntoparserLogFile("\nLine " + std::to_string($u.stop->getLine()) + ": program : program unit\n");

        std::string output = $prog_list.get_list_as_string();
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
    | u=unit
    {
        $prog_list.add($u.unit_val);
        writeIntoparserLogFile("\nLine " + std::to_string($u.stop->getLine()) + ": program : unit\n");
        writeIntoparserLogFile($prog_list.get_list_as_string() + "\n");
    }
    ;

unit returns [std::string unit_val]
    : vd=var_declaration
    {
        $unit_val = $vd.var_decl;
        writeIntoparserLogFile("Line " + std::to_string($vd.start->getLine()) + ": unit : var_declaration\n");
        writeIntoparserLogFile($unit_val );
    }
    | fd=func_declaration
    {
        $unit_val = $fd.func_decl;
        writeIntoparserLogFile("Line " + std::to_string($fd.start->getLine()) + ": unit : func_declaration\n");
        writeIntoparserLogFile($unit_val);
    }
    | fdef=func_definition
    {
        $unit_val = $fdef.func_def;
        writeIntoparserLogFile("Line " + std::to_string($fdef.stop->getLine()) + ": unit : func_definition\n");
        writeIntoparserLogFile($unit_val);
    }
    ;

func_declaration returns [std::string func_decl]
    : t=type_specifier ID LPAREN p=parameter_list RPAREN SEMICOLON
    {
        if (symb.getCurrentScope()->lookUp(parserLogFile, $ID->getText()) == nullptr) {
            SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "FUNCTION");
            symb.insert(funcSymbol);
        }

        $func_decl = $t.name_line + " " + $ID->getText() + "(" + $p.param_list + ");";

        FunctionInfo fi;
        fi.returnType = $t.name_line;
        fi.isDefined = false;
        fi.paramTypes = $p.param_types;
        functionTable[$ID->getText()] = fi;
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
        writeIntoparserLogFile($func_decl + "\n\n");
    }
    | t=type_specifier ID LPAREN RPAREN SEMICOLON
    {
        if (symb.getCurrentScope()->lookUp(parserLogFile, $ID->getText()) == nullptr) {
            SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "FUNCTION");  
            symb.insert(funcSymbol);
        }
        $func_decl = $t.name_line + " " + $ID->getText() + "();";
        
        FunctionInfo fi;
        fi.returnType = $t.name_line;
        fi.isDefined = false;
        functionTable[$ID->getText()] = fi;
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");
        writeIntoparserLogFile($func_decl + "\n\n"); 

    };

func_definition returns [std::string func_def]
    : t=type_specifier ID
    {
        currentFunction = $ID->getText();
        currentOffset = 0;
        localVarOffset.clear();
        currentFunctionParams.clear();  
        hasReturnStatement = false;  
        
        // Generating function prologue
        if ($ID->getText() == "main") {
            emitCode("main PROC");
            emitCode("MOV AX, @DATA");
            emitCode("MOV DS, AX");
            inMainFunction = true;
        } else {
            emitCode($ID->getText() + " PROC");
        }
        emitCode("PUSH BP");
        emitCode("MOV BP, SP");

        if(functionTable.find($ID->getText()) != functionTable.end()) {
            FunctionInfo& existingFunc = functionTable[$ID->getText()];
            if(existingFunc.returnType != $t.name_line) {
                syntaxErrorCount++;
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Return type mismatch of " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Return type mismatch of " + $ID->getText() + "\n");
            }
            if(existingFunc.isDefined) {
                syntaxErrorCount++;
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple definition of " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple definition of " + $ID->getText() + "\n");                
            }
        }

        SymbolInfo* found = symb.getCurrentScope()->lookUp(parserLogFile, $ID->getText());
        if(found != nullptr && found->getType() != "FUNCTION") {
            syntaxErrorCount++;
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");                
        }

        if(found == nullptr) {
            SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "FUNCTION");
            symb.insert(funcSymbol);
        }
    } LPAREN
    {
        symb.enterScope();
        scopeEntered = true;
    } 
    p=parameter_list RPAREN 
    {
        int totalParams = $p.param_types.size();
        if (totalParams > 1) {
            for (size_t i = 0; i < currentFunctionParams.size(); i++) {
                int paramOffset = 4 + (totalParams - 1 - i) * 2;

                localVarOffset[currentFunctionParams[i]] = -paramOffset;
            }
        }
        
        if(functionTable.find($ID->getText()) != functionTable.end()) {
            FunctionInfo& existingFunc = functionTable[$ID->getText()];
            
            if(!existingFunc.isDefined) { 
                if(existingFunc.paramTypes.size() != $p.param_types.size()) {
                    syntaxErrorCount++;
                    writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");
                    writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");
                }
                else {
                    for(size_t i = 0; i < existingFunc.paramTypes.size(); i++) {
                        if(existingFunc.paramTypes[i] != $p.param_types[i]) {
                            syntaxErrorCount++;
                            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + $ID->getText() + "\n");
                            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + $ID->getText() + "\n");
                        }
                    }
                }
            }
        }

        FunctionInfo fi;
        fi.returnType = $t.name_line;
        fi.isDefined = true;
        fi.paramTypes = $p.param_types;
        functionTable[$ID->getText()] = fi;      
    }
    c=compound_statement
    {
        $func_def = $t.name_line + " " + $ID->getText() + "(" + $p.param_list + ")" + $c.comp_stmt;
        
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
                int paramBytes = $p.param_types.size() * 2;
                if (paramBytes > 0) {
                    emitCode("RET " + std::to_string(paramBytes));
                } else {
                    emitCode("RET");
                }
            }
            emitCode($ID->getText() + " ENDP");
            returnLabel = "";  
        }

        if(functionTable.find(currentFunction) != functionTable.end()) {
            FunctionInfo& currentFunc = functionTable[currentFunction];
            if(currentFunc.returnType == "void" && $c.comp_stmt.find("return") != std::string::npos) {
                writeIntoErrorFile("Error at line " + std::to_string($c.stop->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
                writeIntoparserLogFile("Error at line " + std::to_string($c.stop->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
                syntaxErrorCount++;
            }
        }
        
        currentFunction = "";
        symb.exitScope();
        scopeEntered = false;
        
        writeIntoparserLogFile("Line " + std::to_string($c.stop->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");
        writeIntoparserLogFile($func_def + "\n\n");
        
    }

    | t=type_specifier ID 
    {
        currentFunction = $ID->getText();
        currentOffset = 0;
        localVarOffset.clear();
        currentFunctionParams.clear();  
        hasReturnStatement = false;  

        if ($ID->getText() == "main") {
            emitCode("main PROC");
            emitCode("MOV AX, @DATA");
            emitCode("MOV DS, AX");
            inMainFunction = true;
        } else {
            emitCode($ID->getText() + " PROC");
        }
        emitCode("PUSH BP");
        emitCode("MOV BP, SP");
        
        if(functionTable.find($ID->getText()) != functionTable.end()) {
            FunctionInfo& existingFunc = functionTable[$ID->getText()];
            
            if(existingFunc.returnType != $t.name_line) {
                syntaxErrorCount++;
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Return type mismatch of " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Return type mismatch of " + $ID->getText() + "\n");
            }
            
            if(existingFunc.isDefined) {
                syntaxErrorCount++;
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple definition of " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple definition of " + $ID->getText() + "\n");                              
            }
        }

        SymbolInfo* found = symb.getCurrentScope()->lookUp(parserLogFile, $ID->getText());
        if(found != nullptr && found->getType() != "FUNCTION") {
            syntaxErrorCount++;
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + "\n");                
        }

        if(found == nullptr) {
            SymbolInfo* funcSymbol = new SymbolInfo($ID->getText(), "FUNCTION");
            symb.insert(funcSymbol);
        }
    }
    LPAREN RPAREN 
    {
        symb.enterScope();
        scopeEntered = true;
        
        if(functionTable.find($ID->getText()) != functionTable.end()) {
            FunctionInfo& existingFunc = functionTable[$ID->getText()];
            
            if(!existingFunc.isDefined && !existingFunc.paramTypes.empty()) {
                syntaxErrorCount++;
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");
            }
        }
        
        FunctionInfo fi;
        fi.returnType = $t.name_line;
        fi.isDefined = true;
        functionTable[$ID->getText()] = fi;        
    }
    c=compound_statement
    {
        $func_def = $t.name_line + " " + $ID->getText() + "()" + $c.comp_stmt;
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
            emitCode($ID->getText() + " ENDP");
            returnLabel = "";  
        }

        if(functionTable.find(currentFunction) != functionTable.end()) {
            FunctionInfo& currentFunc = functionTable[currentFunction];
            if(currentFunc.returnType == "void" && $c.comp_stmt.find("return") != std::string::npos) {
                writeIntoErrorFile("Error at line " + std::to_string($c.stop->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
                writeIntoparserLogFile("Error at line " + std::to_string($c.stop->getLine()) + ": Cannot return value from function " + currentFunction + " with void return type\n");
                syntaxErrorCount++;
            }
        }
        
        currentFunction = "";
        symb.exitScope();
        scopeEntered = false; 
        
        writeIntoparserLogFile("Line " + std::to_string($c.stop->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");
        writeIntoparserLogFile($func_def + "\n\n");

    }
    ;

parameter_list returns [std::string param_list, std::vector<std::string> param_types]
    : p=parameter_list COMMA t=type_specifier ID
    {
        if(symb.getCurrentScope()->lookUp(parserLogFile, $ID->getText()) != nullptr){
            syntaxErrorCount++;
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + " in parameter\n");
            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Multiple declaration of " + $ID->getText() + " in parameter\n");
        }

        $param_list = $p.param_list + "," + $t.name_line + " " + $ID->getText();
        $param_types = $p.param_types;
        $param_types.push_back($t.name_line);

        if (scopeEntered) {
            SymbolInfo* paramSymbol = new SymbolInfo($ID->getText(), "ID");
            symb.insert(paramSymbol);
            
            // Adding to parameter tracking list
            currentFunctionParams.push_back($ID->getText());
            
            // Seting parameter offset (parameters are at positive offsets from BP)
            // Initial assignment - will be corrected after parsing all parameters
            int totalParams = $param_types.size();            
            int paramOffset = 4 + (totalParams - 1) * 2;      
            localVarOffset[$ID->getText()] = -paramOffset;  
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID\n");
        writeIntoparserLogFile($param_list + "\n");
    }

    | p=parameter_list COMMA t=type_specifier
    {
        $param_list = $p.param_list + "," + $t.name_line + " " ;
        $param_types = $p.param_types;
        $param_types.push_back($t.name_line);
        
        writeIntoparserLogFile("Line " + std::to_string($t.start->getLine()) + ": parameter_list : parameter_list COMMA type_specifier\n");
        writeIntoparserLogFile($param_list + "\n");
    }

    | t=type_specifier ID
    {
        $param_list = $t.name_line + " " + $ID->getText() ;
        $param_types.push_back($t.name_line);

        if(scopeEntered){
            SymbolInfo* paramSymbol = new SymbolInfo($ID->getText(), "ID");
            symb.insert(paramSymbol);
            
            // Adding to parameter tracking list  
            currentFunctionParams.push_back($ID->getText());
            
            // Setting parameter offset (parameter will be at [BP+4] - will be adjusted later)
            int initialOffset = 4;
            localVarOffset[$ID->getText()] = -initialOffset;  // Store as negative to indicate parameter
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": parameter_list : type_specifier ID\n");
        writeIntoparserLogFile($param_list + "\n");
    }

    | t=type_specifier
    {
        $param_list = $t.name_line ;
        $param_types.push_back($t.name_line);
        
        writeIntoparserLogFile("Line " + std::to_string($t.start->getLine()) + ": parameter_list : type_specifier\n");
        writeIntoparserLogFile($param_list + "\n");
    }
    
    | t=type_specifier ADDOP
    {
        $param_list = $t.name_line ;
        $param_types.push_back($t.name_line);
        writeIntoErrorFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");
        writeIntoparserLogFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting RPAREN or COMMA\n");       
        syntaxErrorCount++;
        
    };

compound_statement returns [std::string comp_stmt]
    :LCURL 
    {
        if (!scopeEntered) {
            symb.enterScope();
            scopeEntered = true;
        }        
    } s=statements RCURL
    {
        $comp_stmt = "{\n" + $s.stmt_list + "}\n";

        writeIntoparserLogFile("Line " + std::to_string($RCURL->getLine()) + ": compound_statement : LCURL statements RCURL\n");
        writeIntoparserLogFile($comp_stmt + "\n");
        symb.printAllScopes(parserLogFile);
        writeIntoparserLogFile("\n");

        if (!scopeEntered) {
            symb.exitScope();
            scopeEntered = false;
        }     
    }
    
    | LCURL RCURL
    {
        symb.enterScope();
        $comp_stmt = "{\n}\n";
        
        writeIntoparserLogFile("Line " + std::to_string($RCURL->getLine()) + ": compound_statement : LCURL RCURL\n");
        writeIntoparserLogFile($comp_stmt + "\n");
        symb.printAllScopes(parserLogFile);
        writeIntoparserLogFile("\n");
        
        symb.exitScope();
    };
             
var_declaration returns [std::string var_decl]
    : t=type_specifier dl=declaration_list sm=SEMICOLON
    {
        if($t.name_line == "void"){
            writeIntoErrorFile("Error at line " + std::to_string($sm->getLine()) + ": Variable type cannot be void\n");
            writeIntoparserLogFile("Error at line " + std::to_string($sm->getLine()) + ": Variable type cannot be void\n");
            syntaxErrorCount++;        
        }

        // Generating assembly for variable declarations
        std::string vars = $dl.var_list.get_list_as_string();
        std::istringstream varStream(vars);
        std::string varEntry;
        
        while (std::getline(varStream, varEntry, ',')) {
            varEntry.erase(0, varEntry.find_first_not_of(" \t"));
            varEntry.erase(varEntry.find_last_not_of(" \t") + 1);
            
            std::string varName = varEntry;
            std::string varType = $t.name_line;
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
                writeIntoErrorFile("Error at line " + std::to_string($sm->getLine()) + ": Multiple declaration of " + varName + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string($sm->getLine()) + ": Multiple declaration of " + varName + "\n");
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

        $var_decl = $t.name_line + " " + $dl.var_list.get_list_as_string() + ";";
        
        writeIntoparserLogFile("Line " + std::to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON\n");
        writeIntoparserLogFile($var_decl + "\n");
    }

    | t=type_specifier de=declaration_list_err sm=SEMICOLON {
        syntaxErrorCount++;
      }
    ;

declaration_list_err returns [std::string error_name]: {
        $error_name = "Error in declaration list";
    };

type_specifier returns [std::string name_line]	
    : INT {
        $name_line = $INT->getText();
        writeIntoparserLogFile("Line " + std::to_string($INT->getLine()) + ": type_specifier : INT\n");
        writeIntoparserLogFile($name_line + "\n");
    }
     | FLOAT {
        $name_line = $FLOAT->getText();
        writeIntoparserLogFile("Line " + std::to_string($FLOAT->getLine()) + ": type_specifier : FLOAT\n");
        writeIntoparserLogFile($name_line + "\n");
    }
     | VOID {
        $name_line = $VOID->getText();
        writeIntoparserLogFile("Line " + std::to_string($VOID->getLine()) + ": type_specifier : VOID\n");
        writeIntoparserLogFile($name_line + "\n");
    };

declaration_list returns [str_list var_list]
    : dl=declaration_list COMMA ID
    {
        $var_list = $dl.var_list;
        $var_list.add($ID->getText());
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": declaration_list : declaration_list COMMA ID\n");
        writeIntoparserLogFile($var_list.get_list_as_string() + "\n");
    }
    | dl=declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
    {
        $var_list = $dl.var_list;
        $var_list.add($ID->getText() + "[" + $CONST_INT->getText() + "]");
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
        writeIntoparserLogFile($var_list.get_list_as_string() + "\n");
    }
    | ID
    {
        $var_list.add($ID->getText());
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": declaration_list : ID\n");
        writeIntoparserLogFile($ID->getText() + "\n");
    }
    | ID LTHIRD CONST_INT RTHIRD
    {
        $var_list.add($ID->getText() + "[" + $CONST_INT->getText() + "]");
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n");
        writeIntoparserLogFile($ID->getText() + "[" + $CONST_INT->getText() + "]\n");
    }

    | dl=declaration_list ADDOP ID
    {
        $var_list = $dl.var_list;
        syntaxErrorCount++;
        writeIntoErrorFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
        writeIntoparserLogFile("Error at line " + std::to_string($ADDOP->getLine()) + ": syntax error, unexpected ADDOP, expecting COMMA or SEMICOLON\n");
    }
    ;

statements returns [std::string stmt_list]
    : s=statement
    {
        $stmt_list = $s.stmt_val;
        writeIntoparserLogFile("Line " + std::to_string($s.start->getLine()) + ": statements : statement\n");
        writeIntoparserLogFile($stmt_list + "\n");
    }	

    | st=statements s=statement
    {
        $stmt_list = $st.stmt_list.substr(0, $st.stmt_list.length()) + $s.stmt_val;
        writeIntoparserLogFile("Line " + std::to_string($s.stop->getLine()) + ": statements : statements statement\n");
        writeIntoparserLogFile($stmt_list + "\n");
    }
    | st=statements variable ASSIGNOP simple_expression_err
    {
        $stmt_list = $st.stmt_list.substr(0, $st.stmt_list.length());
    }
    | st=statements expression INVALID_CHAR
    {
        $stmt_list = $st.stmt_list.substr(0, $st.stmt_list.length());
        syntaxErrorCount++;
        writeIntoErrorFile("Error at line " + std::to_string($INVALID_CHAR->getLine()) + ": Unrecognized character " + $INVALID_CHAR->getText() + "\n");
        writeIntoparserLogFile("Error at line " + std::to_string($INVALID_CHAR->getLine()) + ": Unrecognized character " + $INVALID_CHAR->getText() + "\n");                            
    }
    ;

statement returns [std::string stmt_val]
    : vd=var_declaration
    {
        $stmt_val = $vd.var_decl + "\n";
        
        writeIntoparserLogFile("Line " + std::to_string($vd.start->getLine()) + ": statement : var_declaration\n");
        writeIntoparserLogFile($stmt_val + "\n");
    }

    | es=expression_statement
    {
        $stmt_val = $es.expr_stmt + "\n";
        
        writeIntoparserLogFile("Line " + std::to_string($es.start->getLine()) + ": statement : expression_statement\n");
        writeIntoparserLogFile($stmt_val + "\n");
    }

    | c=compound_statement
    {
        $stmt_val = $c.comp_stmt + "\n";
        
        writeIntoparserLogFile("Line " + std::to_string($c.stop->getLine()) + ": statement : compound_statement\n");
        writeIntoparserLogFile($stmt_val + "\n");
    }
    | FOR LPAREN es1=expression_statement
    {
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
    }
    es2=expression_statement
    {

    }
    e=expression RPAREN
    {
        inForCondition = false;
        inForIncrement = false;
    }
    s=statement
    {
        symb.exitScope();

        std::string incrementExpr = $e.expr_val;
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

        std::string conditionExpr = $es2.expr_stmt;
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
        
        $stmt_val = "for(" + $es1.expr_stmt + $es2.expr_stmt + $e.expr_val + ")" + $s.stmt_val;
        
        writeIntoparserLogFile("Line " + std::to_string($s.stop->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
        writeIntoparserLogFile($stmt_val + "\n");
    }

    
    | IF LPAREN 
    {
        std::string savedIfFalseLabel = currentIfFalseLabel;
        std::string savedIfEndLabel = currentIfEndLabel;

        inIfCondition = true;
        currentIfFalseLabel = newLabel();

        if (!savedIfFalseLabel.empty()) {
            ifEndLabelStack.push_back(savedIfFalseLabel);
        }
        if (!savedIfEndLabel.empty()) {
            ifEndLabelStack.push_back(savedIfEndLabel);
        }
    }
    e=expression RPAREN
    {
        symb.enterScope();
        inIfCondition = false;  
    }     
    s=statement
    {
        $stmt_val = "if(" + $e.expr_val + ")" + $s.stmt_val;

        emitCode(currentIfFalseLabel + ":");

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
        
        writeIntoparserLogFile("Line " + std::to_string($s.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement\n");
        writeIntoparserLogFile($stmt_val + "\n");
        
        symb.exitScope();
    }
    | IF LPAREN 
    {
        std::string savedIfFalseLabel = currentIfFalseLabel;
        std::string savedIfEndLabel = currentIfEndLabel;

        inIfCondition = true;
        currentIfFalseLabel = newLabel();
        currentIfEndLabel = newLabel();

        if (!savedIfFalseLabel.empty()) {
            ifEndLabelStack.push_back(savedIfFalseLabel);
        }
        if (!savedIfEndLabel.empty()) {
            ifEndLabelStack.push_back(savedIfEndLabel);
        }
    }
    e=expression RPAREN 
    {
        symb.enterScope();
        inIfCondition = false;  
    }
    s1=statement
    {
        symb.exitScope();

        emitCode("JMP " + currentIfEndLabel);

        emitCode(currentIfFalseLabel + ":");
    } 
    ELSE 
    {
        symb.enterScope();  
    }s2=statement
    {
        $stmt_val = "if(" + $e.expr_val + ")" + $s1.stmt_val + "else " + $s2.stmt_val;

        emitCode(currentIfEndLabel + ":");

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
        
        writeIntoparserLogFile("Line " + std::to_string($s2.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement\n");
        writeIntoparserLogFile($stmt_val + "\n");
        
        symb.exitScope();
    }

    | WHILE LPAREN 
    {
        std::string savedLoopBodyLabel = currentLoopBodyLabel;
        std::string savedContinueLabel = currentContinueLabel;
        std::string savedLoopExitLabel = currentLoopExitLabel;

        std::string conditionLabel = newLabel();  
        std::string bodyLabel = newLabel();       
        std::string exitLabel = newLabel();       

        emitCode(conditionLabel + ":");

        inLoopCondition = true;
        currentLoopBodyLabel = bodyLabel;
        currentLoopExitLabel = exitLabel;
    }
    e=expression RPAREN
    {
        inLoopCondition = false;  

        emitCode(bodyLabel + ":");
        
        symb.enterScope();  
    }     
    s=statement
    {
        emitCode("JMP " + conditionLabel);

        emitCode(exitLabel + ":");

        currentLoopBodyLabel = savedLoopBodyLabel;
        currentContinueLabel = savedContinueLabel;
        currentLoopExitLabel = savedLoopExitLabel;
        
        $stmt_val = "while(" + $e.expr_val + ")" + $s.stmt_val;
        
        writeIntoparserLogFile("Line " + std::to_string($s.stop->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement\n");
        writeIntoparserLogFile($stmt_val + "\n");
        
        symb.exitScope();
    }
    | PRINTLN LPAREN ID RPAREN SEMICOLON
    {
        $stmt_val = "println(" + $ID->getText() + ");\n";

        std::string varName = $ID->getText();
        if (currentFunction.empty()) {
            emitCode("MOV AX, " + varName + "       ; Line " + std::to_string($ID->getLine()));
        } else {
            if (localVarOffset.find(varName) != localVarOffset.end()) {
                emitCode("MOV AX, " + getVarOffset(varName) + "       ; Line " + std::to_string($ID->getLine()));
            } else {
                emitCode("MOV AX, " + varName + "       ; Line " + std::to_string($ID->getLine()));
            }
        }
        
        emitCode("CALL print_output");
        emitCode("CALL new_line");

        InsertResult result = symb.lookupWithPosition($ID->getText());
        if(!result.found) {
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
            syntaxErrorCount++;
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
        writeIntoparserLogFile($stmt_val + "\n");
    }
    | RETURN e=expression SEMICOLON
    {
        $stmt_val = "return " + $e.expr_val + ";\n";
        hasReturnStatement = true;  

        std::string exprStr = $e.expr_val;
        bool isSimpleConstant = (exprStr.find_first_not_of("0123456789") == std::string::npos);
        bool isSimpleVar = (exprStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

        if (isSimpleConstant) {
            emitCode("MOV AX, " + exprStr);
        } else if (isSimpleVar) {
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
            bool needsPop = (exprStr.find("*") != std::string::npos) || (exprStr.find("/") != std::string::npos) || (exprStr.find("%") != std::string::npos) || (exprStr.find("+") != std::string::npos) || (exprStr.find("-") != std::string::npos) || (exprStr.find("&&") != std::string::npos) || (exprStr.find("||") != std::string::npos) || (exprStr.find("(") != std::string::npos);
            
            if (needsPop) {
                emitCode("POP AX");
            }
        }

        if (!currentFunction.empty()) {
            if (currentFunction == "main") {
                emitCode("ADD SP, " + std::to_string(currentOffset));
                emitCode("POP BP");
                emitCode("MOV AX,4CH");
                emitCode("INT 21H");
            } else {
                if (currentOffset > 0) {
                    emitCode("ADD SP, " + std::to_string(currentOffset));
                }
                emitCode("POP BP");

                int paramCount = currentFunctionParams.size();
                if (paramCount > 0) {
                    emitCode("RET " + std::to_string(paramCount * 2));
                } else {
                    emitCode("RET");
                }
            }
        }
        
        writeIntoparserLogFile("Line " + std::to_string($e.stop->getLine()) + ": statement : RETURN expression SEMICOLON\n");
        writeIntoparserLogFile($stmt_val + "\n");
    }

    |SWITCH LPAREN e=expression RPAREN
    {
        symb.enterScope();
    }		
    LCURL cases=case_statements RCURL
    {
        $stmt_val = "switch(" + $e.expr_val + "){\n" + $cases.case_stmts + "}\n";
        
        writeIntoparserLogFile("Line " + std::to_string($cases.stop->getLine()) + ": statement : SWITCH LPAREN expression RPAREN LCURL case_statements RCURL\n");
        writeIntoparserLogFile($stmt_val + "\n");
        
        symb.exitScope();
    }

    |ID COLON 
    {
        $stmt_val = $ID->getText() + ":\n";
        calledLabel = true;
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": statement : ID COLON\n");
        writeIntoparserLogFile($stmt_val + "\n");
    }

    |GOTO ID SEMICOLON
    {
        if(calledLabel == true){
            $stmt_val = "goto " + $ID->getText() + ";\n";
            calledLabel = false;
        }
        else{
            syntaxErrorCount++;
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": statement : GOTO ID SEMICOLON\n");
        writeIntoparserLogFile($stmt_val + "\n");
    }
    ;

case_statements returns [std::string case_stmts]
    : c=case_statement
    {
        $case_stmts = $c.case_stmt;
        
        writeIntoparserLogFile("Line " + std::to_string($c.start->getLine()) + ": case_statements : case_statement\n");
        writeIntoparserLogFile($case_stmts + "\n");
    }
    | cs=case_statements c=case_statement
    {
        $case_stmts = $cs.case_stmts + $c.case_stmt;
        
        writeIntoparserLogFile("Line " + std::to_string($c.stop->getLine()) + ": case_statements : case_statements case_statement\n");
        writeIntoparserLogFile($case_stmts + "\n");
    }
    ;

case_statement returns [std::string case_stmt]
    : CASE CONST_INT COLON s=statements BREAK SEMICOLON
    {
        $case_stmt = "case " + $CONST_INT->getText() + ":\n" + $s.stmt_list + "break;\n";
        
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": case_statement : CASE CONST_INT COLON statements BREAK SEMICOLON\n");
        writeIntoparserLogFile($case_stmt + "\n");
    }
    | DEFAULT COLON s=statements BREAK SEMICOLON
    {
        $case_stmt = "default:\n" + $s.stmt_list + "break;\n";
        
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": case_statement : DEFAULT COLON statements BREAK SEMICOLON\n");
        writeIntoparserLogFile($case_stmt + "\n");
    }
    ;   

expression_statement returns [std::string expr_stmt]
    : SEMICOLON
    {
        $expr_stmt = ";\n";
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : SEMICOLON\n");
        writeIntoparserLogFile($expr_stmt + "\n");
    }
    | e=expression SEMICOLON
    {
        $expr_stmt = $e.expr_val + ";\n";
        writeIntoparserLogFile("Line " + std::to_string($SEMICOLON->getLine()) + ": expression_statement : expression SEMICOLON\n");
        writeIntoparserLogFile($expr_stmt + "\n");
    };

variable returns [std::string var_name]
    :ID
    {
        $var_name = $ID->getText();

        InsertResult result = symb.lookupWithPosition($ID->getText());
        SymbolInfo* varInfo = symb.getCurrentScope()->lookUp(parserLogFile, $ID->getText());

        if(!result.found){
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
            syntaxErrorCount++;            
        }

        if(varInfo != nullptr){
            if(varInfo->getType() == "ARRAY" && $ctx->parent->getText().find("[") == std::string::npos){
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Type mismatch, " + $ID->getText() + " is an array\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Type mismatch, " + $ID->getText() + " is an array\n");
                syntaxErrorCount++;            
            }
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID\n");
        writeIntoparserLogFile($var_name + "\n");
    }

    | ID LTHIRD e=expression RTHIRD
    {
        $var_name = $ID->getText() + "[" + $e.expr_val + "]";

        InsertResult result = symb.lookupWithPosition($ID->getText());
        if(!result.found) {
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Undeclared variable " + $ID->getText() + "\n");
            syntaxErrorCount++;
        }
        else {
            SymbolInfo* varInfo = symb.getCurrentScope()->lookUp(parserLogFile, $ID->getText());

            if(varInfo != nullptr && varInfo->getType() != "ARRAY") {
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": " + $ID->getText() + " not an array\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": " + $ID->getText() + " not an array\n");
                syntaxErrorCount++;
            }
        }

        if($e.expr_val.find(".") != std::string::npos){
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Expression inside third brackets not an integer\n");
            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Expression inside third brackets not an integer\n"); 
            syntaxErrorCount++;          
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": variable : ID LTHIRD expression RTHIRD\n");
        writeIntoparserLogFile($var_name + "\n");
    };

expression returns [std::string expr_val]
    : l=logic_expression
    {
        $expr_val = $l.logic_val;
        writeIntoparserLogFile("Line " + std::to_string($l.start->getLine()) + ": expression : logic_expression\n");
        writeIntoparserLogFile($expr_val + "\n");
    }
    |	v=variable ASSIGNOP 
    {
        inAssignmentContext = true;  
    }
    l=logic_expression
    {
        inAssignmentContext = false;  
        $expr_val = $v.var_name + $ASSIGNOP->getText() + $l.logic_val;

        std::string logicStr = $l.logic_val;
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
            emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string($l.start->getLine()));
        } else if (isSimpleVariable) {
            if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string($l.start->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string($l.start->getLine()));
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
                emitCode("POP AX       ; Line " + std::to_string($l.start->getLine()));
            }
        }
        
        std::string varName = $v.var_name;

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

        std::string varName2 = $v.var_name;
        size_t bracketPos2 = varName2.find("[");

        if(bracketPos2 != std::string::npos){
            varName2 = varName2.substr(0, bracketPos2);
        }

        SymbolInfo* symbol = symb.getCurrentScope()->lookUp(parserLogFile, $v.var_name);

        bool isModulusOp = $l.logic_val.find("%") != std::string::npos;
        bool isFloatValue = $l.logic_val.find(".") != std::string::npos;

        if(!isModulusOp) {
            SymbolInfo* symbol = symb.getCurrentScope()->lookUp(parserLogFile, varName2);
            if(symbol != nullptr) {
                if(symbol->getType() == "ARRAY" && isFloatValue) {
                    writeIntoErrorFile("Error at line " + std::to_string($v.start->getLine()) + ": Type Mismatch\n");
                    writeIntoparserLogFile("Error at line " + std::to_string($v.start->getLine()) + ": Type Mismatch\n");
                    syntaxErrorCount++;
                }
                else if(symbol->getType() == "INT" && isFloatValue) {
                    writeIntoErrorFile("Error at line " + std::to_string($v.start->getLine()) + ": Type Mismatch\n");
                    writeIntoparserLogFile("Error at line " + std::to_string($v.start->getLine()) + ": Type Mismatch\n");
                    syntaxErrorCount++;
                }
            }
        }
        
        writeIntoparserLogFile("Line " + std::to_string($l.start->getLine()) + ": expression : variable ASSIGNOP logic_expression\n");
        writeIntoparserLogFile($expr_val + "\n");
    };

logic_expression returns [std::string logic_val]
    : r=rel_expression
    {
        $logic_val = $r.rel_val;
        writeIntoparserLogFile("Line " + std::to_string($r.start->getLine()) + ": logic_expression : rel_expression\n");
        writeIntoparserLogFile($logic_val + "\n");
    }

    | r1=rel_expression LOGICOP r2=rel_expression
    {
        $logic_val = $r1.rel_val + $LOGICOP->getText() + $r2.rel_val;

        std::string rel1Str = $r1.rel_val;
        std::string rel2Str = $r2.rel_val;
        
        bool isSimpleVar1 = (rel1Str.find("*") == std::string::npos && rel1Str.find("+") == std::string::npos && rel1Str.find("-") == std::string::npos && rel1Str.find("/") == std::string::npos && rel1Str.find("%") == std::string::npos && rel1Str.find("(") == std::string::npos && rel1Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

        bool isSimpleVar2 = (rel2Str.find("*") == std::string::npos && rel2Str.find("+") == std::string::npos && rel2Str.find("-") == std::string::npos && rel2Str.find("/") == std::string::npos && rel2Str.find("%") == std::string::npos && rel2Str.find("(") == std::string::npos && rel2Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

        std::string label1 = newLabel();  
        std::string label2 = newLabel();   
        std::string label3 = newLabel();  
        std::string label4 = newLabel();  
        
        if (isSimpleVar1 && isSimpleVar2 && ($LOGICOP->getText() == "||")) {
            if (currentFunction.empty() || localVarOffset.find(rel1Str) == localVarOffset.end()) {
                emitCode("MOV AX, " + rel1Str + "       ; Line " + std::to_string($LOGICOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(rel1Str) + "       ; Line " + std::to_string($LOGICOP->getLine()));
            }
            emitCode("CMP AX, 0");
            emitCode("JNE " + label1);  
            emitCode("JMP " + label3);  
            
            emitCode(label3 + ":");     

            if (currentFunction.empty() || localVarOffset.find(rel2Str) == localVarOffset.end()) {
                emitCode("MOV AX, " + rel2Str + "       ; Line " + std::to_string($LOGICOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(rel2Str) + "       ; Line " + std::to_string($LOGICOP->getLine()));
            }
            emitCode("CMP AX, 0");
            emitCode("JNE " + label1);  
            emitCode("JMP " + label2); 
            
            emitCode(label1 + ":");     
            emitCode("MOV AX, 1       ; Line " + std::to_string($LOGICOP->getLine()));
            emitCode("JMP " + label4); 
            emitCode(label2 + ":");     
            emitCode("MOV AX, 0");
            emitCode(label4 + ":");     
        } 
        
        else if (isSimpleVar1 && isSimpleVar2 && ($LOGICOP->getText() == "&&")) {
            if (currentFunction.empty() || localVarOffset.find(rel1Str) == localVarOffset.end()) {
                emitCode("MOV AX, " + rel1Str + "       ; Line " + std::to_string($LOGICOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(rel1Str) + "       ; Line " + std::to_string($LOGICOP->getLine()));
            }
            emitCode("CMP AX, 0");
            emitCode("JE " + label2);   
            
            if (currentFunction.empty() || localVarOffset.find(rel2Str) == localVarOffset.end()) {
                emitCode("MOV AX, " + rel2Str + "       ; Line " + std::to_string($LOGICOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(rel2Str) + "       ; Line " + std::to_string($LOGICOP->getLine()));
            }
            emitCode("CMP AX, 0");
            emitCode("JE " + label2);   

            emitCode("MOV AX, 1       ; Line " + std::to_string($LOGICOP->getLine()));
            emitCode("JMP " + label4); 
            emitCode(label2 + ":");    
            emitCode("MOV AX, 0");
            emitCode(label4 + ":");     
        } else {
            if ($LOGICOP->getText() == "||") {
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
            } else if ($LOGICOP->getText() == "&&") {
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
        
        writeIntoparserLogFile("Line " + std::to_string($LOGICOP->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression\n");
        writeIntoparserLogFile($logic_val + "\n");
    };

rel_expression returns [std::string rel_val]
    : s=simple_expression
    {
        $rel_val = $s.simple_val;
        writeIntoparserLogFile("Line " + std::to_string($s.start->getLine()) + ": rel_expression : simple_expression\n");
        writeIntoparserLogFile($rel_val + "\n");
    }

    | s1=simple_expression RELOP s2=simple_expression
    {
        $rel_val = $s1.simple_val + $RELOP->getText() + $s2.simple_val;
        std::string simple1Str = $s1.simple_val;
        std::string simple2Str = $s2.simple_val;
        
        bool isSimpleVar1 = (simple1Str.find("*") == std::string::npos && simple1Str.find("+") == std::string::npos && simple1Str.find("-") == std::string::npos && simple1Str.find("/") == std::string::npos && simple1Str.find("%") == std::string::npos && simple1Str.find("(") == std::string::npos && simple1Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

        bool isSimpleVar2 = (simple2Str.find("*") == std::string::npos && simple2Str.find("+") == std::string::npos && simple2Str.find("-") == std::string::npos && simple2Str.find("/") == std::string::npos && simple2Str.find("%") == std::string::npos && simple2Str.find("(") == std::string::npos && simple2Str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);

        std::string label1 = newLabel();
        std::string label2 = newLabel();
        std::string label3 = newLabel();

        if (!inForCondition) {
            if (isSimpleVar1 && isSimpleVar2) {
                if (currentFunction.empty() || localVarOffset.find(simple1Str) == localVarOffset.end()) {
                    emitCode("MOV AX, " + simple1Str + "       ; Line " + std::to_string($RELOP->getLine()));
                } else {
                    emitCode("MOV AX, " + getVarOffset(simple1Str) + "       ; Line " + std::to_string($RELOP->getLine()));
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
                    emitCode("MOV AX, " + simple1Str + "       ; Line " + std::to_string($RELOP->getLine()));
                } else {
                    emitCode("MOV AX, " + getVarOffset(simple1Str) + "       ; Line " + std::to_string($RELOP->getLine()));
                }
                emitCode("CMP AX, BX");
            } 
            
            else {
                emitCode("POP BX          ; Second operand");
                emitCode("POP AX          ; First operand");
                emitCode("CMP AX, BX");
            }
        
            if (inIfCondition) {
                if ($RELOP->getText() == "<") {
                    emitCode("JGE " + currentIfFalseLabel);  // Jump to false if NOT less than
                } else if ($RELOP->getText() == "<=") {
                    emitCode("JG " + currentIfFalseLabel);   // Jump to false if NOT less than or equal
                } else if ($RELOP->getText() == ">") {
                    emitCode("JLE " + currentIfFalseLabel);  // Jump to false if NOT greater than
                } else if ($RELOP->getText() == ">=") {
                    emitCode("JL " + currentIfFalseLabel);   // Jump to false if NOT greater than or equal
                } else if ($RELOP->getText() == "==") {
                    emitCode("JNE " + currentIfFalseLabel);  // Jump to false if NOT equal
                } else if ($RELOP->getText() == "!=") {
                    emitCode("JE " + currentIfFalseLabel);   // Jump to false if equal
                }
            } 
            
            else if (inLoopCondition) {
                if ($RELOP->getText() == "<") {
                    emitCode("JL " + currentLoopBodyLabel);   // Jump to body if less than
                } else if ($RELOP->getText() == "<=") {
                    emitCode("JLE " + currentLoopBodyLabel);  // Jump to body if less than or equal
                } else if ($RELOP->getText() == ">") {
                    emitCode("JG " + currentLoopBodyLabel);   // Jump to body if greater than
                } else if ($RELOP->getText() == ">=") {
                    emitCode("JGE " + currentLoopBodyLabel);  // Jump to body if greater than or equal
                } else if ($RELOP->getText() == "==") {
                    emitCode("JE " + currentLoopBodyLabel);   // Jump to body if equal
                } else if ($RELOP->getText() == "!=") {
                    emitCode("JNE " + currentLoopBodyLabel);  // Jump to body if not equal
                }
                emitCode("JMP " + currentLoopExitLabel);      // Jump to exit if condition fails
            } 
            
            else {
                std::string label1 = newLabel();
                std::string label2 = newLabel();
                std::string label3 = newLabel();
                
                if ($RELOP->getText() == "<") {
                    emitCode("JL " + label1);
                } else if ($RELOP->getText() == "<=") {
                    emitCode("JLE " + label1);
                } else if ($RELOP->getText() == ">") {
                    emitCode("JG " + label1);
                } else if ($RELOP->getText() == ">=") {
                    emitCode("JGE " + label1);
                } else if ($RELOP->getText() == "==") {
                    emitCode("JE " + label1);
                } else if ($RELOP->getText() == "!=") {
                    emitCode("JNE " + label1);
                }
                
                emitCode("JMP " + label3);
                emitCode(label1 + ":");
                emitCode("MOV AX, 1       ; Line " + std::to_string($RELOP->getLine()));
                emitCode("JMP " + label2);
                emitCode(label3 + ":");
                emitCode("MOV AX, 0");
                emitCode(label2 + ":");
                emitCode("PUSH AX");
            }
        }  
        
        writeIntoparserLogFile("Line " + std::to_string($RELOP->getLine()) + ": rel_expression : simple_expression RELOP simple_expression\n");
        writeIntoparserLogFile($rel_val + "\n");
    };

simple_expression returns [std::string simple_val]
    : t=term
    {
        $simple_val = $t.term_val;
        writeIntoparserLogFile("Line " + std::to_string($t.start->getLine()) + ": simple_expression : term\n");
        writeIntoparserLogFile($simple_val + "\n");
    }

    | s=simple_expression ADDOP t=term
    {
        $simple_val = $s.simple_val + $ADDOP->getText() + $t.term_val;

        std::string simpleStr = $s.simple_val;
        std::string termStr = $t.term_val;
        
        bool isSimpleConst1 = (simpleStr.find("*") == std::string::npos &&  simpleStr.find("+") == std::string::npos &&  simpleStr.find("-") == std::string::npos && simpleStr.find("/") == std::string::npos && simpleStr.find("%") == std::string::npos && simpleStr.find("(") == std::string::npos && simpleStr.find_first_not_of("0123456789") == std::string::npos);

        bool isSimpleConst2 = (termStr.find("*") == std::string::npos &&  termStr.find("+") == std::string::npos && termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos && termStr.find_first_not_of("0123456789") == std::string::npos);

        bool isSimpleVar = (simpleStr.find("*") == std::string::npos && simpleStr.find("+") == std::string::npos &&  simpleStr.find("-") == std::string::npos && simpleStr.find("/") == std::string::npos && simpleStr.find("%") == std::string::npos && simpleStr.find("(") == std::string::npos);

        bool isSimpleVar2 = (termStr.find("*") == std::string::npos && termStr.find("+") == std::string::npos &&  termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos && termStr.find_first_not_of("0123456789") != std::string::npos);
        
        if (isSimpleConst1 && isSimpleConst2) {
            emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            emitCode("MOV DX, AX");
            emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            
            if ($ADDOP->getText() == "+") {
                emitCode("ADD AX, DX");
            } else {
                emitCode("SUB AX, DX");
            }
        } 
        
        else if (isSimpleVar && isSimpleVar2) {
            if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string($ADDOP->getLine()));
            }
            emitCode("MOV DX, AX");

            if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string($ADDOP->getLine()));
            }
            
            if ($ADDOP->getText() == "+") {
                emitCode("ADD AX, DX");
            } else {
                emitCode("SUB AX, DX");
            }

            if (!inAssignmentContext) {
                emitCode("PUSH AX");
            }
        } else if (isSimpleVar && isSimpleConst2) {
            emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            emitCode("MOV DX, AX");
            
            if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string($ADDOP->getLine()));
            }
            
            if ($ADDOP->getText() == "+") {
                emitCode("ADD AX, DX");
            } else {
                emitCode("SUB AX, DX");
            }

            if (!inAssignmentContext) {
                emitCode("PUSH AX");
            }
        } else if (isSimpleVar) {
            emitCode("POP AX       ; Line " + std::to_string($ADDOP->getLine()));
            emitCode("MOV DX, AX");
            
            if (currentFunction.empty() || localVarOffset.find(simpleStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + simpleStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(simpleStr) + "       ; Line " + std::to_string($ADDOP->getLine()));
            }
            
            if ($ADDOP->getText() == "+") {
                emitCode("ADD AX, DX");
            } else {
                emitCode("SUB AX, DX");
            }
        } else if (isSimpleVar2) {
            if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string($ADDOP->getLine()));
            }
            emitCode("PUSH AX");

            emitCode("POP BX          ; Second operand (term)");
            emitCode("POP AX          ; First operand (simple_expression)");
            
            if ($ADDOP->getText() == "+") {
                emitCode("ADD AX, BX");
            } else {
                emitCode("SUB AX, BX");
            }
            emitCode("PUSH AX");
        } else if (!isSimpleConst1 && !isSimpleVar && isSimpleConst2) {
            emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            emitCode("MOV DX, AX");
            emitCode("POP AX       ; Line " + std::to_string($ADDOP->getLine()));
            
            if ($ADDOP->getText() == "+") {
                emitCode("ADD AX, DX");
            } else {
                emitCode("SUB AX, DX");
            }
            emitCode("PUSH AX");
        } else {
            emitCode("POP DX          ; Second operand (term)");
            emitCode("POP AX          ; First operand (simple_expression)");
            if ($ADDOP->getText() == "+") {
                emitCode("ADD AX, DX");
            } else {
                emitCode("SUB AX, DX");
            }
        }
        
        if (!(isSimpleConst1 && isSimpleConst2) && !(isSimpleVar && isSimpleConst2) && !isSimpleVar2 && !(!isSimpleConst1 && !isSimpleVar && isSimpleConst2)) {
            emitCode("PUSH AX");
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ADDOP->getLine()) + ": simple_expression : simple_expression ADDOP term\n");
        writeIntoparserLogFile($simple_val + "\n");
    }
    ;

simple_expression_err : s=simple_expression ADDOP ASSIGNOP
    { 
        writeIntoErrorFile("Error at line " + std::to_string($ASSIGNOP->getLine()) + 
                         ": syntax error, unexpected ASSIGNOP\n");
        writeIntoparserLogFile("Error at line " + std::to_string($ASSIGNOP->getLine()) + 
                             ": syntax error, unexpected ASSIGNOP\n");
        syntaxErrorCount++;       

    }
    ;

term returns [std::string term_val]
    : u=unary_expression
    {
        $term_val = $u.unary_val;
        writeIntoparserLogFile("Line " + std::to_string($u.start->getLine()) + ": term : unary_expression\n");
        writeIntoparserLogFile($term_val + "\n");
    }

    | t=term MULOP u=unary_expression
    {
        $term_val = $t.term_val + $MULOP->getText() + $u.unary_val;

        std::string termStr = $t.term_val;
        std::string unaryStr = $u.unary_val;

        bool isSimpleTerm = (termStr.find("*") == std::string::npos && termStr.find("+") == std::string::npos &&  termStr.find("-") == std::string::npos && termStr.find("/") == std::string::npos && termStr.find("%") == std::string::npos && termStr.find("(") == std::string::npos);

        bool isSimpleUnary = (unaryStr.find("*") == std::string::npos &&  unaryStr.find("+") == std::string::npos &&  unaryStr.find("-") == std::string::npos && unaryStr.find("/") == std::string::npos && unaryStr.find("%") == std::string::npos && unaryStr.find("(") == std::string::npos);
        
        if (isSimpleTerm && isSimpleUnary) { 
            if (currentFunction.empty() || localVarOffset.find(unaryStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + unaryStr + "       ; Line " + std::to_string($MULOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(unaryStr) + "       ; Line " + std::to_string($MULOP->getLine()));
            }
            emitCode("MOV CX, AX");

            if (currentFunction.empty() || localVarOffset.find(termStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string($MULOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(termStr) + "       ; Line " + std::to_string($MULOP->getLine()));
            }
        } else if (isSimpleTerm && !isSimpleUnary) {
            emitCode("POP AX       ; Line " + std::to_string($MULOP->getLine()));
            emitCode("MOV CX, AX");
            emitCode("MOV AX, " + termStr + "       ; Line " + std::to_string($MULOP->getLine()));
        } else if (!isSimpleTerm && isSimpleUnary) {
            emitCode("POP AX       ; Line " + std::to_string($MULOP->getLine()));
            emitCode("MOV CX, " + unaryStr + "       ; Line " + std::to_string($MULOP->getLine()));
        } else {
            emitCode("POP CX          ; Second operand (unary_expression)");
            emitCode("POP AX          ; First operand (term)");
        }
        
        if ($MULOP->getText() == "*") {
            emitCode("CWD");
            emitCode("MUL CX");
        } else if ($MULOP->getText() == "/") {
            emitCode("CWD");
            emitCode("DIV CX");
        } else if ($MULOP->getText() == "%") {
            emitCode("CWD");
            emitCode("DIV CX");
            emitCode("MOV AX, DX");
        }
        emitCode("PUSH AX");
       
        if($MULOP->getText() == "%" && ($u.unary_val.find(".") != std::string::npos || $t.term_val.find(".") != std::string::npos)){
            writeIntoErrorFile("Error at line " + std::to_string($t.start->getLine()) + ": Non-Integer operand on modulus operator\n");
            writeIntoparserLogFile("Error at line " + std::to_string($t.start->getLine()) + ": Non-Integer operand on modulus operator\n");
            syntaxErrorCount++;            
        }

        if(($MULOP->getText() == "%" || $MULOP->getText() == "/") && $u.unary_val == "0") {
            writeIntoErrorFile("Error at line " + std::to_string($t.start->getLine()) + ": Modulus by Zero\n");
            writeIntoparserLogFile("Error at line " + std::to_string($t.start->getLine()) + ": Modulus by Zero\n");
            syntaxErrorCount++;
        }
        
        writeIntoparserLogFile("Line " + std::to_string($MULOP->getLine()) + ": term : term MULOP unary_expression\n");
        writeIntoparserLogFile($term_val + "\n");
    };

unary_expression returns [std::string unary_val]
    : ADDOP u=unary_expression
    {
        $unary_val = $ADDOP->getText() + $u.unary_val;

        std::string unaryStr = $u.unary_val;
        bool isSimpleVar = (unaryStr.find("*") == std::string::npos && unaryStr.find("+") == std::string::npos && unaryStr.find("-") == std::string::npos && unaryStr.find("/") == std::string::npos && unaryStr.find("%") == std::string::npos && unaryStr.find("(") == std::string::npos && unaryStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
        
        if (isSimpleVar && $ADDOP->getText() == "-") {
            if (currentFunction.empty() || localVarOffset.find(unaryStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + unaryStr + "       ; Line " + std::to_string($ADDOP->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(unaryStr) + "       ; Line " + std::to_string($ADDOP->getLine()));
            }
            emitCode("NEG AX");
        } else {
            emitCode("POP AX          ; Get operand");
            if ($ADDOP->getText() == "-") {
                emitCode("NEG AX");
            }
            emitCode("PUSH AX");
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ADDOP->getLine()) + ": unary_expression : ADDOP unary_expression\n");
        writeIntoparserLogFile($unary_val + "\n");
    }

    | NOT u=unary_expression
    {
        $unary_val = "!" + $u.unary_val;

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
        
        writeIntoparserLogFile("Line " + std::to_string($NOT->getLine()) + ": unary_expression : NOT unary_expression\n");
        writeIntoparserLogFile($unary_val + "\n");
    }

    | f=factor
    {
        $unary_val = $f.factor_val;
        writeIntoparserLogFile("Line " + std::to_string($f.start->getLine()) + ": unary_expression : factor\n");
        writeIntoparserLogFile($unary_val + "\n");
    };

factor returns [std::string factor_val]
    : v=variable
    {
        $factor_val = $v.var_name;

        std::string varName = $v.var_name;

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

        writeIntoparserLogFile("Line " + std::to_string($v.start->getLine()) + ": factor : variable\n");
        writeIntoparserLogFile($factor_val + "\n");
    }

    | ID LPAREN a=argument_list RPAREN
    {
        $factor_val = $ID->getText() + "(" + $a.arg_list + ")";

        if(functionTable.find($ID->getText()) == functionTable.end()){
            writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Undefined function " + $ID->getText() + "\n");
            writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Undefined function " + $ID->getText() + "\n");       
            syntaxErrorCount++;
        }
        else{
            FunctionInfo& func = functionTable[$ID->getText()];

            if(func.returnType == "void"){
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Void function used in expression\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Void function used in expression\n");
                syntaxErrorCount++;
            }

            std::vector<std::string> providedArgs;
            std::istringstream argStream($a.arg_list);
            std::string arg;

            while(std::getline(argStream, arg, ',')){
                if(!arg.empty()){
                    providedArgs.push_back(arg);
                }
            }

            if(providedArgs.size() != func.paramTypes.size()){
                writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");
                writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": Total number of arguments mismatch with declaration in function " + $ID->getText() + "\n");
                syntaxErrorCount++;
            }
            else{
                for(size_t i = 0; i < providedArgs.size(); i++){
                    if(func.paramTypes[i] == "int" && providedArgs[i].find(".") != std::string::npos){
                        writeIntoErrorFile("Error at line " + std::to_string($ID->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + $ID->getText() + "\n");
                        writeIntoparserLogFile("Error at line " + std::to_string($ID->getLine()) + ": " + std::to_string(i+1) + "th argument mismatch in function " + $ID->getText() + "\n");
                        syntaxErrorCount++;
                        break;
                    }
                }
            }

            emitCode("CALL " + $ID->getText() + "       ; Line " + std::to_string($ID->getLine()));
            
            if(func.returnType != "void") {
                emitCode("PUSH AX");
            } else {
                emitCode("PUSH AX");
            }
        }
        
        writeIntoparserLogFile("Line " + std::to_string($ID->getLine()) + ": factor : ID LPAREN argument_list RPAREN\n");
        writeIntoparserLogFile($factor_val + "\n");
    }	

    | LPAREN e=expression RPAREN
    {
        $factor_val = "(" + $e.expr_val + ")";
        std::string exprStr = $e.expr_val;

        bool isSimpleArithmetic = (exprStr.find("*") == std::string::npos && exprStr.find("/") == std::string::npos && exprStr.find("%") == std::string::npos && exprStr.find("(") == std::string::npos && exprStr.find("&&") == std::string::npos && exprStr.find("||") == std::string::npos && (exprStr.find("+") != std::string::npos || exprStr.find("-") != std::string::npos));
        
        if (isSimpleArithmetic) {
            emitCode("PUSH AX       ; Push parenthesized expression result");
        }
        
        writeIntoparserLogFile("Line " + std::to_string($LPAREN->getLine()) + ": factor : LPAREN expression RPAREN\n");
        writeIntoparserLogFile($factor_val + "\n");
    }

    | CONST_INT
    {
        $factor_val = $CONST_INT->getText();       
        writeIntoparserLogFile("Line " + std::to_string($CONST_INT->getLine()) + ": factor : CONST_INT\n");
        writeIntoparserLogFile($factor_val + "\n");
    }

    | CONST_FLOAT
    {
        $factor_val = $CONST_FLOAT->getText();
        emitCode("MOV AX, " + $CONST_FLOAT->getText().substr(0, $CONST_FLOAT->getText().find(".")));
        emitCode("PUSH AX");
        
        writeIntoparserLogFile("Line " + std::to_string($CONST_FLOAT->getLine()) + ": factor : CONST_FLOAT\n");
        writeIntoparserLogFile($factor_val + "\n");
    }

    | v=variable INCOP
    {
        $factor_val = $v.var_name + "++";

        if (!inForIncrement) {
            std::string varName = $v.var_name;

            size_t bracketPos = varName.find("[");
            if (bracketPos != std::string::npos) {
                std::string arrayName = varName.substr(0, bracketPos);
                std::string indexStr = varName.substr(bracketPos + 1);
                indexStr = indexStr.substr(0, indexStr.find("]"));
                
                if (currentFunction.empty() || localVarOffset.find(arrayName) == localVarOffset.end()) {
                    if (indexStr.find_first_not_of("0123456789") == std::string::npos) {
                        int index = std::stoi(indexStr);
                        emitCode("MOV AX, " + arrayName + "[" + std::to_string(index * 2) + "]       ; Line " + std::to_string($INCOP->getLine()));
                        emitCode("PUSH AX");
                        emitCode("INC AX");
                        emitCode("MOV " + arrayName + "[" + std::to_string(index * 2) + "], AX");
                        emitCode("POP AX");
                    } else {
                        emitCode("MOV BX, " + indexStr);
                        emitCode("SHL BX, 1");  // Multiply by 2 for word size
                        emitCode("MOV AX, " + arrayName + "[BX]       ; Line " + std::to_string($INCOP->getLine()));
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
                        emitCode("MOV AX, [BP-" + std::to_string(actualOffset) + "]       ; Line " + std::to_string($INCOP->getLine()));
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
                        emitCode("MOV AX, [BP+BX]       ; Line " + std::to_string($INCOP->getLine()));
                        emitCode("PUSH AX");
                        emitCode("INC AX");
                        emitCode("MOV [BP+BX], AX");
                        emitCode("POP AX");
                    }
                }
            } else {
                // Regular variable (not array)
                if (currentFunction.empty()) {
                    emitCode("MOV AX, " + varName + "       ; Line " + std::to_string($INCOP->getLine()));
                    emitCode("PUSH AX");
                    emitCode("INC AX");
                    emitCode("MOV " + varName + ", AX");
                    emitCode("POP AX");
                } else {
                    if (localVarOffset.find(varName) != localVarOffset.end()) {
                        emitCode("MOV AX, " + getVarOffset(varName) + "       ; Line " + std::to_string($INCOP->getLine()));
                        emitCode("PUSH AX");
                        emitCode("INC AX");
                        emitCode("MOV " + getVarOffset(varName) + ", AX");
                        emitCode("POP AX");
                    }
                }
            }
        }
        
        writeIntoparserLogFile("Line " + std::to_string($INCOP->getLine()) + ": factor : variable INCOP\n");
        writeIntoparserLogFile($factor_val + "\n");
    }

    | v=variable DECOP
    {
        $factor_val = $v.var_name + "--";

        std::string varName = $v.var_name;
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
        } else if (!inForIncrement) {
            // Only generate decrement code if NOT in FOR loop increment section
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
        
        writeIntoparserLogFile("Line " + std::to_string($DECOP->getLine()) + ": factor : variable DECOP\n");
        writeIntoparserLogFile($factor_val + "\n");
    };

argument_list returns [std::string arg_list]
    : a=arguments
    {
        $arg_list = $a.args_val;
        writeIntoparserLogFile("Line " + std::to_string($a.start->getLine()) + ": argument_list : arguments\n");
        writeIntoparserLogFile($arg_list + "\n");
    }
    |
    {
        $arg_list = "";
        writeIntoparserLogFile("argument_list : <empty>\n");
        writeIntoparserLogFile("\n");
    };

arguments returns [std::string args_val]
    : a=arguments COMMA l=logic_expression
    {
        $args_val = $a.args_val + "," + $l.logic_val;
        
        std::string logicStr = $l.logic_val;
        bool isSimpleConstant = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("0123456789") == std::string::npos);
        
        bool isSimpleVar = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
        
        if (isSimpleConstant) {
            emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string($l.start->getLine()));
            emitCode("PUSH AX");
        } 
        
        else if (isSimpleVar) {
            if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string($l.start->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string($l.start->getLine()));
            }
            emitCode("PUSH AX");
        } else {
            emitCode("POP AX       ; Line " + std::to_string($l.start->getLine()));
            emitCode("PUSH AX");
        }
        
        writeIntoparserLogFile("Line " + std::to_string($l.start->getLine()) + ": arguments : arguments COMMA logic_expression\n");
        writeIntoparserLogFile($args_val + "\n");
    }
    | l=logic_expression
    {
        $args_val = $l.logic_val;

        std::string logicStr = $l.logic_val;
        bool isSimpleConstant = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("0123456789") == std::string::npos);
        
        bool isSimpleVar = (logicStr.find("*") == std::string::npos && logicStr.find("+") == std::string::npos && logicStr.find("-") == std::string::npos && logicStr.find("/") == std::string::npos && logicStr.find("%") == std::string::npos && logicStr.find("(") == std::string::npos && logicStr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") == std::string::npos);
        
        if (isSimpleConstant) {
            emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string($l.start->getLine()));
            emitCode("PUSH AX");
        } 
        
        else if (isSimpleVar) {
            if (currentFunction.empty() || localVarOffset.find(logicStr) == localVarOffset.end()) {
                emitCode("MOV AX, " + logicStr + "       ; Line " + std::to_string($l.start->getLine()));
            } else {
                emitCode("MOV AX, " + getVarOffset(logicStr) + "       ; Line " + std::to_string($l.start->getLine()));
            }
            emitCode("PUSH AX");
        } 
        
        else {
            emitCode("POP AX       ; Line " + std::to_string($l.start->getLine()));
            emitCode("PUSH AX");
        }
        
        writeIntoparserLogFile("Line " + std::to_string($l.start->getLine()) + ": arguments : logic_expression\n");
        writeIntoparserLogFile($args_val + "\n");
    };