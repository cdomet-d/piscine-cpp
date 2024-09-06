/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1024/09/03 11:34:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/06 18:30:08 by cdomet-d         ###   ########lyon.fr   */
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
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << "default constructor called " << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << this->name << " has been created!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << this->name << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << copy.name << " has been copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &comp)
{
	this->attackDamage = comp.attackDamage;
	this->energyPoints = comp.energyPoints;
	this->hitPoints = comp.hitPoints;
	this->name = comp.name;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void FragTrap::highFivesGuys(void)
{
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R 
	<< this->name << " gives you a superb high five !" << std::endl;
}
