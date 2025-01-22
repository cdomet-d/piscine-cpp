/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/22 23:19:25 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsert.hpp"
#include "cerrno"
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

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::printContainer()
{
	size_t i = 0;
	size_t j = 0;

	for (; i < container.size(); ++i) {
		j = 0;
		std::cout << "container[" << std::setw(3) << i + 1 << "] ";
		for (; j < container[i].size(); ++j) {
			std::cout << std::setw(3) << container[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "---" << std::endl;
}

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::makePairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	size_t i = 0;
	size_t pairLevel = cont.size() / PAIR;

	while (i < cont.size() && (cont.size() - i > PAIR)) {
		cont[i].insert(cont[i].end(), cont[i + 1].begin(), cont[i + 1].end());
		cont.erase(cont.begin() + i + 1);
		i++;
	}
	size_t last = cont.size() - 1;
	if (cont.size() > pairLevel && cont[last - 1].size() < curElemSize) {
		cont[last - 1].insert(cont[last - 1].end(), cont[last].begin(),
							  cont[last].end());
		cont.erase(cont.begin() + last);
	}
	printContainer();
	curElemSize = curElemSize * PAIR;
	if (container.size() > PAIR)
		makePairs(cont);
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