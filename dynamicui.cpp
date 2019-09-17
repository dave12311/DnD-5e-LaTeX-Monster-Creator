#include "dynamicui.h"
#include <QLayout>
#include <QLineEdit>

Traits::Traits(Ui::MainWindow *uip) : DynamicUI(uip) {
    QHBoxLayout *layout = new QHBoxLayout;
    QLineEdit *name = new QLineEdit;
    QLineEdit *description = new QLineEdit;

    Layouts.append(layout);

    Objects.append(*(new QList<QObject*>));
    Objects[0].append(name);
    Objects[0].append(description);

    setFirstProperties();
}

void Traits::setProperties(){

}

void Traits::setFirstProperties(){
    setProperties();

}
