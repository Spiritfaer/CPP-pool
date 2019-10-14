#include "Book.hpp"
#include <iostream>
#include <iomanip>

void
Book::usage() const {
	std::cout << "ALLOWED COMMAND - ADD, SEARCH, EXIT" << std::endl;
}

void
Book::initList()
{
	current_ = 0;
	strcpy(list_[first_name], "First name");
	strcpy(list_[last_name], "Last name");
	strcpy(list_[nickname], "Nickname");
	strcpy(list_[login], "Login");
	strcpy(list_[postal_address] ,"Postal address");
	strcpy(list_[email_address] ,"Email address");
	strcpy(list_[phone_number] ,"Phone number");
	strcpy(list_[birthday_date] ,"Birthday date");
	strcpy(list_[favorite_meal] ,"Favorite meal");
	strcpy(list_[underwear_color] ,"Underwear color");
	strcpy(list_[darkest_secret] ,"Darkest secret");
}

void
Book::addPerson() {

	Person		thePeople;
	std::string	buff;

	if (current_ >= MAX) {
		std::cout << FULL_BOOK << std::endl;
		return;
	}
	std::cout << FILLING_FIELD << std::endl;
	for (int i = 0; i < max_list && !std::cin.eof(); ++i) {
		std::cout
			<< i + 1
			<< ". "
			<< list_[i]
			<< std::endl;

		std::getline(std::cin, buff);
		thePeople.setFieldByKey(buff, i);
	}
	book_[current_] = thePeople;
	++current_;
}

void
Book::shortInfo(size_t index) const {
	std::cout
		<< std::setw(10)
		<< index + 1
		<< "|";

	for (int i = 0; i < login; ++i) {
		if (book_[index].getFieldByKey(i).length() > 10) {
			std::cout
				<< std::setw(9)
				<< book_[index].getFieldByKey(i).substr(0,9)
				<< ".";
		}
		else
			std::cout
				<< std::setw(10)
				<< book_[index].getFieldByKey(i);
		std::cout << "|";
	}
	std::cout << std::endl;
}

void Book::searchPerson() const {
	size_t 	index = 0;

	std::cout
		<< std::setw(44)
		<< HEAD
		<< std::endl;

	std::cout
		<< std::setw(10)
		<< "Index"
		<< "|";

	for (int i = 0; i < login; ++i) {
		std::cout
			<< std::setw(10)
			<< list_[i]
			<< "|";
	}
	std::cout << std::endl;
	for (int i = 0; i < current_; ++i) {
		shortInfo(i);
	}
	std::cout
		<< std::setw(44)
		<< CHOSE_INDEX
		<< std::endl;

	std::cin >> index;
	personInfo(index);
}

void Book::personInfo(size_t index) const {

	if (index - 1 >= current_)
		return;
	for(int i = 0; i < max_list; ++i) {
		std::cout
			<< list_[i]
			<< " - "
			<< book_[index - 1].getFieldByKey(i)
			<< std::endl;
	}
}

void	Book::loop() {

	std::string leasing;
	std::cout << SAY_HELLO << std::endl;
	for (int i = 1; i;) {

		std::cout << "-> ";
		std::cin.clear();
		std::getline(std::cin, leasing);
		if (leasing == "ADD")
			addPerson();
		else if (leasing == "SEARCH")
			searchPerson();
		else if (leasing == "EXIT" || std::cin.eof())
			i = 0;
		else
			usage();
	}
	std::cout << SAY_GOODBYE << std::endl;
}
