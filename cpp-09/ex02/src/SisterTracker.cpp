/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SisterTracker.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:23:36 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/03 19:59:27 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "SisterTracker.hpp"
#include <algorithm>
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
	// std::cout << "Updating sister" << std::endl;
	for (size_t i = 0; i < sisterIndex.size(); ++i) {
		// std::cout << "i	" << i << " | Insertion index " << insertionIndex << std::endl;
		if (sisterIndex.at(i) > insertionIndex)
			sisterIndex.at(i)++;
	}
	// print();
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
