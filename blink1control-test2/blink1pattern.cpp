
#include "blink1pattern.h"

#include <QDebug>

Blink1Pattern::Blink1Pattern( QObject *parent ) : QObject(parent)
 {
    qDebug() << "Created: "; // << QObject::name();
 }

// Blink1Pattern::~Blink1Pattern()
 //{
 //   qDebug() << "Deleted: "; // << name();
 //}

//Blink1Pattern::Blink1Pattern(QString aname)
//{
    //name = aname;
//}


void Blink1Pattern::update()
{
    qDebug() << "update:";
}

void Blink1Pattern::play()
{
    qDebug() << "play:";
}

void Blink1Pattern::stop()
{
    qDebug() << "stop:";
}

