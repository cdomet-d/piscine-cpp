/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:10:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 13:30:13 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

AMateria::AMateria(void)
{
	std::cout << "constructor called " << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
	std::cout << "copy constructor called " << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "deconstructor called " << std::endl;
}

AMateria &AMateria::operator=(const AMateria &comp)
{
	this->type = comp.type;
	return *this;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
std::string const &AMateria::getType() const {
	return this->type;
}
