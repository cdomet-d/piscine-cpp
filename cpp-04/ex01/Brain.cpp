/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:07 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/26 17:22:57 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <iomanip>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Brain::Brain(void)
{
	std::cout << "Brain constructor called " << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Brain copy constructor called " << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain deconstructor called " << std::endl;
}

Brain &Brain::operator=(const Brain &comp)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = comp.ideas[i];
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Brain::fillArr(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}
void Brain::displayArr(void) const
{
	for (int i = 0; i < 10; i++)
		std::cout << "[ " << std::setw(2) << i + 1 << " ] "
				  << this->ideas[i] << std::endl;
}