// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main_viso.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/14 12:36:14 by ahavrius          #+#    #+#             //
//   Updated: 2019/04/14 12:36:15 by ahavrius         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitorDisplay.hpp"
#include "GraphicalMonitor.hpp"
#include "ConsoleMonitor.hpp"

#include <iostream>

int main(int ac, char** av){
    if (ac != 2)
    {
		std::cout << "usage:  " << av[0] << " < console / graphic >" << std::endl;
    	return (0);
    }
    std::string type_monitor(av[1]);
    if (type_monitor != "console" && type_monitor != "graphic")
    {
		std::cout << "usage:  " << av[0] << " < console / graphic >" << std::endl;
    	return (0);
    }
    
    try
    {
        IMonitorDisplay *monitor;
    if (type_monitor == "console")
        monitor = new ConsoleMonitor();
    else
        monitor = new GraphicalMonitor();
    monitor->run();

    delete monitor;
    }
    catch(...){}

    return 0;
}