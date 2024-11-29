/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:38:39 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/29 14:50:50 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
	int height;
	int width;
	int depth;
	int x;
	int y;
};

std::ostream &operator<<(std::ostream &os, const Data &print);