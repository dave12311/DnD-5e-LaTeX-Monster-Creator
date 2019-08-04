#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "monsterenum.h"
#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
		ui->setupUi(this);
		monster = new Monster;

		//Connect editingFinished() signals to updateLatex()
		QObject::connect(ui->monsterName,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterType,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterAC,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterHP,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterSpeed,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterSTR,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterDEX,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterCON,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterINT,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterWIS,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterCHA,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterSavingThrows,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterSkills,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterDamageVulnerabilities,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterDamageResistances,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterDamageImmunities,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterConditionImmunities,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterSenses,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterLanguages,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));
		QObject::connect(ui->monsterChallenge,SIGNAL(editingFinished()),monster,SLOT(updateLatex()));

		//Request input box data
		QObject::connect(monster,SIGNAL(requestListPointer()),this,SLOT(dataRequested()));

		//Send input data
		QObject::connect(this,SIGNAL(sendListPointer(QList<QString>*)),monster,SLOT(receiveListPointer(QList<QString>*)));

		//Connect functions to display text in the GUI
		QObject::connect(monster,SIGNAL(sendText(QString*)),this,SLOT(writeLatexOut(QString*)));

		//Setup default ui
		ui->monsterAttackType1->addItem("Weapon");
		ui->monsterAttackType1->addItem("Spell");

		ui->monsterAttackDistance1->addItem("Melee");
		ui->monsterAttackDistance1->addItem("Ranged");
		ui->monsterAttackDistance1->addItem("Both");
		ui->monsterAttackRange1->setHidden(true);
		ui->label_attackRange1->setHidden(true);

		ui->monsterAttackDamageType1->addItem("Acid");
		ui->monsterAttackDamageType1->addItem("Bludgeoning");
		ui->monsterAttackDamageType1->addItem("Cold");
		ui->monsterAttackDamageType1->addItem("Fire");
		ui->monsterAttackDamageType1->addItem("Force");
		ui->monsterAttackDamageType1->addItem("Lightning");
		ui->monsterAttackDamageType1->addItem("Necrotic");
		ui->monsterAttackDamageType1->addItem("Piercing");
		ui->monsterAttackDamageType1->addItem("Poison");
		ui->monsterAttackDamageType1->addItem("Psychic");
		ui->monsterAttackDamageType1->addItem("Radiant");
		ui->monsterAttackDamageType1->addItem("Slashing");
		ui->monsterAttackDamageType1->addItem("Thunder");

		ui->monsterAttackPlusDamageType1->addItem("Acid");
		ui->monsterAttackPlusDamageType1->addItem("Bludgeoning");
		ui->monsterAttackPlusDamageType1->addItem("Cold");
		ui->monsterAttackPlusDamageType1->addItem("Fire");
		ui->monsterAttackPlusDamageType1->addItem("Force");
		ui->monsterAttackPlusDamageType1->addItem("Lightning");
		ui->monsterAttackPlusDamageType1->addItem("Necrotic");
		ui->monsterAttackPlusDamageType1->addItem("Piercing");
		ui->monsterAttackPlusDamageType1->addItem("Poison");
		ui->monsterAttackPlusDamageType1->addItem("Psychic");
		ui->monsterAttackPlusDamageType1->addItem("Radiant");
		ui->monsterAttackPlusDamageType1->addItem("Slashing");
		ui->monsterAttackPlusDamageType1->addItem("Thunder");
}

MainWindow::~MainWindow(){
	delete ui;
}

void MainWindow::writeLatexOut(QString *text){
	ui->latexOut->setText(*text);
}

