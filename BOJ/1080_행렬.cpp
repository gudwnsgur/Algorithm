#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int n, m, cnt=0;
bool A[50][50] = { false, };
bool B[50][50] = { false, };

int main() {
	cin >> n >> m;
	string str;
	for (int i = 0; i < n*2; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (i < n) A[i][j] = (str[j] == '1' ? true : false);
			else B[i%n][j] = (str[j] == '1' ? true : false);
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (A[i][j] != B[i][j]) {
				cnt++;
				for (int k = 0; k < 9; k++) 
					A[(k / 3) + i][(k % 3) + j] = !A[(k / 3) + i][(k % 3) + j];
			}
		}
	}
	bool checkTrue = true;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			if (A[i][j] != B[i][j]) checkTrue = false;
		}
	}
	if (checkTrue) cout << cnt << endl;
	else cout << "-1" << endl;
	return 0;
}