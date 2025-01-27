/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/27 17:57:28 by cdomet-d         ###   ########.fr       */
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

template < template < typename, typename = std::allocator< int > >
		   class Container >
MergeInsert< Container >::MergeInsert()
{
}

template < template < typename, typename = std::allocator< int > >
		   class Container >
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

template < template < typename, typename = std::allocator< int > >
		   class Container >
MergeInsert< Container >::~MergeInsert(void)
{
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::undoPairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	Container< Container< int, std::allocator< int > > > main;
	Container< Container< int, std::allocator< int > > > pending;
	bool hasStraggler = (cont[cont.size() - 1].size() != curElemSize);

	curElemSize /= PAIR;

	size_t pairLevel;
	hasStraggler ? (pairLevel = ((cont.size() - 1) * 2) + 1)
				 : (pairLevel = cont.size() * 2);
	Container< Container< int, std::allocator< int > > > splitPairs;

	std::cout << "UNDOING PAIRS" << std::endl
			  << "Pair Level:	" << pairLevel << std::endl
			  << "Has straggler:	" << (hasStraggler ? "true" : "false")
			  << std::endl;

	splitPairs.resize(pairLevel);

	size_t j = 0;
	for (size_t i = 0; i < cont.size(); ++i) {
		std::cout << "\ni: " << i << " | " << "j: " << j << std::endl;
		if (i % 2)
			splitPairs[i].insert(splitPairs[i].begin(),
								 (cont[j].begin() + curElemSize),
								 cont[j].end());
		else
			splitPairs[i].insert(splitPairs[i].begin(), cont[j].begin(),
								 (cont[j].begin() + curElemSize));
		j += (i % 2);
		printContainer(splitPairs);
	}
	size_t back = splitPairs.size() - 1;
	splitPairs[back].insert(splitPairs[back].begin(),
							cont[(cont.size() - 1)].begin(),
							cont[(cont.size() - 1)].end());
	printContainer(splitPairs);
}

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::makePairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	size_t i = 0;
	size_t pairLevel = cont.size() / PAIR;

	if (curElemSize > 1) {
		std::cout << "Making pairs of: " << curElemSize << std::endl;
		while (i < pairLevel && (cont.size() - i >= PAIR)) {
			cont[i].insert(cont[i].end(), cont[i + 1].begin(),
						   cont[i + 1].end());
			cont.erase(cont.begin() + i + 1);
			i++;
			std::cout << "After creating pair:\n---\n";
			printContainer(cont);
		}
		size_t last = cont.size() - 1;
		std::cout << "cont[last].size() |  curElemSize" << std::endl;
		std::cout << cont[last].size() << " | " << curElemSize << std::endl;
		if (cont.size() > 1 && cont[last - 1].size() < curElemSize) {
			cont[last - 1].insert(cont[last - 1].end(), cont[last].begin(),
								  cont[last].end());
			cont.erase(cont.begin() + last);
			std::cout << "After dealing with straggler:\n---\n";
			printContainer(cont);
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

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::printContainer(
	const Container< Container< int, std::allocator< int > > > &cont)
{
	size_t i = 0;
	size_t j = 0;

	for (; i < cont.size(); ++i) {
		j = 0;
		std::cout << "cont[" << std::setw(3) << i << "]	";
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

template < template < typename, typename = std::allocator< int > >
		   class Container >
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

template < template < typename, typename = std::allocator< int > >
		   class Container >
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
	std::cout << "After sorting pairs:\n---\n";
	printContainer(cont);
}

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::sort()
{
	makePairs(container);
	undoPairs(container);
}

/* ************************************************************************** */
/*                               EXCEPTIONS                                   */
/* ************************************************************************** */

template < template < typename, typename = std::allocator< int > >
		   class Container >
const char *MergeInsert< Container >::forbiddenToken::what() const throw()
{
	return "Forbidden token in input";
}
template < template < typename, typename = std::allocator< int > >
		   class Container >
const char *MergeInsert< Container >::outOfRange::what() const throw()
{
	return "Value is outside expected range (uint32) [0 - 4294967295]";
}

template < template < typename, typename = std::allocator< int > >
		   class Container >
const char *MergeInsert< Container >::singleValue::what() const throw()
{
	return "Single value cannot be sorted";
}