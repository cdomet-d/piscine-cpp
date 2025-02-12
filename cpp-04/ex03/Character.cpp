/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:35:02 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
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

Character::Character(const Character &rhs) : ICharacter(rhs)
{
	*this = rhs;
	std::cout << "Character rhs constructor called" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	std::cout << "Character deconstructor called" << std::endl;
}

Character &Character::operator=(const Character &rhs)
{
	this->name = rhs.name;
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	for (int i = 0; i < 4; i++)
	{
		if (rhs.inventory[i])
			this->inventory[i] = rhs.inventory[i]->clone();
		else 
			this->inventory[i] = NULL;
			
	}
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
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	std::cout << "Charater.unequip(): " << this->getName() << std::endl;
	if (idx >= 0 && idx < 4 && this->inventory[idx])
	{
		this->inventory[idx] = NULL;
		return;
	}
	std::cout << "No Materia equiped at slot "<< idx << " for Character: " << this->getName() << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Charater.use(): " << this->getName() << std::endl;
	if ((idx >= 0 && idx < 4) && this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << "No Materia equiped at slot "<< idx << " for Character: " << this->getName() << std::endl;
}

void Character::displayInventory(void)
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Charater.displayInventory(): " << this->getName() << std::endl;
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
