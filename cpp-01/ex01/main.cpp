/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:45:04 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void) {
	Zombie *zArray;
	std::size_t N = 100;
	std::size_t i;

	zArray = zombieHorde(N, "Agathe");
	for (i = 0; i < N; i++)
		zArray[i].announce();
	delete[] zArray;
}
