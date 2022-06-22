#include "Filters.h"

Filters::Filters()
{
    for(int i=0;i<NUMBER_OF_PROPERTIES;i++)
    {
        properties.numericVal.push_back(-1);
    }

    filter_name[0]="Complexity: ";
    filter_name[1]="Randomness: ";
    filter_name[2]="Interaction: ";
    filter_name[3]="Time: ";
    filter_name[4]="Players: ";
}

/*
 * Function reading data from sliders to filters
 */
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
            properties.numericVal[i]=slider.value();
        }
    }
}

/*
 * Function reading data from checkBox to tag filters
 */
void Filters::setTagFilter(std::vector<QCheckBox*>tags)
{
    properties.tags.clear();
    properties.tags.reserve(tags.size());
    for(int i=0;i<tags.size();i++)
    {
        if(tags[i]->checkState())
        {
            properties.tags.emplace_back(true);
        }
        else
        {
            properties.tags.emplace_back(false);
        }
    }
}



int Filters::getFilterValue(int nr)
{
    if(nr<NUMBER_OF_PROPERTIES)
    {
      return properties.numericVal[nr];
    }
    return -1;
}

std::vector<bool>* Filters::getFilterTags()
{
    return &properties.tags;
}

void Filters::clearFilter(QSlider &slider)
{
    slider.setValue(-1);
}

void Filters::clearTagFilter(QCheckBox &checkBox)
{
    checkBox.setChecked(false);
}




