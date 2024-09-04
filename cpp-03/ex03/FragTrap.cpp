/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/04 15:28:56 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

FragTrap::FragTrap(void)
{
	this->setMaxHitPoint(100);
	this->setDamage(30);
	this->setEnergy(100);
	this->setHealth(100);
	std::cout << "FragTrap default constructor called " << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setMaxHitPoint(100);
	this->setDamage(30);
	this->setEnergy(100);
	this->setHealth(100);
	std::cout << "FragTrap " << this->getName() << " has been created!" << std::endl;
}

FragTrap::~FragTrap(void) 
{
	std::cout << "FragTrap " << this->getName() << " has been destroyed!" << std::endl;
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
	this->setMaxHitPoint(comp.getMaxHitPoint());
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " gives you a superb high five !" << std::endl;
}
