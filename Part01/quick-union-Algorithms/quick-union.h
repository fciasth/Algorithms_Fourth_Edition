/*
*Data:Aug,24 2015
*Author:fciasth
*Modify:
*Effect:
!问题：***动态连通性***
输入一对整数对，“p和q是连通的”一对整数p和q可以被理解为他们具有
#自反性：p和p连通
#对称性：若p与q连通，则q与p连通
#传递性：若p与q连通，q与r连通，则p与r连通
设计一个数据结构保存程序已知的所有整数对的足够多的信息，判断一对对象是否相连。
*Alogorithms:**********quick-union算法***********
*此算法是为了提高union（）的速度，它和quick-find算法是互补的
*数据结构：已触点作为引所的id[]数组
*每个触点所对应的id[]元素都是同一个分量中的另一个触点的名称（也可能是它自己的）
*我们将这种联系称为链接
*实现find()，我们从给定的触点开始，由它的链接得到另一个触点，再由这个触点的链接到达第三个触点
*如此继续跟着链接直到到达一个根触点（链接指向自己的触点）
*实现union(),我们由p和q的链接分别找到它们的根触点
*然后只需将一个根触点链接到另一个即可将一个分量重命名为另一个分量
*Time and space complexity of the algorithm:
*union()访问数组的次数:在(N+3)到(2N+1)之间
*N+3=2次find()+N次for循环访问判断+1次相等
*2N+1=2次find()+N次for循环访问判断+N-1次相等
*若最后我们只等到一个连通分量则(N+3)(N-1)~N^2次数访问
*所以一般在平方级别
* 
*/
#ifdef QUICK-UNION
#define QUICK-UNION
class UF
{
private:
	int count;//分量数量
	int id[];
public:
	UF(int N)
	{	//初始化分量id
		count = N;
		int* id = new int[N];
		for (int i = 0; i < N; i++)
			id[i] = i;
	}
	int count_(){ return count; }

	int find(int p)
	{
		while (p!=id[p]) p =id[p];
		return p;
	}

	bool connected(int p, int q)
	{
		return find(p) == find(q);
	}
	void union_(int p, int q)
	{
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot = qRoot)return;
		id[pRoot] = qRoot;

		count_()--;
	}
};

#endif // QUICK-UNION
