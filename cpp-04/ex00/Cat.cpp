/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/26 17:14:47 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called " << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called " << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat deconstructor called " << std::endl;
}

Cat &Cat::operator=(const Cat &comp)
{
	(void)comp;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Cat::makeSound(void) const
{
	std::cout << "Mew" << std::endl;
}
