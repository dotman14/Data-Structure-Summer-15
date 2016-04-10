#include <iostream>
#include <ostream>
#include "Skill.h"
#include "SkillTree.h"
#include <queue>

using namespace std;

SkillTree::SkillTree()
{
	root  = NULL;
	title = NULL;
}

SkillTree::SkillTree(char* newTitle)
{
	title = new char[strlen(newTitle) + 1];
	strcpy_s(title, (strlen(newTitle) + 1), newTitle);

	this->root = NULL;
}

SkillTree& SkillTree::operator=(const SkillTree& SKObj)
{
	SkillTree* tree = new SkillTree;
	tree->title = new char[strlen(SKObj.title) + 1];
	strcpy_s(tree->title, (strlen(SKObj.title) + 1), SKObj.title);

	copy_r(SKObj.root, tree->root, NULL);

	return *tree;
}

SkillTree::SkillTree(const SkillTree& SKObj)
{
	title = new char[strlen(SKObj.title) + 1];
	strcpy_s(title, (strlen(SKObj.title) + 1), SKObj.title);

	copy_r(SKObj.root, this->root, NULL);
}

void SkillTree::copy_r(Node* origin, Node* dest, Node* par)
{
	dest = new Node;
	dest->aSkill = origin->aSkill;
	dest->parent = par;

	for (int i = 0; i < CHILD_MAX; i++)
	{
		if (origin->children[i] != NULL)
		{
			copy_r(origin->children[i], dest->children[i], dest);
		}
	}
}

void SkillTree::AddSkill(char* name, char* desc, int level)
{
	Skill s(name, desc, level);
	Node * newNode = new Node(s);
	newNode->parent = NULL;
	for (int i = 0; i < CHILD_MAX; i++)
	{
		newNode->children[i] = NULL;
	}

	if (this->root == NULL)
	{
		this->root = newNode;
	}
	else
	{
		this->root->parent = newNode;
		newNode->children[0] = this->root;
		this->root = newNode;
	}
}

void SkillTree::AddSkill(char* name, char* desc, int level, char* parentName)
{
	if (this->root == NULL)
	{
		return;
	}

	queue<Node*> nodeQueue;
	nodeQueue.push(this->root);

	while (!nodeQueue.empty())
	{
		Node * newNode = nodeQueue.front();
		nodeQueue.pop();
		if (strcmp(newNode->aSkill.GetName(), parentName) == 0)
		{
			for (int i = 0; i < CHILD_MAX; i++)
			{
				if (newNode->children[i] == NULL)
				{
					Skill newSkill(name, desc, level);
					Node * child = new Node(newSkill);
					child->parent = newNode;
					newNode->children[i] = child;
					return;
				}
			}
		}
		for (int i = 0; i < CHILD_MAX; i++)
		{
			if (newNode->children[i] != NULL)
			{
				nodeQueue.push(newNode->children[i]);
			}
		}
	}
}

char* SkillTree::GetTitle() const
{
	return title;
}

Skill* SkillTree::FindSkill(char* name)
{
	if (this->root == NULL)
		return NULL;
	else
	{
		queue<Node*> nodeQueue;
		nodeQueue.push(this->root);

		while (!nodeQueue.empty())
		{
			Node * newNode = nodeQueue.front();
			nodeQueue.pop();

			if (strcmp(newNode->aSkill.GetName(), name) == 0)
			{
				return &(newNode->aSkill);
			}
			for (int i = 0; i < CHILD_MAX; i++)
			{
				if (newNode->children[i] != NULL)
				{
					nodeQueue.push(newNode->children[i]);
				}
			}
		}
	}
	return NULL;
}

void SkillTree::Display(ostream& out)
{
	out << "Skill Tree: " << title << "\n";
	if (this->root == NULL)
	{
		cout << "  Empty\n";
		return;
	}
	else
		Display_r(out, this->root, 1);
}

void SkillTree::Display_r(ostream& out, Node* n, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		out << "  ";
	}
	cout << "- ";
	n->aSkill.Display(out);

	for (int i = 0; i < CHILD_MAX; i++)
	{
		if (n->children[i] != NULL)
		{
			Display_r(out, n->children[i], depth + 1);
		}
	}
}

SkillTree::~SkillTree()
{
	delete title;
	destruct_r(this->root);
}

void SkillTree::destruct_r(Node* n)
{
	for (int i = 0; i < CHILD_MAX; i++)
	{
		if (n->children[i] != NULL)
		{
			destruct_r(n->children[i]);
		}
	}
	delete n;
}