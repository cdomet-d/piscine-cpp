#include "HumanB.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:15 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/25 12:46:16 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(void) {
}

HumanB::HumanB(std::string _name) {
	this->name = _name;
	this->weapon = NULL;
}

void HumanB::attack(void) 
{
	if (this->weapon)
	{
		std::cout	<< this->name
					<< " attacks with their "
					<< weapon->getType()
					<< " !"
					<< std::endl;
	}
	else
	{
		std::cout	<< this->name
					<< " cowers in fear, for they are disarmed !"
					<< std::endl;
	}
}

void HumanB::setWeapon(Weapon& _weapon) 
{
		this->weapon = &_weapon;
		std::cout	<< this->name
				<< " has found a "
				<< weapon->getType()
				<< " !"
				<< std::endl;
}

HumanB::~HumanB(void) 
{

}
