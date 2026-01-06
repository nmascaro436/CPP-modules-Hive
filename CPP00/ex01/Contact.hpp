#ifndef CONTACT_HPP
#define CONTACT_HPP

#pragma once 
#include <iostream>

class Contact
{
	private:
	std::string _firstName;
	std::string _lastName;
	std::string	_nickname;
	std::string _num;
	std::string _secret;

	public:
	Contact();
	~Contact();

	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getNum();
	std::string getSecret();
	void setFirstName(std::string firstName);
	void setLastName(std::string LastName);
	void setNickname(std::string nickname);
	void setNum(std::string num);
	void setSecret(std::string secret);
};

#endif