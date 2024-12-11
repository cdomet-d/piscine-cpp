/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:46:29 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/11 16:12:10 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "unitTest.hpp"
#include "Span.hpp"
#include <fstream>
#include <iterator>

static void invalidIterators(Span span, std::vector<unsigned int> src);
static void invalidIntervals(Span span);
static void elemLimits(Span span, std::vector<unsigned int> src);

void errorHandling(Span span, std::vector<unsigned int> src)
{
	std::cout << std::endl << "TESTING INVALID ITERATORS" << std::endl;
	invalidIterators(span, src);
	std::cout << std::endl << "TESTING INVALID INTERVALS" << std::endl;
	invalidIntervals(span);
	std::cout << std::endl << "TESTING ELEM LIMITS" << std::endl;
	elemLimits(span, src);
}

static void invalidIterators(Span span, std::vector<unsigned int> src)
{
	std::cout << "filling Span: begin == end" << std::endl;
	TEST_THROW(span.fillSpan(span.getSpanBegin(), src.begin(), src.begin()),
			   std::out_of_range);
	std::cout << "filling Span: begin > end" << std::endl;
	TEST_THROW(span.fillSpan(span.getSpanBegin(), src.end(), src.begin()),
			   std::out_of_range);
	std::cout << "filling Span: span.begin is invalid" << std::endl;
	TEST_THROW(span.fillSpan(span.getSpanBegin() - 5, src.begin(), src.end()),
			   std::out_of_range);
	std::cout << "filling Span: src greater than span.size()" << std::endl;
	TEST_THROW(span.fillSpan(span.getSpanBegin(), src.begin(), src.end() + 10),
			   Span::ElemCountTooHigh);
}
static void invalidIntervals(Span span)
{
	std::cout << "testing longestSpan on span: " << span << std::endl;
	TEST_THROW(span.longestSpan(), std::length_error);
	std::cout << "testing shortestSpan on span: " << span << std::endl;
	TEST_THROW(span.shortestSpan(), std::length_error);
	std::cout << "adding one number " << span << std::endl;
	span.addNumber(5);
	std::cout << "testing longestSpan on span: " << span << std::endl;
	TEST_THROW(span.longestSpan(), std::length_error);
	std::cout << "testing shortestSpan on span: " << span << std::endl;
	TEST_THROW(span.shortestSpan(), std::length_error);
}

static void elemLimits(Span span, std::vector<unsigned int> src)
{
	try {
		span.fillSpan(span.getSpanBegin(), src.begin(), src.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "filling Span, then adding another number" << std::endl;
	TEST_THROW(span.addNumber(999), Span::ElemCountTooHigh);
	std::cout << "filling Span, then inserting another range" << std::endl;
	TEST_THROW(span.fillSpan(span.getSpanBegin(), src.begin(), src.end()),
			   Span::ElemCountTooHigh);
}

void largeArr(const char *str)
{
	std::ifstream vecInput(str);
	std::vector<unsigned int> src;

	try {
		src.assign(std::istream_iterator<unsigned int>(vecInput),
				   std::istream_iterator<unsigned int>());
		std::cout << src.size() << std::endl;
		Span span(src.size());
		span.fillSpan(span.getSpanBegin(), src.begin(), src.end());
		std::cout << span << std::endl << std::endl;
		std::cout << "longuest | " << span.longestSpan() << std::endl;
		std::cout << "shortest | " << span.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}