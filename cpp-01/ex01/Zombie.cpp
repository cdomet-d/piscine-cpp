/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:45:10 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iomanip>
#include <iostream>

Zombie::Zombie(void) {}

void Zombie::nameZombie(std::size_t i, std::string name) {
	this->it = i;
	this->_name = name;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " has taken a headshot" << std::endl;
}

void Zombie::announce(void) {
	std::cout << std::setw(2) << this->it << " | " << this->_name
			  << ": BraiiiiiiinnnzzzZ.." << std::endl;
}