/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:23:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:45:51 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <sstream>
#include <string>

#define COLOR "\x1B[1;32m"
#define PINK "\x1B[1;31m"
#define END "\033[0m"

class Replace {

  private:
	std::string needle;
	std::string rep;
	std::string buffer;
	std::stringstream file;
	std::size_t needle_beg;
	std::size_t needle_prev;

  public:
	~Replace();
	Replace();
	std::string retNewStr();
	void setBeg();
	void setBuffer(std::ifstream &_file);
	void setNeedle(std::string _needle);
	bool checkNeedle();
	void setRep(std::string _rep);
};

#endif
