/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:46:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 13:44:27 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include "Span.hpp"

#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

// test macro to compare expected exception against received exception
#define TEST_THROW(testObject, expected)                                       \
	try {                                                                      \
		testObject;                                                            \
		std::cout << BR "expected " #expected ", but program didn't throw" R   \
				  << std::endl;                                                \
	} catch (expected const &e) {                                              \
		std::cout << BG << e.what() << R << std::endl;                         \
	} catch (std::exception &e) {                                             \
		std::cout << BR "expected " #expected "" << ", got : " << e.what()     \
				  << R << std::endl;                                           \
	}

void errorHandling(Span &span, const std::vector< unsigned int > &src);
void largeArr(const char *str);
void deepCopy(Span &span);

#endif