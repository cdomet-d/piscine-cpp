/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:54 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 18:01:38 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called " << std::endl;
	this->type = "WrongAnimal";
	
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called " << std::endl;
	 *this = copy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal deconstructor called " << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &comp)
{
	this->type = comp.type;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void WrongAnimal::makeSound() const
{
	std::cout << "*generic WrongAnimal noise*" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}