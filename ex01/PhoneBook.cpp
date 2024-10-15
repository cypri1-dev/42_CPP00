/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:16:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/11 13:29:53 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <sstream>
#include <string>

int	PhoneBook::stringToInt(std::string& str)
{
	int number;
	std::stringstream ss(str);
	ss >> number;
	return (number);
}

bool	PhoneBook::isValidNumber(std::string index)
{
	int	indexAtoi;
	for(size_t i = 0; i < index.length(); i++)
	{
		if (!std::isdigit(index[i]))
			return (false);
	}
	indexAtoi = stringToInt(index);
	if (indexAtoi >= 0 && indexAtoi <= 7)
	{
		if(!tabContact[indexAtoi].isEmpty())
			return (true);
		else
		{
			std::cout << YELLOW << "No contact found at this index." << RESET << std::endl;
			return (false);
		}
	}
	else
	{
		std::cout << "Index out of range, please enter a number between " << BOLD_ON << YELLOW << "0 and 7" << BOLD_OFF << "." << std::endl;
		return (false);
	}
	return (false); 
}

bool	PhoneBook::getInput(std::string& input)
{
	if (!std::getline(std::cin, input))
	{
		std::cout << BOLD_ON << "\033[31m\nCtrl+D detected\033[0m" << BOLD_OFF << std::endl;
		return(false);
	}
	return (true);
}

#include <iomanip>

void	PhoneBook::displayList()
{
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for(int i = 0; i < 8; i++)
		this->tabContact[i].print(i);
}

void	PhoneBook::search(void)
{
	bool isValid = false;
	std::cout << "\033[2J" << "\033[0;0H";
	this->displayList();
	if (tabContact[0].isEmpty())
	{
		std::cout << "PhoneBook is " << BOLD_ON << YELLOW << "empty" << BOLD_OFF << "! Please enter at least one contact to use index search." << std::endl;
		return;
	}
	else 
	{
		while(!isValid)
		{
			std::string index;
			std::cout << "Enter an " << BOLD_ON << "index" << BOLD_OFF << " :" << std::endl;
			if (!std::getline(std::cin, index))
				break;
			//add protection;
			if (isValidNumber(index))
			{
				isValid = true;
				tabContact[stringToInt(index)].printFullContact(stringToInt(index));
				break;
			}
		}
	}
}

void	PhoneBook::exitPhonebook(void)
{
	std::cout << "\033[2J" << "\033[0;0H";
	std::cout << GREEN << "Closing " << RESET << "Phonebook! 👋" << std::endl;
	exitRequest = true;
}

void	PhoneBook::add(void)
{
	std::cout << "\033[2J" << "\033[0;0H";
	static size_t contact_number = 0;
	this->tabContact[contact_number % 8].fillInfos();
	contact_number++;
}

void	PhoneBook::run()
{
	this->exitRequest = false;
	static const struct
	{
		std::string keyword;
		void (PhoneBook::*func)(void);
	}
	selection[] = 
	{
		{ .keyword = "ADD", .func = &PhoneBook::add},
		{ .keyword = "SEARCH", .func = &PhoneBook::search},
		{ .keyword = "EXIT", .func = &PhoneBook::exitPhonebook},
	};
	
	std::cout << "📇 "<< BOLD_ON << "MyPhoneBook" << BOLD_OFF << " 📇\n\n" << std::endl;
	while(!this->exitRequest)
	{
		std::cout << "Please, choose from the following choices: "
		<< BOLD_ON << "ADD" << BOLD_OFF << " ➕, " << BOLD_ON << "SEARCH" << BOLD_OFF << " 🔍 or " << BOLD_ON << "EXIT" << BOLD_OFF << " 👋: ";
		std::string input;
		if (!getInput(input)) 
			break;
		for (size_t i = 0; i < sizeof(selection) / sizeof(selection[0]); i++) {
			if (input == selection[i].keyword) {
				(this->*selection[i].func)();
				continue;
			}
		}
	}
}
