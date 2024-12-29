/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:46:22 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/20 13:52:56 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Invalid num of args\n", 1);
	
	try
	{
		int out = RPN::evaluate(argv[1]);
		std::cout << out << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	catch (...)
	{
		std::cerr << "Unknown Error catched.\n";
		return (1);
	}
	
	return (0);
	
}