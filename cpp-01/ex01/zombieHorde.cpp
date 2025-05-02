/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:40:50 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:45:18 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name) {
	Zombie *zArray;

	try {
		zArray = new Zombie[N];
	} catch (const std::exception &ba) { std::cout << ba.what() << std::endl; }
	for (int i = 0; i < N; i++)
		zArray[i].nameZombie(i, name);
	return (zArray);
}
