/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 17:39:20 by cdomet-d         ###   ########.fr       */
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
	std::cout << "Cat constructor called " << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called " << std::endl;
	 *this = copy;
}

Cat::~Cat(void)
{
	std::cout << "Cat deconstructor called " << std::endl;
}

Cat &Cat::operator=(const Cat &comp)
{
	this->type = comp.type;
	return *this;
}
	
/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Cat::makeSound(void) const 
{
	std::cout << "Mew" << std::endl;
}

