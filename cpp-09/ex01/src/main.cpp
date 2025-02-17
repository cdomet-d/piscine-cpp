/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:57:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/17 14:10:58 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "unitTest.hpp"
int main(int ac, char *av[])
{
	if (ac < 2 || (ac > 2) || (ac == 2 && !av[1])) {
		std::cerr << "Expected quoted string" << std::endl
				  << "Usage: ./RPN < \"expression-to-evaluate\" >" << std::endl
				  << "Usage: ./RPN < -t > to run automated tests" << std::endl;
		return 1;
	}

	std::string expr = av[1];
	if (expr == "-t") {
		try {
			testValid();
			testInvalid();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
		return 0;
	}

	RPN rpn;
	try {
		rpn.compute(expr);
		std::cout << rpn.getResult() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
