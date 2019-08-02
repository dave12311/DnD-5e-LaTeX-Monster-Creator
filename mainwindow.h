#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
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

	//Spells
	QList<QHBoxLayout*> innateSpellLayouts;
	QList<QSpinBox*> innateSpellSpinBoxes;
	QList<QWidget*> innateSpellLineEdits;

	QList<QHBoxLayout*> spellLayouts;
	QList<QComboBox*> spellComboBoxes;
	QList<QSpinBox*> spellSpinBoxes;
	QList<QWidget*> spellLineEdits;

public slots:
	//Write text in the GUI
	void writeLatexOut(QString *text);

	//Request input data
	void dataRequested();

	//Spells
	void addInnateSpellSlot();
	void removeInnateSpellSlot(QString text);

	void addSpellSlot();
	void removeSpellSlot(QString text);

signals:
	//Send input data
	void sendListPointer(QList<QString> *list);

private slots:
	void on_monsterInnateSpellcasting_textChanged(const QString &arg1);
	void on_monsterSpellcasting_textChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
