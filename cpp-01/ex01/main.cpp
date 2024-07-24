/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/24 17:03:26 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie*		zArray;
	std::size_t	N = 100;
	std::size_t	i;

	zArray = zombieHorde(N, "Agathe");
	for (i = 0; i < N; i++)
		zArray[i].announce();
	delete []zArray;
}
