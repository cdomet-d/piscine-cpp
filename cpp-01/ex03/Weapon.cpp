/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/29 11:48:33 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void){

}

Weapon::Weapon(std::string type) {
	this->type = type;
}

const std::string& Weapon::getType(void) {
	return (this->type);
}

void Weapon::setType(const std::string type_ref) {
	this->type = type_ref;
}

void Weapon::display(void) {
	std::cout << "Weapon type: " << this->type << std::endl;
}

Weapon::~Weapon(void) {
	
}
