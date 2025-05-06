/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:30:38 by wdegraf           #+#    #+#             */
/*   Updated: 2025/05/06 14:34:12 by wdegraf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/// @brief main function for the Ford-Johnson sort (PmergeMe).
/// @param argc argument count
/// @param argv argument vector
/// @return 0 on success, 1 on error
/// @details This is a simplified Ford-Johnson algorithm. The process
/// begins by forming (min, max) pairs. I then recursively sort the 'second'
/// elements of each pair. The 'first' elements are inserted into a sorted
/// sequence — this builds the base. Then I insert the sorted 'second'
/// elements one-by-one using binary search. I’ve also generated the Jacobsthal
/// sequence to reflect how the full Ford-Johnson optimizes insertion order,
/// although my insertions are still linear. The goal was to stay faithful to
///the structure while keeping the implementation clean and efficient.
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return (1);
    }

    std::vector<int> inVector;
    try 
    {
        for (int i = 1; i < argc; ++i)
        {
            int v = std::stoi(argv[i]);
            if (v < 1)
                throw std::invalid_argument("Only positive integers are allowed.");
            inVector.push_back(v);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: Invalid argument - " << e.what() << std::endl;
        return (1);
    }

    std::list<int> inList(inVector.begin(), inVector.end());

    PmergeMe sorter;
    sorter.seeBefore("Vector", inVector);
    sorter.processVector(inVector);
    sorter.processList(inList);

    return (0);
}
