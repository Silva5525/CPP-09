/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:52:24 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/20 12:14:56 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

/// @brief Class to store and retrieve exchange rates for Bitcoin
/// @note New in C++;
/// @fn std::map is a sorted associative container that contains
/// key-value pairs with unique keys. (string must be unique and
/// float is the value associated with the key)
/// std::map is automaticly sorted in alphabetical order for string keys
class BitcoinExchange
{
	private:
		std::map<std::string, float> datas;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& dataFile);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		float getRate(const std::string& date) const;
		static bool validDate(const std::string& date);
};

void	processInputFile(const std::string& iFile, const BitcoinExchange& btcEx);

#endif
