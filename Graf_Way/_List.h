#pragma once

#define NULL 0

struct item{
	int num;
	int Value;
	int VertexA, VertexB;
	item* next;
	item* previous;
	item(){
		next = NULL;
	}
	item(int num_, int Value_, int VertexA_, int VertexB_){
		VertexA = VertexA_;
		VertexB = VertexB_;
		num = num_;
		Value = Value_;
		next = NULL;
		previous = NULL;
	}
	~item(){
	}
};

class _List
{
	item* head;
	int ni;
public:
	_List(void );
	_List(_List& lst);
	_List& operator=(const _List& lst);
	void Change(item* a, item* b);
	void Add(int num_, int Value_, int VertexA_, int VertexB_);
	void Sort();
	void Clear();
	void Print();
	void Input();
	~_List(void);
	item* GetHead()
	{
		return head;
	}
	operator item*()
	{
		return NULL;
	}
};

