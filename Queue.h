#pragma once
#include"Node.h"
#include<iostream>
using namespace std;
template<class T>
class Queue
{
private:
	Node<T>* Front;
	Node<T>* Rear;
	int count;   // To know the number of elements in the queue
public:
	Queue()
	{
		Front = nullptr;
		Rear = nullptr;
		count = 0;
	}
	bool IsEmpty()
	{
		if ((Front == nullptr) && (Rear == nullptr))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Enqueue(const T& item)
	{
		Node<T>* Temp = new Node<T>();
		Temp->SetData(item);
		count++;
		if (IsEmpty())
		{
			Front = Temp;
			Rear = Temp;
			return true;
		}
		else
		{
			Temp->SetNext(nullptr);
			Rear->SetNext(Temp);
			Rear = Temp;
			return true;
		}
	}
	bool Dequeue(T& item)
	{
		if (IsEmpty())
		{
			cout << " ";
			count = 0;
			return false;
		}
		else if (Front == Rear)
		{
			item = Front->GetData();
			delete Front;
			Front = nullptr;
			Rear = nullptr;
			count--;
			return true;
		}
		else
		{
			Node<T>* Temp = Front;
			Front = Front->GetNext();
			item = Temp->GetData();
			delete Temp;
			count--;
			return true;
		}
	}
	bool peek(T& item) const
	{
		if (Front == nullptr)
			return false;
		item = Front->GetData();
		return true;
	}
	void PeekFront(T& item)
	{
		item = Front->GetData();
	}
	void PeekRear(T& item)
	{
		item = Rear->GetData();
	}
	void Display()
	{
		if (IsEmpty())
		{
			cout << " " ;
		}
		Node<T>* Temp = Front;
		while (Temp != nullptr)
		{
			cout << Temp->GetData() << " ,";
			Temp = Temp->GetNext();
		}
	}
	int GetSize()   // to return the size of the queue
	{
		return count;
	}
	/*void Clear()
	{
		while (!IsEmpty())
		{
			Dequeue();
		}
	}*/
	~Queue()
	{
		//Clear();
	}

};

