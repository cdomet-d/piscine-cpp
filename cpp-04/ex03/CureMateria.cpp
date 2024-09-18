/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureMateria.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:31:49 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 13:51:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CureMateria.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

CureMateria::CureMateria(void)
{
	std::cout << "constructor called " << std::endl;
	this->type = "cure";
}

CureMateria::CureMateria(const CureMateria &copy) : AMateria(copy)
{
	std::cout << "copy constructor called " << std::endl;
	*this = copy;
}

CureMateria::~CureMateria(void)
{
	std::cout << "deconstructor called " << std::endl;
}

CureMateria &CureMateria::operator=(const CureMateria &comp) 
{
	this->type = comp.type;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
CureMateria* CureMateria::clone() const
{
	return new CureMateria();
}

void CureMateria::use(ICharacter& target)
{
	std::cout <<  "* heals " << target->getName() << " wounds *" << std::endl;
}
