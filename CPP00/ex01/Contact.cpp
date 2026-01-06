#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact(){}

std::string Contact::getFirstName()
{
	return _firstName;
}

std::string Contact::getLastName()
{
	return _lastName;
}

std::string Contact::getNickname()
{
	return _nickname;
}

std::string Contact::getNum()
{
	return _num;
}

std::string Contact::getSecret()
{
	return _secret;
}
void Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}
void Contact::setLastName(std::string LastName)
{
	this->_lastName = LastName;
}
void Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}
void Contact::setNum(std::string num)
{
	this->_num = num;
}
void Contact::setSecret(std::string secret)
{
	this->_secret = secret;
}
