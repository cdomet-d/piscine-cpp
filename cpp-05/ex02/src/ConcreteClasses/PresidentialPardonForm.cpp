/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:18:04 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/20 16:33:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string _name, const std::string _target,
											 const short int _signGrade, const short _execGrade)
	: AForm(_name, _target, _signGrade, _execGrade) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) { }

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "default deconstructor called " << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &comp)
{
	AForm::operator=(comp);
	return *this;
}


/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
	
/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
	
/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */