/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:08 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:44:21 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string _name, Weapon &_weapon) : weapon(_weapon) {
	this->name = _name;
}

HumanA::~HumanA(void) {}

void HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon.getType()
			  << " !" << std::endl;
}
