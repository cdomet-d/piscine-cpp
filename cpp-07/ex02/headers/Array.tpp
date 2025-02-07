/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:16:55 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/07 11:00:15 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

template < typename Arr >
Array< Arr >::Array(void) : len(0), arr(new Arr[0])
{
}

template < typename Arr >
Array< Arr >::Array(unsigned int n) : len(n), arr(new Arr[n])
{
	for (size_t i = 0; i < n; i++)
		arr[i] = Arr();
	return;
}

template < typename Arr >
Array< Arr >::Array(const Array &copy) : arr(NULL)
{
	*this = copy;
}

template < typename Arr >
Array< Arr >::~Array(void)
{
	delete[] this->arr;
}

template < typename Arr >
Array< Arr > &Array< Arr >::operator=(const Array< Arr > &comp)
{
	delete[] this->arr;
	this->arr = new Arr[comp.len];
	this->len = comp.len;
	this->fill(comp[0]);
	return *this;
}

template < typename Arr >
const Arr &Array< Arr >::operator[](size_t index) const
{
	if (index > len)
		throw std::out_of_range("invalid index is OOB");
	return arr[index];
}
template < typename Arr >
Arr &Array< Arr >::operator[](size_t index)
{
	if (index > len)
		throw std::out_of_range("invalid index is OOB");
	return arr[index];
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
template < typename Arr >
void Array< Arr >::fill(const Arr rhs)
{
	for (size_t i = 0; i < len; i++)
		arr[i] = rhs;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
template < typename Arr >
size_t Array< Arr >::size() const
{
	return len;
}

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */
