#include "monster.h"
#include <string.h>

Monster::Monster(){}

Monster::~Monster(){}

void InputData::clear(){
	basicData.clear();
	innateSpellcasting.clear();
	innateSpells.clear();
	spellcasting.clear();
	spells.clear();
	actions.clear();
	attacks.clear();
}

void Monster::updateLatex(){
	emit requestInputData();

	//Begin
	latexString = "\\begin{DndMonster}{";
	latexString.append(inputData->basicData[monsterName]);
	latexString.append("}\n");

	//Monster type
	if(inputData->basicData[1] != nullptr){
		latexString.append("\t\\DndMonsterType{");
		latexString.append(inputData->basicData[monsterType]);
		latexString.append("}\n\n");
	}

	//Basics
	if(inputData->basicData[monsterAC] != nullptr || inputData->basicData[monsterHP] != nullptr || inputData->basicData[monsterSpeed] != nullptr){
		latexString.append("\t\\DndMonsterBasics[\n");
		if(inputData->basicData[monsterAC] != nullptr){
			latexString.append("\t\tarmor-class = {");
			latexString.append(inputData->basicData[monsterAC]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterHP] != nullptr){
			latexString.append("\t\thit-points = {\\DndDice{");
			latexString.append(inputData->basicData[monsterHP]);
			latexString.append("}},\n");
		}
		if(inputData->basicData[monsterSpeed] != nullptr){
			latexString.append("\t\tspeed = {");
			latexString.append(inputData->basicData[monsterSpeed]);
			latexString.append("},\n");
		}
		latexString.append("\t]\n\n");
	}

	//Ability scores
	if(inputData->basicData[monsterSTR] != nullptr || inputData->basicData[monsterDEX] != nullptr || inputData->basicData[monsterCON] != nullptr ||
			inputData->basicData[monsterINT] != nullptr || inputData->basicData[monsterWIS] != nullptr || inputData->basicData[monsterCHA] != nullptr){
		latexString.append("\t\\DndMonsterAbilityScores[\n");
		if(inputData->basicData[monsterSTR] != nullptr){
			latexString.append("\t\tstr = ");
			latexString.append(inputData->basicData[monsterSTR]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterDEX] != nullptr){
			latexString.append("\t\tdex = ");
			latexString.append(inputData->basicData[monsterDEX]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterCON] != nullptr){
			latexString.append("\t\tcon = ");
			latexString.append(inputData->basicData[monsterCON]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterINT] != nullptr){
			latexString.append("\t\tint = ");
			latexString.append(inputData->basicData[monsterINT]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterWIS] != nullptr){
			latexString.append("\t\twis = ");
			latexString.append(inputData->basicData[monsterWIS]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterCHA] != nullptr){
			latexString.append("\t\tcha = ");
			latexString.append(inputData->basicData[monsterCHA]);
			latexString.append(",\n");
		}
        latexString.append("\t]\n\n");
	}

	//Details
	if(inputData->basicData[monsterSavingThrows] != nullptr || inputData->basicData[monsterSkills] != nullptr || inputData->basicData[monsterDamageVulnerabilities] != nullptr ||
			inputData->basicData[monsterDamageResistances] != nullptr || inputData->basicData[monsterDamageImmunities] != nullptr ||
			inputData->basicData[monsterConditionImmunities] != nullptr || inputData->basicData[monsterSenses] != nullptr || inputData->basicData[monsterLanguages] != nullptr ||
			inputData->basicData[monsterChallenge] != nullptr){
		latexString.append("\t\\DndMonsterDetails[\n");
		if(inputData->basicData[monsterSavingThrows] != nullptr){
			latexString.append("\t\tsaving-throws = {");
			latexString.append(inputData->basicData[monsterSavingThrows]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterSkills] != nullptr){
			latexString.append("\t\tskills = {");
			latexString.append(inputData->basicData[monsterSkills]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterDamageVulnerabilities] != nullptr){
			latexString.append("\t\tdamage-vulnerabilities = {");
			latexString.append(inputData->basicData[monsterDamageVulnerabilities]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterDamageResistances] != nullptr){
			latexString.append("\t\tdamage-resistances = {");
			latexString.append(inputData->basicData[monsterDamageResistances]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterDamageImmunities] != nullptr){
			latexString.append("\t\tdamage-immunities = {");
			latexString.append(inputData->basicData[monsterDamageImmunities]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterConditionImmunities] != nullptr){
			latexString.append("\t\tcondition-immunities = {");
			latexString.append(inputData->basicData[monsterConditionImmunities]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterSenses] != nullptr){
			latexString.append("\t\tsenses = {");
			latexString.append(inputData->basicData[monsterSenses]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterLanguages] != nullptr){
			latexString.append("\t\tlanguages = {");
			latexString.append(inputData->basicData[monsterLanguages]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterChallenge] != nullptr){
			latexString.append("\t\tchallenge = ");
			latexString.append(inputData->basicData[monsterChallenge]);
			latexString.append(",\n");
		}
		latexString.append("\t]\n\n");
	}

	//Innate Spellcasting
	if(inputData->innateSpellcasting != ""){
		latexString.append("\t\\DndMonsterAction{Innate Spellcasting}\n\t");
		latexString.append(inputData->innateSpellcasting);
		latexString.append("\n\t\\begin{DndMonsterSpells}\n");
		for(int i = 0; i < inputData->innateSpells.count(); i++){
			if(inputData->innateSpells[i].name != ""){
				latexString.append("\t\t\\DndInnateSpellLevel");
				if(inputData->innateSpells[i].num == 0){
					latexString.append("{");
					latexString.append(inputData->innateSpells[i].name);
				}else{
					latexString.append("[");
					latexString.append(QString::number(inputData->innateSpells[i].num));
					latexString.append("]{");
					latexString.append(inputData->innateSpells[i].name);
				}
				latexString.append("}\n");
			}
		}
		latexString.append("\t\\end{DndMonsterSpells}\n\n");
	}

	//Spellcasting
	if(inputData->spellcasting != ""){
		latexString.append("\t\\DndMonsterAction{Spellcasting}\n\t");
		latexString.append(inputData->spellcasting);
		latexString.append("\n\t\\begin{DndMonsterSpells}\n");
		for(int i = 0; i < inputData->spells.count(); i++){
			if(inputData->spells[i].name != ""){
				latexString.append("\t\t\\DndMonsterSpellLevel");
				if(inputData->spells[i].levelIndex != 0){
					latexString.append("[");
					latexString.append(QString::number(inputData->spells[i].levelIndex));
					latexString.append("][");
					latexString.append(QString::number(inputData->spells[i].num));
					latexString.append("]");
				}
				latexString.append("{");
				latexString.append(inputData->spells[i].name);
				latexString.append("}\n");
			}
		}
		latexString.append("\t\\end{DndMonsterSpells}\n\n");
	}

	//Actions
	if(inputData->actions.count() != 0){
		latexString.append("\t\\DndMonsterSection{Actions}\n");
	}
	for(int i = 0; i < inputData->actions.count(); i++){
		if(inputData->actions[i].name != "" || inputData->actions[i].name != ""){
			latexString.append("\t\\DndMonsterAction{");
			latexString.append(inputData->actions[i].name);
			latexString.append("}\n\t");
			latexString.append(inputData->actions[i].desc);
			latexString.append("\n\n");
		}
	}

	//Attacks


	//End
	latexString.append("\\end{DndMonster}");
	emit sendText(latexString);
}

void Monster::receiveInputData(InputData *data){
	inputData = data;
}
