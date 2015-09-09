
#include <iostream>
#include "union-find.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "�����봥������" << endl;
	int N;
	cin >> N;
	UF uf = new UF(N);
	cout << "��������Ҫ�������������" << endl;
	for (int i = 0; i < N; i++)
	{
		int p, q;
		cin >> p;
		cin >> q;
		if (uf.connected(p,q)) continue;
		uf.union_(p, q);
		cout << "������ĵ���λ������Ϊ:" << p << " " << q << endl;
	}
	cout << uf.count_() << "components" << endl;
}