#include <iostream>
#include <algorithm>
#include "Apothecary.h"
#include "main.h"
#include "Potion.h"

using namespace std;

Apothecary::Apothecary(int oSize, int sSize) : orderSize(oSize), shelfSize(sSize), top(-1), rear(-1), front(-1)
{
	orderArray = new PotionType[orderSize];
	shelfArray = new PotionType[shelfSize];
}

Apothecary::~Apothecary()
{
	delete[] orderArray;
	delete[] shelfArray;
}

void Apothecary::SetOrderSize(int orderSize)
{
	this->orderSize = orderSize;
}

void  Apothecary::SetShelfSize(int shelfSize)
{
	this->shelfSize = shelfSize;
}
void  Apothecary::SetTop(int top)
{
	this->top = top;
}
void  Apothecary::SetRear(int rear)
{
	this->rear = rear;
}
void  Apothecary::SetFront(int front)
{
	this->front = front;
}

int Apothecary::GetOrderSize()
{
	return orderSize;
}

int Apothecary::GetShelfSize()
{
	return shelfSize;
}

Apothecary::Apothecary(const Apothecary& Apo)
{
	SetOrderSize(Apo.orderSize);
	SetShelfSize(Apo.shelfSize);
	SetRear(Apo.rear);
	SetFront(Apo.front);
	SetTop(Apo.top);

	orderArray = new PotionType[orderSize];
	shelfArray = new PotionType[shelfSize];

	for (int i = 0; i < orderSize; ++i)
	{
		orderArray[i] = Apo.orderArray[i];
	}

	for (int i = 0; i < shelfSize; ++i)
	{
		shelfArray[i] = Apo.shelfArray[i];
	}
}

Apothecary& Apothecary::operator=(Apothecary Apo)
{
	swap(*this, Apo);
	return *this;
}

bool Apothecary::OrderPotion(PotionType type)
{
	if (IsOrderFull())
		return false;

	else if (IsOrderEmpty())
	{
		front = 0;
		rear = 0;
	}
	else
		rear++;

	orderArray[rear] = type;
	return true;
}

bool Apothecary::IsOrderEmpty() const
{
	return ((rear == -1) && (front == -1));
}

bool Apothecary::IsOrderFull() const
{
	return (rear == (orderSize - 1));
}

bool Apothecary::IsShelfFull() const
{
	return ((top + 1) == shelfSize);
}

bool Apothecary::IsShelfEmpty() const
{
	return (top == -1);
}

bool Apothecary::PushShelf(PotionType aType)
{
	if (IsShelfFull())
		return false;
	else
	{
		top++;
		shelfArray[top] = aType;
	}
	return true;
}

PotionType Apothecary::PeekOrder() const
{
	if (!IsOrderEmpty())
		return orderArray[front];
	else
		return UNKNOWN;
}

void Apothecary::DequeueOrder()
{
	if (IsOrderEmpty())
		return;
	else
	{
		if (front == rear)
			front = rear = -1;
		else if (front == orderSize && rear == orderSize)
			front = 0;
		else
			front++;
		return;
	}
}

bool Apothecary::BuyPotion(Potion& potion)
{
	if (IsShelfEmpty())
		return false;
	else
	{
		potion.SetType(PeekShelf());
		top--;
	}
	return true;
}

PotionType Apothecary::PeekShelf() const
{
	if (!IsOrderEmpty())
		return shelfArray[top];
	else
		return UNKNOWN;
}

int Apothecary::MakePotions()
{
	int i = 0;
	if (IsOrderEmpty())
		return i;

	if (IsShelfFull())
	{
		cout << "The shelf of potions is full.  You can't make any more until somebody buys some.\n";
		return i;
	}
	while ((!IsOrderEmpty()) && (!IsShelfFull()))
	{
		PushShelf(PeekOrder());
		cout << "Made a " << PotionTypeString(PeekOrder()) << " potion.\n";
		DequeueOrder();
		i++;
	}
	return i;
}

void swap(Apothecary& oldApo, Apothecary& newApo)
{
	swap(oldApo.front, newApo.front);
	swap(oldApo.rear, newApo.rear);
	swap(oldApo.top, newApo.top);
	swap(oldApo.orderSize, newApo.orderSize);
	swap(oldApo.shelfSize, newApo.shelfSize);
	swap(oldApo.orderArray, newApo.orderArray);
	swap(oldApo.shelfArray, newApo.shelfArray);
}
