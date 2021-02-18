#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 1000000001
#define MIN 0
using namespace std;

int n, m;
vector<int> arr;
vector<pair<int, int>> tree;


pair<int, int> initTree(int node, int s, int e) {
	if (s == e) return tree[node] = { arr[s], arr[e] };

	pair<int, int> left = initTree(node * 2, s, (s + e) / 2);
	pair<int, int> right = initTree(node * 2 + 1, (s + e) / 2 + 1, e);


	return 	tree[node] = { (left.first < right.first ? left.first : right.first) ,
						(left.second > right.second ? left.second : right.second) };
}

pair<int, int> getNum(int node, int s, int e, int left, int right) {
	if (left <= s && e <= right) return tree[node];
	if (e < left || right < s) return{ MAX , MIN};

	pair<int, int> a = getNum(node * 2, s, (s + e) / 2, left, right);
	pair<int, int> b = getNum(node * 2 + 1, (s + e) / 2 + 1, e, left, right);
	return{ (a.first < b.first ? a.first : b.first) , (a.second > b.second ? a.second : b.second) };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	arr = vector<int>(n + 1);
	tree = vector<pair<int, int>>(1 << ((int)ceil(log2(n)) + 1));

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	initTree(1, 1, n);


	int left, right;
	for (int i = 0; i < m; i++) {
		cin >> left >> right;
		pair<int, int> res = getNum(1, 1, n, left, right);
		cout << res.first << ' ' << res.second << endl;
	}
	return 0;
}
