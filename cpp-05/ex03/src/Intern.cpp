/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:32:53 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/26 13:04:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

/* ************************************************************************** */
/*                                  EXCEPTIONS                                */
/* ************************************************************************** */

const char *Intern::FormNotFoundException::what() const throw()
{
	return "/!\\ Form type not found. Expected <robotomy request>, \
<presidential request> or <shrubbery request>";
}
/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Intern::Intern(void)
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(const Intern &comp)
{
	(void)comp;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

static AForm *newPresidentialForm(std::string formName, std::string target)
{
	return new PresidentialPardonForm(formName, target);
}
static AForm *newRobotomyForm(std::string formName, std::string target)
{
	return new RobotomyRequestForm(formName, target);
}
static AForm *newShrubberyForm(std::string formName, std::string target)
{
	return new ShrubberyCreationForm(formName, target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	static const Intern::Entry lookupTable[3] = {
		{"robotomy request", &newRobotomyForm},
		{"presidential request", &newPresidentialForm},
		{"shrubbery request", &newShrubberyForm}};

	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(lookupTable[i].fName) == 0)
			return lookupTable[i].F(formName, target);
	}
	throw FormNotFoundException();
	return NULL;
}