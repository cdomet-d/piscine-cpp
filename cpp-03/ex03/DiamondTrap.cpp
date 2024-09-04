/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/04 15:40:36 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "DiamondTrap " << this->getName() << " has been created!" << std::endl;
	this->name = _name;
	ClapTrap::name = _name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << "copy constructor called " << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->getName() << " has been destroyed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &comp)
{
	this->setDamage(comp.getDamage());
	this->setEnergy(comp.getEnergy());
	this->setDamage(comp.getHealth());
	this->setName(comp.getName());
	this->setMaxHitPoint(comp.getMaxHitPoint());
	return *this;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
