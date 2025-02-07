/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:58:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/07 10:23:22 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template < typename type >
void swap(type &a, type &b)
{
	type tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template < typename type >
type min(type a, type b)
{
	if (a == b)
		return b;
	return (a < b) ? a : b;
}

template < typename type >
type max(type a, type b)
{
	if (a == b)
		return b;
	return (a > b) ? a : b;
}
#endif
