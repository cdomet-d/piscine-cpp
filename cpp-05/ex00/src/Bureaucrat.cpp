/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:15:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:23:53 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                  EXCEPTIONS                                */
/* ************************************************************************** */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "	/!\\ Invalid grade: too high (< 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "	/!\\ Invalid grade: too low (> 150)";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : name("Unset"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string _name, short int _grade) : name(_name),
																	grade(_grade)
{
	if (_grade > 150)
	{
		std::cout << "	expected [1 - 150], got " << _grade << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (_grade < 1)
	{
		std::cout << "	expected [1 - 150], got " << _grade << std::endl;
		throw Bureaucrat::GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name(rhs.getName()), grade(rhs.getGrade()) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	grade = rhs.grade;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Bureaucrat::downgrade(void)
{
	if (grade >= 150)
	{
		std::cout << "	Bureaucrat is already at lowest grade" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	grade++;
}

void Bureaucrat::upgrade(void)
{
	if (grade <= 1)
	{
		std::cout << "	Bureaucrat is already at highest grade" << std::endl;
		throw Bureaucrat::GradeTooHighException();
	}
	grade--;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
const std::string Bureaucrat::getName(void) const
{
	return name;
}

short int Bureaucrat::getGrade(void) const
{
	return grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &print)
{
	os << print.getName() << ", bureaucrat grade: " << print.getGrade();
	return os;
}
