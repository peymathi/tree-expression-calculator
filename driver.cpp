/* I pledge that I have neither given nor received any help on this assignment */

// Driver for the program
#include "Calculator.h"

// For exception handling
#include "Eval_Expr_Tree.h"
#include "Expr_Builder.h"

#include <iostream>

int main()
{
  // Program takes a string from the user and prints the result of the expression until the user enters quit

  // String for user input
  std::string userInput;

  // Integer to store the result of the evaluated expression
  int result;

  // Calculator object
  Calculator * calc = new Calculator();

  while(true)
  {
    std::cout << "Enter an expression or enter QUIT: ";
    std::cin >> userInput;

    // If the user entered QUIT, then break from the loop and the program
    if(userInput == "QUIT")
    {
      break;
    }

    // Attempt to calculate the entered string using the calculator
    try
    {
      calc->set_expression(userInput);
      result = calc->evaluate();

      std::cout << result << std::endl;
    }

    // Catches Divide by zero exception
    catch(Eval_Expr_Tree::divide_by_zero ex)
    {
      std::cout << "Expression attempts to divide by zero. Please try again." << std::endl;
    }

    // Catches Mod by zero exception
    catch(Eval_Expr_Tree::mod_by_zero ex)
    {
      std::cout << "Expression attempts to take a modulus by zero. Please try again." << std::endl;
    }

    // Catches logic error
    catch(Expr_Builder::logic_error ex)
    {
      std::cout << "Logic error in the entered expression. Please try again." << std::endl;
    }

    // Catches empty exception
    catch(Calculator::empty_expression ex)
    {
      std::cout << "No expression entered. Please try again." << std::endl;
    }

    // Catches invalid token exception
    catch(Calculator::invalid_token ex)
    {
      std::cout << "Invalid Token entered. Please try again." << std::endl;
    }

    // Catches unknown errors
    catch(...)
    {
      std::cout << "Unknown Error. Please try again" << std::endl;
    }
  }

  delete calc;
  return 0;
}
