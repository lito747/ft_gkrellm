#include "Ponny.hpp"

int Ponny::_tick = 0;

Ponny::Ponny(const Ponny &obj) {
	static_cast<void>(obj);
}
Ponny &Ponny::operator=(const Ponny &obj) {
	static_cast<void>(obj);
	return *this;
}

Ponny::Ponny() : _Type("Ponny"), _result(new std::vector<std::string>), _result1(new std::vector<std::string>), _result2(new std::vector<std::string>) {
	this->_result->push_back("	 ,    ");
	this->_result->push_back("/,`\\     ");
	this->_result->push_back("` | \\____\\ ");
	this->_result->push_back(" _(      ) \\ ");
	this->_result->push_back(" \\-\\~~~_|\\  \\");
	this->_result->push_back("/    \\ `   \\  `" );
	this->_result->push_back("    `     `");

	this->_result1->push_back(",~~_");
	this->_result1->push_back("|/\\ =_ _ ~");
	this->_result1->push_back(" _( )_( )\\~~");
	this->_result1->push_back(" \\,\\  _|\\ \\~~~");
	this->_result1->push_back("    \\`   \\");
	this->_result1->push_back("    `    `");
	this->_result1->push_back("    `     `");

	this->_result2->push_back("((^--__");
	this->_result2->push_back("| /\\  --___ __");
	this->_result2->push_back("   (  /  \\  ) \\");
	this->_result2->push_back("   / |~~~~/  \\  \\");
	this->_result2->push_back(" /    \\ /      \\");
	this->_result2->push_back(" ");
	this->_result2->push_back(" ");
}

Ponny::~Ponny()	{
	delete this->_result;
	delete this->_result1;
	delete this->_result2;
}

void								Ponny::cicle() {}

const	std::vector<std::string> 	&Ponny::getResult() const {
		if (Ponny::_tick % 2 == 0) {
			Ponny::_tick += 1;
			return *(this->_result);
		} else if (Ponny::_tick % 3 == 0) {
		Ponny::_tick += 1;
		return *(this->_result1);
		}
		Ponny::_tick += 1;
		return *(this->_result2);
}
const std::string 					&Ponny::getType() const {
		return this->_Type;
}
