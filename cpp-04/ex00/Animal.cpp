/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:54 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/27 11:30:15 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal default constructor called " << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << "Animal string constructor called " << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Animal copy constructor called " << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal deconstructor called " << std::endl;
}

Animal &Animal::operator=(const Animal &comp)
{
	type = comp.type;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Animal::makeSound() const
{
	std::cout << " * generic animal noise * " << std::endl;
}

std::string Animal::getType(void) const
{
	return type;
}