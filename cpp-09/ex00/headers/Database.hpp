/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:42:36 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/16 13:03:28 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <map>
#include <string>

class Database {
  public:
	/*                               ORTHODOX CLASS                           */
	Database(void);
	Database(const std::string &filename);
	Database(const Database &copy);
	~Database(void);
	Database &operator=(const Database &copy);

	/*                               METHODS                                  */

	/*                               GETTERS                                  */
	void print();

	/*                               SETTERS                                  */
  private:
	std::map< std::string, double > database;

	/*                               METHODS                                  */
	bool dateIsValid(const std::string& date);
};

#endif
