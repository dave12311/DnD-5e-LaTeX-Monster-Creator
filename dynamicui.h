#ifndef DYNAMICUI_H
#define DYNAMICUI_H

#include <QObject>
#include "ui_mainwindow.h"

class UI_Element : public QObject {
    Q_OBJECT
public:
    QObject *Layout;
    QList<QObject*> Objects;
    QList<QMetaObject::Connection> createConnections, destroyConnections;
    UI_Element *destroyThis;
public slots:
    void createElement();
    void destroyElement();
};

class DynamicUI : public QObject {
	Q_OBJECT
public:
    DynamicUI(Ui_MainWindow *uip);
protected:
    //Pointer to main UI object
	Ui_MainWindow *UI;

    QList<UI_Element*> Elements;

    //Index of last accessed elements
    int lastIndex;

    //Connect UI element updates to addSlot()
    void createUpdateConnections();

	virtual void setProperties() = 0;
	virtual void setFirstProperties() = 0;
};

class Traits : public DynamicUI {
public:
	Traits(Ui_MainWindow *uip);
	void setProperties() override;
	void setFirstProperties() override;
private:
    enum objectTypes{Name, Description};
};

#endif // DYNAMICUI_H
