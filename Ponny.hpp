
#ifndef PONNY_HPP
#define PONNY_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include "IMonitorModule.hpp"


class Ponny : public IMonitorModule {
private:

	std::string						_Type;
	std::vector<std::string>		*_result;
	std::vector<std::string>		*_result1;
	std::vector<std::string>		*_result2;
	static int _tick;
	Ponny(const Ponny &obj);
	Ponny &operator=(const Ponny &obj);
public:

	Ponny();
	virtual ~Ponny();

	virtual void							cicle();
	virtual const std::vector<std::string> 	&getResult() const;
	virtual const std::string 				&getType() const;
};

#endif