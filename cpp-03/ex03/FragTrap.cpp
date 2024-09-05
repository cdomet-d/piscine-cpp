/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1024/09/03 11:34:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/05 15:50:36 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <iomanip>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

FragTrap::FragTrap(void)
{
	this->setDamage(30);
	this->setEnergy(100);
	this->setHealth(100);
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << "default constructor called " << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setDamage(30);
	this->setEnergy(100);
	this->setHealth(100);
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << this->getName() << " has been created!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << this->getName() << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	*this = copy;
	std::cout << "copy constructor called " << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &comp)
{
	this->setDamage(comp.getDamage());
	this->setEnergy(comp.getEnergy());
	this->setDamage(comp.getHealth());
	this->setName(comp.getName());
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void FragTrap::highFivesGuys(void)
{
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << this->getName() << " gives you a superb high five !" << std::endl;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
long int FragTrap::getFragHitPts(void) const
{
	return this->fragTrapHitPts;
}

long int FragTrap::getFragEnergyPts(void) const
{
	return this->fragTrapEnergyPts;
}

long int FragTrap::getFragDmg(void) const
{
	return this->fragTrapAttackDmg;
}
