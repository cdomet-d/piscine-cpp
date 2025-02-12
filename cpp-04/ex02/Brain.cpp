/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:07 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:24:52 by cdomet-d         ###   ########.fr       */
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

Brain::Brain(const Brain &rhs)
{

	*this = rhs;
	std::cout << "Brain rhs constructor called " << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain deconstructor called " << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return *this;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */

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