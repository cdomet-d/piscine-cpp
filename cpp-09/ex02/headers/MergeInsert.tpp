/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/23 17:04:14 by cdomet-d         ###   ########.fr       */
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
MergeInsert< Container >::MergeInsert(const std::string &seq) : curElemSize(2)
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
	sortPairs(container);
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
	Container main;
	Container pending;
	curElemSize /= PAIR;

	if (container.size())
	
}

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::makePairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	size_t i = 0;
	size_t pairLevel = cont.size() / PAIR;

	while (i < pairLevel && (cont.size() - i > PAIR) ) {
		cont[i].insert(cont[i].end(), cont[i + 1].begin(), cont[i + 1].end());
		cont.erase(cont.begin() + i + 1);
		i++;
	}
	size_t last = cont.size() - 1;
	if (cont.size() > 1 && cont[last - 1].size() < curElemSize) {
		cont[last - 1].insert(cont[last - 1].end(), cont[last].begin(),
							  cont[last].end());
		cont.erase(cont.begin() + last);
	}
	if (pairLevel > 1)
		sortPairs(cont);
	printContainer();
	curElemSize *= PAIR;
	if (pairLevel > 1)
		makePairs(cont);
}

/* ************************************************************************** */
/*                               DEBUG                                        */
/* ************************************************************************** */

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::printContainer()
{
	size_t i = 0;
	size_t j = 0;

	for (; i < container.size(); ++i) {
		j = 0;
		std::cout << "container[" << std::setw(3) << i << "]	";
		for (; j < container[i].size(); ++j) {
			std::cout << std::setw(3) << container[i][j] << " ";
			if (j == (container[i].size() / 2) - 1)
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
	for (size_t	i = 0; i < cont.size() - 1; i += 2){
		if (cont[i].back() > cont[i + 1].back())
			std::swap(cont[i], cont[i + 1]);
	}
}

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::sort()
{
	makePairs(container);
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