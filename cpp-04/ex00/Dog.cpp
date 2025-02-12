/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:23:19 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Dog::Dog(void) : Animal("Dog") 
{
	std::cout << "Dog constructor called " << std::endl;
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	std::cout << "Dog rhs constructor called " << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog deconstructor called " << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	(void)rhs;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Dog::makeSound(void) const
{
	std::cout << "Waf" << std::endl;
}