/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:57:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/13 15:18:27 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iomanip>
#include <iostream>
#include <map>

#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

#define VALID_EXPR(rpn, expr, expected)                                        \
	try {                                                                      \
		std::cout << std::setw(35) << std::left << "Evaluating: " + expr       \
				  << " | ";                                                    \
		rpn.evaluateExpression(expr);                                          \
		if (rpn.getResult() == expected) {                                     \
			std::cout << BG "expected " << std::setw(10) << expected           \
					  << " got " << std::setw(10) << rpn.getResult() << R      \
					  << std::endl;                                            \
		} else                                                                 \
			std::cout << BR "expected " << std::setw(10) << expected           \
					  << " got " << std::setw(10) << rpn.getResult() << R      \
					  << std::endl;                                            \
	} catch (std::exception & e) {                                             \
		std::cout << BR "expected " << expected << " got : " << e.what() << R  \
				  << std::endl;                                                \
	}

#define INVALID_EXPR(expr, testObject, expected)                               \
	try {                                                                      \
		std::cout << std::setw(35) << std::left << "Evaluating: " #expr ""     \
				  << " | ";                                                    \
		testObject;                                                            \
		std::cout << BR "expected	" #expected ", but program didn't throw" R \
				  << std::endl;                                                \
	} catch (expected & e) {                                                   \
		std::cout << BG "expected	" #expected "" << "	got: " << e.what()     \
				  << R << std::endl;                                           \
	} catch (std::exception & e) {                                             \
		std::cout << BR "expected	" #expected "" << "	got: " << e.what()     \
				  << R << std::endl;                                           \
	}

void runTests()
{
	{
		std::cout << "Valid expressions" << std::endl;

		std::map< std::string, int > validOp;
		RPN rpn;

		validOp["7 2 + 3 * 4 -"] = 23;
		validOp["5 6 * 8 - 2 /"] = 11;
		validOp["1 2 + 3 * 4 + 5 *"] = 65;
		validOp["8 2 * 3 + 4 * 5 -"] = 71;
		validOp["2 3 + 4 * 5 - 5 /"] = 3;
		validOp["8 4 / 3 * 2 + 7 -"] = 1;
		validOp["9 3 / 2 * 4 + 6 -"] = 4;
		validOp["1 2 + 3 + 4 + 5 *"] = 50;
		validOp["8 9 + 5 * 5 *"] = 425;
		for (std::map< std::string, int >::iterator it = validOp.begin();
			 it != validOp.end(); ++it) {
			VALID_EXPR(rpn, it->first, it->second);
		}
	}
	std::cout << "\nException testing" << std::endl;
	{
		RPN rpn;
		INVALID_EXPR("5 2 * 3 + 4 * 0 /",
					 rpn.evaluateExpression("5 2 * 3 + 4 * 0 /"),
					 RPN::DivisionByZero);
	}
	{
		RPN rpn;
		INVALID_EXPR("7 2 + 3e * 4 -", rpn.evaluateExpression("7 2 + 3e * 4 -"),
					 RPN::UnexpectedToken);
	}
	{
		RPN rpn;
		INVALID_EXPR("5 *", rpn.evaluateExpression("5 *"),
					 RPN::MissingOperands);
	}
	{
		RPN rpn;
		INVALID_EXPR("1 / + 3 * 4 + 5 *",
					 rpn.evaluateExpression("1 / + 3 * 4 + 5 *"),
					 RPN::MissingOperands);
	}
	{
		RPN rpn;
		INVALID_EXPR("", rpn.evaluateExpression(""), RPN::MissingOperators);
	}
	{
		RPN rpn;
		INVALID_EXPR("8 9 + 5 5 *", rpn.evaluateExpression(""),
					 RPN::MissingOperators);
	}
}
int main(int ac, char *av[])
{
	if (ac < 2) {
		std::cerr << "Usage: ./RPN < \"expression-to-evaluate\" >" << std::endl
				  << "Usage: ./RPN < -t > to run automated tests" << std::endl;
		return 1;
	}

	std::string expr = av[1];
	if (expr == "-t") {
		try {
			runTests();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
		return 0;
	}

	RPN rpn;
	try {
		rpn.evaluateExpression(expr);
		std::cout << rpn.getResult() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
