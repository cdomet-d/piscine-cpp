/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:58:51 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/13 17:40:46 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
  public:
	/*                               ORTHODOX CLASS                           */
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange(void);
	BitcoinExchange &operator=(const BitcoinExchange &copy);

	/*                               METHODS                                  */
	bool getDatabase(std::string input);
	/*                               GETTERS                                  */

	/*                               SETTERS                                  */
  private:
	std::map<std::string, int> database;
};

#endif