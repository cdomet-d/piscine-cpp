/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:47:26 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/02 17:52:23 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

clapTrap::clapTrap(void) {}

clapTrap::clapTrap(std::string _name)
{
	this->name = _name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "clapTrap " << this->name << " has been created!" << std::endl
			  << std::endl;
}

clapTrap::clapTrap(const clapTrap &copy)
{
	std::cout << "clapTrap " << copy.name << " has been copied!" << std::endl
			  << std::endl;
	clapTrap(copy.name);
}

clapTrap::~clapTrap(void)
{
	std::cout << std::endl
			  << "clapTrap " << this->name << " has been destroyed!" << std::endl;
}

clapTrap &clapTrap::operator=(const clapTrap &comp)
{
	this->name = comp.name;
	this->hitPoints = comp.hitPoints;
	this->energyPoints = comp.energyPoints;
	this->attackDamage = comp.attackDamage;
	return *this;
}

/* ************************************************************************** */
/*                               ACCESSORS                                    */
/* ************************************************************************** */
unsigned int clapTrap::getDamage(void)
{
	return this->attackDamage;
}

unsigned int clapTrap::getEnergy(void)
{
	return this->energyPoints;
}

long int clapTrap::getHealth(void)
{
	return this->hitPoints;
}

void clapTrap::setDamage(unsigned int newDamage)
{
	this->attackDamage = newDamage;
	std::cout << std::endl
			  << "clapTrap " << this->name << " now deals " << newDamage << " damage !" << std::endl
			  << std::endl;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void clapTrap::attack(const std::string &target)
{
	if (this->getEnergy() > 0 && this->getHealth() > 0)
	{
		this->energyPoints -= 1;
		std::cout << this->name << " attacks " << target << ", dealing " << this->attackDamage << " damage!" << std::endl;
	}
	else
	{
		if (this->getHealth() <= 0)
			std::cout << this->name << " is dead and can't attack" << std::endl;
		if (this->getEnergy() <= 0)
			std::cout << this->name << " is exhausted and cannot attack anymore..." << std::endl;
	}
}

void clapTrap::takeDamage(unsigned int amount)
{
	if (this->getHealth() > 0)
	{
		this->hitPoints -= amount;
		std::cout << this->name << " takes " << amount << " damage!" << std::endl;
	}
	else
		std::cout << this->name << " is already dead..." << std::endl;
	if (this->getHealth() <= 0)
		std::cout << this->name << " died!" << std::endl;
}

void clapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() > 0 && this->getHealth() <= 10)
	{
		this->energyPoints -= 1;
		if ((this->getHealth() + amount) <= 10)
		{
			std::cout << this->name << " heals itself by " << amount << " HP!" << std::endl;
			this->hitPoints += amount;
		}
		else
		{
			std::cout << this->name << " heals itself by " << amount- this->getHealth() << " HP!" << std::endl;
			this->hitPoints = 10;
		}
	}
	else
	{
		if (this->getEnergy() <= 0)
			std::cout << this->name << " is exhausted and cannot use Repair..." << std::endl;
		else if (this->getHealth() >= 10)
			std::cout << this->name << " is already at full health..." << std::endl;
	}
}

void clapTrap::displayStats(void)
{
	std::cout << std::setw(4) << std::left << "Name: " << std::setw(8) << this->name
			  << std::setw(4) << std::left << " HP: " << std::setw(8) << this->getHealth()
			  << std::setw(4) << std::left << " AP: " << std::setw(8) << this->getEnergy()
			  << std::endl;
}
