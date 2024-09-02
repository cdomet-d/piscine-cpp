/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:37:20 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/02 16:57:20 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include <iostream>

int	main(void)
{
	clapTrap laura("Laura");
	clapTrap agathe("Agathe");

	laura.setDamage(2);
	agathe.setDamage(2);

	laura.displayStats();
	agathe.displayStats();

	laura.attack("Agathe");
	agathe.takeDamage(laura.getDamage());
	laura.displayStats();
	agathe.displayStats();
	
	laura.setDamage(5);
	
	laura.attack("Agathe");
	agathe.takeDamage(laura.getDamage());
	agathe.displayStats();
	agathe.beRepaired(10);
	agathe.displayStats();
	laura.displayStats();


}