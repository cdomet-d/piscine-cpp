/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:02:04 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/15 10:51:05 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include <iostream>

void testSwap();
void testMin();
void testMax();
void mandatoryMain();

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "To test Swap	enter:	1" << std::endl
				  << "To test Min	enter:	2" << std::endl
				  << "To test Max	enter:	3" << std::endl
				  << "To test Mandatory	enter:	4" << std::endl
				  << "To see all tests	enter:	5" << std::endl;
		return 1;
	}
	std::string input = av[1];
	if (input.compare("1") == 0)
		testSwap();
	else if (input.compare("2") == 0)
		testMin();
	else if (input.compare("3") == 0)
		testMax();
	else if (input.compare("4") == 0)
		mandatoryMain();
	else if (input.compare("5") == 0) {
		testSwap();
		std::cout << "---" << std::endl << std::endl;
		testMin();
		std::cout << "---" << std::endl << std::endl;
		testMax();
		std::cout << "---" << std::endl << std::endl;
		mandatoryMain();
	} else {
		std::cout << "To test Swap	enter:	1" << std::endl
				  << "To test Min	enter:	2" << std::endl
				  << "To test Max	enter:	3" << std::endl
				  << "To test Mandatory	enter:	4" << std::endl
				  << "To see all tests	enter:	5" << std::endl;
		return 1;
	}
}