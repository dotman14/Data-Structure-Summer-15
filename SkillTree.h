#ifndef SKILLTREE_H
#define SKILLTREE_H

#include <iostream>
#include <ostream>
#include "Skill.h"

using namespace std;

static const int CHILD_MAX = 3;

class SkillTree
{
public:
	SkillTree();
	SkillTree(char* title);

	~SkillTree();
	SkillTree(const SkillTree& SKObj);
	SkillTree& operator=(const SkillTree& SKObj);

	void   Display(ostream& cout);
	void   AddSkill(char* name, char* desc, int level);
	void   AddSkill(char* name, char* desc, int level, char* parentName);
	char*  GetTitle() const;
	void   SetParentName(char* parentName);
	char*  GetParentName();
	Skill* FindSkill(char* name);

private:

	struct Node
	{
		Skill aSkill;
		Node* parent;
		Node* children[CHILD_MAX];

		Node()
		{
		};

		Node(const Skill& n) : aSkill(n), parent(NULL)
		{
			for (int i = 0; i < CHILD_MAX; i++)
			{
				children[i] = NULL;
			}
		};
	};

	Node* root;
	char* title;
	int   size;

	void copy_r(Node* origin, Node* dest, Node* par);
	void Display_r(ostream& out, Node* n, int depth);
	void destruct_r(Node* n);
};

#endif