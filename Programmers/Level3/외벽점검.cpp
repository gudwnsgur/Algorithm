#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

vector<int> dists, weaks;
vector<int> v;
bool visited[8] = { false, };
int arr[8] = { 0, };
int impossible = 0, curCnt = 0;
int answer;
int dfsCnt = 0;

void dfs(int length, int n, int node) {
	if (length == n) {
		dfsCnt++;
		vector<int> d;
		for (int i = 0; i < n; i++) d.push_back(arr[i]);
		int vIndex = 0, dIndex = 0, curCnt = 0;

		for (; vIndex < v.size() && dIndex < dists.size(); dIndex++) {
			curCnt++;
			node += d[dIndex];
			while (vIndex < v.size() && node >= v[vIndex]) vIndex++;
			node = v[vIndex];
		}
		if (vIndex < v.size() && dIndex == d.size()) impossible++;
		answer = min(answer, curCnt);
		return;
	}

	for (int i = 0; i < dists.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[length] = dists[i];
			dfs(length + 1, n, node);
			visited[i] = false;
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	answer = dist.size();
	weaks = weak, dists = dist;

	for (int i = 0; i < weak.size(); i++) {
		v.clear();
		for (int j = i; j < i + weak.size(); j++) {
			v.push_back(j / weak.size() ? weak[j%weak.size()]+n : weak[j]);
		}
		int node = weaks[i];
		dfs(0, dist.size(), node);
	}
	cout << "DFS : " << dfsCnt << endl;
	if (impossible == dist.size()) return -1;
	return answer;
}