/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:58:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/03 16:12:21 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

#include <iostream>

template <typename T>
void swap(T *a, T *b)
{
	T *tmp;

	tmp = a;
	std::cout << a << " | " << b << std::endl;
	a = b;
	std::cout << a << " | " << b << std::endl;
	b = tmp; 
	std::cout << a << " | " << b << std::endl;
}
#endif
