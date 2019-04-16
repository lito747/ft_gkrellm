
#include "Cpui.hpp"

Cpui::Cpui(const Cpui &obj) {
	static_cast<void>(obj);
}
Cpui &Cpui::operator=(const Cpui &obj) {
	static_cast<void>(obj);
	return *this;
}

Cpui::Cpui(): _Type("Cpu info"), _result(new std::vector<std::string>) {

	char buf[BUFF_LEN];
	size_t buflen = BUFF_LEN;
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

	std::string tmp = buf;
	this->_result->push_back(tmp.substr(0, tmp.find("M) ") + 2));
	this->_result->push_back(tmp.substr(tmp.find("M) ") + 3, tmp.length()));


	// char buf2[BUFF_LEN];
	// sysctlbyname("machdep.cpu.logical_per_package", &buf2, &buflen, NULL, 0);
	// std::string tmp2 = buf2;
	// tmp2 = buf2;
	// this->_result->push_back(tmp2);

	// char buf3[BUFF_LEN];
	// sysctlbyname("machdep.cpu.cores_per_package", &buf3, &buflen, NULL, 0);
	// std::string tmp3 = buf3;
	// std::cout << tmp3 << std::endl;
	// tmp3 = buf3;
	// this->_result->push_back(tmp3);
}
Cpui::~Cpui()	{
	delete this->_result;
}

void								Cpui::cicle() {}

const	std::vector<std::string> 	&Cpui::getResult() const {
		return *(this->_result);
}
const std::string 					&Cpui::getType() const {
		return this->_Type;
}
	



