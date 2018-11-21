/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Mod_Expr_Node class

#include "Mod_Expr_Node.h"

// Defalut Constructor
Mod_Expr_Node::Mod_Expr_Node(void)
: Bin_Expr_Node(void)
{}

// Initializing Constructor
Mod_Expr_Node::Mod_Expr_Node(Expr_Node * left, Expr_Node * right)
: Bin_Expr_Node(left, right)
{}

// Destructor
Mod_Expr_Node::~Mod_Expr_Node(void)
{}

// Evaluate Method
int Mod_Expr_Node::evaluate(int num1, int num2)
{
  // If the second number is zero, throw mod_by_zero exception
  if(num2 == 0)
  {
    throw mod_by_zero();
  }

  return num1 % num2;
}
