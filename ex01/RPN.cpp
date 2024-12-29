/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:46:25 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/22 15:07:05 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

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


/// @brief 
/// @param expression 
/// @return 
/// @note New in C++:
/// @fn tokens() Tokenize the input string.
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
