/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:21 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/25 17:29:16 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Now, create two classes: HumanA and HumanB. They both have a Weapon and a
// name. They also have a member function attack() that displays (of course, without the
// angle brackets):
// <name> attacks with their <weapon type>
// HumanA and HumanB are almost the same except for these two tiny details:
// • While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int main(void)
// {
// 	Weapon	wA = Weapon("axe");
// 	Weapon*	wB = new Weapon("lance");
// 	HumanA	laura = HumanA("Laura", wA);
// 	HumanB	agathe = HumanB("Agathe");
// 	laura.attack();
// 	agathe.attack();
// 	agathe.setWeapon(wB);
// 	agathe.attack();
// 	delete wB;
// 	return (0);
// }

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
return 0;
}