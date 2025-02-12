/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAform.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:38:22 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 17:01:18 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                  EXCEPTIONS                                */
/* ************************************************************************** */

const char *AForm::GradeTooHighException::what() const throw()
{
	return "/!\\ AForm: Invalid grade: too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "/!\\ AForm: Invalid grade: too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "/!\\ AForm: Form has not been signed by competent authorities";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

AForm::AForm(void) : name("Unset"), target("Unset"), signGrade(1), execGrade(1), isSigned(false) {}

AForm::AForm(const std::string _name, const std::string _target, const short int _signGrade, const short _execGrade)
	: name(_name), target(_target), signGrade(_signGrade), execGrade(_execGrade), isSigned(false)
{
	if (_signGrade < 1 || _execGrade < 1)
	{
		std::cout << "	expected [1 - 150]; got "
				  << (_signGrade < 1 ? _signGrade : _execGrade) << std::endl;
		throw AForm::GradeTooHighException();
	}
	else if (_signGrade > 150 || _execGrade > 150)
	{
		std::cout << "	expected [1 - 150]; got "
				  << (_signGrade > 150 ? _signGrade : _execGrade) << std::endl;
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm &rhs) : name(rhs.name), signGrade(rhs.signGrade),
								  execGrade(rhs.execGrade)
{
	*this = rhs;
}

AForm::~AForm(void) {}

AForm &AForm::operator=(const AForm &rhs)
{
	isSigned = rhs.isSigned;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void AForm::beSigned(const Bureaucrat signer)
{
	if (signer.getGrade() > signGrade)
		return throw AForm::GradeTooLowException();
	isSigned = true;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
const std::string AForm::getName(void) const
{
	return name;
}

const std::string AForm::getTarget(void) const
{
	return target;
}

short int AForm::getSignGrade(void) const
{
	return signGrade;
}

short int AForm::getExecGrade(void) const
{
	return execGrade;
}

bool AForm::getSignedStatus(void) const
{
	return isSigned;
}

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &os, const AForm &print)
{
	os << "[" << print.getName() << "] "
	   << (print.getSignedStatus() ? "[Signed] " : "[Not signed] ") << "[Signing req "
	   << print.getSignGrade() << "] [Exec req " << print.getExecGrade() << "] ";
	return os;
}
