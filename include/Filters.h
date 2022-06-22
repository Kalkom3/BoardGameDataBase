#ifndef FILTERS_H
#define FILTERS_H

#include <QWidget>
#include <QSlider>
#include <QString>
#include <QLabel>
#include <vector>
#include <QCheckBox>

#include "PropertiesStruct.h"

constexpr int NUMBER_OF_PROPERTIES = 5;

class Filters
{
public:

    Filters();
    void setFilter(QSlider& slider,QLabel& label);
    void setTagFilter(std::vector<QCheckBox*>tags);
    void clearTagFilter(QCheckBox &checkBox);
    void clearFilter(QSlider &slider);
    int getFilterValue(int nr);
    std::vector<bool>* getFilterTags();

private:
    propertiesStruct properties;
    QString filter_name[NUMBER_OF_PROPERTIES];

};

#endif
