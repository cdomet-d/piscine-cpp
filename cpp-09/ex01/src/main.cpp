/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:57:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/10 14:41:47 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <map>

#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

#define TEST_EXPR(rpn, expr, expected)                                         \
	try {                                                                      \
		std::cout << "Evaluating: " + expr << "	| ";                           \
		rpn.evaluateExpression(expr);                                          \
		if (rpn.getStackValue() == expected)                                   \
			std::cout << BG "expected " << expected << ", got "                \
					  << rpn.getStackValue() << R << std::endl;                \
		else                                                                   \
			std::cout << BR "expected" << expected << ", got "                 \
					  << rpn.getStackValue() << R << std::endl;                \
	} catch (std::exception & e) {                                             \
		std::cout << BR "expected " << expected << ", got : " << e.what() << R \
				  << std::endl;                                                \
	}

void runTests(RPN rpn)
{
	std::map< std::string, int > validOp;

	validOp["3 4 + 2 *"] = 14;
	validOp["7 2 + 3 * 4 -"] = 23;
	validOp["5 6 * 8 - 2 /"] = 11;
	validOp["1 2 + 3 * 4 + 5 *"] = 65;
	validOp["8 2 * 3 + 4 * 5 -"] = 71;
	validOp["2 3 + 4 * 5 - 6 /"] = 3;
	validOp["8 4 / 3 * 2 + 7 -"] = 1;
	validOp["5 2 * 3 + 4 * 0 /"] = 26;
	validOp["9 3 / 2 * 4 + 6 -"] = 4;
	validOp["1 2 + 3 + 4 + 5 *"] = 50;

	for (std::map< std::string, int >::iterator it = validOp.begin();
		 it != validOp.end(); ++it) {
		TEST_EXPR(rpn, it->first, it->second);
	}
}
int main(int ac, char *av[])
{
	RPN rpn;
	if (ac < 2) {
		runTests(rpn);
		return 0;
	}

	std::string expr = av[1];
	try {
		rpn.evaluateExpression(expr);
		std::cout << rpn.getStackValue() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}