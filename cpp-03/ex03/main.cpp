/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:37:20 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/06 18:22:36 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap v("V");
	DiamondTrap ian(v);
	// ClapTrap	cT("ew");
	// ClapTrap	cT2(cT);

	// cT2.attack("Hehe");
	// cT2.takeDamage(5);
	// cT2.beRepaired(2);

	// v.whoAmI();
	ian.whoAmI();
	ian.displayStat();
	// v.displayStat();
	// v.attack("Arasaka Corporation");
	// v.takeDamage(99);
	// v.whoAmI();
	
}
