/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/22 18:06:40 by cdomet-d         ###   ########lyon.fr   */
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
	std::cout	<< "accounts: " << getNbAccounts() << "; "
				<< "total: " << getTotalAmount() << "; "
				<< "deposit: " << getNbDeposits() << "; "
				<< "withdrawals: " << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	// [19920104_091532] index:0;amount:42;created
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount +=initial_deposit;
	_amount = initial_deposit;
	std::cout	<< "index: " << _accountIndex << "; "
				<< "amount: " << _amount << "; "
				<< "created" << std::endl;
}

Account::~Account(void)
{
	std::cout	<< "index: " << _accountIndex << "; "
				<< "amount: " << _amount << "; "
				<< "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_amount +=deposit;
	_nbDeposits +=1;
	std::cout 	<< "index: " << _accountIndex << "; " 
			<< "p_amount: " << (_amount - deposit) << "; "
			<< "deposit: " << deposit << "; "
			<< "amount: " << _amount << "; "
			<< "nb_deposits: " << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= _amount)
	{	
		// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
		_totalNbWithdrawals += 1;
		_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		std::cout 	<< "index: " << _accountIndex << "; " 
					<< "p_amount: " << (_amount + withdrawal) << "; "
					<< "withdrawal: " << withdrawal << "; "
					<< "amount: " << _amount << "; "
					<< "nb_withdrawals: " << _nbWithdrawals << std::endl;

		return (true);
	}
	// [19920104_091532] index:0;p_amount:47;withdrawal:refused
	std::cout 	<< "index: " << _accountIndex << "; " 
				<< "p_amount: " << _amount << "; "
				<< "withdrawal: refused;" << std::endl;
	return (false);
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout 	<< "index: " << _accountIndex << "; " 
				<< "amount: " << _amount << "; "
				<< "deposits: " << _nbDeposits << "; "
				<< "withdrawals: " << _nbWithdrawals << std::endl;

	
}

void Account::_displayTimestamp(void)
{
}
