/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from Bin_Expr_Node class. This class represents all binary nodes that contain
// the subtraction operation

#ifndef _DIV_EXPR_NODE_
#define _DIV_EXPR_NODE_

#include "Bin_Expr_Node.h"
#include <exception>

class Div_Expr_Node : public Bin_Expr_Node
{
public:
  // Exception to be thrown when dividing by zero is attempted
  class divide_by_zero : public std::exception
  {
    // Default Constructor
    divide_by_zero(void)
    : std::exception(void)
    {}

  };

  // Default Constructor
  Div_Expr_Node(void);

  // Initializing Constructor
  Div_Expr_Node(Expr_Node * left, Expr_Node * right);

  // Destructor
  ~Div_Expr_Node(void);

  // Evalutate Method
  int evaluate(int num1, int num2);

};

#endif
