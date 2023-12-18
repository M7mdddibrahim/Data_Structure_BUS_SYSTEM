#pragma once
template <class T>
class Node
{
private:
	T Data;
	int Priority;
	Node<T>* Next;  // Pointer to next node
public:
	Node() // Default Constructor
	{
		Next = nullptr;
	}
	Node(T newitem) // Non-Default Constructor
	{
		Data = newitem;
		Next = nullptr;
	}
	void SetData(T newitem)
	{
		Data = newitem;
	}
	void SetNext(Node<T>* nextptr)
	{
		Next = nextptr;
	}
	void SetPriority(int p)
	{
		Priority = p;
	}
	T GetData()  const
	{
		return Data;
	}
	Node<T>* GetNext()  const
	{
		return Next;
	}
	int GetPriority()
	{
		return Priority;
	}
};

