/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/06 18:31:01 by cdomet-d         ###   ########lyon.fr   */
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

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R << copy.name << " has been copied!" << std::endl;
	DiamondTrap::name = copy.DiamondTrap::name;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R << this->name << " has been destroyed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &comp)
{
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R " operator=() has been called." << std::endl;
	this->attackDamage = comp.attackDamage;
	this->energyPoints = comp.energyPoints;
	this->hitPoints = comp.hitPoints;
	this->ClapTrap::name = comp.ClapTrap::name;
	this->DiamondTrap::name = comp.DiamondTrap::name;
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