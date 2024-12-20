/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:58:51 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/20 17:03:52 by cdomet-d         ###   ########lyon.fr   */
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

	/*                               INIT                                     */
	void buildMap(const char sep, const std::string &filename);

	/*                               PARSING                                  */
	bool dateIsValid(long lineNo, const std::string &date);
	bool yearIsValid(int year, long lineNo, const char *rest,
					 const std::string &date);
	bool monthIsValid(int month, long lineNo, const char *rest,
					  const std::string &date);
	bool dayIsValid(int year, int month, int day, long lineNo, const char *rest,
					const std::string &date);
	void getValidBitValue(char sep, const std::string &val,
						  const std::string &key, long lineNo);

	/*                               HELPERS                                  */
	bool conversionIsValid(long lineNo, const std::string &date);
	bool isLeapYear(int year, long lineNo, const std::string &date);
	bool restIsValid(const char *rest, char expectedChar, bool acceptWSpace,
					 long lineNo, const std::string &line);
	void trimDate(std::string &date);

	/*                               DISPLAY                                  */

	/**
 * @brief Notifies the user that the map builder has encountered an error by printing the line number,
  the guilty line and what went wrong with it, then returns false.
 *
	Formatting: std::cout << "On line: " << lineNo << ": " + errLine + ": " + err << std::endl;

	Output: On line: 30: 2013-06-31: No such day in that month
 */
	bool pError(const std::string &err, const std::string &errLine,
				long lineNo);
};

#endif