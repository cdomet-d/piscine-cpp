/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:37:20 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/06 18:25:30 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include <iostream>

int	main(void)
{
	ClapTrap johnny("Johnny");
	ClapTrap v(johnny);

	johnny.attack("Arasaka Corporation");
	johnny.takeDamage(2);
	johnny.beRepaired(2);
	johnny.attack("Adam Smasher");
	johnny.takeDamage(10);

	v.attack("Arasaka Corporation");
	v.takeDamage(2);
	v.beRepaired(2);
	v.attack("Adam Smasher");
	v.takeDamage(10);

}
