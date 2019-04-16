
#ifndef OSI_HPP
#define OSI_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include "IMonitorModule.hpp"

class OSi : public IMonitorModule {
private:

	std::string						_Type;
	std::vector<std::string>		*_result;
	OSi(const OSi &obj);
	OSi &operator=(const OSi &obj);
public:

	OSi();
	virtual ~OSi();

	virtual void							cicle();
	virtual const std::vector<std::string> 	&getResult() const;
	virtual const std::string 				&getType() const;
	
};

#endif