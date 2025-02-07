/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:15:03 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/07 10:52:48 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template < typename Arr >

class Array {
  public:
	/*                               ORTHODOX CLASS                           */
	Array(void);
	Array(unsigned int n);
	Array(const Array &copy);
	~Array(void);
	Array &operator=(const Array &comp);
	Arr &operator[](size_t index);
	const Arr &operator[](size_t index) const;

	/*                               METHODS                                  */
	void fill(const Arr rhs);

	/*                               GETTERS                                  */
	size_t size() const;

	/*                               SETTERS                                  */
  private:
	size_t len;
	Arr *arr;
};

#include "Array.tpp"
#endif
