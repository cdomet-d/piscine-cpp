/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:10:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/20 16:19:56 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

AMateria::AMateria(void)
{
	// std::cout << "Cure constructor called " << std::endl;
}

AMateria::AMateria(std::string const &_type)
{
	// std::cout << "Cure string constructor called " << std::endl;
	this->type = _type;
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
	// std::cout << "Cure copy constructor called " << std::endl;
}

AMateria::~AMateria(void)
{
	// std::cout << "Cure deconstructor called " << std::endl;
}

AMateria &AMateria::operator=(const AMateria &comp)
{
	this->type = comp.type;
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
