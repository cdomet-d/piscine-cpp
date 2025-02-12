/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <iomanip>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R << "default constructor called." << std::endl;
}

// 	Hit points (FragTrap) -> 100
// Energy points (ScavTrap) -> 50
// Attack damage (FragTrap) - 30
// attack() (Scavtrap)

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name")
{
	DiamondTrap::name = _name;
	this->attackDamage = FragTrap::dftFragDmg;
	this->hitPoints = FragTrap::dftFragHitPts;
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R << DiamondTrap::name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs)
{
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R << rhs.name << " has been copied!" << std::endl;
	DiamondTrap::name = rhs.DiamondTrap::name;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R << this->name << " has been destroyed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R " operator=() has been called." << std::endl;
	this->attackDamage = rhs.attackDamage;
	this->energyPoints = rhs.energyPoints;
	this->hitPoints = rhs.hitPoints;
	this->ClapTrap::name = rhs.ClapTrap::name;
	this->DiamondTrap::name = rhs.DiamondTrap::name;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void DiamondTrap::whoAmI()
{
	std::cout << std::setw(15) << std::left << " " << "My DiamondTrap name is " << DiamondTrap::name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::displayStat()
{
	std::cout << std::setw(15) << std::left << " " 
	<< "My stats are: Attack: " 
	<< this->attackDamage << " | " << "Health: " << this->hitPoints << " | " 
	<< "Energy: " << this->energyPoints << std::endl;
}