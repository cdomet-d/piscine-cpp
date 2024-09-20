/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:08:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/20 17:29:31 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

#include <iostream>

int main(void)
{
	{
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

		applicant = csweetin;
		applicant.use(0, csweetin);
		applicant.use(1, csweetin);
		applicant.use(-9, csweetin);
		applicant.use(10, csweetin);
	}

	{
		std::cout << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << std::endl;
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		IMateriaSource* src = new MateriaSource();
		
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		AMateria* ice;
		ice = src->createMateria("ice");
		me->equip(ice);
		
		AMateria* cure;
		cure = src->createMateria("cure");
		me->equip(cure);
		
		me->displayInventory();
		me->use(0, *bob);
		me->use(1, *me);

		me->unequip(1);

		delete cure;
		delete bob;
		delete me;
		delete src;
	}
}
