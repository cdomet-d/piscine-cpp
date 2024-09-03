/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:37:20 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/03 11:40:40 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
# include <iostream>

int	main(void)
{
	scavTrap laura("Laura");
	clapTrap agathe("Agathe");

	laura.displayStats();
	agathe.displayStats();

	laura.setDamage(5);
	laura.attack("Agathe");
	agathe.takeDamage(laura.getDamage());
	agathe.displayStats();
	agathe.beRepaired(10);
	laura.beRepaired(15);

	laura.setDamage(2);
	while (laura.getEnergy() > 0)
	{
		laura.attack("Agathe");
		agathe.takeDamage(laura.getDamage());
	}
	laura.attack("Agathe");
	laura.displayStats();
	agathe.displayStats();
	agathe.beRepaired(20);
	agathe.beRepaired(20);
}
