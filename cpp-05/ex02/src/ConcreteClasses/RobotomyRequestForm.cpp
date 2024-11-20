/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:13 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/20 16:33:31 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string _name, const std::string _target,
											 const short int _signGrade, const short _execGrade)
	: AForm(_name, _target, _signGrade, _execGrade) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) { }

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "default deconstructor called " << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &comp)
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