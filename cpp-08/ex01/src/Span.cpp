/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 5:07:40 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 11:5:55 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iomanip>

std::ostream &operator<<(std::ostream &os, const Span &print)
{
	os << "Span size: [" << print.getSpanSize() << "] || Elem in span: ["
	   << print.getTrackElem() << "]";
	return os;
}

const char *Span::ElemCountTooHigh::what() const throw()
{
	return "Too many elements in span";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Span::Span(void)
	: longestMax(0), longestMin(0), shortestMax(0), shortestMin(0),
	  trackElem(0), spanSize(0)
{
	span.reserve(0);
}

Span::Span(unsigned int n)
	: longestMax(0), longestMin(0), shortestMax(0), shortestMin(0),
	  trackElem(0), spanSize(n)
{
	span.reserve(n);
}

Span::Span(const Span &rhs)
{
	*this = rhs;
}

Span::~Span(void) {}

Span &Span::operator=(const Span &rhs)
{
	span = rhs.span;
	longestMax = rhs.longestMax;
	longestMin = rhs.longestMin;
	shortestMax = rhs.shortestMax;
	shortestMin = rhs.shortestMin;
	trackElem = rhs.trackElem;
	spanSize = rhs.spanSize;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Span::addNumber(unsigned int n)
{
	if (trackElem >= spanSize)
		throw Span::ElemCountTooHigh();
	span.push_back(n);
	trackElem += 1;
}

void Span::fillSpan(const std::vector< unsigned int >::iterator pos,
					std::vector< unsigned int >::iterator begin,
					std::vector< unsigned int >::iterator end)
{
	if (pos < span.begin() || pos > span.end())
		throw std::out_of_range("pos is out of bounds (pos < span.begin() "
								"|| pos >= span.end())");
	if (begin >= end)
		throw std::out_of_range("range is invalid (begin > end)");
	if (trackElem + std::distance(begin, end) > spanSize)
		throw Span::ElemCountTooHigh();
	span.insert(pos, begin, end);
	trackElem += std::distance(begin, end);
}

unsigned int Span::shortestSpan()
{
	unsigned int current = 0;

	if (span.empty() || trackElem <= 1)
		throw std::length_error(
			"Cannot compare empty or single digit range");
	std::sort(span.begin(), span.end());
	unsigned int shortest = *(span.begin() + 1) - *span.begin();
	shortestMin = *span.begin();
	shortestMax = *(span.begin() + 1);
	for (std::vector< unsigned int >::iterator it = span.begin();
		 it != span.end(); ++it) {
		if (it + 1 != span.end())
			current = *(it + 1) - *it;
		if (current < shortest && current != 0) {
			shortestMin = *it;
			shortestMax = *(it + 1);
			shortest = current;
		}
	}
	std::cout << std::setw(5) << std::left << "between "
			  << std::setw(12) << shortestMin << " and " << std::setw(12)
			  << shortestMax << " | ";
	return shortest;
}

unsigned int Span::longestSpan()
{
	if (span.empty() || trackElem <= 1)
		throw std::length_error(
			"Cannot compare empty or single digit range");
	longestMax = *std::max_element(span.begin(), span.end());
	longestMin = *std::min_element(span.begin(), span.end());
	std::cout << std::setw(5) << std::left << "between "
			  << std::setw(12) << longestMin << " and " << std::setw(12)
			  << longestMax << " | ";
	return longestMax - longestMin;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
unsigned int Span::getTrackElem() const
{
	return trackElem;
}

unsigned int Span::getSpanSize() const
{
	return spanSize;
}

std::vector< unsigned int >::iterator Span::getSpanBegin()
{
	return span.begin();
}
std::vector< unsigned int >::iterator Span::getSpanEnd()
{
	return span.end();
}

void Span::print()
{
	for (std::vector< unsigned int >::iterator it = span.begin();
		 it != span.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
