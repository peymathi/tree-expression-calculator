/* I pledge that I have neither given nor receieved any help on this assignment */

// Wrapper class for the expression evaluator. Takes a string. Builds a tree. Evaluates that tree.

#ifndef _CALCULATOR_CS363_
#define _CALCULATOR_CS363_

#include "Expr_Tree_Builder.h"
#include "Expr_Tree.h"
#include "Stack.h"
#include "Queue.h"
#include <sstream>

class Calculator
{
public:
  // Exception to be thrown when an invalid token is entered
  class invalid_token : public std::exception
  {
  public:
    // Default Constructor
    invalid_token(void)
    : std::exception()
    {}
  };

  // Exception to be thrown when evaluation is attempted on an empty expression
  class empty_expression : public std::exception
  {
  public:
    // Default Constructor
    empty_expression(void)
    : std::exception()
    {}
  };

  // Default Constructor
  Calculator(void);

  // Destructor
  ~Calculator(void);

  // Takes in a new infix string
  void set_expression(std::string expr);

  // Evaluates the current expression and returns the result
  int evaluate(void);

  // Getter method for the result
  int get_result(void);

private:
  // String to represent the current expression
  std::string expression_;

  // Integer to store the result
  int result_;

  // Expression tree
  Expr_Tree * expression_tree_;

  // Stack for the infix to postfix conversion
  Stack<std::string> * operators_;

  // Queue to hold the postfix representation of the expression
  Queue<std::string> * postfix_;

  // Helper methods for evaluating the string are below:
  // Converts the string saved in state from infix to postfix
  void infix_to_postfix(void);

  // Helper method for infix_to_postfix. Moves operators around according to precedence
  void move_operators(std::string token);

  // Builds the Expression tree from the currently saved string
  void build_tree(void);

  // Tests tokens if they are integers
  bool is_int(std::string token);

};

// Include inline Implementation
#include "Calculator.inl"

#endif
