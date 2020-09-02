#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<int> dwarf(9);
int sum = 0;

int findFake() {
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (dwarf[i] + dwarf[j] == sum - 100) return i * 10 + j;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}
	sort(dwarf.begin(), dwarf.end());
	int fake = findFake();
	
	for (int i = 0; i < 9; i++) {
		if (i != fake / 10 && i != fake % 10) cout << dwarf[i] << endl;
	}
	return 0;
}