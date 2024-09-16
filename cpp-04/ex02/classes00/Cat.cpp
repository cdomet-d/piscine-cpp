/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:19 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/16 17:51:30 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Cat::Cat(void)
{
	this->type = "Cat";
	brain = new Brain;
	std::cout << "Cat constructor called " << std::endl;
}

Cat::Cat(const Cat &copy) : Aanimal(copy)
{
	this->brain = new Brain();
	*this = copy;
	std::cout << "Cat copy constructor called " << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat deconstructor called " << std::endl;
}

Cat &Cat::operator=(const Cat &comp)
{
	this->type = comp.type;
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
