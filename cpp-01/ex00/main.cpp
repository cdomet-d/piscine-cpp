/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/24 15:21:36 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	Glen("Glen");
	Zombie	*Abraham;

	Abraham = newZombie("Abraham");
	randomChump("The Governor");
	Glen.announce();
	Abraham->announce();
	delete Abraham;
	
}
