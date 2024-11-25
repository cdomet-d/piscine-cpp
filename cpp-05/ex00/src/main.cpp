/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/25 17:05:41 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

// #ifndef TEST_THROW
#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

#define TEST_THROW(testObject, expected)                                                      \
	try                                                                                       \
	{                                                                                         \
		testObject;                                                                           \
		std::cout << BR "expected " #expected ", but program didn't throw" R << std::endl;    \
	}                                                                                         \
	catch (expected & e)                                                                      \
	{                                                                                         \
		std::cout << BG << e.what() << R << std::endl;                                        \
	}                                                                                         \
	catch (std::exception & e)                                                                \
	{                                                                                         \
		std::cout << BR "expected " #expected "" << ", got : " << e.what() << R << std::endl; \
	}


// #endif

int main(void)
{
	{
		std::cout << std::endl
				  << BG
				  << "Valid Bureaucrats" << R << std::endl;

		Bureaucrat one("One", 1);
		Bureaucrat two("Two", 130);
		std::cout << "	" << one << std::endl;
		std::cout << "	" << two << std::endl;
		std::cout << "=> Demoting one" << std::endl;
		one.downgrade();
		std::cout << "	" << one << std::endl;
		std::cout << "=> Promoting Two" << std::endl;
		two.upgrade();
		std::cout << "	" << two << std::endl;
	}
	{
		std::cout << std::endl
				  << BG
				  << "Creating Invalid Bureaucrat (too low)" << R << std::endl;
		TEST_THROW(Bureaucrat drone("Invalid grade", 151), Bureaucrat::GradeTooLowException);
	}

	{
		std::cout << std::endl
				  << BG
				  << "Creating Invalid Bureaucrat (too high)" << R << std::endl;
		TEST_THROW(Bureaucrat drone("Invalid grade", -5), Bureaucrat::GradeTooHighException);
	}

	{
		std::cout << std::endl
				  << BG
				  << "Creating HighestGrade Bureaucrat" << R << std::endl;
		Bureaucrat drone("Higuest", 1);
		TEST_THROW(drone.upgrade(), Bureaucrat::GradeTooHighException);
	}

	{
		std::cout << std::endl
				  << BG
				  << "Creating LowestGrade Bureaucrat" << R << std::endl;
		Bureaucrat drone("Lowest", 150);
		TEST_THROW(drone.downgrade(), Bureaucrat::GradeTooLowException);
	}
}
