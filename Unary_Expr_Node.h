/* I pledge that I have neither given nor receieved any help on this assignment */

// This class inherits from Expr_Node class and represents nodes that are not leaf nodes but
// only have one child

#ifndef _UNARY_EXPR_NODE_
#define _UNARY_EXPR_NODE_

#include "Expr_Node.h"

class Unary_Expr_Node : public Expr_Node
{
public:
  // Default Constructor
  Unary_Expr_Node(void);

  // Initializing Constructor
  Unary_Expr_Node(Expr_Node * child);

  // Destructor
  ~Unary_Expr_Node(void);

  // Evaluate Method
  int evaluate(void);

protected:
  // Expr_Node Child for this Unary Node
  Expr_Node * child_;

};

#endif
