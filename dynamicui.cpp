#include "dynamicui.h"
#include <QLayout>
#include <QLineEdit>

DynamicUI::~DynamicUI() {
	//Free Layouts
	for(int i=0; i < Layouts.count(); i++){
		delete Layouts[i];
	}
	Layouts.clear();

	//Free Objects
	for(int i=0; i < Objects.count(); i++){
		for(int j=0; j < Objects[i].count(); j++){
			delete Objects[i][j];
		}
	}
	Objects.clear();
}

Traits::Traits(Ui_MainWindow *uip) : DynamicUI(uip) {
    //Create all objects and layouts
	QList<QObject*> list1, list2;
    auto *layout = new QHBoxLayout;
    auto *name = new QLineEdit;
    auto *description = new QLineEdit;

	//Add objects to layouts
    layout->addWidget(name);
    layout->addWidget(description);

    //Add everything to object variables
    Layouts.append(layout);
	Objects.append(list1);
    Objects[0].append(name);
	Objects.append(list2);
    Objects[1].append(description);

    //Set properties of the first element
    setFirstProperties();
}

void Traits::setProperties() {
    static_cast<QLineEdit*>(Objects[Names].last())->setFont(QFont("Noto Sans", -1, QFont::Bold));
    static_cast<QLineEdit*>(Objects[Descriptions].last())->setFont(QFont("Noto Sans", -1, -1, true));
    static_cast<QHBoxLayout*>(Layouts.last())->setStretch(0,2);
    static_cast<QHBoxLayout*>(Layouts.last())->setStretch(1,5);
}

void Traits::setFirstProperties() {
    setProperties();
    static_cast<QLineEdit*>(Objects[Names].first())->setPlaceholderText("Grappler");
    static_cast<QLineEdit*>(Objects[Descriptions].first())->setPlaceholderText("Foo has advantage on attacks against creatures grappled by it.");
    UI->traits->addLayout(static_cast<QHBoxLayout*>(Layouts.first()));
}
