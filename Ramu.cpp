
#include "Ramu.hpp"

Ramu::Ramu(const Ramu &obj) {
	static_cast<void>(obj);
}
Ramu &Ramu::operator=(const Ramu &obj) {
	static_cast<void>(obj);
	return *this;
}

Ramu::Ramu() : _Type("Ram usage"), _result(new std::vector<std::string>) {}

Ramu::~Ramu()	{
	delete this->_result;
}

void								Ramu::cicle() {

    std::system( "top -l 1 | grep -E \"^Phys\" > ./tmpram" );
    std::ifstream               rifs("./tmpram");
    std::string                 rline = "";
    std::vector<std::string>    ram;
    std::stringstream           res;
    int first = 0;
    double pr = 0;
   

    for(;getline(rifs, rline, ' ');) {
        ram.push_back(rline);
    }
    if (this->_result->size() == 0) {
        this->_result->push_back("8192M");
        for (int i = 1, k = (CIKLE + 2); i < k; ++i){
            this->_result->push_back("0");
        }
    }
    rifs.close();
     this->_result->at(1) = ram.at(1);


     first = std::atoi(ram.at(1).c_str());

     pr = (static_cast<double>(first) /  8192) * 100;
    if (this->_result->size() >= (CIKLE + 2)) {
        this->_result->erase(this->_result->begin() + 2);
    }

     res << static_cast<int>(pr);
     this->_result->push_back(res.str());

    std::fstream ofs;
    ofs.open("./tmpram", std::ios::out | std::ios::trunc);
    ofs.close();
}


const	std::vector<std::string> 	&Ramu::getResult() const {
		return *(this->_result);
}
const std::string 					&Ramu::getType() const {
		return this->_Type;
}
