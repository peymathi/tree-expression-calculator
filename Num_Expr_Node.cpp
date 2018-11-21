/* I pledge that I have neither given nor receieved any help on this assignment */

// Implementation for the Num_Expr_Node class

#include "Num_Expr_Node.h"

// Default Constructor
Num_Expr_Node::Num_Expr_Node(void)
: this->number_(0)
{}

// Initializing Constructor
Num_Expr_Node::Num_Expr_Node(int num)
: this->number_(num)
{}

// Destructor
Num_Expr_Node::~Num_Expr_Node(void)
{}

// Evaluate Method
int Num_Expr_Node::evaluate(void)
{
  return this->number_;
}
