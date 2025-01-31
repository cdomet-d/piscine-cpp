/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SisterTracker.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:23:36 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/31 17:13:37 by cdomet-d         ###   ########.fr       */
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
	std::cout << "Updating sister" << std::endl;
	for (size_t i = 0; i < sisterIndex.size(); ++i) {
		// std::cout << "i	" << i << " | Insertion index " << insertionIndex << std::endl;
		if (sisterIndex[i] > insertionIndex)
			sisterIndex[i]++;
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
size_t SisterTracker::getMaxRange(size_t bIndex)
{
	// std::vector< int >::iterator it =
	// 	std::find(sisterIndex.begin(), sisterIndex.end(), bIndex);
	size_t i = 0;
	while (i != bIndex) {
		++i;
	}
	if (i > sisterIndex.size())
		throw std::runtime_error("couldn't find bIndex in SisterIndex");
	return sisterIndex[i];
}

/* ************************************************************************** */
/*                               SETTER                                       */
/* ************************************************************************** */

void SisterTracker::add(size_t aIndex)
{
	sisterIndex.push_back(aIndex);
}

void SisterTracker::reset()
{
	sisterIndex.clear();
}
