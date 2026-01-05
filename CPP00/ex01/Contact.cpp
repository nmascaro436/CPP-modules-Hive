#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string num,
	std::string secret)
{
		this->first_name = first_name;
		this->last_name = last_name;
		this->nickname = nickname;
		this->num = num;
		this->secret = secret;
}
Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	num = "";
	secret = "";
}
std::string Contact::get_first_name()
{
	return first_name;
}

std::string Contact::get_last_name()
{
	return last_name;
}

std::string Contact::get_nickname()
{
	return nickname;
}

std::string Contact::get_num()
{
	return num;
}

std::string Contact::get_secret()
{
	return secret;
}
