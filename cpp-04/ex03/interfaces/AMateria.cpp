/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:10:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/27 11:20:51 by cdomet-d         ###   ########lyon.fr   */
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

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
	std::cout << "AMateria copy constructor called " << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria deconstructor called " << std::endl;
}

AMateria &AMateria::operator=(const AMateria &comp)
{
	type = comp.type;
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
