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

// Accept method
void Unary_Expr_Node::accept(Expr_Node_Visitor & visitor)
{
  visitor.visit_unary_node(*this);
}

// Get child
Expr_Node * Unary_Expr_Node::get_child(void)
{
  return this->child_
}
