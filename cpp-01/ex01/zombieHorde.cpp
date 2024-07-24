/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:40:50 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/24 17:02:51 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
// #include <ostream>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zArray;
	
	try
	{
		zArray = new Zombie[N];
	}
	catch(const std::exception& ba)
	{
		std::cerr << ba.what() << std::endl;
	}
	for (int i = 0; i < N; i++)
		zArray[i].nameZombie(i, name);
	return (zArray);
}
