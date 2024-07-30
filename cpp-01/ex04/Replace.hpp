/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:23:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/30 17:03:56 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <sstream>

class Replace {
	private:
		std::string	needle;
		std::string	rep;
		std::string	buffer;
		std::stringstream file;
		std::size_t	needle_beg;
		std::size_t	needle_prev;
	public:
		Replace();
		~Replace();
		void setNeedle(std::string _needle);
		void setBuffer(std::ifstream& _file);
		void displayBuffer();
		void setRep(std::string _rep);
		void setBeg();
		std::string retNewStr();
};

#endif
