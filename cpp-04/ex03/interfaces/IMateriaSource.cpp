/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:40:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/19 18:07:20 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

IMateriaSource::IMateriaSource(void)
{
	// std::cout << "constructor called " << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &copy)
{
	// std::cout << "copy constructor called " << std::endl;
	*this = copy;
}

IMateriaSource::~IMateriaSource(void)
{
	// std::cout << "deconstructor called " << std::endl;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &comp)
{
	(void)comp;
	return *this;
}
