/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:08:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/18 16:40:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "IceMateria.hpp"
#include "CureMateria.hpp"

int main(void)
{
	Character csweetin("csweetin");
	Character applicant("applicant");
	AMateria *im1 = new IceMateria;
	AMateria *cm1 = new CureMateria;

	csweetin.equip(im1);
	csweetin.equip(cm1);

	csweetin.displayInventory();
	csweetin.use(0, applicant);
	csweetin.use(1, csweetin);

	applicant = csweetin;
	applicant.use(0, csweetin);
	applicant.use(1, csweetin);
	// delete im1;
	// delete cm1;
}