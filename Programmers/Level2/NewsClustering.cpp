#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	string tmp = "";
	vector<string> v1, v2;
	for (int i = 0; i < str1.size() - 1; i++) {
		tmp = "";

		tmp.push_back(tolower(str1[i]));
		tmp.push_back(tolower(str1[i + 1]));
		if ((tmp[0] >= 'a' && tmp[0] <= 'z') && (tmp[1] >= 'a' && tmp[1] <= 'z'))
			v1.push_back(tmp);
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		tmp = "";
		tmp.push_back(tolower(str2[i]));
		tmp.push_back(tolower(str2[i + 1]));
		if ((tmp[0] >= 'a' && tmp[0] <= 'z') && (tmp[1] >= 'a' && tmp[1] <= 'z'))
			v2.push_back(tmp);
	}
	if (!v1.size() && !v2.size()) return 65536;
	if (!v1.size() || !v2.size()) return 0;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << ' ';
	}
	int idx1 = 0, idx2 = 0;
	int molcule = 0, denominator = 0;
	while (1) {
		if (v1[idx1] == v2[idx2]) {
			denominator++; molcule++;
			idx1++; idx2++;
		}
		else if (v1[idx1] < v2[idx2]) {
			idx1++;
			denominator++;
		}
		else {
			idx2++;
			denominator++;
		}
		if (idx1 >= v1.size() || idx2 >= v2.size()) break;
	}
	cout << v1.size() - idx1 << " " << v2.size() - idx2 << endl;
	denominator += (v1.size() - idx1 == 0) ? v2.size() - idx2 : v1.size() - idx1;

	cout << molcule << '/' << denominator << endl;
	answer = (65536 * molcule) / denominator;
 	return answer;
}

int main() {
	int result = solution("E=M*C^2", "e=m*c^2");
	cout << result << endl;
	return 0;
}