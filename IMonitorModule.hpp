#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <vector>
#include <string>

class IMonitorModule {
	public:
		virtual ~IMonitorModule() {}

		virtual void							cicle(void) = 0;
		virtual std::vector<std::string> const	&getResult(void) const = 0;
		virtual std::string const				&getType(void) const = 0;
};

#endif