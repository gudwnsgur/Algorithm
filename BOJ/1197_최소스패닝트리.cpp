#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int v, e;
int a, b, c;
int result = 0;
vector<int> parent;

int getParent(int node) {
	if (parent[node] == node) return node;
	return getParent(parent[node]);
}
bool findUnion(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	a < b ? parent[b] = a : parent[a] = b;
	return;
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int > b) {
	return a.Y < b.Y;
}
int main() {
	cin >> v >> e;
	parent = vector<int>(v + 1);
	for (int i = 1; i <= v; i++) parent[i] = i;

	vector<pair<pair<int, int>, int>> value;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		value.push_back({ {a,b}, c });
	}
	sort(value.begin(), value.end(), compare);
	
	for (int i = 0; i < value.size(); i++) {
		int src = value[i].X.X, dest = value[i].X.Y;
		if (!findUnion(src, dest)) {
			result += value[i].Y;
			unionParent(src, dest);
		}
	}
	cout << result << endl;
	return 0;
}
