# Expression Calculator Implemented Using Expression Tree
This is the second version of the expression calculator. This version uses an Expression Tree to solve the expression and it was built to practice using the Composite, Visitor, and Builder Patterns of Software Design. 

Version 1 of the expression calculator, which uses a Stack instead of a Tree, can be found [here](https://github.com/peymathi/expression-calculator-stack). 

Version 3 of the expression calculator, which combines Versions 1 and 2 and adds a web interface, can be found [here](https://github.com/peymathi/expression-calculator-web).

## Installation
Clone the repository with:

```git clone https://github.com/peymathi/tree-expression-calculator.git```

Run `make`

Run `bin/expression_calc_tree.exe`

Enter any expression using digits 0-9 and operators '*', '/', '+', '-', '%', '(', ')', with a space between every number and operator.

Example Input: `( 2 + 7 ) * ( 4 - 2 ) / 7 % 8`

Example Output: `2`
