#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include "IMonitorModule.hpp"


class Data : public IMonitorModule {
private:

	std::string						_Type;
	std::vector<std::string>		*_result;
	Data(const Data &obj);
	Data &operator=(const Data &obj);
public:

	Data();
	virtual ~Data();

	virtual void							cicle();
	virtual const std::vector<std::string> 	&getResult() const;
	virtual const std::string 				&getType() const;
};

#endif