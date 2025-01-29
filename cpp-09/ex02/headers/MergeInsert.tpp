/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/29 14:33:55 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsert.hpp"
#include "cerrno"
#include <algorithm>
#include <iomanip>
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
MergeInsert< Container >::MergeInsert()
{
}

template <
	template < typename, typename = std::allocator< int > > class Container >
MergeInsert< Container >::MergeInsert(const std::string &seq) : curElemSize(1)
{
	char *endptr = NULL;
	int64_t n = std::strtod(seq.c_str(), &endptr);
	addValidValue(n, endptr);
	while (*endptr) {
		n = std::strtod(endptr + 1, &endptr);
		addValidValue(n, endptr);
	}
	iSize = container.size();
	if (iSize <= 1)
		throw singleValue();
}

template <
	template < typename, typename = std::allocator< int > > class Container >
MergeInsert< Container >::~MergeInsert(void)
{
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::fillMain(
	Container< Container< int, std::allocator< int > > > &cont)
{
	splitPairs(cont);
	// std::cout << "Entering fillMain" << std::endl;
	// printContainer(cont);
	hasStraggler = (cont[cont.size() - 1].size() != curElemSize);
	if (!hasStraggler && cont.size() == PAIR) {
		// std::cout << "Container is already sorted" << std::endl;
		// std::cout << "Exiting fillMain" << std::endl << std::endl;
		return;
	} else if (hasStraggler && cont.size() == (PAIR + 1)) {
		// std::cout << "Container is already sorted" << std::endl;
		// std::cout << "Exiting fillMain" << std::endl << std::endl;
		return;
	}
	// std::cout << "Container must be sorted: printing cont" << std::endl;
	// printContainer(cont);

	Container< Container< int, std::allocator< int > > > main;
	main.resize(cont.size());
	for (size_t i = 0; i < 2; ++i) {
		main[i].insert(main[i].begin(), cont[i].begin(), cont[i].end());
	}
	// std::cout << "Printing main after adding b0 & a0" << std::endl;
	// printContainer(main);
	// std::cout << "Printing cont after adding b0 & a0" << std::endl;
	// printContainer(main);
	for (size_t i = 2; i < cont.size(); ++i) {
		if (!(i % 2)) {
			main[i].insert(main[i].begin(), cont[i].begin(), cont[i].end());
			cont[i].erase(cont[i].begin(), cont[i].end());
		}
	}

	// std::cout << "Printing MAIN" << std::endl;
	// printContainer(main);
	// std::cout << "Printing PEND" << std::endl;
	// printContainer(cont);
	cont = main;
	// std::cout << "Exiting fillMain" << std::endl << std::endl;
}

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::splitPairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	hasStraggler = (cont[cont.size() - 1].size() != curElemSize);

	printContainer(cont, "this->cont, entering SplitPair");
	curElemSize /= PAIR;
	Container< Container< int, std::allocator< int > > > splitPairs;

	// size_t splitPairSize;
	// hasStraggler ? (splitPairSize = (cont.size() - 1))
	// 			 : (splitPairSize = cont.size());
	// splitPairSize *= 2;
	// std::cout << "Has straggler:	" << (hasStraggler ? "true	" : "false	")
	// 		  << std::endl
	// 		  << "Cont.size():	" << cont.size() << std::endl
	// 		  << "splitPairSize:	" << splitPairSize << std::endl;

	splitPairs.resize(cont.size());

	size_t j = 0;
	for (size_t i = 0; i < splitPairs.size(); ++i) {
		if (splitPairs.size() == splitPairs.capacity()) {
			splitPairs.resize((splitPairs.size() + 1));
		}
		if (i % 2) {
			std::cout << "i: " << i << " | " << "j: " << j << std::endl;
			splitPairs[i].insert(splitPairs[i].begin(),
								 (cont[j].begin() + curElemSize),
								 cont[j].end());
		} else
			splitPairs[i].insert(splitPairs[i].begin(), cont[j].begin(),
								 (cont[j].begin() + curElemSize));
		j += (i % 2);
	}
	printContainer(splitPairs, "splitPairs, after splittingPairs");
	if (hasStraggler) {
		if (!makeElemFromStraggler(splitPairs)) {
			if (splitPairs.size() == splitPairs.capacity()) {
				splitPairs.resize((splitPairs.size() + 1));
			}
			size_t back = splitPairs.size() - 1;
			splitPairs[back].insert(splitPairs[back].begin(),
									cont[(cont.size() - 1)].begin(),
									cont[(cont.size() - 1)].end());
		}
	}
	cont = splitPairs;
	// std::cout << "Container after recovering value" << std::endl;
	printContainer(cont, "this->cont, exiting splitPairs");
}
template <
	template < typename, typename = std::allocator< int > > class Container >
