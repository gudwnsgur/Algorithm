#include <string>
#include <vector>
#include <iostream>
using namespace std;

int num[9] = {-1, };
int arr[9] = { 0, };
bool pos = false;
bool cal = false;
vector<int> v;

void calculate(int length, int n, int src, int dest) {
	if (cal) return;
	if (length == n) {
		if (src == dest) cal = true;
		return;
	}
	if (length == 0) calculate(length + 1, n, v[length], dest);

	calculate(length + 1, n, src + v[length], dest);
	calculate(length + 1, n, src - v[length], dest);
	calculate(length + 1, n, src * v[length], dest);
	if(v[length] != 0) calculate(length + 1, n, src / v[length], dest);
}

bool promise(int length, int dest) {
	v = vector<int>(length);
	for (int i = 0; i < length; i++) v[i] = num[arr[i]];
	
	cal = false;
	calculate(0, length, 0, dest);
	return cal;
}

void dfs(int length, int cur, int total, int dest) {
	if (pos) return;
	
	if (cur == total ) {
		if (promise(length, dest)) pos = true;
		return;
	}

	for (int i = total; i >= 1; i--) {
		if (cur + i <= total) {
			arr[length] = i;
			dfs(length + 1, cur + i, total, dest);
		}
	}
}

bool possible(int n, int cnt, int dest) {
	pos = false;
	dfs(0, 0,  cnt, dest);
	return pos;
}

int solution(int N, int number) {
	int n = N;
	for (int i = 1; i <= 8; i++) {
		num[i] = n;
		n = n * 10 + N;
	}

	for (int i = 1; i <= 8; i++) {
		if (possible(N, i, number)) return i;
	}
	return -1;
}
