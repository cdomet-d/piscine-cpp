/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/03 14:37:10 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

scavTrap::scavTrap(std::string name) : clapTrap(name)
{
	this->setMaxHitPoint(100);
	this->setDamage(20);
	this->setEnergy(50);
	this->setHealth(100);
	std::cout << "scavTrap " << this->getName() << " has been created!" << std::endl;
}

scavTrap::~scavTrap(void) 
{
	std::cout << "scavTrap " << this->getName() << " has been destroyed!" << std::endl;
}

void scavTrap::guardGate(void)
{
	std::cout << "scavTrap " << this->getName() << " is now in Gate Keeper mode." << std::endl;
}