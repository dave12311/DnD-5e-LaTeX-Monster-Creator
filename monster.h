#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>

struct Spell{
	QString name;
	int levelIndex;
	int num;
};

struct Action{
	QString name;
	QString desc;
};

struct Attack{
	int typeIndex;
	int distanceIndex;
	QString name;
	QString reach;
	QString range;
	QString targets;
	QString modifier;
	QString damage;
	int damageTypeIndex;
	QString plusDamage;
	int plusDamageTypeIndex;
	QString orDamage;
	QString orDamageWhen;
	QString extra;
};

class InputData{
public:
	QList<QString> basicData;

	QString innateSpellcasting;
	QList<Spell> innateSpells;

	QString spellcasting;
	QList<Spell> spells;

	QList<Action> actions;

	QList<Attack> attacks;

	void clear();
};

enum monsterEnum{
	monsterName, monsterType, monsterAC, monsterHP, monsterSpeed, monsterSTR, monsterDEX, monsterCON, monsterINT, monsterWIS, monsterCHA,
	monsterSavingThrows, monsterSkills, monsterDamageVulnerabilities, monsterDamageResistances, monsterDamageImmunities,
	monsterConditionImmunities, monsterSenses, monsterLanguages, monsterChallenge
};

class Monster : public QObject{
	Q_OBJECT

public:
	Monster();
	~Monster();

private:
	QString latexString;
	InputData *inputData;

public slots:
	//Textbox changed, regenerate latex
	void updateLatex();

	//Receive input data
	void receiveInputData(InputData *data);

signals:
	//Display text in GUI
	void sendText(const QString &text);

	//Request input data
	void requestInputData();
};

#endif // MONSTER_H
