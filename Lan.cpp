#include "Lan.hpp"


Lan::Lan(const Lan &obj) {
	static_cast<void>(obj);
}
Lan &Lan::operator=(const Lan &obj) {
	static_cast<void>(obj);
	return *this;
}


Lan::Lan() : _Type("Lan info"), _result(new std::vector<std::string>) {}

Lan::~Lan()	{
	delete this->_result;
}

void								Lan::cicle() {

    std::system( "top -l 1 | grep -E \"^Networks\" > ./Networks" );
    std::ifstream               rifs("./Networks");
    std::string                 rline = "";
    std::vector<std::string>    net;
    std::stringstream           res;


    for(;getline(rifs, rline, ' ');) {
        net.push_back(rline);
    }

    rifs.close();
    if (this->_result->size() == 0) {
        this->_result->push_back(" ");
        this->_result->push_back(" ");
    }
    this->_result->at(0) = net.at(2);
    this->_result->at(1) = net.at(4);

    std::fstream ofs;
    ofs.open("./Networks", std::ios::out | std::ios::trunc);
    ofs.close();
   
}   

const	std::vector<std::string> 	&Lan::getResult() const {
		return *(this->_result);
}
const std::string 					&Lan::getType() const {
		return this->_Type;
}

