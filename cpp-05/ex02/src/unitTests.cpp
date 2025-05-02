/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:38:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:49:26 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unitTests.hpp"

void testPresidentialForms(void) {
	{
		Bureaucrat drone("Roselyn Myers", 1);
		PresidentialPardonForm pardon("Robert R. Linden");

		std::cout << std::endl
				  << BG << "Valid" << R << std::endl
				  << "Using: " << pardon << "and\n"
				  << drone << std::endl;
		drone.signForm(pardon);
		pardon.execute(drone);
	}
	{
		Bureaucrat drone("Roselyn Myers", 150);
		PresidentialPardonForm pardon("Robert R. Linden");

		std::cout << BG << std::endl
				  << "Expecting sign GradeTooLowException with " << drone << R
				  << std::endl
				  << "Using: " << pardon << "and\n"
				  << drone << std::endl;
		TEST_THROW(pardon.beSigned(drone), AForm::GradeTooLowException);
	}

	{
		Bureaucrat drone("Roselyn Myers", 10);
		PresidentialPardonForm pardon("Robert R. Linden");

		std::cout << BG << std::endl
				  << "Expecting exec GradeTooLowException with " << drone << R
				  << std::endl
				  << "Using: " << pardon << "and\n"
				  << drone << std::endl;
		drone.signForm(pardon);
		TEST_THROW(pardon.execute(drone), AForm::GradeTooLowException);
	}

	{
		Bureaucrat drone("Roselyn Myers", 5);
		PresidentialPardonForm pardon("Robert R. Linden");

		std::cout << BG << std::endl
				  << "Expecting FormNotSignedException " << R << std::endl
				  << "Using: " << pardon << "and\n"
				  << drone << std::endl;
		TEST_THROW(pardon.execute(drone), AForm::FormNotSignedException);
	}
}

void testRobotomyRequestForm(void) {
	{
		Bureaucrat drone("Saka Drone", 1);
		RobotomyRequestForm robotomy("Adam Smasher");

		std::cout << std::endl
				  << BG << "Valid" << R << std::endl
				  << "Using: " << robotomy << "and\n"
				  << drone << std::endl;
		drone.signForm(robotomy);
		robotomy.execute(drone);
	}
	{
		Bureaucrat drone("Saka Drone", 150);
		RobotomyRequestForm robotomy("Adam Smasher");

		std::cout << BG << std::endl
				  << "Expecting sign GradeTooLowException" << R << std::endl
				  << "Using: " << robotomy << "and\n"
				  << drone << std::endl;

		TEST_THROW(robotomy.beSigned(drone), AForm::GradeTooLowException);
	}

	{
		Bureaucrat drone("Saka Drone", 70);
		RobotomyRequestForm robotomy("Adam Smasher");

		std::cout << BG << std::endl
				  << "Expecting exec GradeTooLowException with " << drone << R
				  << std::endl
				  << "Using: " << robotomy << "and\n"
				  << drone << std::endl;
		drone.signForm(robotomy);
		TEST_THROW(robotomy.execute(drone), AForm::GradeTooLowException);
	}

	{
		Bureaucrat drone("Saka Drone", 5);
		RobotomyRequestForm robotomy("Adam Smasher");

		std::cout << BG << std::endl
				  << "Expecting FormNotSignedException " << R << std::endl
				  << "Using: " << robotomy << "and\n"
				  << drone << std::endl;
		TEST_THROW(robotomy.execute(drone), AForm::FormNotSignedException);
	}
}

void testShrubberyForm(void) {

	{
		Bureaucrat drone("Bisoutruffe", 1);
		ShrubberyCreationForm trees("home");

		std::cout << std::endl
				  << BG << "Valid" << R << std::endl
				  << "Using: " << trees << "and\n"
				  << drone << std::endl;
		drone.signForm(trees);
		trees.execute(drone);
	}
	{
		Bureaucrat drone("Bisoutruffe", 150);
		ShrubberyCreationForm trees("home");

		std::cout << BG << std::endl
				  << "Expecting sign GradeTooLowException" R << std::endl
				  << "Using: " << trees << "and\n"
				  << drone << std::endl;
		TEST_THROW(trees.beSigned(drone), AForm::GradeTooLowException);
	}

	{
		Bureaucrat drone("Bisoutruffe", 140);
		ShrubberyCreationForm trees("home");

		std::cout << BG << std::endl
				  << "Expecting exec GradeTooLowException" << R << std::endl
				  << "Using: " << trees << "and\n"
				  << drone << std::endl;
		drone.signForm(trees);
		TEST_THROW(trees.execute(drone), AForm::GradeTooLowException);
	}

	{
		Bureaucrat drone("Bisoutruffe", 5);
		ShrubberyCreationForm trees("home");

		std::cout << BG << std::endl
				  << "Expecting FormNotSignedException " << R << std::endl
				  << "Using: " << trees << "and\n"
				  << drone << std::endl;
		TEST_THROW(trees.execute(drone), AForm::FormNotSignedException);
	}
}