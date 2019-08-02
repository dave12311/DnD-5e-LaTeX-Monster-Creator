#include "mainwindow.h"
#include "monster.h"
#include <QApplication>
#include <QObject>
#include "ui_mainwindow.h"

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	MainWindow w;

	//Start main window
	w.show();
	//Disable resize
	//w.setFixedSize(w.size());

	return a.exec();
}
