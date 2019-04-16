#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include "IMonitorModule.hpp"

#define MAX_NAME 255

class User : public IMonitorModule {
private:

	std::string						_Type;
	std::vector<std::string>		*_result;
	User(const User &obj);
	User &operator=(const User &obj);
public:

	User();
	virtual ~User();

	virtual void							cicle();
	virtual const std::vector<std::string> 	&getResult() const;
	virtual const std::string 				&getType() const;
};

#endif