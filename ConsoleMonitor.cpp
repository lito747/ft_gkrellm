// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ConsoleMonitor.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/14 12:40:41 by ahavrius          #+#    #+#             //
//   Updated: 2019/04/14 12:40:41 by ahavrius         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ConsoleMonitor.hpp"
#include "OSi.hpp"
#include "Cpui.hpp"
#include "User.hpp"
#include "Data.hpp"
#include "Cpuu.hpp"
#include "Ramu.hpp"
#include "Lan.hpp"
#include "Ponny.hpp"

ConsoleMonitor::ConsoleMonitor()
{
    _module_discret = new IMonitorModule*[6];
    _module_discret[0] = new Cpui();
    _module_discret[1] = new OSi();
    _module_discret[2] = new User();
    _module_discret[3] = new Data();
    _module_discret[4] = new Lan();
    _module_discret[5] = new Ponny();

	_module_continuous = new IMonitorModule*[2];
    _module_continuous[0] = new Cpuu();
    _module_continuous[1] = new Ramu();  
    
	initscr();
	_window = newwin(_window_height, _window_width, 0, 0);
	wattron(_window, A_BOLD);
	wattroff(_window, A_BOLD);
	keypad(_window, true);
	nodelay(_window, true);
	box(_window, 0, 0);
	wrefresh(_window);

	cbreak();
	curs_set(0);
	start_color();
	noecho();
	clear();

    init_pair(10, COLOR_BLACK, COLOR_BLACK);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
}

void    ConsoleMonitor::_drawString(int x, int y, std::string str, int color){

    wattron(_window, COLOR_PAIR(color));
	mvwaddstr(_window, y, x, str.c_str());
	wattroff(_window, COLOR_PAIR(color));
}

ConsoleMonitor::~ConsoleMonitor()
{
    delete [] _module_discret;
    delete [] _module_continuous;
    endwin();
}

void    ConsoleMonitor::drawDiscret(int *x, int *y, std::string type, std::vector<std::string> value, int color){

    _drawString(*x + _line_length/2, *y, type, color);
    *y += _line_shift;
    
    for (std::vector<std::string>::iterator it = value.begin() ; it != value.end(); ++it)
    {
       _drawString(*x + _line_length /3, *y, *it, color );
        *y += _line_shift;
    }
    _drawString(*x, *y, std::string(_window_width - 2, '-'), color );
    *y += _line_shift;  
}

void    ConsoleMonitor::_drawRect(int x, int y, int x1, int y1,int color){
    int shift_x = x1 - x;

    for(int j = y; j < y1; j++)
        _drawString(x, j, std::string(shift_x, '|'), color );
}

void    ConsoleMonitor::drawGraphic(int *x, int *y, std::string type, std::vector<std::string> value, int color){
		std::vector<std::string>::iterator it = value.begin();
        int shift_x = _window_width / 25;
        int shift_y = _window_height / 10;
        float ratio = 0.0;

        _drawString(*x + _line_length/2, *y, type, color );
        *y += _line_shift;
        for ( ; it != value.begin() + 2; ++it)
        {
           _drawString(*x + _line_length/2, *y, *it, color );
            *y += _line_shift;
        }
        *x += _line_shift/3;
        for( ; it != value.end(); ++it)
        {
            ratio = static_cast<float>(shift_y) * (100.0 - std::stof(*it)) / 100.0;
            _drawRect(*x, *y + static_cast<int>(ratio), *x + shift_x, *y + shift_y, color);
            *x += shift_x;
        }
        *x = 1;
        *y += shift_y;
    	_drawString(*x, *y, std::string(_window_width - 2, '-'), color );
        *y += _line_shift;
}

void    ConsoleMonitor::run(){
	int 	key = 0;
	bool	exitGame = false;
    int x;
    int y;

	while(!exitGame) {
		key = wgetch(_window);
		exitGame = key == 'q';
		werase(_window);
        box(_window, 0, 0);

		x = 1;
        y = 1;
        for(int i = 0; i < 6; i++)
        {
            _module_discret[i]->cicle();
            drawDiscret(&x, &y, _module_discret[i]->getType(), _module_discret[i]->getResult(), _color_text);
        }
        for(int i = 0; i < 2; i++)
        {
            _module_continuous[i]->cicle();
            drawGraphic(&x, &y, _module_continuous[i]->getType(), _module_continuous[i]->getResult(), _color_plot);
        }

		wrefresh(_window);
		usleep(1000);
	}

}
