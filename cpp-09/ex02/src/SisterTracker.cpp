/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SisterTracker.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:23:36 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/31 14:58:32 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SisterTracker.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

SisterTracker::SisterTracker() {
}

SisterTracker::~SisterTracker(void) {}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void SisterTracker::update(size_t insertionIndex)
{
	for (std::vector< int >::iterator it =
			 std::find(sisterIndex.begin(), sisterIndex.end(), insertionIndex);
		 it != sisterIndex.end(); ++it) {
		(*it)++;
	}
}

void SisterTracker::print()
{
	for (size_t i = 0; i < sisterIndex.size(); ++i)
		std::cout << std::setw(30) << std::left << "SisterIndex" << "["
				  << std::setw(3) << i << "]	" << sisterIndex[i] << std::endl;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
size_t SisterTracker::getMaxRange(size_t bIndex)
{
	std::vector< int >::iterator it =
		std::find(sisterIndex.begin(), sisterIndex.end(), bIndex);
	return std::distance(sisterIndex.begin(), it);
}

/* ************************************************************************** */
/*                               SETTER                                       */
/* ************************************************************************** */

void SisterTracker::add(size_t aIndex) {
	sisterIndex.push_back(aIndex);
}

void SisterTracker::reset() {
	sisterIndex.clear();
}
