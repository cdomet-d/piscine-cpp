/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:30:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/31 12:26:58 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>

Replace::Replace()
{
	this->needle_prev = 0;
	std::cout << "Instance created" << std::endl << std::endl;
}
Replace::~Replace()
{
	std::cout << "Instance destructed" << std::endl;
}

void Replace::setNeedle(std::string _needle)
{
	this->needle = _needle;
}

void Replace::setBuffer(std::ifstream& _file)
{
	this->file << _file.rdbuf();
	this->buffer = this->file.str();
	
}

void Replace::displayBuffer()
{
	std::cout << this->buffer << std::endl;
}

void Replace::setRep(std::string _rep)
{
	this->rep = _rep;
}

void Replace::setBeg()
{
	this->needle_beg = this->buffer.find(this->needle, (this->needle_prev + this->rep.length()));
	this->needle_prev = needle_beg;

}

std::string Replace::retNewStr()
{
	while (this->needle_beg != std::string::npos)
	{
		try
		{
			this->setBeg();
			if (this->needle_beg <= this->buffer.size())
			{
				std::cout << this->needle_beg << " | " << (this->needle_prev + this->rep.length()) << std::endl;
				// std::cout << this->buffer << std::endl;
				this->buffer.erase(this->needle_beg, this->needle.size());
				// std::cout << this->buffer << std::endl;
				this->buffer.insert(this->needle_beg, this->rep);
				// std::cout << this->buffer << std::endl;
			}
		}
		catch (const std::out_of_range &err)
		{
			std::cerr << "Exception: " << err.what() << std::endl;
		}
	}
	return (this->buffer);
}
