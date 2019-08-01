#include "monster.h"
#include "monsterenum.h"
#include <string.h>

Monster::Monster(){}

Monster::~Monster(){}

void Monster::updateLatex(){
	emit requestData();

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
			latexString.append("\t\thit-points = {");
			latexString.append((*inputListPointer)[monsterHP]);
			latexString.append("},\n");
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


	//End
	latexString.append("\\end{DndMonster}");
	emit sendText(&latexString);
}

void Monster::receiveListPointer(QList<QString> *listPointer){
	inputListPointer = listPointer;
}
