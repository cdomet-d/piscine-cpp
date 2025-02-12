/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:54 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called " << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
	std::cout << "WrongAnimal constructor called " << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	*this = rhs;
	std::cout << "WrongAnimal rhs constructor called " << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal deconstructor called " << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	(void)rhs;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void WrongAnimal::makeSound() const
{
	std::cout << " * generic WrongAnimal noise * " << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return type;
}