/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:47:26 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/03 11:52:53 by cdomet-d         ###   ########lyon.fr   */
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
	std::cout << "clapTrap " << this->name << " has been created!"
			  << std::endl;
}

clapTrap::clapTrap(const clapTrap &copy)
{
	std::cout << "clapTrap " << copy.name << " has been copied!"
			  << std::endl;
	clapTrap(copy.name);
}

clapTrap::~clapTrap(void)
{
	std::cout << "clapTrap " << this->name << " has been destroyed!" << std::endl;
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
/*                               GETTERS                                      */
/* ************************************************************************** */

long int clapTrap::getHealth(void)
{
	return this->hitPoints;
}

std::string clapTrap::getName(void)
{
	return this->name;
}

unsigned int clapTrap::getDamage(void)
{
	return this->attackDamage;
}

unsigned int clapTrap::getEnergy(void)
{
	return this->energyPoints;
}

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */

void clapTrap::setDamage(unsigned int _damage)
{
	this->attackDamage = _damage;
}

void clapTrap::setEnergy(unsigned int _energy)
{
	this->energyPoints = _energy;
}

void clapTrap::setHealth(unsigned int _health)
{
	this->hitPoints = _health;
}
void clapTrap::setName(std::string _name)
{
	this->name = _name;
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
		if (this->getHealth() <= 0)
			std::cout << this->name << " died!" << std::endl;
	}
	else
		std::cout << this->name << " is already dead..." << std::endl;
}

void clapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() > 0 && this->getHealth() < 10)
	{
		if ((this->getHealth() + amount) <= 10)
		{
			std::cout << this->name << " heals itself by " << amount << " HP!" << std::endl;
			this->hitPoints += amount;
		}
		else
		{
			this->hitPoints = 10;
			std::cout << this->name << " heals itself by " << amount - this->getHealth() << " HP!" << std::endl;
		}
		this->energyPoints -= 1;
	}
	else
	{
		if (this->getEnergy() <= 0)
			std::cout << this->name << " is exhausted and cannot use Repair..." << std::endl;
		else if (this->getHealth() >= 10)
			std::cout << this->name << " doesn't use repair, it's already at full health." << std::endl;
	}
}

void clapTrap::displayStats(void)
{
	std::cout << std::setw(4) << std::left << "Name: " << std::setw(8) << this->name
			  << std::setw(4) << std::left << " HP: " << std::setw(8) << this->getHealth()
			  << std::setw(4) << std::left << " AP: " << std::setw(8) << this->getEnergy()
			  << std::setw(4) << std::left << " Damage: " << std::setw(8) << this->getDamage()
			  << std::endl;
}
