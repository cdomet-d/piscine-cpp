/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:37:20 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/04 14:23:44 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap laura("Laura");
	ClapTrap agathe("Agathe");

	laura.highFivesGuys();
	agathe.setDamage(50);
	while (agathe.getHealth() > 0)
	{
		laura.attack("Agathe");
		agathe.takeDamage(laura.getDamage());
	}
	laura.beRepaired(200);
	laura.attack("Agathe");
	agathe.takeDamage(laura.getDamage());
	agathe.beRepaired(3);
	agathe.displayStats();
	laura.displayStats();
}
