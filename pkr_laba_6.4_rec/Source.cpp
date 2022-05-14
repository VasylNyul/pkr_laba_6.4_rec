#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

struct Elem
{
	Elem* link;
	int info;
};

void CreateCycle(Elem*& first, int N, int Low, int High, int i);
void Insert(Elem*& L, int value);
void Scan(Elem* first, Elem* L, int V1, int V2);
void Print(Elem* first, Elem* L);
int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Elem* L = NULL;

	int Low, High, N, V1, V2;
	cout << "Найменший елемент списку: "; cin >> Low;
	cout << "Найбільший елемент списку: "; cin >> High;
	cout << "Кількість елементів списку: "; cin >> N;
	cout << "Значення інформаційного поля V1: "; cin >> V1;
	cout << "Значення інформаційного поля V2: "; cin >> V2;
	CreateCycle(L, N, Low, High, 0);
	cout << "Оригінальний список:" << endl;
	Print(L, L);
	cout << endl;
	cout << "Новий список:" << endl;
	Scan(L, L, V1, V2);
	Print(L, L);

	return 0;
}

void CreateCycle(Elem*& first, int N, int Low, int High, int i)
{
	if (i < N)
	{
		int value = Low + rand() % (High - Low + 1);
		Insert(first, value);
		CreateCycle(first, N, Low, High, i + 1);
	}
}

void Insert(Elem*& L, int value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	if (L != NULL)
	{
		Elem* T = L;
		while(T->link != L)
			T = T->link;
		T->link = tmp;
	}
	else
	{
		L = tmp;
	}
	tmp->link = L;
}

void Scan(Elem* first, Elem* L, int V1, int V2)
{
	if (L == NULL)
	{
		return;
	}
	else
	{
		if (L->link != first)
		{
			if (L->info == V1)
			{
				Insert(L, V2);
				Scan(first, L->link, V1, V2);

			}
			else
			{
				Scan(first, L->link, V1, V2);
			}
		}
		else
			if (L->link == first)
			{
				if (L->info == V1)
					Insert(L, V2);
			}
	}
}

void Print(Elem* first, Elem* L)
{
	if (L == NULL)
		return;
	else
		if (L->link == first)
			cout  << setw(4) << L->info;
		if(L->link != first)
		{
			Print(first, L->link);
			cout  << setw(4)<< L->info;
		}
		
}
