#include <iostream>
#include "CStudent.h"
using namespace std;

// Function ?????
template <class T>
void QuickSort(T[], int, int);

template <class T>
int Partition(T[], int, int);

template <class T>
void SwapValue(T arr[], int a, int z);

// Main ???
int main()
{
	CStudent Stuarr[5]; // ????? ???? ????
	int id;
	string name;

	for (int i = 0; i < 5; i++) // ?相??? ??? ???
	{
		cout << i + 1 << "?? ?看? ?相??? ??? ??? ([Ex] 0001 ??曭): ";
		cin >> id >> name;
		Stuarr[i] = CStudent(id, name);
	}

	cout << endl << "???? ?? LIST : " << endl; // ???? ?? ?相??? ??? ???
	for (int i = 0; i < 5; i++)
	{
		cout << Stuarr[i].GetID() << " : " << Stuarr[i].GetName() << endl;
	}

	QuickSort(Stuarr, 0, 4); // ?相? ?????? ????

	cout << endl << "???? ?? LIST : " << endl; // ???? ?? ?相??? ??? ???
	for (int i = 0; i < 5; i++)
	{
		cout << Stuarr[i].GetID() << " : " << Stuarr[i].GetName() << endl;
	}

	return 0;
}

// Function ?????
template <class T>
void QuickSort(T arr[], int first, int last)
{
	if (first >= last)
	{
		return;
	}
	int split = Partition(arr, first, last);
	QuickSort(arr, first, split - 1);
	QuickSort(arr, split + 1, last);
}

template <class T>
int Partition(T arr[], int first, int last)
{
	int lastsmall = first;
	T temp;
	for (int i = first + 1; i <= last; i++)
	{
		if (arr[i] <= arr[first])
		{
			++lastsmall;
			SwapValue(arr, i, lastsmall);
		}
	}
	SwapValue(arr, first, lastsmall);
	return lastsmall;
}

template <class T>
void SwapValue(T arr[], int a, int z)
{
	T temp;
	temp = arr[a];
	arr[a] = arr[z];
	arr[z] = temp;
}

bool operator <=(CStudent& std1, CStudent& std2)
{
	return (std1.GetID() <= std2.GetID());
}