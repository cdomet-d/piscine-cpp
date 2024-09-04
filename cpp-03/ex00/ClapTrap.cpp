/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:47:26 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/04 14:19:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) {}

ClapTrap::ClapTrap(std::string _name)
{
	this->name = _name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << G << "ClapTrap  " << R << this->name << " has been created!"
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << G << "ClapTrap  " << R << copy.name << " has been copied!" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << G << "ClapTrap  " << R << this->name << " has been destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &comp)
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

unsigned int ClapTrap::getDamage(void)
{
	return this->attackDamage;
}

unsigned int ClapTrap::getEnergy(void)
{
	return this->energyPoints;
}

long int ClapTrap::getHealth(void)
{
	return this->hitPoints;
}

void ClapTrap::setDamage(unsigned int newDamage)
{
	this->attackDamage = newDamage;
	std::cout << G << "ClapTrap " << R << this->name << " now deals " << newDamage << " damage !"
			  << std::endl;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void ClapTrap::attack(const std::string &target)
{
	if (this->getEnergy() > 0 && this->getHealth() > 0)
	{
		this->energyPoints -= 1;
		std::cout << G << "ClapTrap " << R << this->name << " attacks " << target << ", dealing " << this->attackDamage << " damage!" << std::endl;
	}
	else
	{
		if (this->getHealth() <= 0)
			std::cout << G << "ClapTrap " << R << this->name << " is dead and can't attack" << std::endl;
		if (this->getEnergy() <= 0)
			std::cout << G << "ClapTrap " << R << this->name << " is exhausted and cannot attack anymore..." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHealth() > 0)
	{
		this->hitPoints -= amount;
		std::cout << G << "ClapTrap " << R << this->name << " takes " << amount << " damage!" << std::endl;
		if (this->getHealth() <= 0)
			std::cout << G << "ClapTrap " << R << this->name << " died!" << std::endl;
	}
	else
		std::cout << G << "ClapTrap " << R << this->name << " is already dead..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() > 0 && this->getHealth() < 10)
	{
		if ((this->getHealth() + amount) <= 10)
		{
			std::cout << G << "ClapTrap " << R << this->name << " heals itself by " << amount << " HP!" << std::endl;
			this->hitPoints += amount;
		}
		else
		{
			this->hitPoints = 10;
			std::cout << G << "ClapTrap " << R << this->name << " heals itself by " << amount - this->getHealth() << " HP!" << std::endl;
		}
		this->energyPoints -= 1;
	}
	else
	{
		if (this->getEnergy() <= 0)
			std::cout << G << "ClapTrap " << R << this->name << " is exhausted and cannot use Repair..." << std::endl;
		else if (this->getHealth() >= 10)
			std::cout << G << "ClapTrap " << R << this->name << " doesn't use repair, it's already at full health." << std::endl;
	}
}

void ClapTrap::displayStats(void)
{
	std::cout << std::setw(4) << std::left << "Name: " << std::setw(8) << this->name
			  << std::setw(4) << std::left << " HP: " << std::setw(8) << this->getHealth()
			  << std::setw(4) << std::left << " AP: " << std::setw(8) << this->getEnergy()
			  << std::setw(4) << std::left << " Damage: " << std::setw(8) << this->getDamage()
			  << std::endl;
}
