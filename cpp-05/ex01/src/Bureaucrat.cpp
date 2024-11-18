/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:15:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/18 14:46:47 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                  EXCEPTIONS                                */
/* ************************************************************************** */

const char *Bureaucrat::GradeTooHigh::what() const throw()
{
	return "\033[0;31m	/!\\ Invalid grade: too high (< 1)\033[0m";
}

const char *Bureaucrat::GradeTooLow::what() const throw()
{
	return "\033[0;31m	/!\\ Invalid grade: too low (> 150)\033[0m";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : name("Unset"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string _name, short int _grade) : name(_name), grade(_grade)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLow();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHigh();
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
		throw Bureaucrat::GradeTooLow();
	grade++;
}

void Bureaucrat::upgrade(void)
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHigh();
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
