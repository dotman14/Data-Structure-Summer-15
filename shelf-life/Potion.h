#include <iostream>
#include "main.h"

#ifndef PORTION_H
#define PORTION_H

using namespace std;

class Potion
{
public:
	Potion();
	PotionType GetType() const;
	void SetType(PotionType);
	friend ostream&	operator<<(ostream& out, const Potion& PotionObj);

private:
	PotionType type;
};
#endif
