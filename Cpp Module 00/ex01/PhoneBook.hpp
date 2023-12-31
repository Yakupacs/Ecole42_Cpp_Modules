#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
	public:
		Phonebook(void)
		{
			for (int i = 0; i < 8; i++)
				this->contacts[i] = Contact();
		};
		void	addContact(Contact contact, int index);
		void	printContacts(void);
		void	printContact(int index);
		bool	isEmpty(int index);
};

#endif