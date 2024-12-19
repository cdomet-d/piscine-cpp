/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:58:51 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/19 16:46:56 by cdomet-d         ###   ########.fr       */
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
	BitcoinExchange(const std::string &database_file,
					const std::string &input_file);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange(void);
	BitcoinExchange &operator=(const BitcoinExchange &copy);

	/*                               METHODS                                  */
	void print();
	void getChangeRate();

	/*                               GETTERS                                  */

	/*                               SETTERS                                  */
  private:
	std::map< std::string, double > database;
	std::map< std::string, double > input;

	/*                               METHODS                                  */
	void buildMap(const char sep, const std::string &filename);
	bool dateIsValid(const std::string &date, long line_count);
	bool yearIsValid(char *remainder, const std::string &date, int year,
					 long line_count);
	bool monthIsValid(char *remainder, const std::string &date, int month,
					  long line_count);
	bool dayIsValid(char *remainder, const std::string &date, int year,
					int month, int day, long line_count);
	void getValidBitValue(char sep, const std::string &val,
						  const std::string &key, long line_count);
	bool printError(const std::string &err, std::string error_line,
					long line_count);
};

#endif