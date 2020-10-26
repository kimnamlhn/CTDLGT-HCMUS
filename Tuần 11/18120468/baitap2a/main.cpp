#include <iostream>
#include <vector>
using namespace std;
#define V 5 


bool isValidEdge(int u, int v, vector<bool> inMST)
{
	if (u == v)
		return false;
	if (inMST[u] == false && inMST[v] == false)
		return false;
	else if (inMST[u] == true && inMST[v] == true)
		return false;
	return true;
}

void primMST(int cost[][V])
{
	vector<bool> inMST(V, false);

	inMST[0] = true;


	int edge_count = 0, mincost = 0;
	while (edge_count < V - 1) {

		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (cost[i][j] < min) {
					if (isValidEdge(i, j, inMST)) {
						min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		if (a != -1 && b != -1) {
			printf("Edge %d:(%d, %d) cost: %d \n",
				edge_count++, a, b, min);
			mincost = mincost + min;
			inMST[b] = inMST[a] = true;
		}
	}
	printf("\n Minimum cost= %d \n", mincost);
}

int main()
{
	/* Let us create the following graph
		  2    3
	  (0)--(1)--(2)
	   |   / \   |
	  6| 8/   \5 |7
	   | /     \ |
	  (3)-------(4)
			9          */
	int cost[][V] = {
		{ INT_MAX, 2, INT_MAX, 6, INT_MAX },
		{ 2, INT_MAX, 3, 8, 5 },
		{ INT_MAX, 3, INT_MAX, INT_MAX, 7 },
		{ 6, 8, INT_MAX, INT_MAX, 9 },
		{ INT_MAX, 5, 7, 9, INT_MAX },
	};
	cout << "Prim's MST for Adjacency Matrix: " << endl;
	primMST(cost);

	//adjacency lists tốt hơn adjacency matrix
	//vì với adjacency lists, chúng ta tận dụng hiệu quả hơn về mặt không gian bộ nhớ
	//tránh lãng phí bộ nhớ

	return 0;
}