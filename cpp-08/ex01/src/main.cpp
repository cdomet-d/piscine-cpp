/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:07 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/09 17:38:40 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	unsigned int val[] = {5,   979, 506, 397, 52,  266, 899, 355, 687,
						  188, 898, 376, 815, 487, 788, 477, 623, 743,
						  950, 488, 94,	 62,  384, 907, 901, 688, 965,
						  841, 956, 584, 489, 607, 193, 767, 852, 365,
						  270, 127, 193, 790, 833, 617, 615, 352, 623};
	std::vector<unsigned int> fillValues(val, val + sizeof(val) / sizeof(int));
	Span span(std::distance(fillValues.begin(), fillValues.end()));

	std::cout << "Distance between begin and end : "
			  << std::distance(fillValues.begin(), fillValues.end()) << std::endl;

	try {
		std::cout << span << std::endl;
		span.fillSpan(span.getSpanEnd(), fillValues.begin(), fillValues.end());
		std::cout << "longuest | " << span.longestSpan() << std::endl;
		std::cout << "shortest | " << span.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
