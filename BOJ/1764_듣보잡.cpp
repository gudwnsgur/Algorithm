#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	vector<string> listen;
	vector<string> watch;
	vector<string> noListenNoWatch;
	string str;
	int n, m, result=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		listen.push_back(str);
	}
	for (int i = 0; i < m; i++) {
		cin >> str;
		watch.push_back(str);
	}
	sort(listen.begin(), listen.end());
	sort(watch.begin(), watch.end());

	int listenIndex = 0, watchIndex = 0;
	while (listenIndex < listen.size() && watchIndex < watch.size() ) {
		if (listen[listenIndex] == watch[watchIndex]) {
			result++;
			noListenNoWatch.push_back(listen[listenIndex]);
			listenIndex++;	watchIndex++;
		}
		else if (listen[listenIndex] > watch[watchIndex]) watchIndex++;
		else listenIndex++;
	}

	cout << result << endl;
	for (int i = 0; i < noListenNoWatch.size(); i++) cout << noListenNoWatch[i] << endl;
	return 0;
}
