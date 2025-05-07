/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:31:28 by wdegraf           #+#    #+#             */
/*   Updated: 2025/05/06 18:12:26 by wdegraf          ###   ########.fr       */
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
/// @details Used Funktions:
/// @fn size() counts the number of elements in the vector.
/// @fn swap() exchanges the values of two elements.
/// @fn emplace_back() adds a new element to the end of the vector.
/// @fn back() returns a reference to the last element of the vector.
/// @fn sort() sorts the elements of the vector in ascending order.
/// @fn begin() returns an iterator to the first element of the vector.
/// @fn end() returns an iterator to the past-the-end element of the vector.
/// @fn upper_bound() returns an iterator to the first element in the range.
/// @fn insert() inserts a new element into the vector at the specified position.
/// @fn advance() moves the iterator forward by a specified number of steps.
/// @fn inserted() checks if an index has been inserted.
/// @fn count() returns the number of elements in the list.
/// @fn find_if() returns an iterator to the first element in the range.
/// @fn front() returns a reference to the first element of the list.
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
