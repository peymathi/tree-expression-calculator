/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Mult_Expr_Node class

#include "Mult_Expr_Node.h"

// Defalut Constructor
Mult_Expr_Node::Mult_Expr_Node(void)
: Bin_Expr_Node(void)
{}

// Initializing Constructor
Mult_Expr_Node::Mult_Expr_Node(Expr_Node * left, Expr_Node * right)
: Bin_Expr_Node(left, right)
{}

// Destructor
Mult_Expr_Node::~Mult_Expr_Node(void)
{}

// Accept method
void Mult_Expr_Node::accept(Expr_Node_Visitor & visitor)
{
  visitor.visit_mult_node(*this);
}