void MainWindow::dataRequested(){
	inputData.clear();
	inputData.append(ui->monsterName->text());
	inputData.append(ui->monsterType->text());
	inputData.append(ui->monsterAC->text());
	inputData.append(ui->monsterHP->text());
	inputData.append(ui->monsterSpeed->text());
	inputData.append(ui->monsterSTR->text());
	inputData.append(ui->monsterDEX->text());
	inputData.append(ui->monsterCON->text());
	inputData.append(ui->monsterINT->text());
	inputData.append(ui->monsterWIS->text());
	inputData.append(ui->monsterCHA->text());
	inputData.append(ui->monsterSavingThrows->text());
	inputData.append(ui->monsterSkills->text());
	inputData.append(ui->monsterDamageVulnerabilities->text());
	inputData.append(ui->monsterDamageResistances->text());
	inputData.append(ui->monsterDamageImmunities->text());
	inputData.append(ui->monsterConditionImmunities->text());
	inputData.append(ui->monsterSenses->text());
	inputData.append(ui->monsterLanguages->text());
	inputData.append(ui->monsterChallenge->text());

	emit sendListPointer(&inputData);
}

void MainWindow::addInnateSpellSlot(){
	//Disconnect sender to prevent spamming
	if(QObject::sender()->objectName() != "monsterInnateSpellcasting"){
		QObject::sender()->disconnect();
	}

	innateSpellLayouts.append(new QHBoxLayout);
	innateSpellSpinBoxes.append(new QSpinBox);
	innateSpellLineEdits.append(new QLineEdit);
	int id = innateSpellLayouts.indexOf(innateSpellLayouts.last());

	//Set properties
	innateSpellSpinBoxes[id]->setToolTip("Spell recharge time in days");
	innateSpellLineEdits[id]->setClearButtonEnabled(true);

	//Add new layout
	ui->innateSpellcasting->addLayout(innateSpellLayouts[id]);

	//Add elements
	innateSpellLayouts[id]->addWidget(innateSpellSpinBoxes[id]);
	innateSpellLayouts[id]->addWidget(innateSpellLineEdits[id]);

	//Scroll down
	//Does not work if only called once?
	QCoreApplication::processEvents();
	QCoreApplication::processEvents();
	ui->scrollArea->ensureWidgetVisible(innateSpellLineEdits[id]);

	//Setup dynamic UI creation
	QObject::connect(innateSpellLineEdits[id], SIGNAL(textChanged(QString)), this, SLOT(addInnateSpellSlot()));
	if(id>0){
		innateSpellLineEdits[id-1]->disconnect();
		QObject::connect(innateSpellLineEdits[id-1], SIGNAL(textChanged(QString)), this, SLOT(removeInnateSpellSlot(QString)));
	}

	if(id>1){
		innateSpellLineEdits[id-2]->disconnect();
	}
}

void MainWindow::removeInnateSpellSlot(QString text){
	if(text == ""){
		innateSpellLineEdits.last()->deleteLater();
		innateSpellSpinBoxes.last()->deleteLater();
		innateSpellLayouts.last()->deleteLater();

		innateSpellLineEdits.removeLast();
		innateSpellSpinBoxes.removeLast();
		innateSpellLayouts.removeLast();

		QObject::connect(innateSpellLineEdits.last(), SIGNAL(textChanged(QString)), this, SLOT(addInnateSpellSlot()));
		if(innateSpellLineEdits.count()>1){
			QObject::connect(innateSpellLineEdits.at(innateSpellLineEdits.count()-2), SIGNAL(textChanged(QString)), this, SLOT(removeInnateSpellSlot(QString)));
		}
	}
}

