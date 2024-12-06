/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:07 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/06 16:48:43 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span span(5);
	unsigned int values[] = {5,	  979, 506, 397, 52,  266, 899, 355, 687,
							 188, 898, 376, 815, 487, 788, 477, 623, 743,
							 950, 488, 94,	62,	 384, 907, 901, 688, 965,
							 841, 956, 584, 489, 607, 193, 767, 852, 365,
							 270, 127, 193, 790, 833, 617, 615, 352, 623};

	std::cout << span << std::endl;
	// span.addNumber(10);
	// span.fillSpan(values, span.getSpanBegin(), span.getSpanEnd());
	std::cout << values + sizeof(values) / sizeof(unsigned int) << std::endl;
	std::cout << span << std::endl;
}