/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:02:04 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/03 16:11:24 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include <iostream>

int main(void)
{
	int a = 15;
	int b = 5;

	std::cout << a << " | " << b << std::endl;
	swap(&a, &b);
	std::cout << a << " | " << b << std::endl;
}