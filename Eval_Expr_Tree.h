/* I pledge that I have neither given nor received any help on this assignment */

/* This class inherits from the Expr_Node_Visitor in order to provide implementation to traverse
  an expression tree */

#ifndef _EVAL_EXPR_TREE_
#define _EVAL_EXPR_TREE_

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:
  // Default Constructor
  Eval_Expr_Tree(void);

  // Destructor
  virtual ~Eval_Expr_Tree(void);

  // Methods for visiting concrete nodes
  virtual void visit_add_node(const Add_Expr_Node & node);
  virtual void visit_sub_node(const Sub_Expr_Node & node);
  virtual void visit_mult_node(const Mult_Expr_Node & node);
  virtual void visit_div_node(const Div_Expr_Node & node);
  virtual void visit_mod_node(const Mod_Expr_Node & node);
  virtual void visit_num_node(const Num_Expr_Node & node);

  // Method to get the result of the expression tree
  int get_result(void) const;

private:
  // State of the object to store the result of the expression
  int result_;

};

// Includes the inline implementation
#include "Eval_Expr_Tree.inl"

#endif
