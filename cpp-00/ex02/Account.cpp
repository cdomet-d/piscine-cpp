/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/23 17:08:34 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts: " << getNbAccounts() << "; "
				<< "total: " << getTotalAmount() << "; "
				<< "deposits: " << getNbDeposits() << "; "
				<< "withdrawals: " << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	this->_nbAccounts += 1;
	this->_totalAmount +=initial_deposit;
	this->_amount = initial_deposit;
	std::cout	<< "index: " << this->_accountIndex << "; "
				<< "amount: " << checkAmount() << "; "
				<< "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index: " << this->_accountIndex << "; "
				<< "amount: " << checkAmount() << "; "
				<< "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
	this->_amount +=deposit;
	this->_nbDeposits +=1;
	std::cout 	<< "index: " << _accountIndex << "; " 
			<< "p_amount: " << (checkAmount() - deposit) << "; "
			<< "deposit: " << deposit << "; "
			<< "amount: " << checkAmount() << "; "
			<< "nb_deposits: " << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal <= checkAmount())
	{	
		_totalNbWithdrawals += 1;
		this->_nbWithdrawals += 1;
		this->_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		std::cout 	<< "index: " << this->_accountIndex << "; " 
					<< "p_amount: " << (checkAmount() + withdrawal) << "; "
					<< "withdrawal: " << withdrawal << "; "
					<< "amount: " << checkAmount() << "; "
					<< "nb_withdrawals: " << this->_nbWithdrawals << std::endl;

		return (true);
	}
	std::cout 	<< "index: " << this->_accountIndex << "; " 
				<< "p_amount: " << checkAmount() << "; "
				<< "withdrawal: refused" << std::endl;
	return (false);
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 	<< "index: " << _accountIndex << "; " 
				<< "amount: " << checkAmount() << "; "
				<< "deposits: " << _nbDeposits << "; "
				<< "withdrawals: " << _nbWithdrawals << std::endl;

	
}

void Account::_displayTimestamp(void)
{
	std::time_t	_rawtime;
	std::tm		*_displayt;
	char		buff[16] = {0};
	
	time(&_rawtime);
	_displayt = localtime(&_rawtime);
	strftime(buff, 16, "%Y%m%d_%H%M%S", _displayt);
	std::cout << "[" << buff << "] ";
	
}
