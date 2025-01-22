/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/22 19:13:51 by cdomet-d         ###   ########.fr       */
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
		for (; j < container[i].size(); ++j) {
			std::cout << std::setw(3) << container[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "array of size {" << i << ", " << j << "}" << std::endl;
}

template < template < typename, typename = std::allocator< int > >
		   class Container >
void MergeInsert< Container >::makePairs(
	Container< Container< int, std::allocator< int > > > &_container)
{
	size_t i = 0;
	size_t j;
	curElemSize = curElemSize * 2;
	while (std::distance(_container.begin() + i, _container.end()) >
		   curElemSize) {
		j = i + 1;
		_container[i].insert(_container[i].end(), _container[j].begin(),
							 _container[j].end());
		_container.erase(_container.begin() + j);
		i++;
	}
	size_t last = container.size();
	if (_container[last - 1].size() < curElemSize && _container[last - 2].size() < curElemSize) {
		std::cout << curElemSize << std::endl;
		_container[last - 2].insert(_container[last - 2].end(), _container[last - 1].begin(),
								 _container[last - 1].end());
		_container.erase(_container.begin() + last - 1);
	}
	printContainer();
	if (std::distance(_container.begin(), _container.end()) > curElemSize)
		makePairs(_container);
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