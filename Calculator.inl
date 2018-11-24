/* I pledge that I have neither given nor received any help on this assignment */

// Inline Implementation for the Calculator class

inline
void Calculator::set_expression(std::string expr)
{
  this->expression_ = expr;
}

inline
int Calculator::get_result(void)
{
  return this->result_;
}
