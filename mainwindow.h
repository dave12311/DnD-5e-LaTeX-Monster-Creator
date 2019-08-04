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
	QList<QLineEdit*> innateSpellLineEdits;

	QList<QHBoxLayout*> spellLayouts;
	QList<QComboBox*> spellComboBoxes;
	QList<QSpinBox*> spellSpinBoxes;
	QList<QLineEdit*> spellLineEdits;

	//Actions
	QList<QHBoxLayout*> actionLayouts;
	QList<QLineEdit*> actionNames;
	QList<QLineEdit*> actionDescriptions;

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

	//Actions
	void addActionSlot();
	void removeActionSlot();

signals:
	//Send input data
	void sendListPointer(QList<QString> *list);

private slots:
	void on_monsterInnateSpellcasting_textChanged(const QString &arg1);
	void on_monsterSpellcasting_textChanged(const QString &arg1);
	void on_monsterActionName1_textChanged(const QString &arg1);
	void on_monsterActionDesc1_textChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
