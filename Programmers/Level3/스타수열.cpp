#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<int, int> m;
std::vector<int> number, input;

int countLength(int star) {
	int cnt = 0;

	for (int i = 0; i < input.size() - 1; i++) {
		int left = input[i], right = input[i + 1];
		if ((left != star && right != star) ||
			(left == star && right == star)) continue;

		cnt += 2;
		i++;
	}
	return cnt;
}

int solution(std::vector<int> a) {
	if (a.size() < 2) return 0;

	input = a;
	int result = 0;

	for (int i = 0; i < a.size(); i++) {
		if (m.find(a[i]) != m.end()) m.find(a[i])->second++;
		else {
			m.insert({ a[i], 1 });
			number.push_back(a[i]);
		}
	}
	if (number.size() == 1) return 0;

	for (int i = 0; i < number.size(); i++) {
		if (m.find(number[i])->second * 2 <= result) continue;

		int star = number[i];
		result = countLength(star);
	}
	return result;
}
//
//
//int main() {
//	while (true) {
//		int n;
//		cin >> n;
//		vector<int> v(n);
//		for (int i = 0; i < n; i++) {
//			cin >> v[i];
//		}
//		m.clear();
//		input.clear();
//		number.clear();
//
//		cout << solution(v) << endl;
//	}
//	return 0;
//}
