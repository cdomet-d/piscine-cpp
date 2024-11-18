/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/18 14:01:40 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
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
	return 0;
}
