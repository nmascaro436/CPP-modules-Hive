#include <iostream>

class Contact
{
	public:
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	int num;
	std::string secret;

	Contact(std::string first_name, std::string last_name, std::string nickname, int num,
	std::string secret){
		this->first_name = first_name;
		this->last_name = last_name;
		this->nickname = nickname;
		this->secret = secret;
	}
};
