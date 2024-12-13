/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:58:51 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/14 16:47:05 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Database.hpp"
#include "Input.hpp"

class BitcoinExchange {
  public:
	/*                               ORTHODOX CLASS                           */
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange(void);
	BitcoinExchange &operator=(const BitcoinExchange &copy);

	/*                               METHODS                                  */
	/*                               GETTERS                                  */

	/*                               SETTERS                                  */
  private:
	Database dbase;
	Input input;
};

#endif