/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1024/09/03 11:34:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
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

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs)
{
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R << rhs.name << " has been copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
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
void FragTrap::highFivesGuys(void)
{
	std::cout << P << std::setw(15) << std::left << "FragTrap " << R 
	<< this->name << " gives you a superb high five !" << std::endl;
}
