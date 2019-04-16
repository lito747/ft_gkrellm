#include "Data.hpp"


Data::Data(const Data &obj) {
	static_cast<void>(obj);
}
Data &Data::operator=(const Data &obj) {
	static_cast<void>(obj);
	return *this;
}


Data::Data() : _Type("Data"), _result(new std::vector<std::string>) {}

Data::~Data()	{
	delete this->_result;
}

void								Data::cicle() {
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d [%X]", &tstruct);
    if (this->_result->size() > 0) {
    	this->_result->pop_back();
    }
    this->_result->push_back(buf);
}

const	std::vector<std::string> 	&Data::getResult() const {
		return *(this->_result);
}
const std::string 					&Data::getType() const {
		return this->_Type;
}
