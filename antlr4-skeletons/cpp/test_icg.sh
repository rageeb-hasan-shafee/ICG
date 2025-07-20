#!/bin/bash

# Clean previous build
make clean

# Generate ANTLR4 files
antlr4 -Dlanguage=Cpp -no-listener -visitor C8086Lexer.g4
antlr4 -Dlanguage=Cpp -no-listener -visitor C8086Parser.g4

# Compile
g++ -std=c++17 -I. -I/usr/include/antlr4-runtime \
    C8086Lexer.cpp \
    C8086Parser.cpp \
    Ctester.cpp \
    -lantlr4-runtime -o icg_compiler

echo "Compilation complete. Testing with input file..."

# Test with the sample input
./icg_compiler input/test.c

echo "Generated assembly files:"
echo "Original: code.asm"
echo "Optimized: optimized_code.asm"

# Display the generated assembly
echo ""
echo "=== Generated Assembly (code.asm) ==="
if [ -f "code.asm" ]; then
    cat code.asm
else
    echo "code.asm not found"
fi

echo ""
echo "=== Optimized Assembly (optimized_code.asm) ==="
if [ -f "optimized_code.asm" ]; then
    cat optimized_code.asm
else
    echo "optimized_code.asm not found"
fi
