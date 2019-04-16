#ifndef CPUU_HPP
#define CPUU_HPP

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

#define	CIKLE 23



class Cpuu : public IMonitorModule {
private:

	std::string						_Type;
	std::vector<std::string>		*_result;
	Cpuu(const Cpuu &obj);
	Cpuu &operator=(const Cpuu &obj);
public:

	Cpuu();
	virtual ~Cpuu();

	virtual void							cicle();
	virtual const std::vector<std::string> 	&getResult() const;
	virtual const std::string 				&getType() const;
};

#endif