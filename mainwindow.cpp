#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
		ui->setupUi(this);
		monster = new Monster;

		//Connect GUI signals
		connect(ui->monsterActionName1,&QLineEdit::textChanged,this,&MainWindow::monsterAction_textChanged);
		connect(ui->monsterActionDesc1,&QLineEdit::textChanged,this,&MainWindow::monsterAction_textChanged);

		connect(ui->monsterAttackName1,&QLineEdit::textChanged,this,&MainWindow::monsterAttack_textChanged);

		//Connect signals to updateLatex()
		connect(ui->monsterName,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterType,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAC,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterHP,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterSpeed,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterSTR,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterDEX,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterCON,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterINT,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterWIS,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterCHA,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterSavingThrows,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterSkills,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterDamageVulnerabilities,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterDamageResistances,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterDamageImmunities,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterConditionImmunities,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterSenses,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterLanguages,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterChallenge,&QLineEdit::textChanged,monster,&Monster::updateLatex);

		connect(ui->monsterInnateSpellcasting,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterSpellcasting,&QLineEdit::textChanged,monster,&Monster::updateLatex);

		connect(ui->monsterActionName1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterActionDesc1,&QLineEdit::textChanged,monster,&Monster::updateLatex);

		connect(ui->monsterAttackType1,QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);
		connect(ui->monsterAttackDistance1,QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);
		connect(ui->monsterAttackName1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackReach1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackRange1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackTargets1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackModifier1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackDamage1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackDamageType1,QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);
		connect(ui->monsterAttackPlusDamage1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackPlusDamageType1,QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);
		connect(ui->monsterAttackOrDamage1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackOrDamageWhen1,&QLineEdit::textChanged,monster,&Monster::updateLatex);
		connect(ui->monsterAttackExtra1,&QLineEdit::textChanged,monster,&Monster::updateLatex);

		//Request input box data
		connect(monster,&Monster::requestInputData,this,&MainWindow::inputDataRequested);

		//Send input data
		connect(this,&MainWindow::sendInputData,monster,&Monster::receiveInputData);

		//Connect functions to display text in the GUI
		connect(monster,&Monster::sendText,this,&MainWindow::writeLatexOut);

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

void MainWindow::writeLatexOut(const QString &text){
	ui->latexOut->setText(text);
}

