#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	vector<int> card(20), tmp(20);
	for (int i = 0; i < 20; i++) card[i] = i + 1;

	int s, e;
	for (int i = 0; i < 10; i++) {
		cin >> s >> e;
		s -= 1; e -= 1;

		for (int i = 0; i < s; i++) tmp[i] = card[i];
		for (int i = e + 1; i < 20; i++) tmp[i] = card[i];

		for (int i = s, j = e; i <= e; i++, j--) tmp[i] = card[j];

		card = tmp;
	}
	for (int i = 0; i < 20; i++) cout << card[i] << ' ';
	cout << endl;
	return 0;
}
