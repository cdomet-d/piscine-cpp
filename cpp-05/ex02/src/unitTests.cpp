/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:38:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/21 13:37:40 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void testPresidentialForms(void)
{
	try
	{
		std::cout << std::endl << "-----\n" << "Valid" << std::endl;
		Bureaucrat drone("President Myers", 4);
		PresidentialPardonForm pardon("NUSA Pardon Form For R. J. Linden", "Robert John Linden");
		drone.signForm(pardon);
		std::cout << pardon << std::endl;
		pardon.execute(drone);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "-----\n" << "Sign grade too low" << std::endl;
		Bureaucrat drone("V", 150);
		PresidentialPardonForm pardon("NUSA Pardon Form For R. J. Linden", "Robert John Linden");
		drone.signForm(pardon);
		std::cout << pardon << std::endl;
		pardon.execute(drone);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "-----\n" << "Exec grade too low" << std::endl;
		Bureaucrat drone("Solomon Reed", 10);
		PresidentialPardonForm pardon("NUSA Pardon Form For R. J. Linden", "Robert John Linden");
		drone.signForm(pardon);
		std::cout << pardon << std::endl;
		pardon.execute(drone);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "-----\n" << "Unsigned form" << std::endl;
		Bureaucrat drone("President Myers", 5);
		PresidentialPardonForm pardon("NUSA Pardon Form For R. J. Linden", "Robert John Linden");
		std::cout << pardon << std::endl;
		pardon.execute(drone);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testRobotomyRequestForm(void)
{
	try
	{
		std::cout << std::endl << "-----\n" << "Valid" << std::endl;
		Bureaucrat drone("Y. Arasaka", 1);
		RobotomyRequestForm request("Request for disposal of Adam Smasher", "A. Smasher");
		drone.signForm(request);
		std::cout << request << std::endl;
		request.execute(drone);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "-----\n" << "Sign grade too low" << std::endl;
		Bureaucrat drone("J. R. Linden", 150);
		RobotomyRequestForm request("Request for disposal of Adam Smasher ", "A. Smasher");
		drone.signForm(request);
		std::cout << request << std::endl;
		request.execute(drone);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "-----\n" << "Exec grade too low" << std::endl;
		Bureaucrat drone("R. Amendiares", 70);
		RobotomyRequestForm request("Request for disposal of Adam Smasher ", "A. Smasher");
		drone.signForm(request);
		std::cout << request << std::endl;
		request.execute(drone);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "-----\n" << "Unsigned form" << std::endl;
		Bureaucrat drone("Y. Arasaka", 1);
		RobotomyRequestForm request("Request for disposal of Adam Smasher ", "A. Smasher");
		std::cout << request << std::endl;
		request.execute(drone);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}