void MainWindow::inputDataRequested(){
	//Build inputData
	inputData.clear();

	//Basic Data
	inputData.basicData.append(ui->monsterName->text());
	inputData.basicData.append(ui->monsterType->text());
	inputData.basicData.append(ui->monsterAC->text());
	inputData.basicData.append(ui->monsterHP->text());
	inputData.basicData.append(ui->monsterSpeed->text());
	inputData.basicData.append(ui->monsterSTR->text());
	inputData.basicData.append(ui->monsterDEX->text());
	inputData.basicData.append(ui->monsterCON->text());
	inputData.basicData.append(ui->monsterINT->text());
	inputData.basicData.append(ui->monsterWIS->text());
	inputData.basicData.append(ui->monsterCHA->text());
	inputData.basicData.append(ui->monsterSavingThrows->text());
	inputData.basicData.append(ui->monsterSkills->text());
	inputData.basicData.append(ui->monsterDamageVulnerabilities->text());
	inputData.basicData.append(ui->monsterDamageResistances->text());
	inputData.basicData.append(ui->monsterDamageImmunities->text());
	inputData.basicData.append(ui->monsterConditionImmunities->text());
	inputData.basicData.append(ui->monsterSenses->text());
	inputData.basicData.append(ui->monsterLanguages->text());
	inputData.basicData.append(ui->monsterChallenge->text());

	//Spells
	Spell tmpSpell;
	inputData.innateSpellcasting = ui->monsterInnateSpellcasting->text();
	for(int i = 0; i < innateSpellLayouts.count(); i++){
		tmpSpell.name = innateSpellLineEdits[i]->text();
		tmpSpell.num = innateSpellSpinBoxes[i]->value();

		inputData.innateSpells.append(tmpSpell);
	}

	inputData.spellcasting = ui->monsterSpellcasting->text();
	for(int i = 0; i < spellLayouts.count(); i++){
		tmpSpell.name = spellLineEdits[i]->text();
		tmpSpell.levelIndex = spellComboBoxes[i]->currentIndex();
		tmpSpell.num = spellSpinBoxes[i]->value();

		inputData.spells.append(tmpSpell);
	}

	//Actions
	Action tmpAction;
	tmpAction.name = ui->monsterActionName1->text();
	tmpAction.desc = ui->monsterActionDesc1->text();
	inputData.actions.append(tmpAction);
	for(int i = 0; i < actionLayouts.count(); i++){
		tmpAction.name = actionNames[i]->text();
		tmpAction.desc = actionDescriptions[i]->text();

		inputData.actions.append(tmpAction);
	}

	//Attacks
	Attack tmpAttack;
	tmpAttack.typeIndex = ui->monsterAttackType1->currentIndex();
	tmpAttack.distanceIndex = ui->monsterAttackDistance1->currentIndex();
	tmpAttack.name = ui->monsterAttackName1->text();
	tmpAttack.reach = ui->monsterAttackReach1->text();
	tmpAttack.range = ui->monsterAttackRange1->text();
	tmpAttack.targets = ui->monsterAttackTargets1->text();
	tmpAttack.modifier = ui->monsterAttackModifier1->text();
	tmpAttack.damage = ui->monsterAttackDamage1->text();
	tmpAttack.damageTypeIndex = ui->monsterAttackDamageType1->currentIndex();
	tmpAttack.plusDamage = ui->monsterAttackPlusDamage1->text();
	tmpAttack.plusDamageTypeIndex = ui->monsterAttackPlusDamageType1->currentIndex();
	tmpAttack.orDamage = ui->monsterAttackOrDamage1->text();
	tmpAttack.orDamageWhen = ui->monsterAttackOrDamageWhen1->text();
	tmpAttack.extra = ui->monsterAttackExtra1->text();
	inputData.attacks.append(tmpAttack);
	for(int i = 0; i < attackLayouts.count(); i++){
		tmpAttack.typeIndex = attackTypes[i]->currentIndex();
		tmpAttack.distanceIndex = attackDistances[i]->currentIndex();
		tmpAttack.name = attackNames[i]->text();
		tmpAttack.reach = attackReaches[i]->text();
		tmpAttack.range = attackRanges[i]->text();
		tmpAttack.targets = attackTargets[i]->text();
		tmpAttack.modifier = attackModifiers[i]->text();
		tmpAttack.damage = attackDamages[i]->text();
		tmpAttack.damageTypeIndex = attackTypes[i]->currentIndex();
		tmpAttack.plusDamage = attackPlusDamages[i]->text();
		tmpAttack.plusDamageTypeIndex = attackPlusDamageTypes[i]->currentIndex();
		tmpAttack.orDamage = attackOrDamages[i]->text();
		tmpAttack.orDamageWhen = attackOrDamageWhens[i]->text();
		tmpAttack.extra = attackExtras[i]->text();
		inputData.attacks.append(tmpAttack);
	}

	emit sendInputData(&inputData);
}

