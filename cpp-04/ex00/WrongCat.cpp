/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/10 18:05:41 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called " << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called " << std::endl;
	 *this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat deconstructor called " << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &comp)
{
	this->type = comp.type;
	return *this;
}
	
/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void WrongCat::makeSound(void) const 
{
	std::cout << "Mew" << std::endl;
}

