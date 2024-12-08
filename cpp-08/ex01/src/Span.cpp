/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:40 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/09 17:33:36 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Span::Span(void) : trackElem(0), spanSize(0)
{
	span.reserve(0);
}
Span::Span(unsigned int n) : trackElem(0), spanSize(n)
{
	span.reserve(n);
}
Span::Span(const Span &copy)
	: trackElem(copy.trackElem), spanSize(copy.spanSize)
{
	*this = copy;
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &comp)
{
	this->span = comp.span;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Span::addNumber(unsigned int n)
{
	if (trackElem >= spanSize)
		throw std::out_of_range("Too many elements in Span");
	span.push_back(n);
	trackElem += 1;
}
void Span::fillSpan(const std::vector<unsigned int>::iterator pos,
					std::vector<unsigned int>::iterator begin,
					std::vector<unsigned int>::iterator end)
{
	if (pos < span.begin() || pos > span.end())
		throw std::out_of_range("pos is out of bounds");
	if (begin >= end)
		throw std::out_of_range("invalid range");
	if (trackElem + std::distance(begin, end) > spanSize)
		throw std::out_of_range("Too many elements in Span");
	span.insert(pos, begin, end);
	trackElem += std::distance(begin, end);
}

unsigned int Span::shortestSpan()
{
	unsigned int current = 0;

	if (trackElem >= 0 && trackElem <= 1)
		throw std::length_error("Cannot compare empty or single digit range");
	std::sort(span.begin(), span.end());
	unsigned int shortest = *(span.begin() + 1) - *span.begin();
	for (std::vector<unsigned int>::iterator it = span.begin(); it != span.end(); ++it) {
		if (it + 1 != span.end())
			current = *(it + 1) - *it;
		if (current < shortest && current != 0)
			shortest = current;
	}
	return shortest;
}

unsigned int Span::longestSpan()
{
	if (trackElem >= 0 && trackElem <= 1)
		throw std::length_error("Cannot compare empty or single digit range");
	return *std::max_element(span.begin(), span.end()) -
		   *std::min_element(span.begin(), span.end());
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

std::vector<unsigned int>::iterator Span::getSpanBegin()
{
	return span.begin();
}
std::vector<unsigned int>::iterator Span::getSpanEnd()
{
	return span.end();
}

void Span::print()
{
	for (std::vector<unsigned int>::iterator it = span.begin();
		 it != span.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Span &print)
{
	os << "Span size: [" << print.getSpanSize() << "] || Elem in span: ["
	   << print.getTrackElem() << "]";
	return os;
}