/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:01:06 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/03 17:07:14 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::fillInfos() 
{
	int i = 0;
	std::string buffer;
	std::string message[5] = {
		"Enter first name 📇: ",
		"Enter last name 👪: ",
		"Enter nickname 😉: ",
		"Enter phone number 📱: ",
		"Enter darkest secret ㊙️: ",
	};
	std::cout << BOLD_ON << message[i] << BOLD_OFF << std::endl;
	std::getline(std::cin, buffer);
	this->firstName = std::string(buffer);
	i++;
	std::cout << BOLD_ON << message[i] << BOLD_OFF << std::endl;
	std::getline(std::cin, buffer);
	this->lastName = std::string(buffer);
	i++;
	std::cout << BOLD_ON << message[i] << BOLD_OFF << std::endl;
	std::getline(std::cin, buffer);
	this->nickname = std::string(buffer);
	i++;
	std::cout << BOLD_ON << message[i] << BOLD_OFF << std::endl;
	std::getline(std::cin, buffer);
	this->phoneNumber = std::string(buffer);
	i++;
	std::cout << BOLD_ON << message[i] << BOLD_OFF << std::endl;
	std::getline(std::cin, buffer);
	this->darkestSecret = std::string(buffer);
}

bool	Contact::isEmpty()
{
	return (this->firstName.empty());
}

std::string Contact::cut(std::string param)
{
	if (param.size() > 10)
	{
		param.resize(9);
		param.append(".");
	}
	else
		while(param.size() < 10)
			param.append(" ");
	return (param);
}

void	Contact::printFullContact(size_t index)
{
	std::cout << "-- Full information at index " << BOLD_ON << index << BOLD_OFF << "--\n" << std::endl;
	std::cout << BOLD_ON << "name 📇: " << BOLD_OFF << this->firstName << std::endl;
	std::cout << BOLD_ON << "last name 👪: " << BOLD_OFF << this->lastName << std::endl;
	std::cout << BOLD_ON << "nickname 😉: " << BOLD_OFF << this->nickname << std::endl;
	std::cout << BOLD_ON << "phone number 📱: " << BOLD_OFF << this->phoneNumber << std::endl;
	std::cout << BOLD_ON << "darkest secret ㊙️: " << BOLD_OFF << this->darkestSecret << std::endl << std::endl;
}

void	Contact::print(size_t index)
{
	if(this->isEmpty())
	{
		printf("          |          |          |          ");
		std::cout << std::endl;
	} 
	else
	{
		std::cout << "         " << index << "|";
		std::cout << cut(this->firstName) << "|";
		std::cout << cut(this->lastName) << "|";
		std::cout << cut(this->nickname) << "|";
		std::cout << std::endl;
	}
}