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
