/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:01:06 by cyferrei          #+#    #+#             */
/*   Updated: 2024/09/27 16:38:30 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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