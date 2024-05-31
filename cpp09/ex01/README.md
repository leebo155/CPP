# Reverse Polish Notation
This exercise uses containers to implement the Reverse Polish Notation Calculator program, which help find the right container for code.

## Rules
Create a program with these constraints:

* The program name is **RPN**.

* Your program must take an inverted Polish mathematical expression as an argument.

* The numbers used in this operation and passed as arguments will always be less
  than 10. The calculation itself but also the result do not take into account this rule.

* Your program must process this expression and output the correct result on the standard output.

* If an error occurs during the execution of the program an error message should be displayed on the standard output.

* Your program must be able to handle operations with these tokens: "+ - / *".

## Execution
```
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>
```
