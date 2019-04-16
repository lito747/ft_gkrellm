#ifndef LAN_HPP
#define LAN_HPP

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

class Lan : public IMonitorModule {
private:

	std::string						_Type;
	std::vector<std::string>		*_result;
	Lan(const Lan &obj);
	Lan &operator=(const Lan &obj);
public:

	Lan();
	virtual ~Lan();

	virtual void							cicle();
	virtual const std::vector<std::string> 	&getResult() const;
	virtual const std::string 				&getType() const;
};

#endif