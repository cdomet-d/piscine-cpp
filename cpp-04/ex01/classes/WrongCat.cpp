/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called " << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal(rhs)
{
	std::cout << "WrongCat rhs constructor called " << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat deconstructor called " << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	(void)rhs;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void WrongCat::makeSound(void) const
{
	std::cout << "WrongMew" << std::endl;
}
