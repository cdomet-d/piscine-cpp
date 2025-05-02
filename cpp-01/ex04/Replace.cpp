/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:30:12 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:45:48 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>

Replace::Replace() {
	this->needle_prev = 0;
}
Replace::~Replace() {}

bool Replace::checkNeedle() {
	if (needle.empty())
		return (false);
	return (true);
}

void Replace::setNeedle(std::string _needle) {
	this->needle = _needle;
}

void Replace::setBuffer(std::ifstream &_file) {
	this->file << _file.rdbuf();
	this->buffer = this->file.str();
}

void Replace::setRep(std::string _rep) {
	this->rep = _rep;
}

void Replace::setBeg() {
	this->needle_beg = this->buffer.find(
		this->needle, (this->needle_prev + this->rep.length()));
	this->needle_prev = needle_beg;
}

std::string Replace::retNewStr() {
	while (this->needle_beg != std::string::npos) {
		try {
			this->setBeg();
			if (this->needle_beg <= this->buffer.size()) {
				this->buffer.erase(this->needle_beg, this->needle.size());
				this->buffer.insert(this->needle_beg, this->rep);
			}
		} catch (const std::out_of_range &err) {
			std::cout << PINK << "Exception: " << err.what() << END
					  << std::endl;
		}
	}
	return (this->buffer);
}
