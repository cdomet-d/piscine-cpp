/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:41 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/05 12:37:22 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string _name) {
		this->name = _name;
}

Zombie::~Zombie(void) {
	std::cout << this->name << " has taken a headshot" << std::endl;
}

void Zombie::announce (void) {
	std::cout	<< this->name
				<< ": BraiiiiiiinnnzzzZ.."
				<< std::endl;
}
