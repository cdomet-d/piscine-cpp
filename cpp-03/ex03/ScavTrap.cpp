/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <iomanip>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ScavTrap::ScavTrap(void)
{
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
	std::cout << B << std::setw(15) << std::left << "ScavTrap " << R << "default constructor called " << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << B << std::setw(15) << std::left << "ScavTrap " << R << this->name << " has been created!" << std::endl;
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << B << std::setw(15) << std::left << "ScavTrap " << R << this->name << " has been destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs) 
{
	std::cout << B << std::setw(15) << std::left << "Scavtrap " << R << rhs.name << " has been copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	this->attackDamage = rhs.attackDamage;
	this->energyPoints = rhs.energyPoints;
	this->hitPoints = rhs.hitPoints;
	this->name = rhs.name;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void ScavTrap::guardGate(void)
{
	std::cout << B << std::setw(15) << std::left << "ScavTrap " << R 
	<< this->name << " is now in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << B << std::setw(15) << std::left << "ScavTrap " << R 
		<< this->name << " attacks " << target << ", dealing " << this->attackDamage << " damage!" << std::endl;
	}
	else
	{
		if (this->hitPoints <= 0)
			std::cout << B << std::setw(15) << std::left << "ScavTrap " << R 
			<< this->name << " is dead and cannot attack" << std::endl;
		if (this->energyPoints <= 0)
			std::cout << B << std::setw(15) << std::left << "ScavTrap " << R 
			<< this->name << " is exhausted and cannot attack" << std::endl;
	}
}