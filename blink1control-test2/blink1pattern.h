#ifndef BLINK1PATTERN_H
#define BLINK1PATTERN_H

#include <QList>
#include <QVariant>
#include <QVector>
#include <QColor>


class Blink1Pattern
{
public:
    Blink1Pattern();

    QString name;

    QList<QColor> colors;
    QList<float> times;

};

#endif // BLINK1PATTERN_H
