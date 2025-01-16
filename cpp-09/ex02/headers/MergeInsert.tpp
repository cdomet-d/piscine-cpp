/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/16 17:38:13 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsert.hpp"

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

template < template < typename > class Container,
		   template < typename > class InnerContainer, typename Type = int >
	MergeInsert < Container< InnerContainer< Type > >::MergeInsert(void)
{
}

template < template < typename > class Container,
		   template < typename > class InnerContainer, typename Type = int >
	MergeInsert <
	Container< InnerContainer< Type > >::MergeInsert(const std::string &seq)
{
}

template < template < typename > class Container,
		   template < typename > class InnerContainer, typename Type = int >
	MergeInsert < Container< InnerContainer< Type > >::~MergeInsert(void)
{
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               EXCEPTIONS                                   */
/* ************************************************************************** */

template < template < typename > class Container,
		   template < typename > class InnerContainer, typename Type = int >
	const char *MergeInsert <
	Container< InnerContainer< Type > >::forbiddenToken::what() const throw()
{
	return "Forbidden token in input"
}
template < template < typename > class Container,
		   template < typename > class InnerContainer, typename Type = int >
	const char *MergeInsert <
	Container< InnerContainer< Type > >::isNegative::what() const throw()
{
	return "Forbidden negative number"
}