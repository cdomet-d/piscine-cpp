/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:40:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 16:27:06 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Ice::Ice(void) : AMateria("Ice")
{
	std::cout << "Ice constructor called " << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice &rhs) : AMateria(rhs)
{
	std::cout << "Ice rhs constructor called " << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice deconstructor called " << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
	(void)rhs;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
Ice *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}