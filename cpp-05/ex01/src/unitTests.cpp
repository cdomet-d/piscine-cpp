/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:38:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 11:45:41 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testBureaucrats(void)
{
	std::cout << "------" << std::endl;
	try
	{
		std::cout << "=> Creating Valid Bureaucrats" << std::endl;
		Bureaucrat One = Bureaucrat("One", 5);
		Bureaucrat Two = Bureaucrat("Two", 130);
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
		Bureaucrat InvalidGrade = Bureaucrat("InvalidGrade", 151);
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
		Bureaucrat InvalidGrade = Bureaucrat("InvalidGrade", -5);
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
		Bureaucrat HighestGrade = Bureaucrat("HighestGrade", 1);
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
		Bureaucrat LowestGrade = Bureaucrat("LowestGrade", 150);
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
		Bureaucrat LowestGrade = Bureaucrat("LowestGrade", 150);
		std::cout << "	" << LowestGrade << std::endl;
		std::cout << "=> Promoting LowestGrade" << std::endl;
		LowestGrade.upgrade();
		std::cout << "	" << LowestGrade << std::endl;
		std::cout << "=> Creating HighestGrade Bureaucrat" << std::endl;
		Bureaucrat HighestGrade = Bureaucrat("HighestGrade", 1);
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
		Form One = Form("One", 5, 1);
		Form Two = Form("Two", 140, 100);
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
		std::cout << "=> Creating Invalid Form (signGrade too low)" << std::endl;
		Form InvalidGrade = Form("InvalidGrade", 151, 130);
		std::cout << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid Form (signGrade too high)" << std::endl;
		Form InvalidGrade = Form("InvalidGrade", -5, 1);
		std::cout << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid Form (execGrade too low)" << std::endl;
		Form InvalidGrade = Form("InvalidGrade", 140, 160);
		std::cout << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		std::cout << "=> Creating Invalid Form (execGrade too high)" << std::endl;
		Form InvalidGrade = Form("InvalidGrade", 1, -5);
		std::cout << InvalidGrade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------" << std::endl;
}