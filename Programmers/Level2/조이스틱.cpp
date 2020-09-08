#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string name) {
	vector<int> v;
	int answer = 0;

	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A') v.push_back(i);
	}
	if (v.size() == 0) return answer;

	answer = v[v.size() - 1];
	answer = min(answer, (int)name.size() - v[0]);
	int leftMax = 0, rightMax = 0;

	if (v.size() > 1) {
		for (int i = 0; i < v.size() - 1; i++) {
			leftMax = v[i]; 
			rightMax = v[i + 1];
			if (leftMax <= name.size() / 2 && rightMax >= name.size() / 2) break;
		}
		answer = min(answer, 2 * leftMax + ((int)name.size() - rightMax));
		answer = min(answer, 2 * ((int)name.size() - rightMax) + leftMax);
	}

	cout << leftMax << ' ' << rightMax << endl;
	cout << v[v.size() - 1] << ' ' << (int)name.size() - v[0] << ' ' << 2 * leftMax + ((int)name.size() - rightMax) << ' ' << 2 * ((int)name.size() - rightMax) + leftMax << endl;

	for (int i = 0; i < name.size(); i++) {
		if (name[i] <= 'N') answer += name[i] - 65;
		else answer += 26 - (name[i] - 65);
	}
	return answer;
}
int main() {
	cout << solution("ABABAAAAABA") << endl;
	return 0;
}