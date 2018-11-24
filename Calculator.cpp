operators_/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Calculator class

#include "Calculator.h"

// Default Constructor
Calculator::Calculator(void)
: expression_(""),
  result_(),
  expression_tree_(nullptr),
  operators_(new Stack<std::string>()),
  postfix_(new Queue<std::string>())
{}

// Destructor
Calculator::~Calculator(void)
{
  delete this->expression_tree_;
  delete this->operators_;
}

// Evaluate
int Calculator::evaluate(void)
{
  // Throw an exception if the user never entered an expression
  if(this->expression_ == "")
  {
    throw empty_expression();
  }

  // Convert the expression from infix to postfix
  this->infix_to_postfix();

  // Build the tree from the expression
  this->build_tree();

  // Evaluate the tree and set result to the evaluation
  this->result_ = this->expression_tree_->evaluate();

  // Return the result
  return this->result_;
}

// Infix to postfix
void Calculator::infix_to_postfix(void)
{
  // String to hold the current parsed token
  std::string token;

  // String stream to parse the data
  std::istringstream stream(this->expression_);

  // Iterates through the entire string
  while(!stream.eof())
  {
    // Gets the current token
    stream >> token;

    // Test the token for each acceptable token

    // Test for integer
    if(this->is_int(token))
    {
      this->postfix_->enqueue(token);
    }

    // Test for addition
    else if(token == "+")
    {
      move_operators(token);
      this->operators_->push(token);
    }

    // Test for subtraction
    else if(token == "-")
    {
      move_operators(token);
      this->operators_->push(token);
    }

    // Test for multiplication
    else if(token == "*")
    {
      move_operators(token);
      this->operators_->push(token);
    }

    // Test for division
    else if(token == "/")
    {
      move_operators(token);
      this->operators_->push(token)
    }

    // Test for modulus
    else if(token == "%")
    {
      move_operators(token);
      this->operators_->push(token);
    }

    // Test for open parenthesis
    else if(token == "(")
    {
      // Push a nullptr onto the stack to represent the open parenthesis
      this->operators_->push(nullptr);
    }

    // Test for closed parenthesis
    else if(token == ")")
    {
      // Pops elements off the stack and enqueues them to postfix_ until open parenthesis is found
      while(!this->operators_->is_empty())
      {
        // If the top does not equal nullptr, pop element and enqueue to postfix
        if(this->operators_->top() != nullptr)
        {
          this->postfix_->enqueue(this->operators_->pop());

          // If after popping this element the stack is empty, then nullptr was never found and therefore there was
          // never an open parenthesis. Throw logic exception
          if(this->operators_->is_empty())
          {

            throw logic_exception();
          }
        }

        // If the top does equal nullptr, pop it from stack and break from while loop
        else
        {
          this->operators_->pop();
          break;
        }
      }
    }

    // Invalid token
    else
    {
      throw invalid_token();
    }
  }

  // End of expression. Pop all elements off the stack and enqueue to postfix expression
  while(!this->operators_->is_empty())
  {
    // Test to see if the operand on stack is an open parenthesis
    if(this->operators_->top() != nullptr)
    {
      this->postfix_->enqueue(this->operators_->pop());
    }

    // An open parenthesis was not closed. Throw logic error
    else
    {
      throw logic_exception();
    }
  }

}

void Calculator::move_operators(std::string token)
{
  // If the operator is addition or subtraction
  if(token == "+" || token == "-")
  {
    // Pop operators off the stack until the stack is empty or an open parenthesis is found
    while(!this->operators_->is_empty() && this->operators_->top() != nullptr)
    {
      this->postfix_->enqueue(this->operators_->pop());
    }
  }

  // If the operator is modulus, division, or multiplication
  else if(token == "*" || token == "/" || token == "%")
  {
    // Pop operators off the stack until the stack is empty, an open parenthesis is found, or the
    // top is a "+" or "-"
    while(!this->operators_->is_empty() && this->operators_->top() != nullptr)
    {
      if(this->operators_->top() == "+" || this->operators_->top() == "-")
      {
        break;
      }

      this->postfix_->enqueue(this->operators_->pop());
    }
  }
}

// Build Tree
void Calculator::build_tree(void)
{
  // For all elements in the queue, build a node for the tree

  // Builder object
  Expr_Tree_Builder * builder = new Expr_Tree_Builder();

  // Token for parsing data
  std::string token;

  while(!this->postfix_->is_empty())
  {
    token = this->postfix_->deqeueue();

    // Number Test
    if(this->is_int(token))
    {
      builder->build_num_node((int)token);
    }

    // Addition Test
    else if(token == "+")
    {
      builder->build_add_node();
    }

    // Subtraction Test
    else if(token == "-")
    {
      builder->build_sub_node();
    }

    // Multiplication Test
    else if(token == "*")
    {
      builder->build_mult_node();
    }

    // Division Test
    else if(token == "/")
    {
      builder->build_div_node();
    }

    // Modulus Test
    else if(token == "%")
    {
      builder->build_mod_node();
    }
  }
}

// Is int
bool Calculator::is_int(std::string token)
{
  // Converts the string to a c style string for digit testing
  const char * cstring = test.c_str();

  // All tokens inputted in the expression will run through this test for integer. Therefore, this algorithm
  // must consider all cases.

  // This if statement weeds out any tokens that do not start out with a digit or the '-' character
  if(isdigit(cstring[0]) || cstring[0] == '-')
  {
    // Test the rest of the string for integers only
    for(size_t i = 1; i < test.length(); i++)
    {
      // If the element at i is not a digit, return false
      if(!isdigit(cstring[i]))
      {
        return false;
      }
    }

    // If the token is a single character that is '-', then this is the subraction token not an integer
    if(test.length() == 1 && cstring[0] == '-')
    {
      return false;
    }

    // Runs only when the cstring is all integers, or a '-' character followed by only integers
    return true;
  }

  // All tokens that do not start as an integer or a '-' character will run this by failing the first if statement
  return false;
}
