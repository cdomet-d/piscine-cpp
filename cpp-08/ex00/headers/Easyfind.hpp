/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:56:06 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/06 14:23:01 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void printArr(T &arr, int seek)
{
	std::cout <<"seeking " << seek << " in: ";
	typename T::iterator it = arr.begin();
	for (; it != arr.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
typename T::iterator easyFind(T &container, int n)
{
	typename T::iterator it = container.begin();
	for (; it != container.end(); ++it) {
		if (*it == n)
			return it;
	}
	return it;
}

#endif
