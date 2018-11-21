/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Unary_Expr_Node class

#include "Unary_Expr_Node.h"

// Default Constructor
Unary_Expr_Node::Unary_Expr_Node(void)
: child_(nullptr)
{}

// Initializing Constructor
Unary_Expr_Node::Unary_Expr_Node(Expr_Node * child)
: child_(child)
{}

// Destructor
Unary_Expr_Node::~Unary_Expr_Node(void)
{
  delete this->child_;
}

// Evaluate Method
int Unary_Expr_Node::evaluate(void)
{
  // Calls the child's evaluate method and returns it
  return this->child_->evaluate();
}
