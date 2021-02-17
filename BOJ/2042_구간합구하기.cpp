#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define ll unsigned long long
using namespace std;

int n, m, k;
vector<ll> arr;
vector<ll> segmentTree;

ll initTree(int node, int s, int e) {
	if (s == e) return segmentTree[node] = arr[s];
	// 리프노드에 값 추가

	return segmentTree[node] = initTree(node * 2, s, (s + e) / 2) 
							+ initTree(node * 2 + 1, (s + e) / 2 + 1, e);
}

ll getSum(int node, int s, int e, int left, int right) {
	if (left > e || right < s) return 0;
	// 범위 밖의 값을 가진 node

	if (left <= s && e <= right) return segmentTree[node];
	// 범위 안에 있는 값을 가진 node

	return getSum(node * 2, s, (s + e) / 2, left, right)
		+ getSum(node * 2 + 1, (s + e) / 2 + 1, e, left, right);
	// 걸쳐있는 node
}

void updateTree(int node, int s, int e, int dest, ll diff) {
	if (dest > e || dest < s) return;
	// dest가 범위 안에 존재하지 않음

	segmentTree[node] += diff;
	// 범위 안의 node값 변경

	if (s != e) {
		updateTree(node*2, s, (s+e)/2, dest, diff);
		updateTree(node * 2 + 1, (s + e) / 2 + 1, e, dest, diff);
	}
	// 리프노드까지
}

int main() {
	cin >> n >> m >> k;
	
	// 배열, 세그먼트트리 초기화
	arr = vector<ll>(n+1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	segmentTree = vector<ll>((1 << ((int)ceil(log2(n)) + 1)));
	initTree(1, 1, n); 

	/*
	// 세그먼트 트리 출력
		for (int i = 1; i < segmentTree.size(); i++)
			cout << segmentTree[i] << ' ';
		cout << endl;
	*/

	for (int i = 0; i < m+k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			updateTree(1, 1, n, b, c - arr[b]);
			arr[b] = c;
		}
		else cout << getSum(1, 1, n, b, c) << endl;

	}

	return 0;
}
