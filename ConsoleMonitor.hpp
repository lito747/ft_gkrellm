// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ConsoleMonitor.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/14 12:43:59 by ahavrius          #+#    #+#             //
//   Updated: 2019/04/14 12:44:01 by ahavrius            ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONSOLEMONITOR_HPP
#define CONSOLEMONITOR_HPP

#include <ncurses.h>

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class ConsoleMonitor : public IMonitorDisplay
{
private:
    IMonitorModule **_module_discret;
    IMonitorModule **_module_continuous;

	WINDOW* _window;

    static const int       _line_shift  = 1;
    static const int       _line_length = 20;
    static const int       _window_width = 50;
    static const int       _window_height = 50;

    static const int       _color_text  = 4;
    static const int       _color_plot  = 5;
    static const int       _color_back  = 10;

    void    _drawString(int x, int y, std::string str, int color);
    void    _drawRect(int x, int y, int x1, int y1,int color);

public:
    ConsoleMonitor();
    ~ConsoleMonitor();
    void    init();
    void    run();
    void    drawDiscret(int *x, int *y, std::string type,
                    std::vector<std::string> value, int color);
    void    drawGraphic(int *x, int *y, std::string type,
                    std::vector<std::string> value, int color);

};




#endif