bool MergeInsert< Container >::makeElemFromStraggler(
	Container< Container< int, std::allocator< int > > > &splitPairs)
{
	size_t back = container.size() - 1;

	if (container[back].size() < (curElemSize * 2)) {
		std::cout << "Straggler cannot make an element - exiting with "
					 "following status: "
				  << std::endl;
		printContainer(container, "this->container in StragglerCanMakeElem");
		std::cout << "---\n";
		return false;
	}
	printContainer(container, "this->container in StragglerCanMakeElem");
	printContainer(splitPairs, "splitPair in StragglerCanMakeElem");
	std::cout << "---\n";
	size_t tracker = 0;
	size_t canMakeElem = container[back].size() / curElemSize;

	size_t sPBack = splitPairs.size() - 1;
	// here we have two problems :
	// 1. resize the vector when there's no more room
	// 2. delete the elements from straggler as insert them in splitPairs.
	while (canMakeElem != 0) {
		if (splitPairs.size() == splitPairs.capacity())
			splitPairs.resize((splitPairs.size() + 1));
		splitPairs[sPBack].insert(
			splitPairs[sPBack].begin(), container[back].begin() + tracker,
			(container[back].begin() + tracker) + curElemSize);
		tracker += curElemSize;
		canMakeElem--;
	}
	printContainer(container, "this->container in makeElemFromStragger");
	printContainer(splitPairs, "splitPairs in makeElemFromStragger");
	return true;
}

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::makePairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	size_t i = 0;
	size_t pairLevel = cont.size() / PAIR;

	if (curElemSize > 1) {
		// std::cout << "Making pairs of: " << curElemSize << std::endl;
		while (i < pairLevel && (cont.size() - i >= PAIR)) {
			cont[i].insert(cont[i].end(), cont[i + 1].begin(),
						   cont[i + 1].end());
			cont.erase(cont.begin() + i + 1);
			i++;
			// std::cout << "After creating pair:\n---\n";
			// printContainer(cont);
		}
		size_t last = cont.size() - 1;
		if (cont.size() > 1 && cont[last - 1].size() < curElemSize) {
			cont[last - 1].insert(cont[last - 1].end(), cont[last].begin(),
								  cont[last].end());
			cont.erase(cont.begin() + last);
			// std::cout << "After dealing with straggler:\n---\n";
			// printContainer(cont);
		}
	}
	if (pairLevel > 1)
		sortPairs(cont);
	if ((cont.size() == 2 && cont[(cont.size() - 1)].size() != curElemSize) ||
		cont.size() == 1)
		return;
	curElemSize *= PAIR;
	makePairs(cont);
}

/* ************************************************************************** */
/*                               DEBUG                                        */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::printContainer(
	const Container< Container< int, std::allocator< int > > > &cont,
	std::string contName)
{
	size_t i = 0;
	size_t j = 0;

	size_t pairIndex = 0;
	bool a, b = false;

	for (; i < cont.size(); ++i) {
		j = 0;
		std::cout << contName << "[" << std::setw(3) << i << "]	";
		if (i % 2 && cont[i].size() == curElemSize) {
			std::cout << "a" << pairIndex << "\t";
			a = true;
		} else if (!(i % 2) && cont[i].size() == curElemSize) {
			std::cout << "b" << pairIndex << "\t";
			b = true;
		} else
			std::cout << "s\t";
		if (a == true && b == true) {
			pairIndex++;
			a = false;
			b = false;
		}
		for (; j < cont[i].size(); ++j) {
			std::cout << std::setw(3) << cont[i][j] << " ";
			if (cont[i].size() == curElemSize && j == (cont[i].size() / 2) - 1)
				std::cout << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "---" << std::endl;
}

/* ************************************************************************** */
/*                               PARSING                                      */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::addValidValue(const int64_t n,
											 const char *endptr)
{
	container.resize(container.size() + 1);
	if (*endptr && *endptr != ' ')
		throw forbiddenToken();
	if (n < 0 || n > UINT32_MAX) {
		std::cerr << n << ": ";
		throw outOfRange();
	}
	container[container.size() - 1].push_back(n);
}

/* ************************************************************************** */
/*                               UTILS                                        */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::sortPairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	for (size_t i = 0; i < cont.size() - 1; i += 2) {
		if (cont[i].size() == curElemSize &&
			cont[i + 1].size() == curElemSize) {
			if (cont[i].back() > cont[i + 1].back())
				std::swap(cont[i], cont[i + 1]);
		}
	}
}

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::sort()
{
	makePairs(container);
	merge(container);
}
template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::merge(
	Container< Container< int, std::allocator< int > > > &cont)
{
	while (cont.size() < iSize)
		fillMain(cont);
}

/* ************************************************************************** */
/*                               EXCEPTIONS                                   */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
const char *MergeInsert< Container >::forbiddenToken::what() const throw()
{
	return "Forbidden token in input";
}
template <
	template < typename, typename = std::allocator< int > > class Container >
const char *MergeInsert< Container >::outOfRange::what() const throw()
{
	return "Value is outside expected range (uint32) [0 - 4294967295]";
}

template <
	template < typename, typename = std::allocator< int > > class Container >
const char *MergeInsert< Container >::singleValue::what() const throw()
{
	return "Single value cannot be sorted";
}