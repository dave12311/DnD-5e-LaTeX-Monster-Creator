#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "monster.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	Monster *monster;
	QList<QString> inputData;

public slots:
	//Write text in the GUI
	void writeLatexOut(QString *text);

	//Request input data
	void dataRequested();

signals:
	//Send input data
	void sendListPointer(QList<QString> *list);
};

#endif // MAINWINDOW_H
