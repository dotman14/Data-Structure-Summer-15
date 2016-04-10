#include <iostream>
#include "SkillTree.h"
#include "Skill.h"

Skill::Skill()
{
	name = NULL;
	desc = NULL;
	level = 0;
}

Skill::Skill(char* name, char* desc, int level) : level(level), name(new char[strlen(name) + 1]), desc(new char[strlen(desc) + 1])
{
	strcpy_s(this->name, (strlen(name) + 1), name);
	strcpy_s(this->desc, (strlen(desc) + 1), desc);
}

Skill::Skill(const Skill& aSkill)
{
	this->name = new char[strlen(aSkill.name) + 1];
	strcpy_s(this->name, (strlen(aSkill.name) + 1), aSkill.name);

	this->level = aSkill.level;

	this->desc = new char[strlen(aSkill.desc) + 1];
	strcpy_s(this->desc, (strlen(aSkill.desc) + 1), aSkill.desc);
}

Skill& Skill::operator=(const Skill& aSkill)
{
	if (this == &aSkill)
		return *this;
	else
	{
		delete[] name;
		delete[] desc;

		name = new char[strlen(aSkill.name) + 1];
		strcpy_s(name, (strlen(aSkill.name) + 1), aSkill.name);

		desc = new char[strlen(aSkill.desc) + 1];
		strcpy_s(name, (strlen(aSkill.desc) + 1), aSkill.desc);

		level = aSkill.level;

		return *this;
	}
}

Skill::~Skill()
{
	delete[] name;
	delete[] desc;
}

char* Skill::GetName() const
{
	return name;
}
char* Skill::GetDesc() const
{
	return desc;
}
int Skill::GetLevel() const
{
	return level;
}

void Skill::Display(ostream& out)
{
	out << GetName() << " -- " << GetDesc() << " [Lvl: " << GetLevel() << "]\n";
}
