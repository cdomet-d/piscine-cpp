/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/13 15:27:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include <iomanip>
#include <iostream>
#include <map>

#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

void testInvalid();
void testValid();

#define VALID_EXPR(rpn, expr, expected)                                        \
	try {                                                                      \
		std::cout << std::setw(35) << std::left << "Evaluating: " + expr       \
				  << " | ";                                                    \
		rpn.compute(expr);                                                     \
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

#endif