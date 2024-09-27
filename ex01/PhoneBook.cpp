/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:16:41 by cyferrei          #+#    #+#             */
/*   Updated: 2024/09/27 17:36:15 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <string>

bool	PhoneBook::getInput(std::string& input)
{
	if (!std::getline(std::cin, input))
	{
		std::cout << "\033[31m\nCtrl+D detected\033[0m" << std::endl;
		return(false);
	}
	return (true);
}

void	PhoneBook::getContactInfos(std::string *infos)
{
	std::string message[4] = {
		"Enter name: ",
		"Enter last name: ",
		"etc",
		"etc",
	};
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << message[i] << std::endl;
		std::string buffer;
		// this->getInput(buffer);
		if(!this->getInput(buffer))
			exit(EXIT_FAILURE);
		infos[i] = std::string(buffer);
	}

}

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
	this->displayList();
}

void	PhoneBook::exitPhonebook(void)
{
	std::cout << "Exiting Phonebook!" << std::endl;
	exit(EXIT_SUCCESS);
}

void	PhoneBook::add(void)
{
	std::string infos[4];
	this->getContactInfos(infos);
	static size_t contact_number = 0;
	this->tabContact[contact_number % 8] = Contact(infos);
	contact_number++;
}

void	PhoneBook::run()
{
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
	
	std::cout << "-- My PhoneBook --\n\n" << std::endl;
	while(true)
	{
		std::cout << "Please, choose from the following choices: ADD, SEARCH or EXIT : ";
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