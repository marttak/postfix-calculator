# Postfix-calculator

School project to learn the use of stack in C++. Code modified from chapter two in "Data Structures and Program Design in C++" by Robert L. Kruse, Alexander J. Ryba.

Postfix notation is a mathematical notation in which operators follow their operands. Example: '3 4 +' produces answer 7.

This program prompts the user to give commands. Commands are:
* [ ? ] push number to stack
* [ x ] exchange positions of two topmost numbers
* [ s ] sum of all numbers in stack
* [ a ] average of all numbers in stack
* [ + ] [ - ] [ * ] [ / ] are arithmetic operations
* [ Q ] quit

Arithmetic operations work only on two topmost numbers. After calculations, operands are removed from stack and answer is pushed to the top.