/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:21:34 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/05 16:19:49 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Jacobsthal.hpp"
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Jacobsthal::Jacobsthal(void)
	: currentJ(1), previousJ(1), nextJ(0), insertedElems(0), totalInsertedElems(0)
{
}

Jacobsthal::~Jacobsthal(void) {}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Jacobsthal::display()
{
	std::cout << "Prev:	" << getPrevI() << std::endl
			  << "Curr:	" << getI() << std::endl
			  << "Next:	" << getNextI() << std::endl;
}

void Jacobsthal::reset()
{
	totalInsertedElems = 0;
	currentJ = 1;
	previousJ = 1;
	nextJ = 0;
}

void Jacobsthal::update()
{
	//  each term is the sum of the previous, plus twice the one before that.
	totalInsertedElems += insertedElems;
	insertedElems = 0;
	size_t oldJ = previousJ;
	previousJ = currentJ;
	currentJ = previousJ + (oldJ * 2);
	nextJ = currentJ + (previousJ * 2);
}
/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
size_t Jacobsthal::getTotalInsertedElems() const
{
	return totalInsertedElems;
}

size_t Jacobsthal::getPrevI() const
{
	return previousJ;
}

size_t Jacobsthal::getNextI() const
{
	return nextJ;
}

size_t Jacobsthal::getI() const
{
	return currentJ;
}

size_t Jacobsthal::getInsertedElems() const
{
	return insertedElems;
}

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */
void Jacobsthal::setTotalInsertedElems()
{
	totalInsertedElems += insertedElems;
}
void Jacobsthal::setInsertedElems(size_t n)
{
	insertedElems = n;
}

bool Jacobsthal::isNeeded(size_t contLen)
{
	return (contLen - totalInsertedElems) > getNextI();
}
/* ************************************************************************** */
/*                               PRIVATE CONSTUCTORS                          */
/* ************************************************************************** */
