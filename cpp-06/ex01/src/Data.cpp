/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:51:01 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/29 14:54:39 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

std::ostream &operator<<(std::ostream &os, const Data &print)
{
	os << "[" << "H: " << print.height << "] " << std::endl
	   << "[" << "W: " << print.width << "] " << std::endl
	   << "[" << "D: " << print.depth << "] " << std::endl
	   << "[" << "x: " << print.x << "] " << std::endl
	   << "[" << "y: " << print.y << "] ";
	return os;
}