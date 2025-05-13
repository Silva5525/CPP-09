/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:30:38 by wdegraf           #+#    #+#             */
/*   Updated: 2025/05/07 12:19:38 by wdegraf          ###   ########.fr       */
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
/// although my insertions are still linear.
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

///------------------------- ENGLISH ------------------------------------
// Summary of The Art of Computer Programming - Volume 3: Sorting and Searching by Donald E. Knuth

// Topic:
// Volume 3 of the legendary series The Art of Computer Programming by Donald Knuth is dedicated to two fundamental
// areas of computer science: sorting and search algorithms. These algorithms are essential for efficient data 
// processing and form the basis of many practical applications.

// 1. sorting
// Basic idea:
// Sorting means putting a sequence of elements in a certain order (e.g. numerically or alphabetically).

// Sorting algorithms:
// Simple sorting methods:

// Insertion Sort, Selection Sort, Bubble Sort

// Good for small amounts of data, but inefficient for large (O(n²))

// More efficient methods:

// Merge Sort (O(n log n), stable)

// Quicksort (O(n log n) average, O(n²) worst case, not stable)

// Heap Sort (O(n log n), not stable)

// Distribution method:

// Counting Sort, Radix Sort, Bucket Sort

// Particularly effective with a limited range of values or known properties of the data

// Analysis:
// Runtime behavior (best/average/worst case)

// Memory consumption

// Stability of the sorting process

// Comparison-based vs. non-comparison-based sorting

// 2nd search method (searching)
// Basic idea:
// Searching means finding a specific element or property in a data structure.

// Search algorithms:
// Linear search:

// Simple, but slow (O(n))

// Binary search:

// Prerequisite: sorted list (O(log n))

// Data structures for search:
// Hash tables:

// Average O(1) access, good practice, but depends on hash function

// Trees (e.g. binary search trees, B-trees):

// Suitable for dynamic data, allow ordered traversal

// Tries (prefix trees):

// Particularly useful for strings

// Knuth's approach:
// Mathematical rigor: Each method is analyzed theoretically.

// Pseudocode: Systematic and machine-oriented.

// Historical classification: History of development and comparison with earlier work.

// Exercises: Often very demanding and in-depth.

// Target group:
// Advanced computer scientists seeking a deep understanding of algorithms, their analysis and efficient implementation.

///------------------------- GERMAN ------------------------------------
// Zusammenfassung von The Art of Computer Programming – Volume 3: Sorting and Searching von Donald E. Knuth

// Thema:
// Band 3 der legendären Reihe The Art of Computer Programming von Donald Knuth widmet sich im Detail zwei fundamentalen Bereichen
// der Informatik: Sortierverfahren und Suchalgorithmen. Diese Algorithmen sind essenziell für effiziente Datenverarbeitung und bilden
// die Grundlage vieler praktischer Anwendungen.

// 1. Sortierverfahren (Sorting)
// Grundidee:
// Sortieren bedeutet, eine Folge von Elementen in eine bestimmte Reihenfolge zu bringen (z. B. numerisch oder alphabetisch).

// Sortieralgorithmen:
// Einfachsortierverfahren:

// Insertion Sort, Selection Sort, Bubble Sort

// Gut für kleine Datenmengen, aber ineffizient bei großen (O(n²))

// Effizientere Verfahren:

// Merge Sort (O(n log n), stabil)

// Quicksort (O(n log n) durchschnittlich, O(n²) worst case, nicht stabil)

// Heap Sort (O(n log n), nicht stabil)

// Verteilungsverfahren:

// Counting Sort, Radix Sort, Bucket Sort

// Besonders effektiv bei beschränktem Wertebereich oder bekannten Eigenschaften der Daten

// Analyse:
// Laufzeitverhalten (Best/Average/Worst Case)

// Speicherverbrauch

// Stabilität des Sortierens

// Vergleichsbasiertes vs. nicht-vergleichsbasiertes Sortieren

// 2. Suchverfahren (Searching)
// Grundidee:
// Suchen bedeutet, ein bestimmtes Element oder eine Eigenschaft in einer Datenstruktur zu finden.

// Suchalgorithmen:
// Lineare Suche:

// Einfach, aber langsam (O(n))

// Binäre Suche:

// Voraussetzung: sortierte Liste (O(log n))

// Datenstrukturen für Suche:
// Hash-Tabellen:

// Durchschnittlich O(1) Zugriff, gute Praxis, aber abhängig von Hash-Funktion

// Bäume (z. B. Binäre Suchbäume, B-Bäume):

// Geeignet für dynamische Daten, ermöglichen geordnete Traversierung

// Tries (Präfixbäume):

// Besonders bei Zeichenketten nützlich

// Knuths Ansatz:
// Mathematische Strenge: Jedes Verfahren wird theoretisch fundiert analysiert.

// Pseudocode: Systematisch und maschinennah.

// Historische Einordnung: Entwicklungsgeschichte und Vergleich zu früheren Arbeiten.

// Übungsaufgaben: Oft sehr anspruchsvoll und tiefgehend.

// Zielgruppe:
// Fortgeschrittene Informatiker, die ein tiefes Verständnis von Algorithmen, deren Analyse und effizienter Implementierung anstreben.

// Fazit:
// Volume 3 ist ein fundamentales Werk über effiziente Datenverarbeitung durch Sortieren und Suchen. Es verbindet Theorie, Praxis und
// mathematische Tiefe und bleibt ein Klassiker für jeden, der Algorithmen nicht nur anwenden, sondern wirklich verstehen will.
