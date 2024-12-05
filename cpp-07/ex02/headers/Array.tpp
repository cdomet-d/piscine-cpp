/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:16:55 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/05 16:48:02 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void) : len(0)
{
	try {
		arr = new T[0];
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return;
	}
}

template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
	arr = new T[n];
	for (size_t i = 0; i < n; i++)
		arr[i] = 0;
	return;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	*this = copy;
}

template <typename T>
Array<T>::~Array(void)
{
	delete []this->arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &comp)
{
	delete []this->arr;
	this->arr = new T[comp.len];
	this->len = comp.len;
	for (size_t i = 0; i < this->len; i++)
		this->arr[i] = comp.arr[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index) const
{
	return arr[index];
}
template <typename T>
T &Array<T>::operator[](size_t index)
{
	return arr[index];
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
template <typename T>
void Array<T>::fill(T fill)
{
	for (size_t i = 0; i < len; i++)
		arr[i] = fill;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
template <typename T>
size_t Array<T>::size() const
{
	return len;
}

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */
