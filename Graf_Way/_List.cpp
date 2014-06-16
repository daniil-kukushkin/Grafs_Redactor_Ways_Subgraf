#include "StdAfx.h"
#include "_List.h"

_List::_List(void)
{
	head = NULL;
	ni = 0;
}

_List::_List(_List& lst)
{
	head = NULL;
	for(item* i = lst.head; i!=NULL; i = i->next)
		Add(i->num, i->Value, i->VertexA, i->VertexB);
}

void _List::Add(int num_, int Value_, int VertexA_, int VertexB_)
{
	if(head == NULL)
		head = new item(num_, Value_, VertexA_, VertexB_);
	else
	{
		item* i;
		for(i = head; i->next != NULL; i = i->next){};
		i->next = new item(num_, Value_, VertexA_, VertexB_);
		i->next->previous = i;
	}
	ni++;
}

void _List::Change(item* a, item* b)
{
	if(a == b)
		return;
	item* temp = b->previous;
	item* temp2 = b->next;
	if(a == b->previous || b == a->previous)
	{
		if(a == b->previous)
		{
			if(a->previous)
			{
				a->previous->next = b;
				b->previous = a->previous;
			}
			else
				b->previous = NULL;

			if(b->next)
			{
				temp2->previous = a;
				a->next = temp2;
			}
			else
				a->next = NULL;

			b->next = a;
			a->previous = b;

		} else 
			if(b == a->previous)
			{
				if(b->previous)
				{
					b->previous->next = a;
					a->previous = b->previous;
				}
				else
					a->previous = NULL;

				if(a->next)
				{
					a->next->previous = b;
					b->next = a->next;
				}
				else
					b->next = NULL;

				a->next = b;
				b->previous = a;
			}
	} else {
		if(a->previous)
		{
			a->previous->next = b;
			b->previous = a->previous;
		}
		else
			b->previous = NULL;
		if(a->next)
		{
			a->next->previous = b;
			b->next = a->next;
		}
		else
			b->next = NULL;

		if(temp)
		{
			temp->next = a;
			a->previous = temp;
		}
		else
			a->previous = NULL;
		if(temp2)
		{
			temp2->previous = a;
			a->next = temp2;
		}
		else
			a->next = NULL;
	}
	if(a == head)
		head = b;
	else
		if(b == head)
			head = a;
}

void _List::Sort() // сортировка списка поиском минимума
{
	item* t = head;
	item* min;
	for(int i=0; i<ni; i++)
	{
		min = t;
		for(item* j=t; j != NULL; j = j->next)
		{
			if(j->Value < min->Value)
				min = j;
		}
		Change(t, min);
		t = min->next;
		if(t == NULL)
			break;
	}
}

_List& _List::operator=(const _List& lst)
{
	Clear();
	for(item* i = lst.head; i!=NULL; i = i->next)
		Add(i->num, i->Value, i->VertexA, i->VertexB);
	return *this;
}

void _List::Clear()
{
	item* i = head, *del;
	while(i!=NULL)
	{
		del = i;
		i = i->next;
		delete del;
	}
	head = NULL;
}

_List::~_List(void)
{
	Clear();
}
