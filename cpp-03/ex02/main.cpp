/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:37:20 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/03 15:14:31 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	fragTrap laura("Laura");
	clapTrap agathe("Agathe");

	laura.highFivesGuys();
	agathe.setDamage(5);
	while (agathe.getEnergy() > 1)
	{
		agathe.attack("Laura");
		laura.takeDamage(agathe.getDamage());
	}
	laura.beRepaired(200);
	laura.attack("Agathe");
	agathe.takeDamage(laura.getDamage());
	agathe.beRepaired(3);
	agathe.displayStats();
	laura.displayStats();
}
