/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:31:28 by wdegraf           #+#    #+#             */
/*   Updated: 2025/05/06 14:26:45 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>		///< std::vector - dynamic array
#include <algorithm>	///< std::sort, std::upper_bound, std::find_if
#include <iostream>		///< std::cout, std::cerr
#include <chrono>		///< std::chrono for performance timing
#include <stdexcept>	///< std::invalid_argument, std::exception
#include <list>			///< std::list - doubly-linked list
#include <string>		///< std::string
#include <climits>		///< INT_MAX for sentinel values

/// @brief Class to sort containers using a Ford-Johnson-like algorithm
/// I match pairs of elements, sort the first element of each pair,
/// and then insert the second element into the sorted list using upper_bound.
/// @note This is a simplified version of the Ford-Johnson merge-insert method.
class PmergeMe
{
	private:
		void	sortVector(std::vector<int>& data);
		void	sortList(std::list<int>& data);

	public:
		PmergeMe() = default;
		~PmergeMe() = default;
		PmergeMe(const PmergeMe&) = delete;
		PmergeMe& operator=(const PmergeMe&) = delete;

		void	processVector(std::vector<int> in);
		void	processList(std::list<int> in);
		
		void	seeBefore(const std::string& type, const std::vector<int>& in);
		void	seeAfter(const std::string& type, const std::vector<int>& sorted);
};

#endif
