#ifndef DYNAMICUI_H
#define DYNAMICUI_H

#include <QObject>
#include "mainwindow.h"

class DynamicUI : public QObject{
    Q_OBJECT
public:
    DynamicUI(Ui::MainWindow *uip) : UI(uip) {}
protected:
    Ui::MainWindow *UI;

    QList<QObject*> Layouts;
    QList< QList<QObject*> > Objects;

    QList< QList<QMetaObject::Connection> > addConnections, removeConnections;

    virtual void setProperties() = 0;
    virtual void setFirstProperties() = 0;
};

class Traits : public DynamicUI{
public:
    Traits(Ui::MainWindow *uip);
    void setProperties() override;
    void setFirstProperties() override;
private:
        enum objectTypes{Names, Descriptions};
};

#endif // DYNAMICUI_H
