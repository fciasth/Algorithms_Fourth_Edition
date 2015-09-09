/*
*Data:Aug,22 2015
*Author:fciasth
*Modify:
*Effect:
!问题：***动态连通性***
输入一对整数对，“p和q是连通的”一对整数p和q可以被理解为他们具有
#自反性：p和p连通
#对称性：若p与q连通，则q与p连通
#传递性：若p与q连通，q与r连通，则p与r连通
设计一个数据结构保存程序已知的所有整数对的足够多的信息，判断一对对象是否相连。
*@Alogorithms:**********quick-find算法***********
*！！！我们可以让它根据以触点为索引的id[]数组来确定
*保证当且仅当id[p]等于id[q]时p和q是连通的 
*在同一连通分量中的触点在id[]中的值必须全部相同
*@Algorithm analysis:
*find()的操作速度明显很快
*因为它只需要访问id[]数组一次
*但quick-find算法一般无法处理大型问题
*因为对每一对输入union()都需要扫描整个id[]数组
*Time and space complexity of the algorithm:
*quick-union算法中的find()方法访问数组的次数为1加上给定触点所对应的节点深度的两倍
*即:1~2N-1
*假设我们使用quick-union算法解决了动态连通性问题最终只得到一个分量，可以推算出算法最坏情况下是平方级别的
*
*/
#ifndef UNION-FIND_h
#define UNION-FIND_h
#include <vector>

using std::vector;

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

	int find(int p){return id[p];}

	bool connected(int p, int q)
	{
		return find(p) == find(q);
	}
	void union_(int p,int q)
	{//将p和q归并到相同的分量中
		int pID = find(p);
		int qID = find(q);
		
		if (pID == qID) return;
		//如果p和q已经在相同的连通分量了不采取行动
		for (int i = 0; i < id[]->length(); i++)
		//将p分量重命名为q的名称
			if (id[i] == pID)
				id[i] = qID;
		count--;
	}
};
#endif 