// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GraphicalMonitor.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/14 12:44:12 by ahavrius          #+#    #+#             //
//   Updated: 2019/04/14 12:44:12 by ahavrius         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GRAPHICALMONITOR_HPP
# define GRAPHICALMONITOR_HPP

# include <string>
# include "mlx.h"
# include <fcntl.h>
# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_data;

typedef struct	s_window
{
	int			width;
	int			height;
	int			color;
}				t_window;


class GraphicalMonitor : public IMonitorDisplay
{
private:
    IMonitorModule **_module_discret;
    IMonitorModule **_module_continuous;

	t_data			_data;
	t_window		_window;
    void            _drawString(int x, int y, std::string str, int color);
    void            _drawRect(int x, int y, int x1, int y1, int color);

    static const int       _line_shift  = 20;
    static const int       _line_length = 100;
    static const int       _window_width = 400;
    static const int       _window_height = 1000;

    static const int       _color_text  = 0xf4c26b;
    static const int       _color_plot  = 0x82b1ff;
    static const int       _color_back  = 0;

public:
    GraphicalMonitor();
    ~GraphicalMonitor();
    void    run();
    void    drawDiscret(int *x, int *y, std::string type,
                    std::vector<std::string> value, int color);
    void    drawGraphic(int *x, int *y, std::string type,
                    std::vector<std::string> value, int color);

};

#endif