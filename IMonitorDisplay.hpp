// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/04/14 12:43:37 by ahavrius          #+#    #+#             //
//   Updated: 2019/04/14 12:43:37 by ahavrius         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP
#include <string>
#include <vector>

class IMonitorDisplay
{
public:
    virtual ~IMonitorDisplay(){}
    virtual void    run() = 0;
    virtual void    drawDiscret(int *x, int *y, std::string type,
                    std::vector<std::string> value, int color) = 0;
    virtual void    drawGraphic(int *x, int *y, std::string type,
                    std::vector<std::string> value, int color) = 0;
};

#endif