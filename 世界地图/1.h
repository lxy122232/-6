#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
#define MAP Etype
#define AreaIndex key
//#define STUDENT Etype
/*class STUDENT
{	
public:
	char number[10];
	char name[10];
};*/
struct MAP
{
	int AreaIndex;
	char AreaName[20];
	int ColorIndex;
};

class Stype
{
public:
	int AreaIndex;
	int ColorIndex;
};




template<class Stype>
class Stack
{	public:
		Stack(int MaxStackSize=20);
		~Stack() {delete[]element;};
		int GetTopAdress() {return top;};
		bool IsEmpty();
		bool IsFull();
		bool GetTop(Stype& result);
		bool Push(Stype& newvalue);
		bool Pop(Stype& result);
		void DisplayStack();
		void DisplayElementStack(int i);
		//void MapColor(int r[8][8], int n, Stack<Stype>& S);
	private:
		int top;
		int MaxSpaceSize;
		Stype *element;
};

template<class Stype>
Stack<Stype>::Stack(int MaxStackSize)
{	MaxSpaceSize=MaxStackSize;
	element=new Stype[MaxSpaceSize];
	top=-1;
}

template<class Stype>
bool Stack<Stype>::IsEmpty()
{	if(top==-1) return true;
	return false;
}
	
template<class Stype>
bool Stack<Stype>::IsFull()
{	if(top>=MaxSpaceSize-1)
		return true;
	return false;
}



template<class Stype>
bool Stack<Stype>::GetTop(Stype& result)
{	if(IsEmpty()) return false;
	result=element[top];
	return true;
}




template<class Stype>
bool Stack<Stype>::Pop(Stype& result)
{	if(IsEmpty()) return false;
		result=element[top--];
	return true;
}




template<class Stype>
bool Stack<Stype>::Push(Stype& newvalue)
{	if(IsFull()) return false;
		element[++top]=newvalue;
	return true;
}




template<class Stype>
void Stack<Stype>::DisplayStack()
{	for(int i=top;i>=-1;i--)
	{	
		cout<<i+1<<"    "<<element[i].AreaIndex<<"    "<<element[i].ColorIndex<<endl;
		cout<<"                                  ";
	}
	cout<<endl<<top+1<<"       "<<top<<"           "<<MaxSpaceSize+1<<endl;
}


template<class Stype>
void Stack<Stype>::DisplayElementStack(int i)
{	cout<<i+1<<"     "<<element[i].AreaIndex<<"         "<<element[i].ColorIndex<<endl;}


