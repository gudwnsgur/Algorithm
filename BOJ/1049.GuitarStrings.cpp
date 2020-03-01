#include <iostream>
#include <algorithm>
using namespace std;

int checkCost(int n, int minEachCost, int minPackCost) {
	int minCost = 100001;

	int a = n * minEachCost;
	int b = (n / 6) * minPackCost + (n % 6) * minEachCost;
	int c = (n / 6 + 1) * minPackCost;

	return min(minCost, min(a, min(b, c)));
}

int main()
{
	int N, M;
	cin >> N >> M;
	int minEachCost = 1001;
	int minPackCost = 1001;
	int** lineCost = new int* [M];


	for (int i = 0; i < M; i++) {
		lineCost[i] = new int[2];
		cin >> lineCost[i][0] >> lineCost[i][1];

		if (minEachCost > lineCost[i][1]) minEachCost = lineCost[i][1];
		if (minPackCost > lineCost[i][0]) minPackCost = lineCost[i][0];
	}

	cout << checkCost(N, minEachCost, minPackCost);
	return 0;
}