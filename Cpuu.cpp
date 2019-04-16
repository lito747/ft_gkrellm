#include "Cpuu.hpp"


Cpuu::Cpuu(const Cpuu &obj) {
	static_cast<void>(obj);
}
Cpuu &Cpuu::operator=(const Cpuu &obj) {
	static_cast<void>(obj);
	return *this;
}


Cpuu::Cpuu() : _Type("Cpu Usage"), _result(new std::vector<std::string>) {}

Cpuu::~Cpuu()	{
	delete this->_result;
}

void								Cpuu::cicle() {

    std::system( "top -l 1 | grep -E \"^CPU\" > ./tmpcpy" );
    std::ifstream               rifs("./tmpcpy");
    std::string                 rline = "";
    std::vector<std::string>    cpu;
    std::stringstream           res;
    int first = 0;
    int second = 0;

    for(;getline(rifs, rline, ' ');) {
        cpu.push_back(rline);
    }

    rifs.close();
    if (this->_result->size() == 0) {
        for (int i = 0, k = (CIKLE + 2); i < k; ++i){
            this->_result->push_back("0");
        }
    }
    this->_result->at(0) = cpu.at(2);
    this->_result->at(1) = cpu.at(4);

    first = std::atoi(cpu.at(2).c_str());
    second = std::atoi(cpu.at(4).c_str());

    if (this->_result->size() >= (CIKLE + 2)) {
        this->_result->erase(this->_result->begin() + 2);
    }

    res << (first + second);
    this->_result->push_back(res.str());

    std::fstream ofs;
    ofs.open("./tmpcpy", std::ios::out | std::ios::trunc);
    ofs.close();
   
}   

const	std::vector<std::string> 	&Cpuu::getResult() const {
		return *(this->_result);
}
const std::string 					&Cpuu::getType() const {
		return this->_Type;
}

