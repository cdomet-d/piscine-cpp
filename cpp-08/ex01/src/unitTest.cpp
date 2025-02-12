/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:46:29 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 12:20:15 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unitTest.hpp"
#include "Span.hpp"
#include <fstream>
#include <iomanip>
#include <iterator>

static void invalidIterators(Span &span, std::vector< unsigned int > src);
static void invalidIntervals(Span &span);
static void elemLimits(Span &span, std::vector< unsigned int > src);
static void displayF(Span &span, const std::string &which);

static void displayF(Span &span, const std::string &which)
{
	std::cout << std::setw(35) << std::left << std::setfill('.') << which
			  << span << std::endl;
	std::cout << std::setw(35) << std::left << std::setfill('.') << ".";
	span.print();
}
void errorHandling(Span &span, const std::vector< unsigned int > &src)
{
	std::cout << std::endl << "TESTING INVALID ITERATORS" << std::endl;
	invalidIterators(span, src);
	std::cout << std::endl << "TESTING INVALID INTERVALS" << std::endl;
	invalidIntervals(span);
	std::cout << std::endl << "TESTING ELEM LIMITS" << std::endl;
	elemLimits(span, src);
	std::cout << std::endl << "TESTING DEEP COPY" << std::endl;
}

static void invalidIterators(Span &span, std::vector< unsigned int > src)
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
static void invalidIntervals(Span &span)
{
	std::cout << "testing longestSpan on span: " << span << std::endl;
	TEST_THROW(span.longestSpan(), std::length_error);
	std::cout << "testing shortestSpan on span: " << span << std::endl;
	TEST_THROW(span.shortestSpan(), std::length_error);
	span.addNumber(5);
	std::cout << "added one number " << span << std::endl;
	std::cout << "testing longestSpan on span: " << span << std::endl;
	TEST_THROW(span.longestSpan(), std::length_error);
	std::cout << "testing shortestSpan on span: " << span << std::endl;
	TEST_THROW(span.shortestSpan(), std::length_error);
}

static void elemLimits(Span &span, std::vector< unsigned int > src)
{
	try {
		span.fillSpan(span.getSpanBegin(), src.begin(), src.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "filling Span, then adding another number:\n"
			  << span << std::endl;
	TEST_THROW(span.addNumber(999), Span::ElemCountTooHigh);
	std::cout << "filling Span, then inserting another range:\n"
			  << span << std::endl;
	TEST_THROW(span.fillSpan(span.getSpanBegin(), src.begin(), src.end()),
			   Span::ElemCountTooHigh);
}

void deepCopy(Span &span)
{
	unsigned int smallVal[] = {29, 22, 32, 21, 15};
	std::vector< unsigned int > smallSrc(
		smallVal, smallVal + sizeof(smallVal) / sizeof(unsigned int));
	try {
		Span cpy(span);
		std::cout << "Constructed cpy from original" << std::endl;
		displayF(span, "Original");
		displayF(cpy, "Copy");
		Span smaller(smallSrc.size());
		smaller.fillSpan(smaller.getSpanBegin(), smallSrc.begin(),
						 smallSrc.end());
		std::cout << "--\nConstructed a smaller span from new values"
				  << std::endl;
		displayF(smaller, "Smaller");
		cpy = smaller;
		std::cout << "--\nMade cpy = smaller" << std::endl;
		displayF(cpy, "Copy");
		displayF(smaller, "Smaller");
		std::cout << "--\nDisplaying original is unchanged" << std::endl;
		displayF(span, "Original");

	} catch (std::exception &e) {
		std::cout << std::setw(35) << std::left << std::setfill('.') << e.what()
				  << std::endl;
		return;
	}
}

void largeArr(const char *str)
{
	std::ifstream vecInput(str);
	std::vector< unsigned int > src;

	if (!vecInput.is_open())
		throw std::runtime_error("Couldn't open file");
	try {
		src.assign(std::istream_iterator< unsigned int >(vecInput),
				   std::istream_iterator< unsigned int >());
		if (vecInput.fail() && !vecInput.eof())
			throw std::runtime_error("Unexpected value in file");
		Span span(src.size());
		span.fillSpan(span.getSpanBegin(), src.begin(), src.end());
		std::cout << span << std::endl
				  << std::endl
				  << std::setw(10) << std::left << "longuest"
				  << span.longestSpan() << std::endl
				  << std::setw(10) << std::left << "shortest"
				  << span.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

