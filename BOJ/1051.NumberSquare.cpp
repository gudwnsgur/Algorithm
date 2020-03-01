#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int findSquare(int n, int m, int** square) {
	int maxLength = min(n, m);

	while (maxLength != 1) {
		for (int i = 0; i <= n - maxLength; i++) {
			for (int j = 0; j <= m - maxLength; j++) {
				if (square[i][j] == square[i][maxLength + j - 1] &&
					square[i][j] == square[maxLength + i - 1][j] &&
					square[i][maxLength + j - 1] == square[maxLength + i - 1][maxLength + j - 1]
					)
					return maxLength * maxLength;
			}
		}
		maxLength--;
	}
	return maxLength;
}

int main() {
	int N, M;
	cin >> N >> M;
	int** square = new int* [N];

	for (int i = 0; i < N; i++) {
		square[i] = new int[M];
		for (int j = 0; j < M; j++) {
			scanf("%1d", &square[i][j]);
		}
	}

	cout << findSquare(N, M, square);

	return 0;

}