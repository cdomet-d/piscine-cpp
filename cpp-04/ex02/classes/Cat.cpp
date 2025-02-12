/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:19 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Cat::Cat(void) : Aanimal("Cat"), brain(new Brain)
{
	std::cout << "Cat constructor called " << std::endl;
}

Cat::Cat(const Cat &rhs) : Aanimal(rhs)
{
	this->brain = new Brain;
	*this = rhs;
	std::cout << "Cat rhs constructor called " << std::endl;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat deconstructor called " << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	*this->brain = *rhs.brain;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Cat::makeSound(void) const
{
	std::cout << "Mew" << std::endl;
}

void Cat::fillPetArr(std::string s) const
{
	this->brain->fillArr(s);
}

void Cat::displayThoughts(void) const 
{
	std::cout << "Brain pointer adress | " << this->brain << std::endl;
	this->brain->displayArr();
}
