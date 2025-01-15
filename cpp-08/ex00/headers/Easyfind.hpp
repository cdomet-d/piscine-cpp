/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:56:06 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/15 17:42:24 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <cstddef>
#include <iostream>

template < typename T >
void printArr(const T &arr, int seek)
{
	std::cout << "seeking " << seek << " in: ";
	typename T::const_iterator it = arr.begin();
	for (; it != arr.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template < typename T >
typename T::const_iterator easyFind(const T &container, int n)
{
//TODO: dont do that, use find
	typename T::const_iterator it = container.begin();
	for (; it != container.end(); ++it) {
		if (*it == n)
			return it;
	}
	return it;
}

#endif
