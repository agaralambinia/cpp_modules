/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:16:41 by defimova          #+#    #+#             */
/*   Updated: 2025/01/05 15:16:42 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "PhoneBook.hpp"
# include "Contact.hpp"

void	search_contact(PhoneBook *phonebook);
void	print_error(void);
void	add(PhoneBook *phonebook);

#endif
