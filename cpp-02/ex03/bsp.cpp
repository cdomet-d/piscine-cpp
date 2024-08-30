/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauseff <jauseff@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:25:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/30 15:15:01 by jauseff          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool triangleIsValid(Point const a, Point const b, Point const c)
{
	if (a == b || a == c || b == c)
	{
		throw std::invalid_argument("Error : triangle is degenerate");
		return false;
	}
	else
		return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed w1;
	Fixed w2;
	Fixed n = 1;

	std::cout << "point is interpreted as: " << point << std::endl;

	if (triangleIsValid(a, b, c) == false)
		return false;

	Fixed vACX = c.getX() - a.getX();
	Fixed vACY = c.getY() - a.getY();
	Fixed vABY = b.getY() - a.getY();
	Fixed vABX = b.getX() - a.getX();
	Fixed vAPY = point.getY() - a.getY();

	w1 = (a.getX() * vACY + vAPY * vACX - point.getX() * vACY) / (vABY * vACX - vABX * vACY);
	w2 = (vAPY - w1 * vABY) / vACY;
	Fixed w3 = n - w1 - w2;
	std::cout << "w1: " << w1 << " | w2: " << w2 << " | w3: " << w3 << " | w1 + w2: " << w1 + w2 << std::endl;
	if ((w1 > 0 && w1 < 1) && (w2 > 0 && w2 < 1) && (w2 + w1 <= 1))
		return true;
	else
		return false;
}
