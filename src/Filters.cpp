#include "Filters.h"

Filters::Filters()
{
    for(int i=0;i<NUMBER_OF_PROPERTIES;i++)
    {
        properties[i]=(-1);
    }

    filter_name[0]="Complexity: ";
    filter_name[1]="Randomness: ";
    filter_name[2]="Interaction: ";
    filter_name[3]="Time: ";
    filter_name[4]="Players: ";
}

void Filters::setFilter(QSlider &slider, QLabel &label)
{
    QString labelText = label.text();
    labelText.chop(1);
    if(slider.value()>=0)
    {
        label.setText(labelText+QString::number(slider.value()));
    }
    else
    {
        label.setText(labelText+"X");
    }

    for(int i=0;i<NUMBER_OF_PROPERTIES;i++)
    {
        if(labelText==filter_name[i])
        {
            properties[i]=slider.value();
        }
    }
}

void Filters::clearFilter(QSlider &slider)
{
    slider.setValue(-1);
}




