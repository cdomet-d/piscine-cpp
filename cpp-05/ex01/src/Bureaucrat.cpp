/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:15:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 13:02:28 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                  EXCEPTIONS                                */
/* ************************************************************************** */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[0;31m	/!\\ Bureaucrat: Invalid grade: too high (< 1)\033[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[0;31m	/!\\ Bureaucrat: Invalid grade: too low (> 150)\033[0m";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : name("Unset"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string _name, short int _grade) : name(_name), grade(_grade)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName()), grade(copy.getGrade()) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &comp)
{
	grade = comp.grade;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Bureaucrat::downgrade(void)
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::upgrade(void)
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
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