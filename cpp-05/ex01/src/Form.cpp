/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:38:22 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 13:02:28 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                  EXCEPTIONS                                */
/* ************************************************************************** */

const char *Form::GradeTooHighException::what() const throw()
{
	return "\033[0;31m	/!\\ Form: Invalid grade: too high (< 1)\033[0m";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "\033[0;31m	/!\\ Form: Invalid grade: too low (> 150)\033[0m";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Form::Form(void) : name("Unset"), signGrade(1), execGrade(1), isSigned(false) {}

Form::Form(const std::string _name, const short int _signGrade, const short _execGrade)
	: name(_name), signGrade(_signGrade), execGrade(_execGrade), isSigned(false)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), signGrade(copy.signGrade), execGrade(copy.execGrade)
{
	*this = copy;
}

Form::~Form(void) {}

Form &Form::operator=(const Form &comp)
{
	isSigned = comp.isSigned;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Form::beSigned(const Bureaucrat signer)
{
	if (signer.getGrade() > signGrade)
		return throw Form::GradeTooLowException();
	isSigned = true;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
const std::string Form::getName(void) const
{
	return name;
}
short int Form::getSignGrade(void) const
{
	return signGrade;
}
short int Form::getExecGrade(void) const
{
	return execGrade;
}
bool Form::getSignedStatus(void) const
{
	return isSigned;
}
/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &os, const Form &print)
{
	os << "	Form name:		" << print.getName() << std::endl
	   << "	Required Grade to sign:	" << print.getSignGrade() << std::endl
	   << "	Required Grade to exec:	" << print.getExecGrade() << std::endl
	   << "	Required signed status:	" << print.getSignedStatus() << std::endl;
	return os;
}
