/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Expr_Tree_Builder class

#include "Expr_Tree_Builder.h"

// Default Constructor
Expr_Tree_Builder::Expr_Tree_Builder(void)
: expression_tree_(nullptr),
  trees_(new Stack<Expr_Node*>),
  current_node_(nullptr)
{}

// Destructor
Expr_Tree_Builder::~Expr_Tree_Builder(void)
{
  // Does not delete the expression tree constained here in order to let the client control that

  // Delete the
  delete this->trees_;
}

// Start Expression
void Expr_Tree_Builder::start_expression(void)
{
  // Creates a new Expr_Tree object and stores it as state
  this->expression_tree_ = new Expr_Tree();
}

// Num
void Expr_Tree_Builder::build_num(int num)
{
  // Creates a new number node and pushes it to the stack of nodes
  Expr_Node * node = new Num_Expr_Node(num);
  this->trees_->push(node);
}

// Add
void Expr_Tree_Builder::build_add_operator(void)
{
  Expr_Node * node = new Add_Expr_Node();

  // Pops off two nodes and sets them as this nodes left and right children

  // Check to make sure the stack has two nodes to pop. If not, throws a logic error
  if(this->trees_->is_empty())
  {

  }

  node->set_right(this->trees_->pop());

  if(this->trees_->is_empty())
  {

  }

  node->set_left(this->trees_->pop());

  // Push the newly created node to the stack
  this->trees_->push(node);

}

// Sub
void Expr_Tree_Builder::build_sub_operator(void)
{
  Expr_Node * node = new Sub_Expr_Node();

  // Pops off two nodes and sets them as this nodes left and right children
  // Checks to make sure the stack has two nodes to pop. If not, throws a logic error
  if(this->trees_->is_empty())
  {
    throw logic_error();
  }

  node->set_right(this->trees_->pop());

  if(this->trees_->is_empty())
  {
    throw logic_error();
  }

  node->set_left(this->trees_->pop());

  // Push the newly created node to the stack
  this->trees_->push(node);

}

// Mult
void Expr_Tree_Builder::build_mult_operator(void)
{
  Expr_Node * node = new Mult_Expr_Node();

  // Pops off two nodes and sets them as this nodes left and right children
  // Checks to make sure the stack has two nodes to pop. If not, throws a logic error
  if(this->trees_->is_empty())
  {
    throw logic_error();
  }

  node->set_right(this->trees_->pop());

  if(this->trees_->is_empty())
  {
    throw logic_error();
  }

  node->set_left(this->trees_->pop());

  // Push the newly created node to the stack
  this->trees_->push(node);

}

// Div
void Expr_Tree_Builder::build_div_operator(void)
{
  Expr_Node * node = new Divide_Expr_Node();

  // Pops off two nodes and sets them as this nodes left and right children
  // Checks to make sure the stack has two nodes to pop. If not, throws a logic error
  if(this->trees_->is_empty())
  {
    throw logic_error();
  }

  node->set_right(this->trees_->pop());

  if(this->trees_->is_empty())
  {
    throw logic_error();
  }

  node->set_left(this->trees_->pop());

  // Push the newly created node to the stack
  this->trees_->push(node);

}

// Mod
void Expr_Tree_Builder::build_mod_operator(void)
{
  Expr_Node * node = new Mod_Expr_Node();

  // Pops off two nodes and sets them as this nodes left and right children
  // Checks to make sure the stack has two nodes to pop. If not, throws a logic error
  if(this->trees_->is_empty())
  {
    throw logic_error();
  }

  node->set_right(this->trees_->pop());

  if(this->trees_->is_empty())
  {
    throw logic_error();
  }

  node->set_left(this->trees_->pop());

  // Push the newly created node to the stack
  this->trees_->push(node);
}

// Get Expression
Expr_Tree * Expr_Tree_Builder::get_expression(void)
{
  // If the stack has an element, set that element as the root node of the Expr_Tree
  if(!this->trees_->is_empty())
  {
    this->expression_tree_->set_root(this->trees_->top());
  }

  // Return the expression tree stored in state
  return this->expression_tree_;

}
