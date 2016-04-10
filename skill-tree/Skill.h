#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <ostream>

using namespace std;

class Skill
{
public:
	Skill();
	Skill(char* name, char* desc, int level);

	~Skill();
	Skill(const Skill& aSkill);
	Skill& operator=(const Skill& aSkill);

	char* GetName() const;
	char* GetDesc() const;
	int   GetLevel() const;

	void Display(ostream& out);

private:
	char* name;
	char* desc;
	int   level;
};

#endif
