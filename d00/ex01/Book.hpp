#ifndef BOOK_HPP
#define BOOK_HPP

#include "Person.hpp"

#define MAX 8

#define SAY_GOODBYE		"----------* END OF PROGRAM *----------"
#define HEAD			"---------* Your pretty phonebook *---------"
#define CHOSE_INDEX		"\n------* Chose your familiar by index *------"
#define SAY_HELLO		"Hello, and welcome to awesome phonebook\nEnter yor command [ADD, SEARCH, EXIT]"
#define FILLING_FIELD	"Please filling the fields of new contacts:"
#define FULL_BOOK		"Sorry! But your phonebook is full"

class Book
{
public:
	Person	book_[MAX];
	char	list_[max_list][SMALL_BUFF];
	size_t	current_;

	void	addPerson();
	void	searchPerson() const;
	void	personInfo(size_t index) const;
	void	shortInfo(size_t index) const;
	void	initList();
	void	loop();
	void	usage() const;
};

#endif
