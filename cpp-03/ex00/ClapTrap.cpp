/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:47:26 by jauseff           #+#    #+#             */
/*   Updated: 2024/09/05 15:39:33 by cdomet-d         ###   ########lyon.fr   */
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
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << G << std::setw(15) << std::left << "ClapTrap " << R << "default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
{
	this->name = _name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << G << std::setw(15) << std::left << "ClapTrap " << R << this->name << " has been created!"
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << G << std::setw(15) << std::left << "ClapTrap " << R << copy.name << " has been copied!"
			  << std::endl;
	ClapTrap(copy.name);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << G << std::setw(15) << std::left << "ClapTrap " << R << this->name << " has been destroyed!" << std::endl;
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
/*                               METHODS                                      */
/* ************************************************************************** */

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << G << std::setw(15) << std::left << "ClapTrap " << R 
		<< this->name << " attacks " << target << ", dealing " << this->attackDamage << " damage!" << std::endl;
	}
	else
	{
		if (this->hitPoints <= 0)
			std::cout << G << std::setw(15) << std::left << "ClapTrap " << R 
			<< this->name << " is dead and can't attack" << std::endl;
		if (this->energyPoints <= 0)
			std::cout << G << std::setw(15) << std::left << "ClapTrap " << R 
			<< this->name << " is exhausted and cannot attack anymore..." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		this->hitPoints -= amount;
		std::cout << G << std::setw(15) << std::left << this->name << R 
		<< "takes " << amount << " damage! " << "It now has " << this->hitPoints << " HP!" << std::endl;
		if (this->hitPoints <= 0)
			std::cout << G << std::setw(15) << std::left << this->name << R << "died!" << std::endl;
	}
	else
		std::cout << G << std::setw(15) << std::left << this->name << R << "is already dead..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		this->hitPoints += amount;
		std::cout << G << std::setw(15) << std::left << this->name << R 
		<< "repairs itself by " << amount << " HP ! It now has " << this->hitPoints << " HP!" << std::endl;
	}
	else
	{
		if (this->energyPoints <= 0)
			std::cout << G << std::setw(15) << std::left << this->name << R << "is exhausted and cannot use Repair..." << std::endl;
		else if (this->hitPoints < 0)
			std::cout << G << std::setw(15) << std::left << this->name << R << "is dead and cannot use repair." << std::endl;
	}
}
