/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:57:06 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:31:07 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Timer.hpp"
#include <iomanip>
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Timer::Timer(void) : start(clock()) {
}

Timer::~Timer(void) {}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Timer::displayTimeElasped() const
{
	double result = static_cast< double >(clock() - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::showpoint << std::setprecision(3) << result
			  << std::endl;
}
