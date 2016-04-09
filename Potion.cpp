#include <iostream>
#include "Potion.h"
#include "main.h"

using namespace std;

Potion::Potion()
{

}

PotionType Potion::GetType() const
{
	return type;
}

void Potion::SetType(PotionType NewType)
{
	type = NewType;
}

ostream& operator<<(ostream& out, const Potion& PotionObj)
{
	out << "Potion of " << PotionTypeString(PotionObj.GetType()) << "\n";
	return out;
}
