#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string relations[20][9] = {"",};
bool visited[9] = { false , };
bool candidated[8889]; 	// candidated[abcd] : (a,b,c,d) = 후보키
int arr[9];
int n, m, result = 0;

bool checkCandidate(int length) {
	int number = 0;

	// candidate 될수 있으면 arr로 candidate[arr] = true 시키고 return true;
	// 될수없으면 false;
	if (arr[0] == 2 && arr[1] == 3) return true;
	return false;
}

void dfs(int length, int cnt) {
	if (length == cnt) {
		int number = 0;
		for (int i = 0; i < length; i++) {
			cout << arr[i] << ' ';
		}cout << endl;
		if (length == 2 && checkCandidate(2)) {
			candidated[arr[1] * 10 + arr[0]] = true;
			result++;
		}
		else {
			vector<int> v;
		}
		return;
	}
	for (int i = 1; i <= m; i++) {
		if (length != 0 && arr[length - 1] >= i);
		else if (!visited[i] && !candidated[i]) {
			visited[i] = true;
			arr[length] = i;
			dfs(length + 1, cnt);
			visited[i] = false;
		}
	}
}

int solution(vector<vector<string>> relation) {
	n = relation.size();
	m = relation[0].size();
	for (int i = 1; i <= m; i++) candidated[i] = true;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			relations[i][j] = relation[i][j-1];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n-1; j++) {
			if (!candidated[i]) break;
			for (int k = j + 1; k < n; k++) {
				if (!relations[j][i].compare(relations[k][i])) {
					candidated[i] = false;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) if (candidated[i]) result++; // 후보키 하나일때

	for (int i = 2; i <= m; i++) {
		int cnt = 0;
		for (int j = 1; j <= m; j++) {
			if (!candidated[j]) cnt++;
		}
		if (cnt >= i) dfs(0, i);
	}

	return result;
}
int main() {

	return 0;
}