/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:19 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/26 17:23:04 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Cat::Cat(void) : Animal("Cat"), brain(new Brain)
{
	std::cout << "Cat constructor called " << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->brain = new Brain;
	*this = copy;
	std::cout << "Cat copy constructor called " << std::endl;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat deconstructor called " << std::endl;
}

Cat &Cat::operator=(const Cat &comp)
{
	*this->brain = *comp.brain;
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
