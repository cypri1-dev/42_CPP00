/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:31:50 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/08 17:39:39 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	std::cout << "[fake_time] index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	_nbAccounts++;
}

Account::~Account()
{
	std::cout << "[fake_time] index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" <<std::endl;
	_nbAccounts--;
}

void	Account::displayAccountsInfos( void )
{
	std::cout <<"[fake_time] accounts:" << _nbAccounts 
	<< ";total:" << _totalAmount 
	<< ";deposits:" << _totalNbDeposits 
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void	Account::displayStatus( void ) const
{
	std::cout << "[fake_time] index:" << this->_accountIndex 
	<< ";amount:" << this->_amount 
	<< ";desposits:" << this->_nbDeposits 
	<< ";withdrawals:" << this->_nbWithdrawals <<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	std::cout << "[fake_time] index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit
	<< ";amount:" << this->_amount;
	this->_nbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	(void)withdrawal;
	return(true);
}