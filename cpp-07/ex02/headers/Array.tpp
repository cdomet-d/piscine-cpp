/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:16:55 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:25:02 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

template < typename ArrType >
Array< ArrType >::Array(void) : len(0), arr(new ArrType[0])
{
}

template < typename ArrType >
Array< ArrType >::Array(unsigned int n) : len(n), arr(new ArrType[n])
{
	for (size_t i = 0; i < n; i++)
		arr[i] = ArrType();
}

template < typename ArrType >
Array< ArrType >::Array(const Array &rhs) : arr(NULL)
{
	*this = rhs;
}

template < typename ArrType >
Array< ArrType >::~Array(void)
{
	delete[] this->arr;
}

template < typename ArrType >
Array< ArrType > &Array< ArrType >::operator=(const Array< ArrType > &rhs)
{
	delete[] this->arr;
	this->arr = new ArrType[rhs.len];
	this->len = rhs.len;
	this->fill(rhs[0]);
	return *this;
}

template < typename ArrType >
const ArrType &Array< ArrType >::operator[](size_t index) const
{
	if (index > len)
		throw std::out_of_range("invalid index is OOB");
	return arr[index];
}
template < typename ArrType >
ArrType &Array< ArrType >::operator[](size_t index)
{
	if (index > len)
		throw std::out_of_range("invalid index is OOB");
	return arr[index];
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
template < typename ArrType >
void Array< ArrType >::fill(const ArrType rhs)
{
	for (size_t i = 0; i < len; i++)
		arr[i] = rhs;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
template < typename ArrType >
size_t Array< ArrType >::size() const
{
	return len;
}

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */
