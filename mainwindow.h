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

	//Attacks
	QList<QHBoxLayout*> attackLayouts;
	QList<QComboBox*> attackTypes;
	QList<QComboBox*> attackDistances;
	QList<QLineEdit*> attackNames;
	QList<QLineEdit*> attackReaches;
	QList<QLineEdit*> attackRanges;
	QList<QLineEdit*> attackTargets;
	QList<QLineEdit*> attackModifiers;
	QList<QLineEdit*> attackDamages;
	QList<QComboBox*> attackDamageTypes;
	QList<QLineEdit*> attackPlusDamages;
	QList<QComboBox*> attackPlusDamageTypes;
	QList<QLineEdit*> attackOrDamages;
	QList<QLineEdit*> attackOrDamageWhens;
	QList<QLineEdit*> attackExtras;

public slots:
	//UI
	void monsterAction_textChanged(const QString &text);
	void monsterAttack_textChanged(const QString &text);

	//Write text in the GUI
	//TODO: change parameter
	void writeLatexOut(const QString &text);

	//Request input data
	void dataRequested();

	//Spells
	void addInnateSpellSlot();
	void removeInnateSpellSlot(const QString &text);

	void addSpellSlot();
	void removeSpellSlot(const QString &text);

	//Actions
	void addActionSlot();
	void removeActionSlot();

signals:
	//Send input data
	void sendListPointer(QList<QString> *list);

private slots:
	void on_monsterInnateSpellcasting_textChanged(const QString &arg1);
	void on_monsterSpellcasting_textChanged(const QString &arg1);
	void on_monsterAttackDistance1_currentTextChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
