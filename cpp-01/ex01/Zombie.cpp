/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/13 11:16:31 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <iomanip>

Zombie::Zombie(void) {
	// std::cout << "Created new zombie" << std::endl;
}

void	Zombie::nameZombie(std::size_t i, std::string name) {
		this->it = i;
		this->_name = name;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " has taken a headshot" << std::endl;
}

void Zombie::announce (void) {
	std::cout	<< std::setw(2)	
				<< this->it << " | "
				<< this->_name
				<< ": BraiiiiiiinnnzzzZ.."
				<< std::endl;
}