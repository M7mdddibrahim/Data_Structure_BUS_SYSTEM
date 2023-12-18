#pragma once
template <template T>
class Node
{
private:
	T item;
	Node<T>* next;

public:
	Node()
	{
		next = nullptr;
	}

	Node(T newItem)
	{
		item = newItem;
		next = nullptr;
	}
	//Node(T item)

	void setItem(T newItem)
	{
		item = newItem;
	}

	void setNext(Node<T> nextNodePtr)
	{
		next = nextNodePtr;
	}

	T getItem() const
	{
		return item;
	}

	Node<T> getNext() const
	{
		return next;
	}
};