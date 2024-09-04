/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:37:20 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/04 14:20:33 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include <iostream>

int	main(void)
{
	ClapTrap laura("Laura");
	ClapTrap agathe("Agathe");

	laura.displayStats();
	agathe.displayStats();

	laura.setDamage(5);
	laura.attack("Agathe");
	agathe.takeDamage(laura.getDamage());
	agathe.beRepaired(10);
	laura.beRepaired(15);

	laura.setDamage(1);
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
