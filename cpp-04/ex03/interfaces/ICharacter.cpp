/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:08:36 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/19 18:07:15 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ICharacter::ICharacter(void)
{
	// std::cout << "ICharacter constructor called " << std::endl;
}

ICharacter::ICharacter(const ICharacter &copy)
{
	// std::cout << "ICharacter copy constructor called " << std::endl;
	*this = copy;
}

ICharacter::~ICharacter(void)
{
	// std::cout << "ICharacter deconstructor called " << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &comp)
{
	(void)comp;
	return *this;
}
