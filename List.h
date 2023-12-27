#pragma once
#include "Node.h"
#include <iostream> 
using namespace std;

template<class T>
class List
{
public:
	Node<T>* head;
	Node<T>* tail;
	int count;
	List() : head(nullptr), tail(nullptr), count(0) {}

	bool isEmpty() const
	{
		return (tail == nullptr && head == nullptr);
	}


	Node <T>* getHead() { return head; }
	//T  getHead1() { return head; }
	Node <T>* getTail() { return tail; }

	int getCount() const { return count; }


	bool DeleteNode( T& value)
	{
		Node <T>* p = head;
		while (p)
		{
			if (p->GetData().getID()== value.getID())
			{
				Node <T>* t = p;
				p = p->GetNext();
				t->SetNext(nullptr);
				delete t;
				count--;
				return true;
			}
			else
			{
				p = p->GetNext();
			}
		}
		return false;
	}
	T peek()
	{
		return (head->GetData());
	}
	
	
	void insertNode(T p)  // insert at tail and equivalent to enqueue
	{
		Node<T>* Process = new Node<T>;
		
			Process->SetData(p);
			if (isEmpty())
			{
				Process->SetNext(nullptr);
				tail = Process;
				head = Process;
			}
			else
			{
				tail->SetNext(Process);
				Process->SetNext(nullptr);
				tail = Process;
			}
			count++;
	}

	bool isFound(const T& p) // test
	{
		if (isEmpty()) // if the list is empty
		{
			return false;
		}

		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->GetData() == p)
			{
				return true;
			}
			temp = temp->GetNext();
		}
		return false;
	}

	void clear()
	{
		while (head != nullptr)
		{
			Node<T>* temp = head;
			head = head->GetNext();
			delete temp;
		}
		tail = nullptr;
		count = 0;
	}

	void Print()
	{
		Node<T>* temp = getHead();
		while (temp)
		{
			cout << temp->GetData();
			if (temp->GetNext())
				cout << ",";
			temp = temp->GetNext();
		}
	}



	/*~List()
	{
		clear();
	}*/

	/*void insertBefore(const T& item, const T& newitem)
	{
		if (isFound(item))
		{
			Node<T>* node1 = new Node<T>();
			node1->getItem() = newitem;
			Node<T>* temp = head;
			while (temp != nullptr && temp->getNext()->getItem() != item)
			{
				temp = temp->getNext();
			}
			node1->getNext() = temp->getNext();
			temp->getNext() = node1;
		}
	}*/

	void insertEnd(const T& item)
	{
		Node<T>* temp = head;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		Node<T>* node1 = new Node<T>();
		node1->getItem() = item;
		temp->getNext() = node1;
		node1->getNext() = nullptr;
	}

	/*Node* GetNode(T& p)
	{
		Node<T>* temp = head; //ptr used for traversing the linkedList
		if (isEmpty()) //empty linked list
		{
			return nullptr;
		}
		while (temp->getNext())  //by th end of the loop temp will point to the last node
		{
			temp = temp->getNext();
		}
		return temp;
	}*/

	/*int getOccurrence(const T& item) const
	{
		int count = 0;
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->getItem() == item)
				count++;
			temp = temp->getNext();
		}
		return count;
	}
	bool deleteNode(const T& item)
	{
		if (isEmpty())
		{
			return 0;
		}
		Node<T>* temp, * temp1;
		temp = head;
		temp1 = nullptr;
		int x = getOccurrence(item);
		while (x)
		{
			while (temp->getNext() != nullptr && temp->getNext()->getItem() != item)
			{
				temp = temp->getNext();
			}
			temp1 = temp->getNext();
			if (temp1 == nullptr)
				temp->setNext(nullptr);
			else
				temp->setNext(temp1->getNext());
			if (item == temp1->getItem())
				x--;
			delete temp1;
		}
		return 1;
	}*/


};


