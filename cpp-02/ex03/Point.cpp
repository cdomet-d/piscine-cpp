/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:24:20 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:23:32 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/*                          CONSTRUCTORS && CIE                               */
/* ************************************************************************** */

Point::Point(void) : x(0), y(0) {}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point::Point(const Point &original) : x(original.x), y(original.y) {}

Point::~Point(void) {}

/* ************************************************************************** */
/*                          GETTERS                                           */
/* ************************************************************************** */

const Fixed Point::getX(void) const
{
	return this->x.toFloat();
}

const Fixed Point::getY(void) const
{
	return this->y.toFloat();
}

/* ************************************************************************** */
/*                          OPERATOR OVERLOADING                              */
/* ************************************************************************** */

Point &Point::operator=(const Point &original)
{
	(void)original;
	return *this;
}

bool Point::operator==(const Point &rhs) const
{
	if (this->x == rhs.getX() && this->y == rhs.getY())
		return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, const Point &print)
{
	os << "x = " << print.getX() << " | y = " << print.getY();
	return os;
}
