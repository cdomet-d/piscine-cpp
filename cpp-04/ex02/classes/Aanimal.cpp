/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:54 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 17:36:55 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Aanimal::Aanimal(void) : type("Aanimal")
{
	std::cout << "Aanimal constructor called " << std::endl;
}

Aanimal::Aanimal(std::string _type) : type(_type) {}

Aanimal::Aanimal(const Aanimal &rhs)
{
	std::cout << "Aanimal rhs constructor called " << std::endl;
	*this = rhs;
}

Aanimal::~Aanimal(void)
{
	std::cout << "Aanimal deconstructor called " << std::endl;
}

Aanimal &Aanimal::operator=(const Aanimal &rhs)
{
	type = rhs.type;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Aanimal::makeSound() const
{
	std::cout << "*generic animal noise*" << std::endl;
}

std::string Aanimal::getType(void) const
{
	return (this->type);
}