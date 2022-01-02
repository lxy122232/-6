#include"1.h"
/*int main()
{cout<<1;
return 0;}
int main()
{	int choice;
	int MaxStackSize=8;
	Etype newvalue,result;
	Stack<Etype>AppStack(MaxStackSize);
	char name[][10]={"peter","lily","maria","bob","gbolin"};
	char number[][10]={"1001","1002","1003","1004","1005"};
	for(int i=0;i<5;i++)
	{	strcpy_s(newvalue.name,name[i]);
		strcpy_s(newvalue.number,number[i]);
		AppStack.Push(newvalue);
	}
	AppStack.DisplayStack();
	while (true)
	{
		cout << "1.输出堆栈中所有元素" << endl;
		cout << "2.返回栈顶" << endl;
		cout << "3.进栈" << endl;
		cout << "4.出栈" << endl;
		cout << "0.exit" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			AppStack.DisplayStack();
			break;
		}
		case 2:
		{
			AppStack.DisplayElementStack(AppStack.GetTopAdress());
			break;
		}
		case 3:
		{	cin >> newvalue.number;
		cin >> newvalue.name;
		AppStack.Push(newvalue);
		AppStack.DisplayStack();
		break;
		}
		case 4:
		{	AppStack.Pop(result);
		cout << result.number << "           " << result.name << endl;
		AppStack.DisplayStack();
		break;
		}
		case 0:
		{return 0;
		break; }
		}
		system("pause");
		system("cls");
	}
}*/
void MapColor(int r[8][8], int n, Stack<Stype>& S)
{
	int MaxStackSize = 20;
	Stack<Stype> Skeep(MaxStackSize);
	//Stack<Stype> S(MaxStackSize);
	Stype x, temp;
	bool flag;
	int currentArea = 1;
	int currentColor = 1;
	x.AreaIndex = currentArea;
	x.ColorIndex = currentColor;
	S.Push(x);
	currentArea++;
	while (currentArea <= n)
	{
		flag = true;
		while (!S.IsEmpty() && flag)
		{
			S.Pop(x);
			Skeep.Push(x);
			if (x.ColorIndex == currentColor && r[currentArea][x.AreaIndex])
				flag = false;
		}
		if (flag)
		{
			x.AreaIndex = currentArea;
			x.ColorIndex = currentColor;
			while (!Skeep.IsEmpty())
			{
				Skeep.Pop(temp);
				S.Push(temp);
			}
			S.Push(x);
			cout << "     jingzhan" << endl;
			S.DisplayStack();
			currentArea++;
			currentColor = 1;
		}
		else
		{
			currentColor++;
			while (!Skeep.IsEmpty())
			{
				Skeep.Pop(temp);
				S.Push(temp);
			}
			while (currentColor > 4)
			{
				S.Pop(x);
				cout << "     chuzhan" << endl;
				S.DisplayStack();
				currentColor = x.ColorIndex + 1;
				currentArea = x.AreaIndex;
			}
			flag = true;
		}
	}
}



int main()
{
	Stype   qq;
	int r[8][8] =
	{ {0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,0},   // 1 near 2,3,4,5,6     
	{0,1,0,0,0,0,1,0},   //  2 near 6,1
	{0,1,0,0,1,1,0,0},   //  3 near 1,4,5
	{0,1,0,1,0,1,1,0},   //  4 near 1,3,5,6
	{0,1,0,1,1,0,1,0},   //  5 near 1,3,4,6
	{0,1,1,0,1,1,0,0},   //  6 near 1,2,4,5
	{0,0,0,0,0,0,0,0} };   //  7 none
	int n = 7;
	Stack<Stype>  S;
	Stack<Stype>  temp;
	MapColor(r, n, S);
	system("cls");
	cout << "1 near 2,3,4,5,6" << endl;
	cout << "2 near 6,1" << endl;
	cout << "3 near 1,4,5" << endl;
	cout << "4 near 1,3,5,6" << endl;
	cout << "5 near 1,3,4,6" << endl;
	cout << "6 near 1,2,4,5" << endl;
	cout << " 7 none" << endl;
	while (!S.IsEmpty())
	{
		S.Pop(qq);
		temp.Push(qq);

	}
	while (!temp.IsEmpty())
	{
		temp.Pop(qq);
		
		cout << "\t第" <<qq.key << "区";
		if (qq.ColorIndex == 1)
		{
		
			cout << "blue" << endl;
		}
		else if (qq.ColorIndex == 2)
		{
			
			cout << "purple" << endl;
		}
		else if (qq.ColorIndex == 3)
		{
			
			cout << "yellow" << endl;
		}
		else if (qq.ColorIndex == 4)
		{

			cout << "red" << endl;
		}
	}

	return 0;
}
