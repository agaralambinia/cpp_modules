/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:16:34 by defimova          #+#    #+#             */
/*   Updated: 2025/01/05 15:16:35 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	command;
	bool		on = true;

	while (on)
	{
		std::cout << "> ";
		std::cin >> command;
		if (std::cin.eof())
			on = false;
		else 
		{
			if (command == "EXIT")
				on = false;
			else if (command == "SEARCH")
				search_contact(&phonebook);
			else if (command == "ADD")
				add(&phonebook);
			else
				print_error();
		}
	}
	return 0;
}
