/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SisterTracker.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:23:36 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/06 17:02:24 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SisterTracker.hpp"
#include <iomanip>
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

SisterTracker::SisterTracker() {}

SisterTracker::~SisterTracker(void) {}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void SisterTracker::update(size_t insertionIndex)
{
	for (size_t i = 0; i < sisterIndex.size(); ++i) {
		if (sisterIndex.at(i) >= insertionIndex)
			sisterIndex.at(i)++;
	}
}

void SisterTracker::print()
{
	for (size_t i = 0; i < sisterIndex.size(); ++i)
		std::cout << std::setw(30) << std::left << "SisterIndex" << "["
				  << std::setw(3) << i << "]	" << sisterIndex[i]
				  << std::endl;
	std::cout << "---" << std::endl;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
size_t SisterTracker::getMaxRange(size_t bIndex) const
{
	size_t i = 0;
	while (i != bIndex) {
		++i;
	}
	if (i > sisterIndex.size())
		throw std::runtime_error("couldn't find bIndex in SisterIndex");
	return sisterIndex.at(i);
}

/* ************************************************************************** */
/*                               SETTER                                       */
/* ************************************************************************** */
void SisterTracker::init(size_t size)
{
	sisterIndex.reserve(size);
}

void SisterTracker::add(size_t aIndex)
{
	sisterIndex.push_back(aIndex);
}

void SisterTracker::reset()
{
	sisterIndex.clear();
}
