#include "monster.h"
#include <string.h>

Monster::Monster(){}

Monster::~Monster(){}

void Monster::updateLatex(){
	emit requestListPointer();

	//Begin
	latexString = "\\begin{DndMonster}{";
	latexString.append((*inputListPointer)[monsterName]);
	latexString.append("}\n");

	//Monster type
	if((*inputListPointer)[1] != nullptr){
		latexString.append("\t\\DndMonsterType{");
		latexString.append((*inputListPointer)[monsterType]);
		latexString.append("}\n\n");
	}

	//Basics
	if((*inputListPointer)[monsterAC] != nullptr || (*inputListPointer)[monsterHP] != nullptr || (*inputListPointer)[monsterSpeed] != nullptr){
		latexString.append("\t\\DndMonsterBasics[\n");
		if((*inputListPointer)[monsterAC] != nullptr){
			latexString.append("\t\tarmor-class = {");
			latexString.append((*inputListPointer)[monsterAC]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterHP] != nullptr){
			latexString.append("\t\thit-points = {\\DndDice{");
			latexString.append((*inputListPointer)[monsterHP]);
			latexString.append("}},\n");
		}
		if((*inputListPointer)[monsterSpeed] != nullptr){
			latexString.append("\t\tspeed = {");
			latexString.append((*inputListPointer)[monsterSpeed]);
			latexString.append("},\n");
		}
		latexString.append("\t]\n\n");
	}

	//Ability scores
	if((*inputListPointer)[monsterSTR] != nullptr || (*inputListPointer)[monsterDEX] != nullptr || (*inputListPointer)[monsterCON] != nullptr ||
			(*inputListPointer)[monsterINT] != nullptr || (*inputListPointer)[monsterWIS] != nullptr || (*inputListPointer)[monsterCHA] != nullptr){
		latexString.append("\t\\DndMonsterAbilityScores[\n");
		if((*inputListPointer)[monsterSTR] != nullptr){
			latexString.append("\t\tstr = ");
			latexString.append((*inputListPointer)[monsterSTR]);
			latexString.append(",\n");
		}
		if((*inputListPointer)[monsterDEX] != nullptr){
			latexString.append("\t\tdex = ");
			latexString.append((*inputListPointer)[monsterDEX]);
			latexString.append(",\n");
		}
		if((*inputListPointer)[monsterCON] != nullptr){
			latexString.append("\t\tcon = ");
			latexString.append((*inputListPointer)[monsterCON]);
			latexString.append(",\n");
		}
		if((*inputListPointer)[monsterINT] != nullptr){
			latexString.append("\t\tint = ");
			latexString.append((*inputListPointer)[monsterINT]);
			latexString.append(",\n");
		}
		if((*inputListPointer)[monsterWIS] != nullptr){
			latexString.append("\t\twis = ");
			latexString.append((*inputListPointer)[monsterWIS]);
			latexString.append(",\n");
		}
		if((*inputListPointer)[monsterCHA] != nullptr){
			latexString.append("\t\tcha = ");
			latexString.append((*inputListPointer)[monsterCHA]);
			latexString.append(",\n");
		}
		latexString.append("\t]\n\n");
	}

	//Details
	if((*inputListPointer)[monsterSavingThrows] != nullptr || (*inputListPointer)[monsterSkills] != nullptr || (*inputListPointer)[monsterDamageVulnerabilities] != nullptr ||
			(*inputListPointer)[monsterDamageResistances] != nullptr || (*inputListPointer)[monsterDamageImmunities] != nullptr ||
			(*inputListPointer)[monsterConditionImmunities] != nullptr || (*inputListPointer)[monsterSenses] != nullptr || (*inputListPointer)[monsterLanguages] != nullptr ||
			(*inputListPointer)[monsterChallenge] != nullptr){
		latexString.append("\t\\DndMonsterDetails[\n");
		if((*inputListPointer)[monsterSavingThrows] != nullptr){
			latexString.append("\t\tsaving-throws = {");
			latexString.append((*inputListPointer)[monsterSavingThrows]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterSkills] != nullptr){
			latexString.append("\t\tskills = {");
			latexString.append((*inputListPointer)[monsterSkills]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterDamageVulnerabilities] != nullptr){
			latexString.append("\t\tdamage-vulnerabilities = {");
			latexString.append((*inputListPointer)[monsterDamageVulnerabilities]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterDamageResistances] != nullptr){
			latexString.append("\t\tdamage-resistances = {");
			latexString.append((*inputListPointer)[monsterDamageResistances]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterDamageImmunities] != nullptr){
			latexString.append("\t\tdamage-immunities = {");
			latexString.append((*inputListPointer)[monsterDamageImmunities]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterConditionImmunities] != nullptr){
			latexString.append("\t\tcondition-immunities = {");
			latexString.append((*inputListPointer)[monsterConditionImmunities]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterSenses] != nullptr){
			latexString.append("\t\tsenses = {");
			latexString.append((*inputListPointer)[monsterSenses]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterLanguages] != nullptr){
			latexString.append("\t\tlanguages = {");
			latexString.append((*inputListPointer)[monsterLanguages]);
			latexString.append("},\n");
		}
		if((*inputListPointer)[monsterChallenge] != nullptr){
			latexString.append("\t\tchallenge = ");
			latexString.append((*inputListPointer)[monsterChallenge]);
			latexString.append(",\n");
		}
		latexString.append("\t]\n\n");
	}

	//End
	latexString.append("\\end{DndMonster}");
	emit sendText(latexString);
}

void Monster::receiveListPointer(QList<QString> *listPointer){
	inputListPointer = listPointer;
}
