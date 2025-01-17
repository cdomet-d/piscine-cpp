/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/17 17:33:07 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsert.hpp"
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
MergeInsert< Container >::MergeInsert(const std::string &seq)
{
	container.resize(1);

	char *endptr;
	uint32_t n = std::strtod(seq.c_str(), &endptr);
	container[0].push_back(n);

	while (*endptr && *endptr == ' ') {
		n = std::strtod(endptr + 1, &endptr);
		container[0].push_back(n);
	}
	std::cout << "Outer container.size(): " << container.size() << std::endl;
	std::cout << "Inner container.size(): " << container[0].size() << std::endl;
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
void MergeInsert< Container >::printContainer()
{
	for (size_t i = 0; i < container.size(); ++i) {
		for (size_t j = 0; j < container[i].size(); ++j) {
			std::cout << container[i][j] << " ";
		}
		std::cout << std::endl;
	}
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
const char *MergeInsert< Container >::isNegative::what() const throw()
{
	return "Forbidden negative number";
}