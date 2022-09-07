#ifndef TAGS_H
#define TAGS_H

#include<QString>

constexpr int NUMBER_OF_TAGS = 13;

struct Tag
{
    QString tagName;
    int tagNr;
};

extern Tag tags[NUMBER_OF_TAGS];

#endif // TAGS_H
