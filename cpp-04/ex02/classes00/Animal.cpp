/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:54 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 17:36:55 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Animal::Animal(void)
{
	std::cout << "Animal constructor called " << std::endl;
	this->type = "Animal";
	
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called " << std::endl;
	 *this = copy;
}

Animal::~Animal(void)
{
	std::cout << "Animal deconstructor called " << std::endl;
}

Animal &Animal::operator=(const Animal &comp)
{
	this->type = comp.type;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Animal::makeSound() const
{
	std::cout << "*generic animal noise*" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}