#!/bin/bash

echo "Cleaning existing generated files..."
rm -f lex.yy.c parser.tab.c parser.tab.h mycompiler

# echo "Creating a simple test file..."
# mkdir -p tests
# echo "int main() { return 0; }" > tests/simple.c

echo "Running flex on scanner.l..."
flex scanner.l || { echo "Flex failed"; exit 1; }

echo "Running bison on parser.y..."
bison -d parser.y || { echo "Bison failed"; exit 1; }

echo "Compiling the compiler..."
gcc -Wall -o mycompiler parser.tab.c lex.yy.c semantic.c -lfl

if [ -f mycompiler ]; then
    echo "Build successful! Run the compiler with: ./mycompiler tests/simple.c"
else
    echo "Build failed. Check the errors above."
fi 