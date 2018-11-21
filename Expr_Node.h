/* I pledge that I have neither given nor receieved any help on this assignment */

// This class is the interface for all Expression Nodes within an expression tree.

#ifndef _EXPR_NODE_
#define _EXPR_NODE_

class Expr_Node
{
public:
  // Default Constructor
  Expr_Node (void);

  // Destructor
  virtual ~Expr_Node (void) = 0;

  // Virtual Evalutate Method to be implemented in all subclasses
  virtual int evaluate (void) = 0;

};

#endif
