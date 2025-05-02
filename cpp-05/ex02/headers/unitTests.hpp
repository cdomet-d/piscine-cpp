/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:01:23 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:48:45 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

// test macro to compare expected exception against received exception
#define TEST_THROW(testObject, expected)                                       \
	try {                                                                      \
		testObject;                                                            \
		std::cout << BR "expected " #expected ", but program didn't throw" R   \
				  << std::endl;                                                \
	} catch (expected & e) {                                                   \
		std::cout << BG << e.what() << R << std::endl;                         \
	} catch (std::exception & e) {                                             \
		std::cout << BR "expected " #expected "" << ", got : " << e.what()     \
				  << R << std::endl;                                           \
	}

#endif
