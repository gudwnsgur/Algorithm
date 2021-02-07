#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<char> alp;
vector<bool> visited;
vector<char> res;

char vowels[5] = { 'a', 'e', 'i', 'o','u' };

bool promise() {
	int curVowels = 0, curConsonants = 0;
	for (int i = 0; i < res.size(); i++) {
		bool v = false;
		for (int j = 0; j < 5; j++) {
			if (res[i] == vowels[j]) v = true;
		}
		v ? curVowels++ : curConsonants++;
	}

	return ( curVowels >= 1 && curConsonants >= 2 );
}
void dfs(int length, int l, int c) {
	if (length == l) {
		if (promise()) {
			for (int i = 0; i < l; i++) {
				cout << res[i];
			}cout << endl;
		}
		return;
	}

	for (int i = 0; i < c; i++) {
		if (!visited[i]) {
			if (length == 0 || (length != 0 && res[length - 1] < alp[i])) {
				visited[i] = true;
				res[length] = alp[i];
				dfs(length + 1, l, c);
				visited[i] = false;
			}
		}
	}

}

int main() {
	int l, c;
	cin >> l >> c;
	alp = vector<char>(c);
	res = vector<char>(l);
	visited = vector<bool>(c, false);


	for (int i = 0; i < c; i++) cin >> alp[i];
	sort(alp.begin(), alp.end());
	dfs(0, l, c);

	return 0;
}

