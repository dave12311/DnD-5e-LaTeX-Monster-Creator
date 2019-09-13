#ifndef DYNAMICUI_H
#define DYNAMICUI_H

#include <QObject>

class DynamicUI : public QObject{
    Q_OBJECT
public:
    DynamicUI();
protected:
    QList< QList<QObject> > Objects;
};

class Traits : public DynamicUI{
public:
    Traits();
};

#endif // DYNAMICUI_H
