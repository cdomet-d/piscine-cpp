/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:52:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 14:27:58 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ICharacter::ICharacter(void)
{
	std::cout << "constructor called " << std::endl;
}

ICharacter::ICharacter(const ICharacter &copy)
{
	std::cout << "copy constructor called " << std::endl;
	*this = copy;
}

ICharacter::~ICharacter(void)
{
	std::cout << "deconstructor called " << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &comp)
{
	this->name = comp.name;
	this->inventory[0] = comp.inventory[0]->clone();
	this->inventory[1] = comp.inventory[1]->clone();
	this->inventory[2] = comp.inventory[2]->clone();
	this->inventory[3] = comp.inventory[3]->clone();
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
	
/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
