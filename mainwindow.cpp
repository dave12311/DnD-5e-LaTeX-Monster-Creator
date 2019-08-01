#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "monsterenum.h"
#include <QObject>

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
		QObject::connect(monster,SIGNAL(requestData()),this,SLOT(dataRequested()));

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
