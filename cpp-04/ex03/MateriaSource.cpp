/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:15:54 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 15:10:39 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	std::cout << "MateriaSource constructor called " << std::endl;
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy) 
{
	std::cout << "MateriaSource copy constructor called " << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource deconstructor called " << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->learned[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &comp)
{
	for (int i = 0; i < 4; i++)
		delete this->learned[i];
	for (int i = 0; i < 4; i++)
	{
		if (comp.learned[i])
			this->learned[i] = comp.learned[i]->clone();
		else
			this->learned[i] = NULL;
	}
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->learned[i])
		{
			this->learned[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->learned[i])
		{
			if (this->learned[i]->getType().compare(type) == 0)
				return this->learned[i]->clone();
		}
	}
	std::cout << "Unknown type" << std::endl;
	return 0;
}
