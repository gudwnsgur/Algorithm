#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int node[101];
int totalCost = 0;

bool compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}
int getParent(int cnt) {
	if (node[cnt] == cnt) return cnt;
	return node[cnt] = getParent(node[cnt]);
}
int findCycle(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b ? 1 : 0;
}

void unionParent(int a, int b) {
	a = getParent(a);
	b= getParent(b);

	if (a<b) node[b] = a;
	else node[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
	for (int i = 0; i < n; i++) node[i] = i;
	sort(costs.begin(), costs.end(), compare);

	for (int i = 0; i < costs.size(); i++) {
		if (!findCycle(costs[i][0], costs[i][1])) {
			totalCost += costs[i][2];
			unionParent(costs[i][0], costs[i][1]);
		}
	}
	return totalCost;
}