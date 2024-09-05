/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/05 17:42:36 by cdomet-d         ###   ########lyon.fr   */
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

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name")
{
	DiamondTrap::name = _name;
	this->setDamage(FragTrap::getFragDmg());
	this->setHealth(FragTrap::getFragHitPts());
	this->setEnergy(ScavTrap::getEnergy());
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R << DiamondTrap::name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << "copy constructor called " << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << C << std::setw(15) << std::left << "DiamondTrap " << R << this->getName() << " has been destroyed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &comp)
{
	this->setDamage(comp.getDamage());
	this->setEnergy(comp.getEnergy());
	this->setDamage(comp.getHealth());
	this->setName(comp.getName());
	this->DiamondTrap::name = comp.DiamondTrap::name;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void DiamondTrap::whoAmI()
{
	std::cout << std::setw(15) << std::left << "My DiamondTrap name is " << DiamondTrap::name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}