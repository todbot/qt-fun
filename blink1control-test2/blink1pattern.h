#ifndef BLINK1PATTERN_H
#define BLINK1PATTERN_H

#include <QObject>
#include <QList>
#include <QColor>


class Blink1Pattern : public QObject
{
    Q_OBJECT

public:
    //Blink1Pattern(QString name);
    Blink1Pattern(QObject *parent=0); //,char *name=0 );
    //~Blink1Pattern();

    void stop();
    void play();
    void update();

    QString name;
    int repeats;
    int playcount;
    int playpos;
    bool playing;

    QList<QColor> colors;
    QList<float> times;

};

#endif // BLINK1PATTERN_H
