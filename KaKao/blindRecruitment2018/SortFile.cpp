#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;

bool cmp(pair<string, pair<string, string>> a, pair<string, pair<string, string>> b) {
	string first = a.first;
	string second = b.first;
	for (int i = 0; i < first.size(); i++) 
		first[i] = toupper(first[i]);
	for (int i = 0; i < second.size(); i++)
		second[i] = toupper(second[i]);
	
	if (first == second) {
		return stoi(a.second.first) < stoi(b.second.first);
	}else {
		return first < second;
	}
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<pair<string, pair<string, string>>> file;

	for (int i = 0; i < files.size(); i++) {
		int digitIndex = 0, j = 0;
		int tailIndex = 0;
		for (; j < files[i].size(); j++) {
			if (isdigit(files[i][j])) {
				digitIndex = j;
				break;
			}
		}
		
		for (; j < files[i].size(); j++) {
			if (!isdigit(files[i][j])) {
				tailIndex = j;
				break;
			}
		}
		if (!tailIndex) tailIndex = files[i].size();

		file.push_back(make_pair(files[i].substr(0, digitIndex), 
						make_pair(files[i].substr(digitIndex,tailIndex-digitIndex), 
							files[i].substr(tailIndex, files[i].size()-tailIndex))));
	}



	stable_sort(file.begin(), file.end(), cmp);

	for (int i = 0; i < file.size(); i++) {
		cout << file[i].first << ' ' << file[i].second.first << ' ' << file[i].second.second << endl;
	}
	for (int i = 0; i < file.size(); i++) {
		string ans = "";
		ans += (file[i].first+file[i].second.first+file[i].second.second);
		answer.push_back(ans);
	}
	return answer;
}

int main() {
	vector <string> a = { "foo9.txt", "foo010bar020.zip", "F-15" };
	solution(a);
	return 0;
}
// 한글자 이상 문자 + 1~5 숫자 (0포함)  + tail