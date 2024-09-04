/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:47:26 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/04 14:34:29 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ClapTrap::ClapTrap(void)
{
	this->maxHitPoint = 10;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string _name)
{
	this->maxHitPoint = 10;
	this->name = _name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << G << "ClapTrap " << R << this->name << " has been created!"
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << G << "ClapTrap " << R << copy.name << " has been copied!"
			  << std::endl;
	ClapTrap(copy.name);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << G << "ClapTrap " << R << this->name << " has been destroyed!" << std::endl;
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
/*                               GETTERS                                      */
/* ************************************************************************** */

long int ClapTrap::getHealth(void) const
{
	return this->hitPoints;
}

std::string ClapTrap::getName(void) const
{
	return this->name;
}

unsigned int ClapTrap::getDamage(void) const
{
	return this->attackDamage;
}

unsigned int ClapTrap::getEnergy(void) const
{
	return this->energyPoints;
}

unsigned int ClapTrap::getMaxHitPoint(void) const
{
	return this->maxHitPoint;
}

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */

void ClapTrap::setDamage(unsigned int _damage)
{
	this->attackDamage = _damage;
}

void ClapTrap::setEnergy(unsigned int _energy)
{
	this->energyPoints = _energy;
}

void ClapTrap::setHealth(unsigned int _health)
{
	this->hitPoints = _health;
}
void ClapTrap::setName(std::string _name)
{
	this->name = _name;
}

void ClapTrap::setMaxHitPoint(unsigned int _maxHitPoint)
{
	this->maxHitPoint = _maxHitPoint;
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
		std::cout << this->name << " takes " << amount << " damage! "
				  << "It now has " << this->getHealth() << " HP!"
				  << std::endl;
		if (this->getHealth() <= 0)
			std::cout << this->name << " died!" << std::endl;
	}
	else
		std::cout << this->name << " is already dead..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHealth() > 0 && this->getEnergy() > 0 && this->getHealth() < this->maxHitPoint)
	{
		this->energyPoints -= 1;
		if ((this->getHealth() + amount) <= this->maxHitPoint)
		{
			this->hitPoints += amount;
			std::cout << this->name << " heals itself! It now has "
					  << this->getHealth() << " HP!" << std::endl;
		}
		else
		{
			this->setHealth(this->maxHitPoint);
			std::cout << this->name << " heals itself ! It now has " << this->getHealth() << " HP!" << std::endl;
		}
	}
	else
	{
		if (this->getEnergy() <= 0)
			std::cout << this->name << " is exhausted and cannot use Repair..." << std::endl;
		else if (this->getHealth() >= this->maxHitPoint)
			std::cout << this->name << " doesn't use repair, it's already at full health." << std::endl;
		else if (this->getHealth() < 0)
			std::cout << this->name << " is dead and cannot use repair." << std::endl;
	}
}

void ClapTrap::displayStats(void)
{
	std::cout << std::setw(4) << std::left << "Name: " << std::setw(8) << this->name
			  << std::setw(4) << std::left << " HP: " << std::setw(8) << this->getHealth()
			  << std::setw(4) << std::left << " AP: " << std::setw(8) << this->getEnergy()
			  << std::setw(4) << std::left << " Damage: " << std::setw(8) << this->getDamage()
			  << std::setw(4) << std::left << " MaxHP: " << std::setw(8) << this->getMaxHitPoint()
			  << std::endl;
}
