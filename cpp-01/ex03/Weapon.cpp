/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:44:02 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void) {}

Weapon::Weapon(std::string _type) {
	this->type = _type;
}

const std::string &Weapon::getType(void) {
	return (this->type);
}

void Weapon::setType(const std::string type_ref) {
	this->type = type_ref;
}

void Weapon::display(void) {
	std::cout << "Weapon type: " << this->type << std::endl;
}

Weapon::~Weapon(void) {}
