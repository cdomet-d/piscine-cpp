/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/24 17:05:10 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <iomanip>

Zombie::Zombie(void) {
	// std::cout << "Created new zombie" << std::endl;
}

void	Zombie::nameZombie(std::size_t i, std::string name) {
		this->i = i;
		this->name = name;
}

Zombie::~Zombie(void) {
	std::cout << this->name << " has taken a headshot" << std::endl;
}

void Zombie::announce (void) {
	std::cout	<< std::setw(2)	
				<< this->i << " | "
				<< this->name
				<< ": BraiiiiiiinnnzzzZ.."
				<< std::endl;
}