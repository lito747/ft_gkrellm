#include "OSi.hpp"

OSi::OSi(const OSi &obj) {
	static_cast<void>(obj);
}
OSi &OSi::operator=(const OSi &obj) {
	static_cast<void>(obj);
	return *this;
}

OSi::OSi() : _Type("OS info"), _result(new std::vector<std::string>) {

	struct utsname	uts;
	uname(&uts);

	this->_result->push_back(uts.sysname);
	this->_result->push_back(uts.release);
}

OSi::~OSi()	{
	delete this->_result;
}

void								OSi::cicle() {}

const	std::vector<std::string> 	&OSi::getResult() const {
		return *(this->_result);
}
const std::string 					&OSi::getType() const {
		return this->_Type;
}
