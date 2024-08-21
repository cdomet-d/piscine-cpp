#include "Harl.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:16:59 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/15 18:17:01 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void Harl::debug(void)
{
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-special-ketchup burger. I really do!"
	<< std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]:  cannot believe adding extra bacon costs more money.\
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month."
	<< std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void Harl::complain(std::string level)
{
	void(Harl::*call[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	cmd[4] = {"debug", "info", "warning", "error"};
	size_t	clevel = 4;

	std::cout << "COMPLAIN LEVEL: " << level << std::endl << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (cmd[i].compare(level) == 0)
		{
			clevel = i;
			break;
		}
	}
	switch (clevel)
	{
		case 0:
			(this->*call[0])();
		case 1:
			(this->*call[1])();
		case 2:
			(this->*call[2])();
		case 3:
			(this->*call[3])();
			break;
		default:
			throw std::runtime_error("Instructions unclear");
	}
	return ;
}
