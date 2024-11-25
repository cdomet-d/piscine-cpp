/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:13 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/25 10:33:02 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {}

// RobotomyRequestForm: Required grades: sign 72, exec 45
RobotomyRequestForm::RobotomyRequestForm(const std::string _name, const std::string _target)
	: AForm(_name, _target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &comp)
{
	AForm::operator=(comp);
	return *this;
}
/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

bool RobotomyRequestForm::halfChance(void)
{
	time_t seed = time(NULL);
	return seed % 2;
}

void RobotomyRequestForm::checkAuth(const short int expect, const short int got)
{
	if (!this->getSignedStatus())
		return throw RobotomyRequestForm::FormNotSignedException();
	if (got > expect)
	{
		std::cout << "Couldn't execute RobotomyForm: expected grade "
				  << expect << " or higher, got: " << got << std::endl;
		return throw RobotomyRequestForm::GradeTooLowException();
	}
}

// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed
void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	this->checkAuth(ROBOTOMY_EXEC_GRADE, executor.getGrade());
	if (this->halfChance())
	{
		std::cout << "** UNBEARABLY LOUD DRILLING NOISES **" << std::endl
				  << "** CONTINUED METAL ON METAL SCREECHING **" << std::endl
				  << this->getTarget() << " has been robotomized!" << std::endl;
		return;
	}
	std::cout << "Robotomy on " << this->getTarget() << " unfortunately failed; better luck next time! "
			  << std::endl;
}
/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */