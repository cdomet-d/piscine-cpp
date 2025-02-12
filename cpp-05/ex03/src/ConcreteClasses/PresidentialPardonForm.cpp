/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:18:04 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:25:02 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string _name, const std::string _target)
	: AForm(_name, _target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm(rhs) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	AForm::operator=(rhs);
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void PresidentialPardonForm::checkAuth(const short int expect, const short int got)
{
	if (!this->getSignedStatus())
	{
		std::cout << "Couldn't execute: " << this->getName() << " because: " << std::endl;
		return throw PresidentialPardonForm::FormNotSignedException();
	}
	if (got > expect)
	{
		std::cout << "Couldn't execute: Expected " << expect << " or higher, got: " << got << std::endl;
		return throw PresidentialPardonForm::GradeTooLowException();
	}
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	this->checkAuth(PRESIDENT_EXEC_GRADE, executor.getGrade());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
