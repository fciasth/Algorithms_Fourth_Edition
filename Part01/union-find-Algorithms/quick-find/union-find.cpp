
#include <iostream>
#include "union-find.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "请输入触点数量" << endl;
	int N;
	cin >> N;
	UF uf = new UF(N);
	cout << "请输入您要相关联的整数对" << endl;
	for (int i = 0; i < N; i++)
	{
		int p, q;
		cin >> p;
		cin >> q;
		if (uf.connected(p,q)) continue;
		uf.union_(p, q);
		cout << "你输入的的两位整数对为:" << p << " " << q << endl;
	}
	cout << uf.count_() << "components" << endl;
}