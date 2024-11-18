/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:38:22 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/18 15:40:03 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                  EXCEPTIONS                                */
/* ************************************************************************** */

const char *Form::GradeTooHigh::what() const throw()
{
	return "\033[0;31m	/!\\ Invalid grade: too high (< 1)\033[0m";
}

const char *Form::GradeTooLow::what() const throw()
{
	return "\033[0;31m	/!\\ Invalid grade: too low (> 150)\033[0m";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Form::Form(void) : name("Unset"), isSigned(false), signGrade(1), execGrade(1) {}

Form::Form(const std::string _name, const short int _signGrade, const short _execGrade) \
: name(_name), isSigned(false), signGrade(_signGrade), execGrade(_execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHigh();
	else if (_execGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLow();
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

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
const std::string Form::getName(void) const
{
	return name;
}
const short int Form::getSignGrade(void) const
{
	return signGrade;
}
const short int Form::getExecGrade(void) const
{
	return execGrade;
}
const bool Form::getSignedStatus(void) const
{
	return isSigned;
}
/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */

std::ostream &operator<<(std::ofstream &os, const Form &print) 
{
	std::cout << "Form name:	" << print.getName() << std::endl
		<< "Required Grade to sign:	" << print.getSignGrade() << std::endl
		<< "Required Grade to exec:	" << print.getExecGrade() << std::endl
		<< "Required signed status:	" << print.getSignedStatus() << std::endl;
}
