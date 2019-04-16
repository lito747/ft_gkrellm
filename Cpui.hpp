
#ifndef CPUI_HPP
#define CPUI_HPP

#define BUFF_LEN 128

#include <iostream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/sysctl.h>
#include "IMonitorModule.hpp"

class Cpui : public IMonitorModule {
private:

	std::string						_Type;
	std::vector<std::string>		*_result;
	Cpui(const Cpui &obj);
	Cpui &operator=(const Cpui &obj);
public:
	Cpui();
	virtual ~Cpui();

	virtual void							cicle();
	virtual const std::vector<std::string> 	&getResult() const;
	virtual const std::string 				&getType() const;
	
};

#endif