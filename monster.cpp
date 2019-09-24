#include "monster.h"

void InputData::clear(){
	basicData.clear();
	traits.clear();
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
	if(inputData->basicData[1] != ""){
		latexString.append("\t\\DndMonsterType{");
		latexString.append(inputData->basicData[monsterType]);
		latexString.append("}\n\n");
	}

	//Basics
	if(inputData->basicData[monsterAC] != "" || inputData->basicData[monsterHP] != "" || inputData->basicData[monsterSpeed] != ""){
		latexString.append("\t\\DndMonsterBasics[\n");
		if(inputData->basicData[monsterAC] != ""){
			latexString.append("\t\tarmor-class = {");
			latexString.append(inputData->basicData[monsterAC]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterHP] != ""){
			latexString.append("\t\thit-points = {\\DndDice{");
			latexString.append(inputData->basicData[monsterHP]);
			latexString.append("}},\n");
		}
		if(inputData->basicData[monsterSpeed] != ""){
			latexString.append("\t\tspeed = {");
			latexString.append(inputData->basicData[monsterSpeed]);
			latexString.append("},\n");
		}
		latexString.append("\t]\n\n");
	}

	//Ability scores
	if(inputData->basicData[monsterSTR] != "" || inputData->basicData[monsterDEX] != "" || inputData->basicData[monsterCON] != "" ||
			inputData->basicData[monsterINT] != "" || inputData->basicData[monsterWIS] != "" || inputData->basicData[monsterCHA] != ""){
		latexString.append("\t\\DndMonsterAbilityScores[\n");
		if(inputData->basicData[monsterSTR] != ""){
			latexString.append("\t\tstr = ");
			latexString.append(inputData->basicData[monsterSTR]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterDEX] != ""){
			latexString.append("\t\tdex = ");
			latexString.append(inputData->basicData[monsterDEX]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterCON] != ""){
			latexString.append("\t\tcon = ");
			latexString.append(inputData->basicData[monsterCON]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterINT] != ""){
			latexString.append("\t\tint = ");
			latexString.append(inputData->basicData[monsterINT]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterWIS] != ""){
			latexString.append("\t\twis = ");
			latexString.append(inputData->basicData[monsterWIS]);
			latexString.append(",\n");
		}
		if(inputData->basicData[monsterCHA] != ""){
			latexString.append("\t\tcha = ");
			latexString.append(inputData->basicData[monsterCHA]);
			latexString.append(",\n");
		}
		latexString.append("\t]\n\n");
	}

	//Details
	if(inputData->basicData[monsterSavingThrows] != "" || inputData->basicData[monsterSkills] != "" || inputData->basicData[monsterDamageVulnerabilities] != "" ||
			inputData->basicData[monsterDamageResistances] != "" || inputData->basicData[monsterDamageImmunities] != "" ||
			inputData->basicData[monsterConditionImmunities] != "" || inputData->basicData[monsterSenses] != "" || inputData->basicData[monsterLanguages] != "" ||
			inputData->basicData[monsterChallenge] != ""){
		latexString.append("\t\\DndMonsterDetails[\n");
		if(inputData->basicData[monsterSavingThrows] != ""){
			latexString.append("\t\tsaving-throws = {");
			latexString.append(inputData->basicData[monsterSavingThrows]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterSkills] != ""){
			latexString.append("\t\tskills = {");
			latexString.append(inputData->basicData[monsterSkills]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterDamageVulnerabilities] != ""){
			latexString.append("\t\tdamage-vulnerabilities = {");
			latexString.append(inputData->basicData[monsterDamageVulnerabilities]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterDamageResistances] != ""){
			latexString.append("\t\tdamage-resistances = {");
			latexString.append(inputData->basicData[monsterDamageResistances]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterDamageImmunities] != ""){
			latexString.append("\t\tdamage-immunities = {");
			latexString.append(inputData->basicData[monsterDamageImmunities]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterConditionImmunities] != ""){
			latexString.append("\t\tcondition-immunities = {");
			latexString.append(inputData->basicData[monsterConditionImmunities]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterSenses] != ""){
			latexString.append("\t\tsenses = {");
			latexString.append(inputData->basicData[monsterSenses]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterLanguages] != ""){
			latexString.append("\t\tlanguages = {");
			latexString.append(inputData->basicData[monsterLanguages]);
			latexString.append("},\n");
		}
		if(inputData->basicData[monsterChallenge] != ""){
			latexString.append("\t\tchallenge = ");
			latexString.append(inputData->basicData[monsterChallenge]);
			latexString.append(",\n");
		}
		latexString.append("\t]\n\n");
	}

	//Traits
	for(int i = 0; i < inputData->traits.count(); i++){
		if(inputData->traits[i].name != "" || inputData->traits[i].desc != ""){
			latexString.append("\t\\DndMonsterAction{");
			latexString.append(inputData->traits[i].name);
			latexString.append("}\n\t");
			latexString.append(inputData->traits[i].desc);
			latexString.append("\n\n");
		}
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
	if(inputData->actions.count() > 1){
		latexString.append("\t\\DndMonsterSection{Actions}\n");
		for(int i = 0; i < inputData->actions.count(); i++){
			if(inputData->actions[i].name != "" || inputData->actions[i].desc != ""){
				latexString.append("\t\\DndMonsterAction{");
				latexString.append(inputData->actions[i].name);
				latexString.append("}\n\t");
				latexString.append(inputData->actions[i].desc);
				latexString.append("\n\n");
			}
		}
	}else if(inputData->attacks.count() > 1 || inputData->attacks.first().name != ""){
		latexString.append("\t\\DndMonsterSection{Actions}\n");
	}

	//Attacks
	for(int i = 0; i < inputData->attacks.count(); i++){
		if(inputData->attacks[i].name != ""){
			latexString.append("\t\\DndMonsterAttack[\n");

			latexString.append("\t\tname={");
			latexString.append(inputData->attacks[i].name);
			latexString.append("},\n");

			latexString.append("\t\tdistance={");
			switch (inputData->attacks[i].distanceIndex) {
			case 0:
				latexString.append("melee");
				break;
			case 1:
				latexString.append("ranged");
				break;
			case 2:
				latexString.append("both");
				break;
			}
			latexString.append("},\n");

			latexString.append("\t\ttype={");
			switch (inputData->attacks[i].typeIndex) {
			case 0:
				latexString.append("weapon");
				break;
			case 1:
				latexString.append("spell");
				break;
			}
			latexString.append("},\n");

			if(inputData->attacks[i].modifier != ""){
				latexString.append("\t\tmod={");
				latexString.append(inputData->attacks[i].modifier);
				latexString.append("},\n");
			}

			if(inputData->attacks[i].distanceIndex != 1 && inputData->attacks[i].reach != ""){
				latexString.append("\t\treach={");
				latexString.append(inputData->attacks[i].reach);
				latexString.append("},\n");
			}

			if(inputData->attacks[i].distanceIndex != 0 && inputData->attacks[i].range != ""){
				latexString.append("\t\trange={");
				latexString.append(inputData->attacks[i].range);
				latexString.append("},\n");
			}

			if(inputData->attacks[i].targets != ""){
				latexString.append("\t\ttargets={");
				latexString.append(inputData->attacks[i].targets);
				latexString.append("},\n");
			}

			if(inputData->attacks[i].damage != ""){
				latexString.append("\t\tdmg=\\DndDice{");
				latexString.append(inputData->attacks[i].damage);
				latexString.append("},\n");

				latexString.append("\t\tdmg-type={");
				latexString.append(dmgType(inputData->attacks[i].damageTypeIndex));
				latexString.append("},\n");
			}

			if(inputData->attacks[i].plusDamage != ""){
				latexString.append("\t\tplus-dmg=\\DndDice{");
				latexString.append(inputData->attacks[i].plusDamage);
				latexString.append("},\n");

				latexString.append("\t\tplus-dmg-type={");
				latexString.append(dmgType(inputData->attacks[i].plusDamageTypeIndex));
				latexString.append("},\n");
			}

			if(inputData->attacks[i].orDamage != ""){
				latexString.append("\t\tor-dmg={");
				latexString.append(inputData->attacks[i].orDamage);
				latexString.append("},\n");
			}

			if(inputData->attacks[i].orDamageWhen != ""){
				latexString.append("\t\tor-dmg-when={");
				latexString.append(inputData->attacks[i].orDamageWhen);
				latexString.append("},\n");
			}

			if(inputData->attacks[i].extra != ""){
				latexString.append("\t\textra={");
				latexString.append(inputData->attacks[i].extra);
				latexString.append("},\n");
			}

			latexString.append("\t]\n\n");
		}
	}

	//End
	latexString.append("\\end{DndMonster}\n");
	emit sendText(latexString);
}

void Monster::receiveInputData(InputData *data){
	inputData = data;
}

QString Monster::dmgType(int n){
	switch (n) {
	case 0:
		return "acid";
	case 1:
		return "bludgeoning";
	case 2:
		return "cold";
	case 3:
		return "fire";
	case 4:
		return "force";
	case 5:
		return "lightning";
	case 6:
		return "necrotic";
	case 7:
		return "piercing";
	case 8:
		return "poison";
	case 9:
		return "psychic";
	case 10:
		return "radiant";
	case 11:
		return "slashing";
	case 12:
		return "thunder";
	}
	return nullptr;
}
