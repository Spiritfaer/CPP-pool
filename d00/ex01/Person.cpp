
#include "Person.hpp"

Person::Person(): index_(0) {}
Person::~Person() {}

void
Person::setFirstName(std::string const &first_name) {
	first_name_ = first_name;
}

void
Person::setLastName(std::string const &last_name) {
	last_name_ = last_name;
}

void
Person::setNickname(std::string const &nickname) {
	nickname_ = nickname;
}

void
Person::setLogin(std::string const &login) {
	login_ = login;
}

void
Person::setPostalAddress(std::string const &postal_address) {
	postal_address_ = postal_address;
}

void
Person::setEmailAddress(std::string const &email_address) {
	email_address_ = email_address;
}

void
Person::setPhoneNumber(std::string const &phone_number) {
	phone_number_ = phone_number;
}

void
Person::setBirthdayDate(std::string const &birthday_date) {
	birthday_date_ = birthday_date;
}

void
Person::setFavoriteMeal(std::string const &favorite_meal) {
	favorite_meal_ = favorite_meal;
}

void
Person::setUnderwearColor(std::string const &underwear_color) {
	underwear_color_ = underwear_color;
}

void
Person::setDarknestSecret(std::string const &darkest_secret) {
	darkest_secret_ = darkest_secret;
}

std::string const& Person::getFirstName() const { return first_name_; }
std::string const& Person::getLastName() const { return last_name_; }
std::string const& Person::getNickname() const { return nickname_; }
std::string const& Person::getLogin() const { return login_; }
std::string const& Person::getPostalAddress() const { return postal_address_; }
std::string const& Person::getEmailAddress() const { return email_address_; }
std::string const& Person::getPhoneNumber() const { return phone_number_; }
std::string const& Person::getBirthdayDate() const { return birthday_date_; }
std::string const& Person::getFavoriteMeal() const { return favorite_meal_; }
std::string const& Person::getUnderwearColor() const { return underwear_color_; }
std::string const& Person::getDarkestSecret() const { return darkest_secret_; }

void
Person::setFieldByKey(std::string const &ref, size_t key) {
	switch (key) {
		case first_name:
			setFirstName(ref);
			break;
		case last_name:
			setLastName(ref);
			break;
		case nickname:
			setNickname(ref);
			break;
		case login:
			setLogin(ref);
			break;
		case postal_address:
			setPostalAddress(ref);
			break;
		case email_address:
			setEmailAddress(ref);
			break;
		case phone_number:
			setPhoneNumber(ref);
			break;
		case birthday_date:
			setBirthdayDate(ref);
			break;
		case favorite_meal:
			setFavoriteMeal(ref);
			break;
		case underwear_color:
			setUnderwearColor(ref);
			break;
		case darkest_secret:
			setDarknestSecret(ref);
			break;
		default:
			return;
	}
}

std::string const&
Person::getFieldByKey(size_t const &key) const
{
	switch (key) {
		case first_name:
			return getFirstName();
		case last_name:
			return getLastName();
		case nickname:
			return getNickname();
		case login:
			return getLogin();
		case postal_address:
			return getPostalAddress();
		case email_address:
			return getEmailAddress();
		case phone_number:
			return getPhoneNumber();
		case birthday_date:
			return getBirthdayDate();
		case favorite_meal:
			return getFavoriteMeal();
		case underwear_color:
			return getUnderwearColor();
		case darkest_secret:
			return getDarkestSecret();
		default:
			return getFirstName();
	}
}
