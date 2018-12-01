/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Calculator class

// COMMENT: Do not go from infix to postfix then to tree. Instead,
// go directly from infix to tree. The extra step is not necessary.

// REPLY: Changed the algorithm to convert from infix to tree directly rather than
// from infix to postfix to tree

#include "Calculator.h"

// Default Constructor
Calculator::Calculator(void)
: expression_string_(""),
  result_(),
  expression_tree_(nullptr),
  operators_(new Stack<Expr_Node*>()),
  current_nodes_(new Stack<Expr_Node*>())
{}

// Destructor
Calculator::~Calculator(void)
{
  delete this->expression_tree_;
}

// Evaluate
int Calculator::evaluate(void)
{
  // Throw an exception if there is an empty expression
  if(this->expression_string_ == "")
  {
    throw empty_expression();
  }

  // Call the build tree method
  this->build_tree();

  // Return result
  return this->result_;
}

void Calculator::build_tree(void)
{
  // Parse the string and test each token type and build nodes accordingly

  // Builder object to build the tree
  Expr_Builder * builder = new Expr_Tree_Builder();

  // Start a new expression
  builder->start_expression();

  // String for parsing the data
  std::string token;

  // String stream to parse the string
  std::istringstream stream(this->expression);

  // Catches all exceptions from building in order to delete the builder object to avoid memory leak
  try
  {
    // Iterate through the entire string
    while(!stream.eof())
    {
      // Get the current token
      stream >> token;

      // Integer test
      if(this->is_int(token))
      {
        // Build a number node
        builder->build_num(std::stoi(token));
      }

      // Addition test
      else if(token == "+")
      {
        // Build an add node
        builder->build_add_operator();
      }

      // Subtraction test
      else if(token == "-")
      {
        // Build a sub node
        builder->build_sub_operator();
      }

      // Multiplication test
      else if(token == "*")
      {
        // Build a multiplication node
        builder->build_mult_operator();
      }

      // Division Test
      else if(token == "/")
      {
        // Build a division node
        builder->build_div_operator();
      }

      // Modulus Test
      else if(token == "%")
      {
        // Build a modulus node
        builder->build_mod_operator();
      }

      // Open parenthesis test
      else if(token == "(")
      {
        // Build an open parenthesis
        builder->build_open_parenthesis();
      }

      // Closed Parenthesis test
      else if(token == ")")
      {
        // Build a closed parenthesis
        builder->build_closed_parenthesis();
      }

      // Invalid Token. Throws exception
      else
      {
        // Delete the builder object first
        delete builder;
        throw invalid_token();
      }
    }
  }

  // Catch logic error
  catch(logic_exception ex)
  {
    delete builder;
    throw logic_exception();
  }

  // Catch division error
  catch(divide_by_zero ex)
  {
    delete builder;
    throw divide_by_zero();
  }

  // Catch mod by zero error
  catch(mod_by_zero ex)
  {
    delete builder;
    throw mod_by_zero();
  }

  // Catch all other exceptions
  catch(...)
  {
    delete builder;
    throw logic_exception();
  }


  // Tree is finished building here. Get the newly created expression tree
  this->expression_tree_ = builder->get_expression();
  delete builder;
}

// Is int
bool Calculator::is_int(std::string token)
{
  // Converts the string to a c style string for digit testing
  const char * cstring = token.c_str();

  // All tokens inputted in the expression will run through this test for integer. Therefore, this algorithm
  // must consider all cases.

  // This if statement weeds out any tokens that do not start out with a digit or the '-' character
  if(isdigit(cstring[0]) || cstring[0] == '-')
  {
    // Test the rest of the string for integers only
    for(size_t i = 1; i < token.length(); i++)
    {
      // If the element at i is not a digit, return false
      if(!isdigit(cstring[i]))
      {
        return false;
      }
    }

    // If the token is a single character that is '-', then this is the subraction token not an integer
    if(token.length() == 1 && cstring[0] == '-')
    {
      return false;
    }

    // Runs only when the cstring is all integers, or a '-' character followed by only integers
    return true;
  }

  // All tokens that do not start as an integer or a '-' character will run this by failing the first if statement
  return false;
}
