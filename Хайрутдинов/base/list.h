#pragma once
#include <stdio.h>
#include <stdlib.h>
template <class Telem>
struct Node
{
	Telem key;
	Node *Next;
	Node(Telem data = Telem(), Node *pNext = nullptr)
	{
		this->key = data;
		this->Next = pNext;
	}
};
template <class Telem>
class List
{
private:
	Node <Telem> *First;
	Node <Telem> *Prev;
	Node <Telem> *Curr;
	int count;
public:
	List()
	{
		First = nullptr;
		count = 0;
	}
	~List()
	{
		Node <Telem> *p = First;
		while (p != nullptr)
		{
			First = p->Next;
			delete p;
			First = p;
		}
	}
	Telem& operator[](const int index)
	{
		int tmp = 0;
		Curr = this->First;
		while (Curr != nullptr)
		{
			if (tmp == index)
				return Curr->key;
			Curr = Curr->Next;
			tmp++;
		}
	}
	bool isEmpty()
	{
		return(First == nullptr);
	}
	int GetCount()
	{
		return count;
	}

	void PushBack(Telem k)
	{
		if (First == nullptr)
		{
			First = new Node <Telem>(k);
		}
		else
		{
			Curr = this->First;
			while (Curr->Next != nullptr)
			{
				Curr = Curr->Next;
			}
			Curr->Next = new Node<Telem>(k);
		}
		count++;
	}
	void PushBegin(Telem k)
	{
		Node <Telem> *tmp = new Node <Telem>(k, First);
		count++;
	}
	void PushThis(Telem k, int index)
	{
		if (index < 0)
			throw "error";
		if (index == 0)
		{
			PushBegin(k);
		}
		else
		{
			Prev = this->First;
			for (int i = 0; i < index - 1; i++)
				Prev = Prev->Next;
			Node <Telem> *tmp = new Node<Telem>(k, Prev->Next);
			Prev->Next = tmp;
			count++;
		}
	}
	void DelBegin()
	{
		if (isEmpty() == true)
		{
			throw "error";
		}
		Node <Telem> *p = First;
		First = First->Next;
		delete p;
		count--;
	}
	void DelThis(int index)
	{
		if (index < 0)
			throw "error";
		if (index == 0)
			DelBegin();
		else
		{
			Prev = this->First;
			for (int i = 0; i < index - 1; i++)
			{
				Prev = Prev->Next;
			}
			Node <Telem> *tmp = Prev->Next;
			Prev->Next = tmp->Next;
			delete tmp;
			count--;
		}
	}
	void DelEnd()
	{
		DelThis(count - 1);
	}
	void Clear()
	{
		while (count != 0)
		{
			DelBegin();
		}
	}
};


