/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:08:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

#include <iostream>

#define R "\033[0m" // reset
#define COLOR "\x1b[35m"

int main(void)
{
	{
		std::cout << COLOR << "\ntesting basic functionnalities" << R << std::endl;
		Character csweetin("csweetin");
		Character applicant("applicant");
		AMateria *im1 = new Ice;
		AMateria *cm1 = new Cure;
		AMateria *im2 = new Ice;
		AMateria *cm2 = new Cure;

		csweetin.equip(im1);
		csweetin.equip(cm1);
		csweetin.equip(im2);
		csweetin.equip(cm2);

		csweetin.displayInventory();
		csweetin.use(0, applicant);
		csweetin.use(1, csweetin);

		csweetin.unequip(2);
		csweetin.unequip(3);

		applicant = csweetin;
		applicant.use(0, applicant);
		applicant.use(1, csweetin);

		std::cout << COLOR << "\nerror testing" << R << std::endl;
		applicant.use(-9, csweetin);
		applicant.use(10, csweetin);
		delete im2;
		delete cm2;
	}

	// {
	// 	std::cout << std::endl;
	// 	IMateriaSource *src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	ICharacter *me = new Character("me");
	// 	AMateria *tmp;
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// 	ICharacter *bob = new Character("bob");
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
	// 	delete bob;
	// 	delete me;
	// 	delete src;
	// }
	{
		std::cout << COLOR << "\ntesting rhs constructor" << R << std::endl;
		Ice	ice;
		std::cout << "ice: " << ice.getType() << std::endl;
		Ice ice2(ice);
		std::cout << "ice2: " << ice2.getType() << std::endl;
	}
}
