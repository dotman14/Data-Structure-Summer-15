#ifndef APOTHECARY_H
#define APOTHECARY_H

#include "Potion.h"
#include "main.h"

using namespace std;

class Apothecary
{
public:
	Apothecary(int oSize, int sSize);
	~Apothecary();
	Apothecary(const Apothecary& NewApo);
	Apothecary& operator=(Apothecary NewApo);

	bool OrderPotion(PotionType aType);
	int  MakePotions();
	bool BuyPotion(Potion& potion);

	void SetOrderSize(int);
	void SetShelfSize(int);
	void SetTop(int);
	void SetRear(int);
	void SetFront(int);

	int  GetOrderSize();
	int  GetShelfSize();

	bool IsOrderEmpty() const;
	bool IsOrderFull() const;
	void DequeueOrder();

	bool IsShelfFull() const;
	bool IsShelfEmpty() const;
	bool PushShelf(PotionType aType);

	PotionType PeekOrder() const;
	PotionType PeekShelf() const;
	friend void swap(Apothecary& first, Apothecary& second);

private:
	int orderSize;
	int shelfSize;
	int top;
	int rear;
	int front;

	PotionType* orderArray;
	PotionType* shelfArray;
};
#endif
