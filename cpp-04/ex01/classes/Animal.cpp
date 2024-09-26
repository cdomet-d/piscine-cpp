/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:54 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/26 12:40:29 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructor called " << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout << "Animal constructor called " << std::endl;
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
	(void)comp;
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