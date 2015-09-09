/*
*Data:Aug,30 2015
*Author:fciasth
*Modify:
*Effect:
!问题：***排序问题***
!将所有元素的主键按照某种方式排序
!#插入排序#:通常人们整理桥牌的方法是一张一张的来,
!将每一张牌插到其他已经有序的牌中适当位置。
!在计算机的实现中，为了给要插入的元素腾出空间，我们需要将其余所有元素在插入之前都向右移动一位.
!Algorithm analysis:
!插入排序所需的时间取决于元素的初始顺序。
!
*/
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int less(int a, int b)
{
	if (a > b)return 1;
	if (b < a)return -1;
	return 0;
}

void exch(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void sort(int(&a)[10])
{
	int N = sizeof(a) / sizeof(a[0]);
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j > 0 && less(a[j], a[j-1]); j--)
			exch(a, j, j - 1);
	}
}

bool isSorted(int(&a)[10])
{
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
		if (less(a[i], a[i - 1])) return false;
	return true;
}

void show(int(&a)[10])
{
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[10];
	cout << "请输入10为随机整数";
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
	{
		cin >> a[i];
		cout << "你输入的为:" << a[i] << endl;
	}
	sort(a);
	cout << isSorted(a) << endl;
	show(a);
	return 0;
}