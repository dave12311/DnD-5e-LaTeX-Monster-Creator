#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>

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
	QList<QString> *inputListPointer;

public slots:
	//Textbox changed, regenerate latex
	void updateLatex();

	//Receive input data
	void receiveListPointer(QList<QString> *list);

signals:
	//Display text in GUI
	void sendText(const QString &text);

	//Request input data
	void requestListPointer();
};

#endif // MONSTER_H
