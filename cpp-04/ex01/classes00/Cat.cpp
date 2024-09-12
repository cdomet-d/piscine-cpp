/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/12 15:59:59 by cdomet-d         ###   ########lyon.fr   */
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
	this->brain = new Brain;
	std::cout << "Cat constructor called " << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
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
	for (size_t i = 0; i < 100; i++)
		this->brain[i] = comp.brain[i];
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
