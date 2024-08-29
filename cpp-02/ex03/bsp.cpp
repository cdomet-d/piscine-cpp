/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:25:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/29 17:24:13 by cdomet-d         ###   ########lyon.fr   */
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

	std::cout << "point is interpreted as: " << point << std::endl;

	if (triangleIsValid(a, b, c) == false)
		return false;
	Fixed vACY = c.getY() - a.getY();
	Fixed vACX = c.getX() - a.getX();

	Fixed vABY = b.getY() - a.getY();
	Fixed vABX = b.getX() - a.getX();

	w1 = (a.getX() * vACY + (point.getY() - a.getY()) * vACX - point.getX() * vACY) / (vABY * vACX - vABX * vACY);
	w2 = (point.getY() - a.getY() - w1 * vABY) / vACY;
	std::cout << "w1: " << w1 << " | w2: " << w2 << " | w1 + w2: " << w1 + w2 << std::endl;
	if ((w1 > 0 && w1 < 1) && (w2 > 0 && w2 < 1) && (w2 + w1 <= 1))
		return true;
	else
		return false;
}
 