#include <iostream>
#include "BST.cpp"
#include <algorithm>

int main()
{
	int maxH = 0, minH = 1000, midH = 0;
	srand(time(NULL));
	int t, N;
	std::cin >> t >> N;
	for (int i = 0; i < t; i++)
	{
		BST <int> bst;
		for (int j = 0; j < N; j++)
		{
			bst.insert(rand());
		}
		midH += bst.getHeight();
		maxH = std::max(bst.getHeight(), maxH);
		minH = std::min(bst.getHeight(), minH);
	}
	std::cout << maxH << " " << minH << " " << (double)midH / t;
	return 0;
}