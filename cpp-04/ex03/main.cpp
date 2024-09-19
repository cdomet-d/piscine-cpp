/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:08:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/19 13:12:59 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	{
		Character csweetin("csweetin");
		Character applicant("applicant");
		AMateria *im1 = new Ice;
		AMateria *cm1 = new Cure;

		csweetin.equip(im1);
		csweetin.equip(cm1);

		csweetin.displayInventory();
		csweetin.use(0, applicant);
		csweetin.use(1, csweetin);

		applicant = csweetin;
		applicant.displayInventory();
		applicant.use(0, csweetin);
		applicant.use(1, csweetin);
	}
	{
		MateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return 0;
	}
}