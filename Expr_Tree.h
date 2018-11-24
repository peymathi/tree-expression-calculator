/* I pledge that I have neither given nor received any help on this assignment */

// This class represents an Expression Tree

#ifndef _EXPR_TREE_
#define _EXPR_TREE_

#include "Math_Expr.h"
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"

class Expr_Tree : public Math_Expr
{
public:
  // Default Constructor
  Expr_Tree(void);

  // Initializing Constructor
  Expr_Tree(Expr_Node * root);

  // Destructor
  ~Expr_Tree(void);

  // Evaluate Method
  virtual int evaluate (void);

  // Setter method for the root node
  void set_root(Expr_Node * root);

  // Getter method for the root node
  Expr_Node * get_root(void);

private:
  // Root node of the Expression Tree
  Expr_Node * root_;

};

// Include inline implementation
#include "Expr_Tree.inl"

#endif
