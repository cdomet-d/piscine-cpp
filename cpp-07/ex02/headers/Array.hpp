/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:15:03 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/05 16:33:11 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array {
  public:
	/*                               ORTHODOX CLASS                           */
	Array(void);
	Array(unsigned int n);
	Array(const Array &copy);
	~Array(void);
	Array &operator=(const Array &copy);
	T &operator[](size_t index);
	T &operator[](size_t index) const;


	/*                               METHODS                                  */
	void fill(T fill);

	/*                               GETTERS                                  */
	size_t size() const;

	/*                               SETTERS                                  */
  private:
	T *arr;
	size_t len;
};

#include "Array.tpp"
#endif
