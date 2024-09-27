/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:01:06 by cyferrei          #+#    #+#             */
/*   Updated: 2024/09/27 17:39:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cstdio>

Contact::Contact(std::string *infos) 
{
	this->name = infos[NAME];
	this->lastName = infos[LASTNAME];
	this->phoneNumber = infos[PHONENUMBER];
	this->darkestSecret = infos[DARKESTSECRET];
}

bool	Contact::isEmpty()
{
	return (this->name.empty());
}

std::string Contact::cut(std::string param) 
{
	if (param.size() <= 10) {
		while (param.size() < 10)
			param.append(" ");
	} else {
		param.resize(9);
		param.append(".");
	}
	return param;
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
		std::cout << index << "         " << "|";
		std::cout << this->cut(this->name) << "|";
		std::cout << this->cut(this->lastName) << "|";
		std::cout << this->cut(this->phoneNumber) << "|";
		std::cout << std::endl;
	}
}