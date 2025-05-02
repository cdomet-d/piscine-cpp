/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:38:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:48:09 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unitTests.hpp"

void testForms(void) {
	{
		std::cout << std::endl << BG << "Valid Forms" << R << std::endl;

		Form One("One", 5, 1);
		Form Two("Two", 140, 100);
		std::cout << One << std::endl;
		std::cout << Two << std::endl;
	}

	{
		std::cout << std::endl
				  << BG << "Creating Invalid Form (signGrade too low)" << R
				  << std::endl;
		TEST_THROW(Form("InvalidGrade", 151, 130), Form::GradeTooLowException);
	}

	{
		std::cout << std::endl
				  << BG << "Creating Invalid Form (signGrade too high)" << R
				  << std::endl;
		TEST_THROW(Form("InvalidGrade", 0, 130), Form::GradeTooHighException);
	}

	{
		std::cout << std::endl
				  << BG << "Creating Invalid Form (execGrade too low)" << R
				  << std::endl;
		TEST_THROW(Form("InvalidGrade", 140, 160), Form::GradeTooLowException);
	}

	{
		std::cout << std::endl
				  << BG << "Creating Invalid Form (execGrade too high)" << R
				  << std::endl;
		TEST_THROW(Form("InvalidGrade", 1, 0), Form::GradeTooHighException);
	}
}
void testFormSignature(void) {
	{
		std::cout << std::endl
				  << BG << "Valid Forms: Form::beSigned" << R << std::endl;
		Bureaucrat John("John", 10);
		Form form("Form A35b - 45", 10, 15);
		std::cout << "attempting to sign " << form << std::endl
				  << "with " << John << std::endl;
		form.beSigned(John);
		std::cout << form << std::endl;
	}

	{
		std::cout << std::endl
				  << BG << "Valid Forms: Bureaucrat::signForm" << R
				  << std::endl;
		Bureaucrat John("John", 10);
		Form form("Form A35b - 45", 10, 15);
		std::cout << "attempting to sign " << form << std::endl
				  << "with " << John << std::endl;
		John.signForm(form);
		std::cout << form << std::endl;
	}

	{
		std::cout << std::endl
				  << BG << "Invalid Forms: Bureaucrat::signForm" << R
				  << std::endl;

		Bureaucrat John("John", 25);
		Form form("Form A35b - 45", 10, 15);
		std::cout << "attempting to sign " << form << std::endl
				  << "with " << John << std::endl;
		John.signForm(form);
		std::cout
			<< std::endl
			<< BG
			<< "Bureaucrat::signForm doesn't throw himself, but it catches\
 the exception thrown by Form::beSigned"
			<< R << std::endl;
	}

	{
		std::cout << std::endl
				  << BG << "Invalid Forms: Bureaucrat::signForm" << R
				  << std::endl;

		Bureaucrat John("John", 25);
		Form form("Form A35b - 45", 10, 15);
		std::cout << "attempting to sign " << form << std::endl
				  << "with " << John << std::endl;
		TEST_THROW(form.beSigned(John), Form::GradeTooLowException);
	}
}

void testBureaucrats(void) {
	{
		std::cout << std::endl << BG << "Valid Bureaucrats" << R << std::endl;

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
				  << BG << "Creating Invalid Bureaucrat (too low)" << R
				  << std::endl;
		TEST_THROW(Bureaucrat drone("Invalid grade", 151),
				   Bureaucrat::GradeTooLowException);
	}

	{
		std::cout << std::endl
				  << BG << "Creating Invalid Bureaucrat (too high)" << R
				  << std::endl;
		TEST_THROW(Bureaucrat drone("Invalid grade", -5),
				   Bureaucrat::GradeTooHighException);
	}

	{
		std::cout << std::endl
				  << BG << "Creating HighestGrade Bureaucrat" << R << std::endl;
		Bureaucrat drone("Higuest", 1);
		TEST_THROW(drone.upgrade(), Bureaucrat::GradeTooHighException);
	}

	{
		std::cout << std::endl
				  << BG << "Creating LowestGrade Bureaucrat" << R << std::endl;
		Bureaucrat drone("Lowest", 150);
		TEST_THROW(drone.downgrade(), Bureaucrat::GradeTooLowException);
	}
}
