/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Expr_Tree class

#include "Expr_Tree.h"

// Default Constructor
Expr_Tree::Expr_Tree(void)
: root_(nullptr)
{}

// Destructor
Expr_Tree::~Expr_Tree(void)
{
  delete this->root_;
}

// Evaluate method
int Expr_Tree::evaluate(void)
{
  // Create a new Eval_Expr_Tree object
  Expr_Node_Visitor * evaluator = new Eval_Expr_Tree();

  // Call the accept method on the root so that the visitor can iterate the enitre tree
  // and calculate the result and store it in its state
  this->root_->accept(*evaluator);

  // Set this objects result member to the result member of the visitor object
  this->result_ = evaluator->get_result();
}
