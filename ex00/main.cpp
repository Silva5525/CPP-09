/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:52:47 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/20 12:26:32 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/// @brief test main for the BitcoinExchange class
int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./bitcoinExchange <File>\n";
		return (1);
	}

	try
	{
		BitcoinExchange btcExchange("bitcoin_data.csv");
		processInputFile(argv[1], btcExchange);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
