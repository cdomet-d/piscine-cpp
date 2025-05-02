/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:44:45 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void) {
	Zombie Glen("Glen");
	Zombie *Abraham;

	Abraham = newZombie("Abraham");
	randomChump("The Governor");
	Glen.announce();
	Abraham->announce();
	delete Abraham;
}
