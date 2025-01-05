#include "main.hpp"

void	search_contact(PhoneBook *phonebook)
{
	int index = 0;

	phonebook->print_phonebook();
	std::cout << "Enter index: ";
	if (!(std::cin >> index))
	{
		std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else if (index >= 0 && index <= (phonebook->get_contact_cnt()))
	{
		phonebook->get_contact(index).print_contact();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		std::cout << "Invalid index" << std::endl;	
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

std::string get_input(std::string message)
{
	std::string input = "";

	while (input.length() == 0)
	{
		std::cout << message;
		std::getline(std::cin, input);
	}
	return (input);
}

void	add(PhoneBook *phonebook)
{
	Contact	to_add;

	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	to_add.set_first_name(get_input("Enter first name: "));
	to_add.set_last_name(get_input("Enter last name: "));
	to_add.set_nickname(get_input("Enter nickname: "));
	to_add.set_phone_number(get_input("Enter phone number: "));
	to_add.set_darkest_secret(get_input("Enter darkest secret: "));
	phonebook->add_contact(to_add);
}

void	print_error(void)
{
	std::cout << "Incorrect command input! Must be one of: ADD SEARCH EXIT" << std::endl;
}
