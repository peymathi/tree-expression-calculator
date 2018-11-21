/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation of the Div_Expr_Node class

#include "Div_Expr_Node.h"

// Default Constructor
Div_Expr_Node::Div_Expr_Node(void)
: Bin_Expr_Node(void)
{}

// Initializing Constructor
Div_Expr_Node::Div_Expr_Node(Expr_Node * left, Expr_Node * right)
: Bin_Expr_Node(left, right)
{}

// Destructor
Div_Expr_Node::~Div_Expr_Node(void)
{}

// Evalutate Method
void Div_Expr_Node::evaluate(int num1, int num2)
{
  // If the second number is zero, throw divide_by_zero exception
  if(num2 == 0)
  {
    throw divide_by_zero();
  }
  
  return num1 / num2;
}
