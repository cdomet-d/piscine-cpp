/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/13 14:27:57 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Usage: <Number to convert and display>" << std::endl;
		return 1;
	}
	std::string s = av[1];
	ScalarConverter::convert(s);
	return 0;
}
