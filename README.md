# COMPILER-DESIGN-BASICS

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: SOHINI SAMUI

*INTERN ID*: CT04DM489

*DOMAIN*: C++

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTHOSH

📘 Compiler Design Basics – Arithmetic Expression Evaluator

📌 Project Overview

This project is a foundational exercise in Compiler Design, focusing on the implementation of a simple compiler-like program that can parse and evaluate basic arithmetic expressions. Developed in C++, the program demonstrates key compiler components such as lexical analysis, parsing, and evaluation, all built into a self-contained application.

The primary goal of this project is to provide a hands-on understanding of expression parsing using recursive descent parsing — a top-down parsing technique often used in real-world compiler design. The project reads arithmetic expressions entered by the user, parses them according to operator precedence and associativity rules, and evaluates the result.

🧠 What It Does

The program functions as a simple arithmetic expression evaluator, capable of interpreting and computing mathematical expressions involving:

Addition (+)

Subtraction (-)

Multiplication (*)

Division (/)

Parentheses (( and )) for grouping

Whitespace tolerance

Floating-point numbers

Example Expressions:

(3 + 4) * 2

7 + 5 * (10 - 3) / 2

42 / (6 + 1)

3.14 * 2 - 0.28

The user enters expressions in the command-line interface, and the program outputs the computed result or a relevant error message.

🔧 How It Works

The program uses a recursive descent parser, breaking the input down using grammar rules defined in functions that represent different parts of an arithmetic expression:

Expression → Term { (+ | -) Term }

Term → Factor { (* | /) Factor }

Factor → Number | ( Expression )

Each of these rules is handled by separate methods in the Parser class:

parseExpression()

parseTerm()

parseFactor()

parseNumber()

These functions analyze the input from left to right and apply appropriate operations while respecting the order of operations (precedence and associativity).

🖥 Usage Instructions

1. Compile the Program:

g++ compiler.cpp -o compiler

2. Run the Program:

./compiler

3. Interact:

Type an arithmetic expression.

View the result.

Type exit to quit.

⚠ Error Handling

The program includes basic error detection for:

Invalid characters or malformed expressions

Missing closing parentheses

Division by zero

These are reported to the user with clear messages and no crash occurs.

📚 Learning Outcomes

This project gives you practical experience with:

Tokenizing and parsing user input

Applying recursive parsing techniques

Evaluating arithmetic expressions with correct precedence

Handling runtime errors gracefully

Designing interpreters using compiler principles

It serves as an ideal starting point for students learning compiler theory, offering a real implementation of the front-end phase of a compiler.

🚀 Future Enhancements (Optional Ideas)

Add support for variables and assignments

Include exponentiation (^)

Add syntax error highlighting

Extend grammar to support unary minus

#OUTPUT

