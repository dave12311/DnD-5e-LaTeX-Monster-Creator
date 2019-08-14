#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
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
	InputData inputData;

	//Spells
	QList<QHBoxLayout*> innateSpellLayouts;
	QList<QSpinBox*> innateSpellSpinBoxes;
	QList<QLineEdit*> innateSpellLineEdits;
	QMetaObject::Connection addInnateSpellConnect;
	QMetaObject::Connection removeInnateSpellConnect;

	QList<QHBoxLayout*> spellLayouts;
	QList<QComboBox*> spellComboBoxes;
	QList<QSpinBox*> spellSpinBoxes;
	QList<QLineEdit*> spellLineEdits;
	QMetaObject::Connection addSpellConnect;
	QMetaObject::Connection removeSpellConnect;

	//Actions
	QList<QHBoxLayout*> actionLayouts;
	QList<QLineEdit*> actionNames;
	QList<QLineEdit*> actionDescriptions;
	QMetaObject::Connection addActionNameConnect;
	QMetaObject::Connection addActionDescConnect;
	QMetaObject::Connection removeActionNameConnect;
	QMetaObject::Connection removeActionDescConnect;

	//Attacks
	QList<QFormLayout*> attackLayouts;
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
	QList<QFrame*> attackLines;
	QList<QLabel*> attackTypeLabels;
	QList<QLabel*> attackDistanceLabels;
	QList<QLabel*> attackNameLabels;
	QList<QLabel*> attackReachLabels;
	QList<QLabel*> attackRangeLabels;
	QList<QLabel*> attackTargetLabels;
	QList<QLabel*> attackModifierLabels;
	QList<QLabel*> attackDamageLabels;
	QList<QLabel*> attackDamageTypeLabels;
	QList<QLabel*> attackPlusDamageLabels;
	QList<QLabel*> attackPlusDamageTypeLabels;
	QList<QLabel*> attackOrDamageLabels;
	QList<QLabel*> attackOrDamageWhenLabels;
	QList<QLabel*> attackExtraLabels;

	QMetaObject::Connection addAttackConnect;
	QMetaObject::Connection removeAttackConnect;

	void removeLastAttack();
	bool checkLastLineEditEmpty(QList<QLineEdit*> &list);

public slots:
	//UI
	void monsterAction_textChanged(const QString &text);

	//Write text in the GUI
	//TODO: change parameter
	void writeLatexOut(const QString &text);

	void inputDataRequested();

	//Spells
	void addInnateSpellSlot();
	void removeInnateSpellSlot(const QString &text);

	void addSpellSlot();
	void removeSpellSlot(const QString &text);

	//Actions
	void addActionSlot();
	void removeActionSlot();

	//Attacks
	void addAttackSlot();
	void removeAttackSlot();

signals:
	//Send input data
	void sendInputData(InputData *data);

private slots:
	void on_monsterInnateSpellcasting_textChanged(const QString &arg1);
	void on_monsterSpellcasting_textChanged(const QString &arg1);

	void spellComboBoxChange();
	void attackDistanceBoxChange();
};

#endif // MAINWINDOW_H
