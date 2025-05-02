/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:56:06 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:55:48 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <cstddef>
#include <iostream>

#define COLOR "\033[0;34m\033[1m"
#define VALID "\033[0;32m\033[1m"
#define RESET "\033[0m"

template < typename T >
void printArr(const T &arr, int seek) {
	std::cout << COLOR << "seeking " << seek << " in: " << RESET;
	typename T::const_iterator it = arr.begin();
	for (; it != arr.end(); ++it) {
		if (*it == seek)
			std::cout << VALID << *it << RESET << " ";
		else
			std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template < typename T >
typename T::const_iterator easyFind(const T &container, int n) {
	typename T::const_iterator it = find(container.begin(), container.end(), n);
	return it;
}

#endif
