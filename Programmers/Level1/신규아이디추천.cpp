#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
	string answer = "", tmp = "";
	int idx = 0;

	// 1단계
	for (int i = 0; i < new_id.size(); i++) new_id[i] = tolower(new_id[i]);
	cout << "1단계 : " << new_id << endl;

	// 2단계
	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_' ||
			(new_id[i] >= 97 && new_id[i] <= 122) ||
			(new_id[i] >= 48 && new_id[i] <= 57)) {
			tmp.push_back(new_id[i]);
		}
	}
	cout << "2단계 : " << tmp << endl;
	new_id.clear();

	for (int i = 0; i < tmp.size(); i++) {
		if (new_id.size() != 0 && (new_id.back() == '.' && tmp[i] == '.'));
		else new_id.push_back(tmp[i]);
	}
	cout << "3단계 : " << new_id << endl;
	tmp.clear();

	for (int i = 0; i < new_id.size(); i++) {
		if (i == 0 && new_id[i] == '.');
		else if (i == new_id.size() - 1 && new_id[i] == '.');
		else tmp.push_back(new_id[i]);
	}
	new_id.clear();
	cout << "4단계 : " << tmp << endl;


	if (tmp.empty()) tmp = "a";
	cout << "5단계 : " << tmp << endl;

	if (tmp.size() >= 16) {
		tmp = tmp.substr(0, 15);
		if (tmp.back() == '.')
			tmp = tmp.substr(0, 14);
	}
	cout << "6단계 : " << tmp << endl;

	if (tmp.size() == 1) {
		tmp.push_back(tmp.back());
		tmp.push_back(tmp.back());
	}
	else if (tmp.size() == 2) tmp.push_back(tmp.back());
	cout << "7단계 : " << tmp << endl;

	return tmp;
}
