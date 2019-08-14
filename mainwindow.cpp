#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QSpinBox>
#include <QLine>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
		ui->setupUi(this);
		monster = new Monster;
        addAttackSlot();

		//Connect GUI signals
		connect(ui->monsterActionName1,&QLineEdit::textChanged,this,&MainWindow::monsterAction_textChanged);
		connect(ui->monsterActionDesc1,&QLineEdit::textChanged,this,&MainWindow::monsterAction_textChanged);

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

		//Request input box data
		connect(monster,&Monster::requestInputData,this,&MainWindow::inputDataRequested);

		//Send input data
		connect(this,&MainWindow::sendInputData,monster,&Monster::receiveInputData);

		//Connect functions to display text in the GUI
		connect(monster,&Monster::sendText,this,&MainWindow::writeLatexOut);
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
	if(sender()->objectName() != "monsterActionName1" && sender()->objectName() != "monsterActionDesc1"){
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

void MainWindow::addAttackSlot(){
	//Disconnect sender to prevent spamming
    if(attackNames.count() > 0){
        attackNames[attackNames.count()-1]->disconnect(addAttackConnect);
    }

	attackLayouts.append(new QFormLayout);
	attackTypes.append(new QComboBox);
	attackDistances.append(new QComboBox);
	attackNames.append(new QLineEdit);
	attackReaches.append(new QLineEdit);
	attackRanges.append(new QLineEdit);
	attackTargets.append(new QLineEdit);
	attackModifiers.append(new QLineEdit);
	attackDamages.append(new QLineEdit);
	attackDamageTypes.append(new QComboBox);
	attackPlusDamages.append(new QLineEdit);
	attackPlusDamageTypes.append(new QComboBox);
	attackOrDamages.append(new QLineEdit);
	attackOrDamageWhens.append(new QLineEdit);
	attackExtras.append(new QLineEdit);
	attackTypeLabels.append(new QLabel);
	attackDistanceLabels.append(new QLabel);
	attackNameLabels.append(new QLabel);
	attackReachLabels.append(new QLabel);
	attackRangeLabels.append(new QLabel);
	attackTargetLabels.append(new QLabel);
	attackModifierLabels.append(new QLabel);
	attackDamageLabels.append(new QLabel);
	attackDamageTypeLabels.append(new QLabel);
	attackPlusDamageLabels.append(new QLabel);
	attackPlusDamageTypeLabels.append(new QLabel);
	attackOrDamageLabels.append(new QLabel);
	attackOrDamageWhenLabels.append(new QLabel);
	attackExtraLabels.append(new QLabel);
	attackLines.append(new QFrame);
	int id = attackLayouts.indexOf(attackLayouts.last());

	//Set properties
	attackTypes[id]->addItem("Weapon");
	attackTypes[id]->addItem("Spell");

	attackDistances[id]->addItem("Melee");
	attackDistances[id]->addItem("Ranged");
	attackDistances[id]->addItem("Both");

	attackDamageTypes[id]->addItem("Acid");
	attackDamageTypes[id]->addItem("Bludgeoning");
	attackDamageTypes[id]->addItem("Cold");
	attackDamageTypes[id]->addItem("Fire");
	attackDamageTypes[id]->addItem("Force");
	attackDamageTypes[id]->addItem("Lightning");
	attackDamageTypes[id]->addItem("Necrotic");
	attackDamageTypes[id]->addItem("Piercing");
	attackDamageTypes[id]->addItem("Poison");
	attackDamageTypes[id]->addItem("Psychic");
	attackDamageTypes[id]->addItem("Radiant");
	attackDamageTypes[id]->addItem("Slashing");
	attackDamageTypes[id]->addItem("Thunder");

	attackPlusDamageTypes[id]->addItem("Acid");
	attackPlusDamageTypes[id]->addItem("Bludgeoning");
	attackPlusDamageTypes[id]->addItem("Cold");
	attackPlusDamageTypes[id]->addItem("Fire");
	attackPlusDamageTypes[id]->addItem("Force");
	attackPlusDamageTypes[id]->addItem("Lightning");
	attackPlusDamageTypes[id]->addItem("Necrotic");
	attackPlusDamageTypes[id]->addItem("Piercing");
	attackPlusDamageTypes[id]->addItem("Poison");
	attackPlusDamageTypes[id]->addItem("Psychic");
	attackPlusDamageTypes[id]->addItem("Radiant");
	attackPlusDamageTypes[id]->addItem("Slashing");
	attackPlusDamageTypes[id]->addItem("Thunder");

	attackLines[id]->setFrameShape(QFrame::HLine);
	attackLines[id]->setFrameShadow(QFrame::Sunken);

	attackTypeLabels[id]->setText("Attack Type");
	attackDistanceLabels[id]->setText("Distance");
	attackNameLabels[id]->setText("Name");
	attackReachLabels[id]->setText("Reach");
	attackRangeLabels[id]->setText("Range");
	attackTargetLabels[id]->setText("Targets");
	attackModifierLabels[id]->setText("Modifier");
	attackDamageLabels[id]->setText("Damage");
	attackDamageTypeLabels[id]->setText("Damage Type");
	attackPlusDamageLabels[id]->setText("Plus Damage");
	attackPlusDamageTypeLabels[id]->setText("Plus Damage Type");
	attackOrDamageLabels[id]->setText("Or Damage");
	attackOrDamageWhenLabels[id]->setText("Or Damage When");
	attackExtraLabels[id]->setText("Extra");

	attackRanges[id]->setHidden(true);
	attackRangeLabels[id]->setHidden(true);

	//Connect Combo Box change
	connect(attackDistances[id],QOverload<int>::of(&QComboBox::currentIndexChanged),this,&MainWindow::attackDistanceBoxChange);

	//Update Latex
	connect(attackTypes[id],QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);
	connect(attackDistances[id],QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);
	connect(attackNames[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackReaches[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackRanges[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackTargets[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackModifiers[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackDamages[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackDamageTypes[id],QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);
	connect(attackPlusDamages[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackPlusDamageTypes[id],QOverload<int>::of(&QComboBox::currentIndexChanged),monster,&Monster::updateLatex);
	connect(attackOrDamages[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackOrDamageWhens[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);
	connect(attackExtras[id],&QLineEdit::textChanged,monster,&Monster::updateLatex);

	ui->attacks->addWidget(attackLines[id]);

	//Add new layout
	ui->attacks->addLayout(attackLayouts[id]);

	//Add elements
	attackLayouts[id]->addRow(attackTypeLabels[id] ,attackTypes[id]);
	attackLayouts[id]->addRow(attackDistanceLabels[id], attackDistances[id]);
	attackLayouts[id]->addRow(attackNameLabels[id], attackNames[id]);
	attackLayouts[id]->addRow(attackReachLabels[id], attackReaches[id]);
	attackLayouts[id]->addRow(attackRangeLabels[id], attackRanges[id]);
	attackLayouts[id]->addRow(attackTargetLabels[id], attackTargets[id]);
	attackLayouts[id]->addRow(attackModifierLabels[id], attackModifiers[id]);
	attackLayouts[id]->addRow(attackDamageLabels[id], attackDamages[id]);
	attackLayouts[id]->addRow(attackDamageTypeLabels[id], attackDamageTypes[id]);
	attackLayouts[id]->addRow(attackPlusDamageLabels[id], attackPlusDamages[id]);
	attackLayouts[id]->addRow(attackPlusDamageTypeLabels[id], attackPlusDamageTypes[id]);
	attackLayouts[id]->addRow(attackOrDamageLabels[id], attackOrDamages[id]);
	attackLayouts[id]->addRow(attackOrDamageWhenLabels[id], attackOrDamageWhens[id]);
	attackLayouts[id]->addRow(attackExtraLabels[id], attackExtras[id]);

	//Setup dynamic UI creation
	addAttackConnect = connect(attackNames[id],&QLineEdit::textChanged,this,&MainWindow::addAttackSlot);
    if(id > 1){
        attackNames[id-2]->disconnect(removeAttackConnect);
    }
    if(id > 0){
		removeAttackConnect = connect(attackNames[id-1],&QLineEdit::textChanged,this,&MainWindow::removeAttackSlot);
	}
}

void MainWindow::removeAttackSlot(){
    if(attackNames.at(attackNames.count()-2)->text() == "" && checkLastLineEditEmpty(attackNames) && checkLastLineEditEmpty(attackReaches) && checkLastLineEditEmpty(attackRanges) &&
			checkLastLineEditEmpty(attackTargets) && checkLastLineEditEmpty(attackModifiers) && checkLastLineEditEmpty(attackDamages) &&
			checkLastLineEditEmpty(attackPlusDamages) && checkLastLineEditEmpty(attackOrDamages) && checkLastLineEditEmpty(attackOrDamageWhens) &&
			checkLastLineEditEmpty(attackExtras)){
		removeLastAttack();

		addAttackConnect = connect(attackNames.last(),&QLineEdit::textChanged,this,&MainWindow::addAttackSlot);
		if(attackNames.count() == 1){
			attackNames.last()->disconnect(removeAttackConnect);
		}
		if(attackNames.count() > 1){
			removeAttackConnect = connect(attackNames.at(attackNames.count()-2),&QLineEdit::textChanged,this,&MainWindow::removeAttackSlot);
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

void MainWindow::attackDistanceBoxChange(){
	for(int i = 0; i < attackLayouts.count(); i++){
		if(attackDistances[i]->currentIndex() == 0){
			attackReachLabels[i]->setVisible(true);
			attackReaches[i]->setVisible(true);
			attackRangeLabels[i]->setVisible(false);
			attackRanges[i]->setVisible(false);
			attackRanges[i]->setText("");
		}else if(attackDistances[i]->currentIndex() == 1){
			attackReachLabels[i]->setVisible(false);
			attackReaches[i]->setVisible(false);
			attackRangeLabels[i]->setVisible(true);
			attackRanges[i]->setVisible(true);
			attackReaches[i]->setText("");
		}else{
			attackReachLabels[i]->setVisible(true);
			attackReaches[i]->setVisible(true);
			attackRangeLabels[i]->setVisible(true);
			attackRanges[i]->setVisible(true);
		}
	}
}


void MainWindow::removeLastAttack(){
	attackTypes.last()->deleteLater();
	attackDistances.last()->deleteLater();
	attackNames.last()->deleteLater();
	attackReaches.last()->deleteLater();
	attackRanges.last()->deleteLater();
	attackTargets.last()->deleteLater();
	attackModifiers.last()->deleteLater();
	attackDamages.last()->deleteLater();
	attackDamageTypes.last()->deleteLater();
	attackPlusDamages.last()->deleteLater();
	attackPlusDamageTypes.last()->deleteLater();
	attackOrDamages.last()->deleteLater();
	attackOrDamageWhens.last()->deleteLater();
	attackExtras.last()->deleteLater();
	attackLines.last()->deleteLater();
	attackTypeLabels.last()->deleteLater();
	attackDistanceLabels.last()->deleteLater();
	attackNameLabels.last()->deleteLater();
	attackReachLabels.last()->deleteLater();
	attackRangeLabels.last()->deleteLater();
	attackTargetLabels.last()->deleteLater();
	attackModifierLabels.last()->deleteLater();
	attackDamageLabels.last()->deleteLater();
	attackDamageTypeLabels.last()->deleteLater();
	attackPlusDamageLabels.last()->deleteLater();
	attackPlusDamageTypeLabels.last()->deleteLater();
	attackOrDamageLabels.last()->deleteLater();
	attackOrDamageWhenLabels.last()->deleteLater();
	attackExtraLabels.last()->deleteLater();
	attackLayouts.last()->deleteLater();

	attackTypes.removeLast();
	attackDistances.removeLast();
	attackNames.removeLast();
	attackReaches.removeLast();
	attackRanges.removeLast();
	attackTargets.removeLast();
	attackModifiers.removeLast();
	attackDamages.removeLast();
	attackDamageTypes.removeLast();
	attackPlusDamages.removeLast();
	attackPlusDamageTypes.removeLast();
	attackOrDamages.removeLast();
	attackOrDamageWhens.removeLast();
	attackExtras.removeLast();
	attackLines.removeLast();
	attackTypeLabels.removeLast();
	attackDistanceLabels.removeLast();
	attackNameLabels.removeLast();
	attackReachLabels.removeLast();
	attackRangeLabels.removeLast();
	attackTargetLabels.removeLast();
	attackModifierLabels.removeLast();
	attackDamageLabels.removeLast();
	attackDamageTypeLabels.removeLast();
	attackPlusDamageLabels.removeLast();
	attackPlusDamageTypeLabels.removeLast();
	attackOrDamageLabels.removeLast();
	attackOrDamageWhenLabels.removeLast();
	attackExtraLabels.removeLast();
	attackLayouts.removeLast();
}

bool MainWindow::checkLastLineEditEmpty(QList<QLineEdit*> &list){
	if(list.at(list.count()-1)->text() == ""){
		return true;
	}else{
		return false;
	}
}
