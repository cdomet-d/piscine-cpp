/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:25:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/28 15:58:54 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed w1;
	Fixed w2;

	Fixed vACY = c.getY() - a.getY();
	Fixed vACX = c.getX() - a.getX();
	Fixed vABY = b.getY() - a.getY();
	Fixed vABX = b.getX() - a.getX();
	
	w1 = (a.getX() * vACY + (point.getY() - a.getY()) * vACX - point.getX() * vACY) \
	/ (vABY * vACX - vABX * vACY);
	w2 = (point.getY() - a.getY() - w1 * vABY) / vACY;
	
	std::cout << w1 << std::endl;
	std::cout << w2 << std::endl;
	std::cout << w1 + w2 << std::endl;
	if ((w1 >= 0 && w1 <= 1) && (w2 >= 0 && w2 <= 1) && (w2 + w1 <= 1))
		return true;
	else
		return false;
}
