/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:38 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/24 14:08:30 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie( std::string name )
{
	Zombie *zombie;
	
	try {
		zombie = new Zombie(name);}
	catch (std::bad_alloc& ba) {
		std::cerr << "Bad allocation: " << ba.what() << std::endl;
	}
	return (zombie);
}