void MainWindow::addSpellSlot(){
	//Disconnect sender to prevent spamming
	if(QObject::sender()->objectName() != "monsterSpellcasting"){
		QObject::sender()->disconnect();
	}

	spellLayouts.append(new QHBoxLayout);
	spellComboBoxes.append(new QComboBox);
	spellSpinBoxes.append(new QSpinBox);
	spellLineEdits.append(new QLineEdit);
	int id = spellLayouts.indexOf(spellLayouts.last());

	//Set properties
	QList<QString> comboItems;
	spellComboBoxes[id]->addItem("Cantrip");
	for(int i=1;i<10;i++){
		QString temp = QString::number(i);
		temp.append(". level");

		spellComboBoxes[id]->addItem(temp);
	}

	spellComboBoxes[id]->addItems(comboItems);

	spellComboBoxes[id]->setToolTip("Spell level");
	spellSpinBoxes[id]->setToolTip("Spell slots");

	spellLineEdits[id]->setClearButtonEnabled(true);

	//Add new layout
	ui->spellcasting->addLayout(spellLayouts[id]);

	//Add elements
	spellLayouts[id]->addWidget(spellComboBoxes[id]);
	spellLayouts[id]->addWidget(spellSpinBoxes[id]);
	spellLayouts[id]->addWidget(spellLineEdits[id]);

	//Scroll down
	//Does not work if only called once?
	QCoreApplication::processEvents();
	QCoreApplication::processEvents();
	ui->scrollArea->ensureWidgetVisible(spellLineEdits[id]);

	//Dynamic UI creation
	QObject::connect(spellLineEdits[id],SIGNAL(textChanged(QString)),this,SLOT(addSpellSlot()));
	if(id>0){
		spellLineEdits[id-1]->disconnect();
		QObject::connect(spellLineEdits[id-1], SIGNAL(textChanged(QString)), this, SLOT(removeSpellSlot(QString)));
	}

	if(id>1){
		spellLineEdits[id-2]->disconnect();
	}
}

void MainWindow::removeSpellSlot(QString text){
	if(text == ""){
		spellLineEdits.last()->deleteLater();
		spellComboBoxes.last()->deleteLater();
		spellSpinBoxes.last()->deleteLater();
		spellLayouts.last()->deleteLater();

		spellLineEdits.removeLast();
		spellComboBoxes.removeLast();
		spellSpinBoxes.removeLast();
		spellLayouts.removeLast();

		QObject::connect(spellLineEdits.last(), SIGNAL(textChanged(QString)), this, SLOT(addSpellSlot()));
		if(spellLineEdits.count()>1){
			QObject::connect(spellLineEdits.at(spellLineEdits.count()-2), SIGNAL(textChanged(QString)), this, SLOT(removeSpellSlot(QString)));
		}
	}
}

void MainWindow::addActionSlot(){
	//Disconnect sender to prevent spamming
	if(QObject::sender()->objectName() != "monsterActionName1" && QObject::sender()->objectName() != "monsterActionDesc1"){
		QObject::sender()->disconnect();
	}

	actionLayouts.append(new QHBoxLayout);
	actionNames.append(new QLineEdit);
	actionDescriptions.append(new QLineEdit);
	int id = actionLayouts.indexOf(actionLayouts.last());

	//Set properties
	actionNames[id]->setFont(QFont("Noto Sans", -1, QFont::Bold));
	actionDescriptions[id]->setFont(QFont("Noto Sans, -1, -1, true"));

	//Add new layout
	ui->actions->addLayout(actionLayouts[id]);

	//Add elements
	actionLayouts[id]->addWidget(actionNames[id]);
	actionLayouts[id]->addWidget(actionDescriptions[id]);

	//Set stretch
	actionLayouts[id]->setStretch(0, 2);
	actionLayouts[id]->setStretch(1, 5);

	//Scroll down
	//Does not work if only called once?
	QCoreApplication::processEvents();
	QCoreApplication::processEvents();
	ui->scrollArea->ensureWidgetVisible(actionNames[id]);

	//Dynamic UI creation
	QObject::connect(actionNames[id],SIGNAL(textChanged(QString)),this,SLOT(addActionSlot()));
	QObject::connect(actionDescriptions[id],SIGNAL(textChanged(QString)),this,SLOT(addActionSlot()));
	if(id>0){
		actionNames[id-1]->disconnect();
		actionDescriptions[id-1]->disconnect();
		QObject::connect(actionNames[id-1],SIGNAL(textChanged(QString)),this,SLOT(removeActionSlot()));
		QObject::connect(actionDescriptions[id-1],SIGNAL(textChanged(QString)),this,SLOT(removeActionSlot()));
	}

	if(id>1){
		actionNames[id-2]->disconnect();
		actionDescriptions[id-2]->disconnect();
	}
}

