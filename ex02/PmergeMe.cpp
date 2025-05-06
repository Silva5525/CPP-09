/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:31:12 by wdegraf           #+#    #+#             */
/*   Updated: 2025/05/06 14:45:15 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/// @brief Generate Jacobsthal numbers up to a limit.
/// @param n Upper bound value for Jacobsthal generation
/// @return Vector of generated Jacobsthal indices
/// @note Jacobsthal numbers: J(n) = J(n-1) + 2*J(n-2), J(0)=0, J(1)=1
std::vector<size_t> generateJacobsthal(size_t n)
{
	std::vector<size_t> num = {1, 3};
	while (num.back() < n)
	{
		num.push_back(num[num.size()-1] + 2 * num[num.size()-2]);
	}
	return (num);
}



/// @brief Print input values before sorting.
/// @param type Label ("Vector" or "List")
/// @param in Container holding unsorted values
void PmergeMe::seeBefore(const std::string& type, const std::vector<int>& input)
{
	std::cout << "Before sorting " << type << ": ";
	for (auto& i : input)
		std::cout << i << " ";
	std::cout << std::endl;
}

/// @brief Print sorted values after sorting.
/// @param type Label ("Vector" or "List")
/// @param sorted Sorted container to print
void PmergeMe::seeAfter(const std::string& type, const std::vector<int>& sorted)
{
	std::cout << "After sorting " << type << ": ";
	for (auto& i : sorted)
		std::cout << i << " ";
	std::cout << std::endl;
}

// /// @brief Sorts a vector using a simplified Ford-Johnson merge-insert method.
// /// @param data Vector to sort
// /// @note Uses pairing, sorting the first element of pairs,
// /// then inserting the second using upper_bound
// void PmergeMe::sortVector(std::vector<int>& data)
// {
//     if (data.size() < 2)
//         return ;

//     std::vector<std::pair<int, int>> pairs;
//     for (size_t i = 0; i + 1 < data.size(); i += 2)
//     {
//         if (data[i] > data[i + 1])
//             std::swap(data[i], data[i + 1]);
//         pairs.emplace_back(data[i], data[i + 1]);
//     }

//     if (data.size() % 2 != 0)
//         pairs.emplace_back(data.back(), INT_MAX);

//     std::vector<int> sorted;
//     for (const auto& pair : pairs)
//         sorted.push_back(pair.first);
//     std::sort(sorted.begin(), sorted.end());

//     for (const auto& pair : pairs)
//     {
//         if (pair.second != INT_MAX)
//         {
//             auto pos = std::upper_bound(sorted.begin(), sorted.end(), pair.second);
//             sorted.insert(pos, pair.second);
//         }
//     }
//     data = sorted;
// }

/// @brief Sorts a vector using a Jacobsthal-guided Ford-Johnson style algorithm.
/// @param data Vector of integers to sort
/// @note Steps:
/// 1. Pair elements and sort within pairs
/// 2. Recursively sort all second elements (maxPart)
/// 3. Insert firsts into result using lower_bound
/// 4. Insert maxPart values using lower_bound if not sentinel
void PmergeMe::sortVector(std::vector<int>& data)
{
	if (data.size() <= 1)
		return;

	std::vector<std::pair<int, int>> pairs;
	size_t i = 0;

	while (i + 1 < data.size()) {
		if (data[i] > data[i + 1])
			std::swap(data[i], data[i + 1]);
		pairs.emplace_back(data[i], data[i + 1]);
		i += 2;
	}

	if (i < data.size())
		pairs.emplace_back(data[i], INT_MAX);

	std::vector<int> maxPart;
	for (const auto& p : pairs)
		maxPart.push_back(p.second);

	sortVector(maxPart);

	std::vector<int> sorted = { pairs[0].first };
	std::vector<size_t> jacob = generateJacobsthal(pairs.size());

	for (size_t j = 1; j < pairs.size(); ++j)
	{
		int x = pairs[j].first;
		auto pos = std::lower_bound(sorted.begin(), sorted.end(), x);
		sorted.insert(pos, x);
	}

	for (int val : maxPart)
	{
		if (val != INT_MAX)
		{
			auto pos = std::lower_bound(sorted.begin(), sorted.end(), val);
			sorted.insert(pos, val);
		}
	}

	data = sorted;
}


/// @brief Handles sorting a vector and timing the operation.
/// @param in Vector to sort
void	PmergeMe::processVector(std::vector<int> in)
{
	auto start = std::chrono::high_resolution_clock::now();

	sortVector(in);
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> elsapsed = end - start;
	
	seeAfter("Vector", in);
	std::cout << "Time to process " << in.size() << " elements with std::vector: "
			  << elsapsed.count() << " us" << std::endl;
}

// /// @brief Sorts a list using a simplified Ford-Johnson merge-insert method.
// /// @param data List to sort
// /// @note Uses pairing, sorting the first element of pairs,
// /// then inserting the second using upper_bound
// void	PmergeMe::sortList(std::list<int>& data)
// {
// 	if (data.size() < 2)
// 		return ;
	
// 	std::list<std::pair<int, int>> pairs;
// 	auto it = data.begin();
// 	while (it != data.end())
// 	{
// 		auto next = std::next(it);
// 		if (next != data.end() && *it > *next)
// 			{
// 				pairs.emplace_back(*next, *it);
// 				std::advance(it, 2);
// 			}
// 		else
// 		{
// 			pairs.emplace_back(*it, INT_MAX);
// 			++it;
// 		}
// 	}
	
// 	std::list<int> sorted;
// 	for (const auto& pair : pairs)
// 		sorted.push_back(pair.first);
// 	sorted.sort();

// 	for (const auto& pair : pairs)
// 	{
// 		if (pair.second != INT_MAX)
// 		{
// 			auto pos = std::find_if(sorted.begin(), sorted.end(), 
// 						[&pair](int i) { return i > pair.second; });
// 			sorted.insert(pos, pair.second);
// 		}
// 	}
// 	data = sorted;
// }

/// @brief Sorts a std::list using a Jacobsthal-guided Ford-Johnson-style algorithm.
/// @param data List of integers to sort
/// @note Steps:
/// 1. Pair elements, sort within each pair
/// 2. Recursively sort the second elements (maxPart)
/// 3. Insert firsts of pairs into result using linear search
/// 4. Insert maxPart values (second elements) using linear search
void PmergeMe::sortList(std::list<int>& data)
{
	if (data.size() <= 1)
		return;

	std::list<std::pair<int, int>> pairs;
	auto it = data.begin();

	while (it != data.end()) {
		auto next = std::next(it);
		if (next != data.end()) {
			int a = *it, b = *next;
			if (a > b) std::swap(a, b);
			pairs.emplace_back(a, b);
			std::advance(it, 2);
		} else {
			pairs.emplace_back(*it, INT_MAX);
			break;
		}
	}

	std::list<int> maxPart;
	for (const auto& p : pairs)
		maxPart.push_back(p.second);

	sortList(maxPart);

	std::list<int> sorted = { pairs.front().first };

	auto jacob = generateJacobsthal(pairs.size());

	for (auto it = std::next(pairs.begin()); it != pairs.end(); ++it)
	{
		if (it->first == INT_MAX) continue;
		auto pos = std::find_if(sorted.begin(), sorted.end(),
					[&](int x){ return x > it->first; });
		sorted.insert(pos, it->first);
	}

	for (const int val : maxPart)
	{
		if (val == INT_MAX) continue;
		auto pos = std::find_if(sorted.begin(), sorted.end(),
					[&](int x){ return x > val; });
		sorted.insert(pos, val);
	}

	data = sorted;
}


/// @brief Handles sorting a list and timing the operation.
/// @param in List to sort
void	PmergeMe::processList(std::list<int> in)
{
	auto start = std::chrono::high_resolution_clock::now();

	sortList(in);
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> elsapsed = end - start;
	
	std::vector<int> sorted(in.begin(), in.end());
	seeAfter("List", sorted);
	std::cout << "Time to process " << in.size() << " elements with std::list: "
			  << elsapsed.count() << " us" << std::endl;
}
