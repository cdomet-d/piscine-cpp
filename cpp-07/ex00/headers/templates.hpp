/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:58:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/15 10:51:37 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template < typename T >
void swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template < typename T >
T min(T a, T b)
{
	if (a == b)
		return b;
	return (a < b) ? a : b;
}

template < typename T >
T max(T a, T b)
{
	if (a == b)
		return b;
	return (a > b) ? a : b;
}
#endif
