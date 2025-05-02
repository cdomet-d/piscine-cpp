/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:44:48 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name) {
	Zombie *zombie;

	try {
		zombie = new Zombie(name);
	} catch (std::bad_alloc &ba) {
		std::cout << "Bad allocation: " << ba.what() << std::endl;
	}
	return (zombie);
}
