#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<class T>
class PriorityQueue
{
private:
	Node<T>* Front;
	int count;
public:
	PriorityQueue()
	{
		Front = nullptr;
		count = 0;
	}
	bool IsEmpty()
	{
		if (Front == nullptr)
			return true;
		else
			return false;
	}
	void Enqueue(T Item, int p)
	{
		Node<T>* Temp = new Node<T>(Item, p);
		if (Front == nullptr)
		{
			Front = Temp;
			count++;
			return;
		}
		if (Front->GetPriority() < p)
		{
			Temp->SetNext(Front);
			Front = Temp;
			return;
		}
		Node<T>* Start = Front;
		while ((Start->GetNext() != nullptr) && (Start->GetNext()->GetPriority()) > p)
		{
			Start = Start->GetNext();
		}
		Start->SetNext(Temp);
		Temp->SetNext(nullptr);
		count++;
	}
	bool Dequeue(T& item)
	{
		if (IsEmpty())
			return false;
		Node<T>* Temp = Front;
		Front = Front->GetNext();
		item = Temp->GetData();
		delete Temp;
		count--;
		return true;
	}
	bool Peek(T& item)
	{
		if (IsEmpty())
			return false;
		else
			item = Front->GetData();

	}
	int GetCount()   // to return the size of priority queue
	{
		return count;
	}
	void Display()
	{
		if (IsEmpty())
		{
			cout << " " << endl;
		}
		Node<T>* Temp = Front;
		while (Temp != nullptr)
		{
			cout << Temp->GetPriority() << " ";
			Temp = Temp->GetNext();
		}
		count << endl;
		Temp = Front;
		while (Temp != nullptr)
		{
			cout << Temp->GetData() << " ";
			Temp = Temp->GetNext();
		}
		count << endl;
	}
	//void Clear()
	//{
	//	while (!IsEmpty())
	//	{
	//		Dequeue();
	//	}
	//}
	~PriorityQueue()
	{
		//Clear();
	}
};

