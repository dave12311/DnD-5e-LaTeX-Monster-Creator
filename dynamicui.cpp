#include "dynamicui.h"
#include <QLayout>
#include <QLineEdit>

void UI_Element::createElement(){

}

void UI_Element::destroyElement(){

}

DynamicUI::DynamicUI(Ui_MainWindow *uip) : UI(uip){
    //Empty constructor
}

void DynamicUI::createUpdateConnections(){
    //Create temporary inner list
    QList<QMetaObject::Connection> tempList;

    const int elementCount = Elements.last()->Objects.count();
    QString className;
    for(int i=0; i < elementCount; i++){
        className = Elements.last()->Objects[i]->metaObject()->className();
        if(className == "QLineEdit"){
            //TODO: Iterate elements and create connections
            //Elements.last()->createConnections.append(connect());
        }
    }
}

Traits::Traits(Ui_MainWindow *uip) : DynamicUI(uip) {
    //Build element
    UI_Element tempElement;

    auto layout = new QHBoxLayout;
    QLineEdit name, desc;
    QList<QObject*> list;

    layout->addWidget(&name);
    layout->addWidget(&desc);

    tempElement.Layout = layout;
    tempElement.Objects = list;
    tempElement.Objects.append(&name);
    tempElement.Objects.append(&desc);

    Elements.append(&tempElement);

    //Set lastIndex
    lastIndex = 0;

	//Set properties of the first element
	setFirstProperties();
}

void Traits::setProperties() {
    static_cast<QLineEdit*>(Elements.last()->Objects.at(Name))->setFont(QFont("Noto Sans", -1, QFont::Bold));
    static_cast<QLineEdit*>(Elements.last()->Objects.at(Description))->setFont(QFont("Noto Sans", -1, -1, true));
    static_cast<QHBoxLayout*>(Elements.last()->Layout)->setStretch(0,2);
    static_cast<QHBoxLayout*>(Elements.last()->Layout)->setStretch(1,5);
}

void Traits::setFirstProperties() {
	setProperties();
    static_cast<QLineEdit*>(Elements.first()->Objects.at(Name))->setPlaceholderText("Grappler");
    static_cast<QLineEdit*>(Elements.first()->Objects.at(Description))->setPlaceholderText(
                "Foo has advantage on attacks against creatures grappled by it.");

    //Add layout to UI
    UI->traits->addLayout(static_cast<QHBoxLayout*>(Elements.first()->Layout));

    //Connect first create segnal
    createUpdateConnections();
}
