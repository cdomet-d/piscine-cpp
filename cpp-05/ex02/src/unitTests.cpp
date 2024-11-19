/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:38:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 17:05:39 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

void testBureaucrats(void)
{
	std::cout << "------" << std::endl;
	try
	{
		std::cout << "=> Creating Valid Bureaucrats" << std::endl;
		Bureaucrat One("One", 5);
		Bureaucrat Two("Two", 130);
		std::cout << "	" << One << std::endl;
		std::cout << "	" << Two << std::endl;
		std::cout << "=> Promoting Two" << std::endl;
		Two.upgrade();
		std::cout << "	" << Two << std::endl;
		std::cout << "=> Demoting One" << std::endl;
		One.downgrade();
		std::cout << "	" << One << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid Bureaucrat (too low)" << std::endl;
		Bureaucrat InvalidGrade("InvalidGrade", 151);
		std::cout << "	" << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid Bureaucrat (too high)" << std::endl;
		Bureaucrat InvalidGrade("InvalidGrade", -5);
		std::cout << "	" << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating HighestGrade Bureaucrat" << std::endl;
		Bureaucrat HighestGrade("HighestGrade", 1);
		std::cout << "	" << HighestGrade << std::endl;
		std::cout << "=> Promoting HighestGrade" << std::endl;
		HighestGrade.upgrade();
		std::cout << "	" << HighestGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating LowestGrade Bureaucrat" << std::endl;
		Bureaucrat LowestGrade("LowestGrade", 150);
		std::cout << "	" << LowestGrade << std::endl;
		std::cout << "=> Demoting LowestGrade" << std::endl;
		LowestGrade.downgrade();
		std::cout << "	" << LowestGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating LowestGrade Bureaucrat" << std::endl;
		Bureaucrat LowestGrade("LowestGrade", 150);
		std::cout << "	" << LowestGrade << std::endl;
		std::cout << "=> Promoting LowestGrade" << std::endl;
		LowestGrade.upgrade();
		std::cout << "	" << LowestGrade << std::endl;
		std::cout << "=> Creating HighestGrade Bureaucrat" << std::endl;
		Bureaucrat HighestGrade("HighestGrade", 1);
		std::cout << "	" << HighestGrade << std::endl;
		std::cout << "=> Demoting HighestGrade" << std::endl;
		HighestGrade.downgrade();
		std::cout << "	" << HighestGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------" << std::endl;
}

void testForms(void)
{
	std::cout << "------" << std::endl;
	try
	{
		std::cout << "=> Creating Valid Forms" << std::endl;
		AForm One("One", 5, 1);
		AForm Two("Two", 140, 100);
		std::cout << One << std::endl;
		std::cout << Two << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid AForm (signGrade too low)" << std::endl;
		AForm InvalidGrade("InvalidGrade", 151, 130);
		std::cout << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid AForm (signGrade too high)" << std::endl;
		AForm InvalidGrade("InvalidGrade", -5, -150);
		std::cout << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid AForm (execGrade too low)" << std::endl;
		AForm InvalidGrade("InvalidGrade", 140, 160);
		std::cout << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid AForm (execGrade too high)" << std::endl;
		AForm InvalidGrade("InvalidGrade", 1, -5);
		std::cout << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------" << std::endl;
}
void testFormSignature(void)
{
	std::cout << std::endl
			  << "Trying AForm::beSigned()..." << std::endl;

	try
	{
		AForm one("A form", 10, 15);
		AForm two("Another form", 10, 15);
		Bureaucrat John("John", 5);
		Bureaucrat Jack("John", 50);

		one.beSigned(John);
		std::cout << one << std::endl;
		two.beSigned(Jack);
		std::cout << two << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "Trying Bureaucrat.signForm()..." << std::endl;
	try
	{
		AForm one("A form", 10, 15);
		AForm two("Another form", 10, 15);
		Bureaucrat John("John", 5);
		Bureaucrat Jack("John", 50);

		John.signForm(one);
		std::cout << one << std::endl;
		Jack.signForm(two);
		std::cout << two << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}