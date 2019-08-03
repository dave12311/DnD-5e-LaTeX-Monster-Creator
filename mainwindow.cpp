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
	innateSpellLayouts.append(new QHBoxLayout);
	innateSpellSpinBoxes.append(new QSpinBox);
	innateSpellLineEdits.append(new QLineEdit);
	int id = innateSpellLayouts.indexOf(innateSpellLayouts.last());

	//Set properties
	innateSpellSpinBoxes[id]->setToolTip("Spell recharge time in days");

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
	spellLayouts.append(new QHBoxLayout);
	spellComboBoxes.append(new QComboBox);
	spellSpinBoxes.append(new QSpinBox);
	spellLineEdits.append(new QLineEdit);
	int id = spellLayouts.indexOf(spellLayouts.last());

	//Set properties
	QList<QString> comboItems;
	for(int i=0;i<10;i++){
		QString temp = QString::number(i);
		temp.append(". level");

		spellComboBoxes[id]->addItem(temp);
	}

	spellComboBoxes[id]->addItems(comboItems);

	spellComboBoxes[id]->setToolTip("Spell level");
	spellSpinBoxes[id]->setToolTip("Spell slots");

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

void MainWindow::on_monsterInnateSpellcasting_textChanged(const QString &arg1){
	if(arg1 != "" && innateSpellLayouts.count() == 0){
		addInnateSpellSlot();
	}else if(arg1 == ""){
		while(innateSpellLayouts.count() != 0){
			innateSpellLineEdits.last()->deleteLater();
			innateSpellSpinBoxes.last()->deleteLater();
			innateSpellLayouts.last()->deleteLater();

			innateSpellLineEdits.removeLast();
			innateSpellSpinBoxes.removeLast();
			innateSpellLayouts.removeLast();
		}
	}
}

void MainWindow::on_monsterSpellcasting_textChanged(const QString &arg1){
	if(arg1 != "" && spellLayouts.count() == 0){
		addSpellSlot();
    }else if(arg1 == ""){
        while (spellLayouts.count() != 0) {
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
}
