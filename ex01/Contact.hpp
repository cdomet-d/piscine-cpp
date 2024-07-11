/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:24:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/11 13:58:11 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
#define	CONTACT_HPP
#include <string>

class Contact {
	private:
		size_t		index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact();
		Contact(std::string newContact[5], size_t i);
		void displayContact(void);
		void displayPhonebook(void);
};

#endif