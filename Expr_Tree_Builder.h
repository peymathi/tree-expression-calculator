/* I pledge that I have neither given nor received any help on this assignment */

// This class inherits from Expr_Builder and builds an expression in the form of a binary tree.
// This class is designed to build an expression tree from an expression in postfix order

#ifndef _EXPR_TREE_BUILDER_
#define _EXPR_TREE_BUILDER_

#include "Expr_Builder.h"
#include "Expr_Tree.h"
#include "Stack.h"
#include "Queue.h"

class Expr_Tree_Builder : public Expr_Builder
{
public:
  // Default Constructor
  Expr_Tree_Builder(void);

  // Destructor
  ~Expr_Tree_Builder(void);

  // Creates the Expr_Tree object
  virtual void start_expression(void);

  // Builds a number node and pushes it to the stack of nodes
  virtual void build_num(int num);

  // Builds a add node and adds it to the tree in the correct place
  virtual void build_add_operator(void);

  // Builds a sub node and adds it to the tree in the correct place
  virtual void build_sub_operator(void);

  // Builds a multiplication node and adds it to the tree in the correct place
  virtual void build_mult_operator(void);

  // Builds a division node and adds it to the tree in the correct place
  virtual void build_div_operator(void);

  // Builds a modulus node and adds it to the tree in the correct place
  virtual void build_mod_operator(void);

  // Builds the actual tree and then returns it
  Math_Expr * get_expression(void);

private:

  // Current State of the expression tree
  Expr_Tree * expression_tree_;

  // Stack for moving nodes around and building the tree
  Stack<Expr_Node*> * trees_;

  // Temporary pointer to an expression node
  Expr_Node * current_node_;

};

#endif
