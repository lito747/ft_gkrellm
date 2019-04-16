
#include "User.hpp"


User::User(const User &obj) {
	static_cast<void>(obj);
}
User &User::operator=(const User &obj) {
	static_cast<void>(obj);
	return *this;
}


User::User() : _Type("User"), _result(new std::vector<std::string>) {

	char hostname[MAX_NAME];
	char username[MAX_NAME];
	gethostname(hostname, MAX_NAME);
	getlogin_r(username, MAX_NAME);

	this->_result->push_back(username);
	this->_result->push_back(hostname);
}

User::~User()	{
	delete this->_result;
}

void								User::cicle() {}

const	std::vector<std::string> 	&User::getResult() const {
		return *(this->_result);
}
const std::string 					&User::getType() const {
		return this->_Type;
}
