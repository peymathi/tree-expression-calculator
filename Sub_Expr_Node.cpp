/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Sub_Expr_Node class

#include "Sub_Expr_Node.h"

// Default Constructor
Sub_Expr_Node::Sub_Expr_Node(void)
: Bin_Expr_Node(void)
{}

// Initializing Constructor
Sub_Expr_Node::Sub_Expr_Node(Expr_Node * left, Expr_Node right)
: Bin_Expr_Node(left, right)
{}

// Destructor
Sub_Expr_Node::~Sub_Expr_Node(void)
{}

// Evalutate Method
int Sub_Expr_Node::evaluate(int num1, int num2)
{
  return num1 - num2;
}
