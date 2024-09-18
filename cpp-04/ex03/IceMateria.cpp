/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceMateria.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:40:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 16:27:06 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IceMateria.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

IceMateria::IceMateria(void)
{
	std::cout << "IceMateria constructor called " << std::endl;
	this->type = "ice";
}

IceMateria::IceMateria(const IceMateria &copy) : AMateria(copy)
{
	std::cout << "IceMateria copy constructor called " << std::endl;
	*this = copy;
}

IceMateria::~IceMateria(void)
{
	std::cout << "IceMateria deconstructor called " << std::endl;
}

IceMateria &IceMateria::operator=(const IceMateria &comp)
{
	this->type = comp.type;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
IceMateria *IceMateria::clone() const
{
	return new IceMateria();
}

void IceMateria::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}