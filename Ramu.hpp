#ifndef RAMU_HPP
#define RAMU_HPP

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
#define MAX_RAM 8192



class Ramu : public IMonitorModule {
private:

	std::string						_Type;
	std::vector<std::string>		*_result;
	Ramu(const Ramu &obj);
	Ramu &operator=(const Ramu &obj);
public:

	Ramu();
	virtual ~Ramu();

	virtual void							cicle();
	virtual const std::vector<std::string> 	&getResult() const;
	virtual const std::string 				&getType() const;
};

#endif