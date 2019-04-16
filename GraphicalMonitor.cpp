// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GraphicalDisplay.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/14 12:40:20 by ahavrius          #+#    #+#             //
//   Updated: 2019/04/14 12:40:21 by ahavrius         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <string>
//#include <mlx.h>
//# include "mlx.h"
#include <unistd.h>
#include "GraphicalMonitor.hpp"

#include "IMonitorModule.hpp"
#include "OSi.hpp"
#include "Cpui.hpp"
#include "User.hpp"
#include "Data.hpp"
#include "Cpuu.hpp"
#include "Ramu.hpp"
#include "Lan.hpp"
#include "Ponny.hpp"

GraphicalMonitor::GraphicalMonitor(){
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
    
    _window.width = _window_width;
	_window.height = _window_height;
	_window.color = _color_back;
	_data.mlx_ptr = mlx_init();

    char *cstr = new char[11];
    strcpy(cstr, "ft_gkrellm");
	_data.mlx_win = mlx_new_window(_data.mlx_ptr, _window.width, _window.height, cstr);
    delete [] cstr;
}

GraphicalMonitor::~GraphicalMonitor(){
    delete [] _module_discret;
    delete [] _module_continuous;
}

void    GraphicalMonitor::_drawRect(int x, int y, int x1, int y1,int color){
    for(int i = x; i < x1; i++)
        for(int j = y; j < y1; j++)
            mlx_pixel_put(_data.mlx_ptr, _data.mlx_win, i, j, color);
}


void    GraphicalMonitor::_drawString(int x, int y, std::string str, int color){
    char *cstr = new char[str.length() + 1];

    strcpy(cstr, str.c_str());
    mlx_string_put(_data.mlx_ptr, _data.mlx_win, x, y, color, cstr);

    delete [] cstr;
}

void    GraphicalMonitor::drawDiscret(int *x, int *y, std::string type, std::vector<std::string> value, int color){
    _drawString(*x + _line_length, *y, type, color );
    *y += _line_shift;
    
    for (std::vector<std::string>::iterator it = value.begin() ; it != value.end(); ++it)
    {
       _drawString(*x + _line_length/2, *y, *it, color );
        *y += _line_shift;
    } 
    _drawString(*x, *y, std::string(_line_length, '-'), color );
    *y += _line_shift;  
}

void    GraphicalMonitor::drawGraphic(int *x, int *y, std::string type,
                    std::vector<std::string> value, int color)
    {
        std::vector<std::string>::iterator it = value.begin();
        int shift_x = _window_width / 25;
        int shift_y = _window_height / 10;
        float ratio = 0.0;

        _drawString(*x + _line_length, *y, type, color );
        *y += _line_shift;
        for ( ; it != value.begin() + 2; ++it)
        {
           _drawString(*x + _line_length, *y, *it, color );
            *y += _line_shift;
        }
        *x += _line_shift/3;
        for( ; it != value.end(); ++it)
        {
            ratio = static_cast<float>(shift_y) * (100.0 - std::stof(*it)) / 100.0;
            _drawRect(*x, *y + static_cast<int>(ratio), *x + shift_x, *y + shift_y, color);
            *x += shift_x;
        }
        *x = 0;
        *y += shift_y;
        _drawString(*x, *y, std::string(_line_length, '-'), color );
        *y += _line_shift;  

    }


void    GraphicalMonitor::run(){
    int x;
    int y;
    while (1)
    {
        mlx_clear_window(_data.mlx_ptr, _data.mlx_win);
        x = 0;
        y = 0;
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
        mlx_do_sync(_data.mlx_ptr);
    	usleep(100000);
    }
}
