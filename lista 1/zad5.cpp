#include <iostream>

struct lnode
{
	int key;
	lnode *next;

	lnode(int value, lnode *l = nullptr)
	{
		key = value;
		next = l;
	}
};

int nty(int n, lnode *l)
{
	int nodeIndex = 1;
	while (l != nullptr)
	{
		if (nodeIndex == n)
			return l->key;
		else
		{
			nodeIndex++;
			l = l->next;
		}
	}
	return 0;
}

//int main()
//{
//	lnode node5(57);
//	lnode node4(41, &node5);
//	lnode node3(35, &node4);
//	lnode node2(23, &node3);
//	lnode node1(11, &node2);
//
//	int res = nty(4, &node1);
//	std::cout << res;
//	getchar();
//}