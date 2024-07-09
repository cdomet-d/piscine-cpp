/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:56:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/09 17:31:09 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::string	user_input;

	getline(std::cin, user_input, '\n');
	Contact	contact_with_name(user_input);
	contact_with_name.display();
	return (0);
}
