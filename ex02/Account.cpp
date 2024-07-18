/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/18 18:06:41 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	_nbAccounts += 1;
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
	// accounts:8;total:20049;deposits:0;withdrawals:0
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposit:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	// [19920104_091532] index:0;amount:42;created
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "created" << std::endl;
}

Account::~Account(void)
{
}

void Account::makeDeposit(int deposit)
{
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_nbWithdrawals -= 1;
	_amount -= withdrawal;
	return false;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
}

void Account::_displayTimestamp(void)
{
}
