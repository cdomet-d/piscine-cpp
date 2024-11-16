/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:15:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/16 19:37:28 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : name("Unset"), grade(150)
{
	std::cout << "default 	constructor called " << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _name, short int _grade) : name(_name), grade(_grade)
{
	std::cout << "custom constructor called " << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName()), grade(copy.getGrade())
{
	std::cout << "copy constructor called " << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "default deconstructor called " << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &comp)
{
	grade = comp.grade;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                             OPERATOR OVERLOAD                              */
/* ************************************************************************** */

Bureaucrat &Bureaucrat::operator++(void)
{
	this->grade--;
	return *this;
}

Bureaucrat Bureaucrat::operator++(int n)
{
	(void)n;
	Bureaucrat old = *this;
	this->grade--;
	return old;
}

Bureaucrat &Bureaucrat::operator--(void)
{
	this->grade++;
	return *this;
}

Bureaucrat Bureaucrat::operator--(int n)
{
	(void)n;
	Bureaucrat old = *this;
	this->grade++;
	return old;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &print)
{
	os << print.getName() << ", bureaucrat grade: " << print.getGrade();
	return os;
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

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */
