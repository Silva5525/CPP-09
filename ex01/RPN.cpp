/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:46:25 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/29 22:27:58 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/// @brief checks if a character is an operator
/// @param c character to check
/// @return true if c is an operator, false otherwise
bool	RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

/// @brief performs an operation on two integers.
/// @param a the first operand (after first operation holds the result
/// of the previous operation)
/// @param b the second operand
/// @param op the operator to apply
/// @return the result of the operation or throws an exception if the
/// operation is invalid or overflows
int RPN::performOperation(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
				throw std::runtime_error("Integer overflow in addition.");
			return (a + b);
		case '-':
			if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
				throw std::runtime_error("Integer overflow in subtraction.");
			return (a - b);
		case '*':
			if (b != 0 && (a > INT_MAX / b || a < INT_MIN / b))
				throw std::runtime_error("Integer overflow in multiplication.");
			return (a * b);
		case '/':
			if (b == 0)
				throw std::runtime_error("Division by zero.");
			return (a / b);
		default:
			throw std::runtime_error("Invalid operator.");
	}
}

/// @brief evaluates a reverse polish notation expression.
/// @param expression to evaluate.
/// @return top of the stack after evaluating the expression or throws
/// an exception if the expression is invalid.
/// @note New in C++:
/// @fn std::stack is a container adapter that gives the programmer the
/// functionality of a stack - specifically, a LIFO (last-in, first-out)
/// data structure. (<int> is the type of the stack and operant the name)
/// @fn size() returns the number of elements in the stack.
/// @fn push() inserts a new element at the top of the stack.
/// @fn top() returns a reference to the top element of the stack.
/// @fn pop() removes the top element of the stack.
/// @fn tokens() Tokenize the input string.
/// @overload >> operator extracts the next token from the istringstream
/// and stores it in the string token. (while it finds a token in tokens)
int RPN::evaluate(const std::string& expression)
{
	std::stack<int> operant;
	std::istringstream tokens(expression);
	std::string token;

	while (tokens >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			operant.push(token[0] - '0');
		else if (token.size() == 1 && isOperator(token[0]))
		{
			if (operant.size() < 2)
				throw std::runtime_error("Not enogh Operands.");
			int b = operant.top();
			operant.pop();
			int a = operant.top();
			operant.pop();
			operant.push(performOperation(a, b, token[0]));
		}
		else
			throw std::runtime_error("Invalid Token");
	}
	
	if (operant.size() != 1)
		throw std::runtime_error("Invalid expression");

	return (operant.top());
}
