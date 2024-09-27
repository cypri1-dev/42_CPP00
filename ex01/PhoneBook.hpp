/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:34:34 by cyferrei          #+#    #+#             */
/*   Updated: 2024/09/27 16:35:52 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact tabContact[8];
	bool getInput(std::string& input);
	void getContactInfos(std::string *infos);
	void add(void);
	void search(void);
	void displayList(void);
	void exitPhonebook(void);

public:
	void run();
};

#endif