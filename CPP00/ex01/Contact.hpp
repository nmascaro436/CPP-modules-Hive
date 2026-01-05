#include <iostream>

class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	std::string num;
	std::string secret;

	public:
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string num,
	std::string secret){
		this->first_name = first_name;
		this->last_name = last_name;
		this->nickname = nickname;
		this->secret = secret;
	}

	public:
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_num();
	std::string get_secret();
};
