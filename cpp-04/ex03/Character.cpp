/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:35:02 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 15:23:35 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Character::Character(void)
{
	std::cout << "constructor called " << std::endl;
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(const Character &copy) : Character(copy)
{
	std::cout << "copy constructor called " << std::endl;
	*this = copy;
}

Character::~Character(void)
{
	std::cout << "deconstructor called " << std::endl;
}

Character &Character::operator=(const Character &comp)
{
	this->name = comp.name;
	delete this->inventory[0];
	delete this->inventory[1];
	delete this->inventory[2];
	delete this->inventory[3];
	this->inventory[0] = comp.inventory[0]->clone();
	this->inventory[1] = comp.inventory[1]->clone();
	this->inventory[2] = comp.inventory[2]->clone();
	this->inventory[3] = comp.inventory[3]->clone();
	return *this;	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Character::equip(AMateria* m)
{
	
}

void Character::unequip(int idx)
{
	
}

void Character::use(int idx, ICharacter& target)
{
	this->inventory[idx]->use(target);
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
	
/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */