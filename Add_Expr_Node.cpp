/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Add_Expr_Node class

#include "Add_Expr_Node.h"

// Default Constructor
Add_Expr_Node::Add_Expr_Node(void)
: Bin_Expr_Node(void)
{}

// Initializing Constructor
Add_Expr_Node::Add_Expr_Node(Expr_Node * left, Expr_Node * right)
: Bin_Expr_Node(left, right)
{}

// Destructor
Add_Expr_Node::~Add_Expr_Node(void)
{}

// Evaluate Method
int Add_Expr_Node::evaluate(int num1, int num2)
{
  return num1 + num2;
}
