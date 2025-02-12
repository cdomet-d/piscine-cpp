/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:10:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

AMateria::AMateria(void) : type("UNDEFINED")
{
	std::cout << "AMateria constructor called " << std::endl;
}

AMateria::AMateria(std::string const &_type) : type(_type)
{
	std::cout << "AMateria string constructor called " << std::endl;
}

AMateria::AMateria(const AMateria &rhs)
{
	*this = rhs;
	std::cout << "AMateria rhs constructor called " << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria deconstructor called " << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	type = rhs.type;
	return *this;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	return;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
std::string const &AMateria::getType() const
{
	return this->type;
}
