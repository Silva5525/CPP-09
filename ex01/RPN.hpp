/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:46:28 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/29 22:28:50 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <climits>

/// @brief 
/// @note New in C++:
/// @example for Orthodox class here:
/// If we dont use Explicit define our Constructor and Destructor
/// The Compiler would create a compiler providet default for them. 
/// @fn = default is used to say Explicit that we want to use a 
/// compiler providet default constructor and destructor.
/// @fn = delete is used here for copy & assign constructor 
/// to forbid their use.
/// @attention after using default and delete for all orthodox parts
/// their is no need for defineing them in the .cpp file.
class RPN
{
	private:
		static bool		isOperator(char c);
		static int		performOperation(int a, int b, char op);

	public:
		RPN() = default;
		~RPN() = default;

		RPN(const RPN&) = delete;
		RPN& operator=(const RPN&) = delete;
		
		static int		evaluate(const std::string& expression);
};

#endif