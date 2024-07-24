/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/24 14:24:55 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	Antoine("Antoine");
	Zombie	*Elsa;
	
	Elsa = newZombie("Elsa");
	randomChump("Constance");
	Antoine.announce();
	Elsa->announce();
	delete Elsa;
	
}
