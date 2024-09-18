/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:35:02 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 16:41:17 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Character::Character(void)
{
	std::cout << "Character constructor called" << std::endl;
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(std::string _name)
{
	this->name = _name;
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
}

Character::~Character(void)
{
	delete this->inventory[0];
	delete this->inventory[1];
	delete this->inventory[2];
	delete this->inventory[3];
	std::cout << "Character deconstructor called" << std::endl;
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
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return;
		}
	}
	std::cerr << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx] = NULL;
	std::cerr << "No Materia equiped at this slot" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if ((idx >= 0 && idx < 4) && this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cerr << "No Materia equiped at this slot in " << this->getName () << std::endl;
}

void Character::displayInventory(void)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			std::cout << "[ " << i << " ] " << this->inventory[i]->getType() << std::endl;
	}
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
std::string const &Character::getName() const
{
	return this->name;
}