void MainWindow::addInnateSpellSlot(){
	//Disconnect sender to prevent spamming
	if(sender()->objectName() != "monsterInnateSpellcasting"){
		sender()->disconnect(addInnateSpellConnect);
	}

	innateSpellLayouts.append(new QHBoxLayout);
	innateSpellSpinBoxes.append(new QSpinBox);
	innateSpellLineEdits.append(new QLineEdit);
	int id = innateSpellLayouts.indexOf(innateSpellLayouts.last());

	//Set properties
	innateSpellSpinBoxes[id]->setToolTip("Spell uses per day");
	innateSpellLineEdits[id]->setToolTip("Spell names");
	innateSpellLineEdits[id]->setClearButtonEnabled(true);

	//Update Latex
	connect(innateSpellLineEdits[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(innateSpellSpinBoxes[id],QOverload<int>::of(&QSpinBox::valueChanged),monster,&Monster::updateLatex);

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
	addInnateSpellConnect = connect(innateSpellLineEdits[id],&QLineEdit::textChanged,this,&MainWindow::addInnateSpellSlot);
	if(id > 1){
		innateSpellLineEdits[id-2]->disconnect(removeInnateSpellConnect);
	}
	if(id > 0){
		removeInnateSpellConnect = connect(innateSpellLineEdits[id-1],&QLineEdit::textChanged,this,&MainWindow::removeInnateSpellSlot);
	}
}

void MainWindow::removeInnateSpellSlot(const QString &text){
	if(text == "" && innateSpellSpinBoxes.last()->value() == 0){
		innateSpellLineEdits.last()->deleteLater();
		innateSpellSpinBoxes.last()->deleteLater();
		innateSpellLayouts.last()->deleteLater();

		innateSpellLineEdits.removeLast();
		innateSpellSpinBoxes.removeLast();
		innateSpellLayouts.removeLast();

		addInnateSpellConnect = connect(innateSpellLineEdits.last(),&QLineEdit::textChanged,this,&MainWindow::addInnateSpellSlot);
		if(innateSpellLineEdits.count() == 1){
			innateSpellLineEdits.last()->disconnect(removeInnateSpellConnect);
		}
		if(innateSpellLineEdits.count() > 1){
			removeInnateSpellConnect = connect(innateSpellLineEdits.at(innateSpellLineEdits.count()-2),&QLineEdit::textChanged,this,&MainWindow::removeInnateSpellSlot);
		}
	}
}

void MainWindow::addSpellSlot(){
	//Disconnect sender to prevent spamming
	if(sender()->objectName() != "monsterSpellcasting"){
		sender()->disconnect(addSpellConnect);
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
	spellSpinBoxes[id]->setToolTip("Available spell slots");
	spellLineEdits[id]->setToolTip("Spell names");

	spellLineEdits[id]->setClearButtonEnabled(true);

	spellSpinBoxes[id]->setVisible(false);

	//Connect Combo Box change
	connect(spellComboBoxes[id],QOverload<int>::of(&QComboBox::currentIndexChanged),this,&MainWindow::spellComboBoxChange);

	//Update Latex
	connect(spellLineEdits[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(spellSpinBoxes[id],QOverload<int>::of(&QSpinBox::valueChanged),monster,&Monster::updateLatex);
	connect(spellComboBoxes[id],QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);

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

	//Setup dynamic UI creation
	addSpellConnect = connect(spellLineEdits[id],&QLineEdit::textChanged,this,&MainWindow::addSpellSlot);
	if(id > 1){
		spellLineEdits[id-2]->disconnect(removeSpellConnect);
	}
	if(id > 0){
		removeSpellConnect = connect(spellLineEdits[id-1],&QLineEdit::textChanged,this,&MainWindow::removeSpellSlot);
	}
}

void MainWindow::removeSpellSlot(const QString &text){
	if(text == "" && spellSpinBoxes.last()->value() == 0 && spellComboBoxes.last()->currentText() == "Cantrip"){
		spellLineEdits.last()->deleteLater();
		spellComboBoxes.last()->deleteLater();
		spellSpinBoxes.last()->deleteLater();
		spellLayouts.last()->deleteLater();

		spellLineEdits.removeLast();
		spellComboBoxes.removeLast();
		spellSpinBoxes.removeLast();
		spellLayouts.removeLast();

		addSpellConnect = connect(spellLineEdits.last(),&QLineEdit::textChanged,this,&MainWindow::addSpellSlot);
		if(spellLineEdits.count() == 1){
			spellLineEdits.last()->disconnect(removeSpellConnect);
		}
		if(spellLineEdits.count() > 1){
			removeSpellConnect = connect(spellLineEdits.at(spellLineEdits.count()-2),&QLineEdit::textChanged,this,&MainWindow::removeSpellSlot);
		}
	}
}

void MainWindow::addActionSlot(){
	//Disconnect sender to prevent spamming
	if(sender()->objectName() != "monsterActionName1" && QObject::sender()->objectName() != "monsterActionDesc1"){
		sender()->disconnect(addActionNameConnect);
		sender()->disconnect(addActionDescConnect);
	}

	actionLayouts.append(new QHBoxLayout);
	actionNames.append(new QLineEdit);
	actionDescriptions.append(new QLineEdit);
	int id = actionLayouts.indexOf(actionLayouts.last());

	//Set properties
	actionNames[id]->setFont(QFont("Noto Sans", -1, QFont::Bold));
	actionDescriptions[id]->setFont(QFont("Noto Sans, -1, -1, true"));

	//Update Latex
	connect(actionNames[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(actionDescriptions[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);

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
	addActionNameConnect = connect(actionNames[id],&QLineEdit::textChanged,this,&MainWindow::addActionSlot);
	addActionDescConnect = connect(actionDescriptions[id],&QLineEdit::textChanged,this,&MainWindow::addActionSlot);
	if(id > 1){
		actionNames[id-2]->disconnect(removeActionNameConnect);
		actionDescriptions[id-2]->disconnect(removeActionDescConnect);
	}
	if(id>0){
		removeActionNameConnect = connect(actionNames[id-1],&QLineEdit::textChanged,this,&MainWindow::removeActionSlot);
		removeActionDescConnect = connect(actionDescriptions[id-1],&QLineEdit::textChanged,this,&MainWindow::removeActionSlot);
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

		addActionNameConnect = connect(actionNames.last(),&QLineEdit::textChanged,this,&MainWindow::addActionSlot);
		addActionDescConnect = connect(actionDescriptions.last(),&QLineEdit::textChanged,this,&MainWindow::addActionSlot);
		if(actionNames.count() == 1){
			actionNames.last()->disconnect(removeActionNameConnect);
			actionDescriptions.last()->disconnect(removeActionDescConnect);
		}
		if(actionNames.count() > 1){
			removeActionNameConnect = connect(actionNames.at(actionNames.count()-2),&QLineEdit::textChanged,this,&MainWindow::removeActionSlot);
			removeActionDescConnect = connect(actionDescriptions.at(actionDescriptions.count()-2),&QLineEdit::textChanged,this,&MainWindow::removeActionSlot);
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

void MainWindow::monsterAction_textChanged(const QString &text){
	if(text != "" && actionLayouts.count() == 0){
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

void MainWindow::monsterAttack_textChanged(const QString &text){
	if(text != "" && attackLayouts.count() == 0){
		addAttackSlot();
	}else if(attackLayouts.count() == 1 && attackNames.last()->text() == "" && attackReaches.last()->text() == "" &&
			 attackRanges.last()->text() == "" && attackTargets.last()->text() == "" && attackModifiers.last()->text() == "" &&
			 attackModifiers.last()->text() == "" && attackDamages.last()->text() == "" && attackPlusDamages.last()->text() == "" &&
			 attackOrDamages.last()->text() == "" && attackOrDamageWhens.last()->text() == "" && attackExtras.last()->text() == ""){
		attackLayouts.last()->deleteLater();

		attackTypes.removeLast();
		attackDistances.removeLast();
		//TODO: etc.
	}
}


void MainWindow::on_monsterAttackDistance1_currentTextChanged(const QString &arg1){
	if(arg1 == "Melee"){
		ui->monsterAttackReach1->setVisible(true);
		ui->label_attackReach1->setVisible(true);
		ui->monsterAttackRange1->setVisible(false);
		ui->label_attackRange1->setVisible(false);
	}else if(arg1 == "Ranged"){
		ui->monsterAttackReach1->setVisible(false);
		ui->label_attackReach1->setVisible(false);
		ui->monsterAttackRange1->setVisible(true);
		ui->label_attackRange1->setVisible(true);
	}else{
		ui->monsterAttackReach1->setVisible(true);
		ui->label_attackReach1->setVisible(true);
		ui->monsterAttackRange1->setVisible(true);
		ui->label_attackRange1->setVisible(true);
	}
}

void MainWindow::spellComboBoxChange(){
	for(int i = 0; i < spellLayouts.count(); i++){
		if(spellComboBoxes[i]->currentIndex() == 0){
			spellSpinBoxes[i]->setVisible(false);
		}else{
			spellSpinBoxes[i]->setValue(0);
			spellSpinBoxes[i]->setVisible(true);
		}
	}
}
