/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:36:29 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/04 18:17:59 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print(T c)
{
	std::cout << c << " ";
}
template <typename T, typename Func>
void inter(T *arr, size_t len, Func function)
{
	for (size_t i = 0; i < len; i++)
		function(arr[i]);
}

#endif
