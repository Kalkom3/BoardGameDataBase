#ifndef FILTERS_H
#define FILTERS_H

#include <QWidget>
#include <QSlider>
#include <QString>
#include <QLabel>
#include <vector>

#define NUMBER_OF_PROPERTIES 5

class Filters
{
public:

    Filters();
    void setFilter(QSlider &slider,QLabel &label);
    void clearFilter(QSlider &slider);
    int properties[NUMBER_OF_PROPERTIES];
    QString filter_name[NUMBER_OF_PROPERTIES];

};

#endif
