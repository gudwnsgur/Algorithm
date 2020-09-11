#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> camera;

bool compare(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {

	sort(routes.begin(), routes.end(), compare);
	camera.push_back(routes[0][1]);

	for (int i = 1; i < routes.size(); i++) {
		if ( routes[i][0] > camera[camera.size() - 1]) camera.push_back(routes[i][1]);
	}

	return camera.size();
}