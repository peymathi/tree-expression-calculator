/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from Expr_Node class. It represents all nodes that have two children.

#ifndef _BIN_EXPR_NODE_
#define _BIN_EXPR_NODE_

#include "Expr_Node.h"

class Bin_Expr_Node : public Expr_Node
{
public:
  // Default Constructor
  Bin_Expr_Node(void);

  // Initializing Constructor
  Bin_Expr_Node(Expr_Node * left, Expr_Node right);

  // Destructor
  ~Bin_Expr_Node(void);

  // Template method that provides the base skeleton for all evaluate operations in subclasses
  virtual int evaluate(void);

  // Method to be implemented in base class for specific operation
  virtual int evaluate(int num1, int num2) = 0;

  // Passes the visitor support method to child methods because this is also an abstract class
  virtual void accept (Expr_Node_Visitor & visitor) = 0;

  // Returns a pointer to the left child
  Expr_Node * get_left(void);

  // Returns a pointer to the right child
  Expr_Node * get_right(void);

protected:
  // Pointers to the left and right children
  Expr_Node * left_;
  Expr_Node * right_;

};

#endif
