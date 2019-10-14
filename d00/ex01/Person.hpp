#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

#define SMALL_BUFF 32
enum {
	first_name, last_name, nickname, login, postal_address, email_address,
	phone_number, birthday_date, favorite_meal, underwear_color, darkest_secret,
	max_list};

class Person
{

public:

	Person();
	~Person();
	int		index_;

	void	setFirstName(std::string const &first_name);
	void	setLastName(std::string const &last_name);
	void	setNickname(std::string const &nickname);
	void	setLogin(std::string const &login);
	void	setPostalAddress(std::string const &postal_address);
	void	setEmailAddress(std::string const &email_address);
	void	setPhoneNumber(std::string const &phone_number);
	void	setBirthdayDate(std::string const &birthday_date);
	void	setFavoriteMeal(std::string const &favorite_meal);
	void	setUnderwearColor(std::string const &underwear_color);
	void	setDarknestSecret(std::string const &darkest_secret);
	void	setFieldByKey(std::string const &ref, size_t key);

	std::string const	&getFirstName() const;
	std::string const	&getLastName() const;
	std::string const	&getNickname() const;
	std::string const	&getLogin() const;
	std::string const	&getPostalAddress() const;
	std::string const	&getEmailAddress() const;
	std::string const	&getPhoneNumber() const;
	std::string const	&getBirthdayDate() const;
	std::string const	&getFavoriteMeal() const;
	std::string const	&getUnderwearColor() const;
	std::string const	&getDarkestSecret() const;
	std::string const	&getFieldByKey(size_t const &key) const;


private:
	std::string		first_name_;
	std::string		last_name_;
	std::string		nickname_;
	std::string		login_;
	std::string		postal_address_;
	std::string		email_address_;
	std::string		phone_number_;
	std::string		birthday_date_;
	std::string		favorite_meal_;
	std::string		underwear_color_;
	std::string		darkest_secret_;
};

#endif