void MainWindow::removeActionSlot(){
	if(actionNames.at(actionNames.count()-2)->text() == "" && actionDescriptions.at(actionDescriptions.count()-2)->text() == ""){
		actionNames.last()->deleteLater();
		actionDescriptions.last()->deleteLater();
		actionLayouts.last()->deleteLater();

		actionNames.removeLast();
		actionDescriptions.removeLast();
		actionLayouts.removeLast();

		QObject::connect(actionNames.last(), SIGNAL(textChanged(QString)), this, SLOT(addActionSlot()));
		QObject::connect(actionDescriptions.last(),SIGNAL(textChanged(QString)),this,SLOT(addActionSlot()));
		if(actionNames.count()>1){
			QObject::connect(actionNames.at(actionNames.count()-2), SIGNAL(textChanged(QString)), this, SLOT(removeActionSlot()));
			QObject::connect(actionDescriptions.at(actionDescriptions.count()-2), SIGNAL(textChanged(QString)), this, SLOT(removeActionSlot()));
		}
	}
}

void MainWindow::on_monsterInnateSpellcasting_textChanged(const QString &arg1){
	if(arg1 != "" && innateSpellLayouts.count() == 0){
		addInnateSpellSlot();
	}else if(arg1 == "" && innateSpellLayouts.count() == 1 && innateSpellLineEdits.last()->text() == "" && innateSpellSpinBoxes.last()->value() == 0){
		innateSpellLineEdits.last()->deleteLater();
		innateSpellSpinBoxes.last()->deleteLater();
		innateSpellLayouts.last()->deleteLater();

		innateSpellLineEdits.removeLast();
		innateSpellSpinBoxes.removeLast();
		innateSpellLayouts.removeLast();
	}
}

void MainWindow::on_monsterSpellcasting_textChanged(const QString &arg1){
	if(arg1 != "" && spellLayouts.count() == 0){
		addSpellSlot();
	}else if(arg1 == "" && spellLayouts.count() == 1 && spellLineEdits.last()->text() == "" &&
			 spellSpinBoxes.last()->value() == 0 && spellComboBoxes.last()->currentText() == "Cantrip"){
		spellLineEdits.last()->deleteLater();
		spellComboBoxes.last()->deleteLater();
		spellSpinBoxes.last()->deleteLater();
		spellLayouts.last()->deleteLater();

		spellLineEdits.removeLast();
		spellComboBoxes.removeLast();
		spellSpinBoxes.removeLast();
		spellLayouts.removeLast();
	}
}

void MainWindow::on_monsterActionName1_textChanged(const QString &arg1){
	if(arg1 != "" && actionLayouts.count() == 0){
		addActionSlot();
	}else if(actionLayouts.count() == 1 && actionNames.last()->text() == "" && actionDescriptions.last()->text() == "" &&
			 ui->monsterActionName1->text() == "" && ui->monsterActionDesc1->text() == ""){
		actionNames.last()->deleteLater();
		actionDescriptions.last()->deleteLater();
		actionLayouts.last()->deleteLater();

		actionNames.removeLast();
		actionDescriptions.removeLast();
		actionLayouts.removeLast();
	}
}

void MainWindow::on_monsterActionDesc1_textChanged(const QString &arg1){
	if(arg1 != "" && actionLayouts.count() == 0){
		addActionSlot();
	}else if(actionLayouts.count() == 1 && actionNames.last()->text() == "" && actionDescriptions.last()->text() == "" &&
			 ui->monsterActionName1->text() == "" && ui->monsterActionDesc1->text() == ""){
		actionNames.last()->deleteLater();
		actionDescriptions.last()->deleteLater();
		actionLayouts.last()->deleteLater();

		actionNames.removeLast();
		actionDescriptions.removeLast();
		actionLayouts.removeLast();
	}
}
