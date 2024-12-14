/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:42:36 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/14 17:33:45 by cdomet-d         ###   ########lyon.fr   */
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
	Database(std::string filename);
	Database(const Database &copy);
	~Database(void);
	Database &operator=(const Database &copy);

	/*                               METHODS                                  */
	bool isDatabaseValid();

	/*                               GETTERS                                  */
	std::map< std::string, int >::iterator getDBBegin();
	std::map< std::string, int >::iterator getDBEnd();
	void print();

	/*                               SETTERS                                  */
  private:
	std::map< std::string, int > database;
};

#endif
