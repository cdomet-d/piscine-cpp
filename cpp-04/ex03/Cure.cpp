/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:31:49 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 16:26:42 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure constructor called " << std::endl;
}

Cure::Cure(const Cure &rhs) : AMateria(rhs)
{
	std::cout << "Cure rhs constructor called " << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure deconstructor called " << std::endl;
}

Cure &Cure::operator=(const Cure &rhs)
{
	(void)rhs;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
Cure *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
