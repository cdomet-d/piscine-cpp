/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:52:54 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
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

Animal::Animal(const Animal &rhs)
{
	*this = rhs;
	std::cout << "Animal rhs constructor called " << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal deconstructor called " << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	type = rhs.type;
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