/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/03 15:15:15 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

fragTrap::fragTrap(std::string name) : clapTrap(name)
{
	this->setMaxHitPoint(100);
	this->setDamage(30);
	this->setEnergy(100);
	this->setHealth(100);
	std::cout << "fragTrap " << this->getName() << " has been created!" << std::endl;
}

fragTrap::~fragTrap(void) 
{
	std::cout << "fragTrap " << this->getName() << " has been destroyed!" << std::endl;
}

void fragTrap::highFivesGuys(void)
{
	std::cout << "fragTrap " << this->getName() << " gives you a superb high five !" << std::endl;
}