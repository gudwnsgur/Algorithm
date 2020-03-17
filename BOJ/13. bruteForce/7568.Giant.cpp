#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int** giant = new int* [N];
	for (int i = 0; i < N; ++i) {
		giant[i] = new int[2];
	}
	for (int i = 0; i < N; i++) {
		cin >> giant[i][0] >> giant[i][1];
	}

	int* ratio = new int[N];
	for (int i = 0; i < N; i++) ratio[i] = 1;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (giant[i][0] < giant[j][0] && giant[i][1] < giant[j][1])
				ratio[i]++;

	for (int i = 0; i < N; i++) cout << ratio[i] << " ";
	return 0;

}