/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:57:06 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/03 14:30:51 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Timer.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <unistd.h>

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
