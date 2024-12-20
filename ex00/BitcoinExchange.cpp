/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:52:37 by wdegraf           #+#    #+#             */
/*   Updated: 2024/12/20 12:41:52 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/// @brief Default constructor for BitcoinExchange
BitcoinExchange::BitcoinExchange() {}

/// @brief Custom constructor for BitcoinExchange
/// @param dataFile file to read the exchange rate from
/// @note New in C++;
/// @fn std::ifstream opens a file for reading.
/// @fn std::getline reads characters from an input stream and stores them into a string.
/// @fn std::istringstream is an input stream that operates on strings.
/// @fn .empty() if map has no values stored becouse of wrong data it
/// returns true so the programm can throw an error.
BitcoinExchange::BitcoinExchange(const std::string& dataFile)
{
	std::ifstream file(dataFile);
	if (!file.is_open())
		throw std::runtime_error("Could not open file.");
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Database empty.");
	while (std::getline(file, line))
	{
		std::istringstream stream(line);
		std::string date;
		float exchangeRate;

		if (std::getline(stream, date, ',') && stream >> exchangeRate)
			datas[date] = exchangeRate;
	}
	if (datas.empty())
		throw std::runtime_error("Database no valid data.");
}

/// @brief Copy constructor for BitcoinExchange
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : datas(src.datas) {}

/// @brief Assignment operator for BitcoinExchange
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		datas = src.datas;
	return (*this);
}

/// @brief Default destructor for BitcoinExchange
BitcoinExchange::~BitcoinExchange() {}

/// @brief getter function returns the exchange rate for a given date
/// @param date the date for which the exchange rate is requested
/// @return pointer to the exchange rate for the given date or nullptr
/// if no data is available. 
/// @note New in C++;
/// @fn .lower_bound() returns an iterator pointing to the first element
/// in the container whose key is not considered to go before k (i.e., either
/// it is equivalent or goes after).
float	BitcoinExchange::getRate(const std::string& date) const
{
	auto it = datas.lower_bound(date);
	if (it == datas.end() || it->first != date)
	{
		if (it == datas.begin())
			throw std::runtime_error("No data available for this date -> " + date);
		it--;
	}
	return (it->second);
}

/// @brief validates a date string in the format "YYYY-MM-DD"
/// @param date to validate
/// @return true if the date is valid, false otherwise
bool	BitcoinExchange::validDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int year, month, day;
	char c1, c2;
	std::istringstream stream(date);
	if (!(stream >> year >> c1 >> month >> c2 >> day))
		return (false);
	if (c1 != '-' || c2 != '-')
		return (false);
	if (year < 0 || month < 1 || month > 12)
		return (false);
	const int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int  maxDays = monthDay[month - 1];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		maxDays = 29;
	if (day < 1 || day > maxDays)
		return (false);
	return (true);
}

/// @brief processes an input file with the format "date | value"
/// @param iFile the file to process
/// @param btcEx the exchange rate data
void	processInputFile(const std::string& iFile, const BitcoinExchange& btcEx)
{
	std::ifstream file(iFile);
	if (!file.is_open())
		throw std::runtime_error("Could not open file.");

	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("File empty.");
	while (std::getline(file, line))
	{
		if (line == "date | value")
			continue ;
		std::istringstream stream(line);
		std::string date, seperator;
		float val;

		if (!(stream >> date >> seperator >> val) || seperator != "|")
		{
			std::cerr << "Invalid input format -> " << line << '\n';
			continue ;
		}
		if (val < 0)
		{
			std::cerr << "Value too low -> " << line << '\n';
			continue ;
		}
		if (val > 1000)
		{
			std::cerr << "Value too high -> " << line << '\n';
			continue ;
		}
		if (!BitcoinExchange::validDate(date))
		{
			std::cerr << "Invalid date ->" << line << '\n';
			continue ;
		}
		try
		{
			float rate = btcEx.getRate(date);
			std::cout << date << " -> " << val << " BTC = " << val * rate << " USD\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
