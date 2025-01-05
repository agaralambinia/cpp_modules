/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:15:46 by defimova          #+#    #+#             */
/*   Updated: 2025/01/05 15:15:48 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::Contact(const Contact &a)
{
    first_name = a.first_name;
    last_name = a.last_name;
    nickname = a.nickname;
    phone_number = a.phone_number;
    darkest_secret = a.darkest_secret;
}

Contact::~Contact() {}

Contact& Contact::operator=(const Contact &a)
{
    if (this != &a)
	{
        first_name = a.first_name;
        last_name = a.last_name;
        nickname = a.nickname;
        phone_number = a.phone_number;
        darkest_secret = a.darkest_secret;
    }
    return *this;
}

void Contact::set_first_name(const std::string &name)
{
	first_name = name;
}

void Contact::set_last_name(const std::string &name) 
{
    last_name = name;
}

void Contact::set_nickname(const std::string &name) 
{
    nickname = name;
}

void Contact::set_phone_number(const std::string &number) 
{
    phone_number = number;
}

void Contact::set_darkest_secret(const std::string &secret) 
{
    darkest_secret = secret;
}

std::string Contact::get_first_name() const
{
	return (first_name);
}

std::string Contact::get_last_name() const
{
	return (last_name);
}

std::string Contact::get_nickname() const
{
	return (nickname);
}

std::string Contact::get_phone_number() const
{
	return (phone_number);
}

std::string Contact::get_darkest_secret() const
{
	return (darkest_secret);
}

void Contact::print_contact() const
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
