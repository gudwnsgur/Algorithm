#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

/*  1. segmentation fault

#define MAX 10000000
bool existed[MAX]{ false, };

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (int i = 0; i < room_number.size(); i++) {
		long long k = room_number[i];
		while (existed[k]) k++;
		existed[k] = true;
		answer.push_back(k);
	}
	return answer;
}
*/

/*
2. 효율성 시간초과

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	map<long long, long long> m;
	for (int i = 0; i < room_number.size(); i++)
	{
		long long K = room_number[i];
		while (m.count(K)) {
			K++;
		}
		m.insert(make_pair(K, room_number[i]));
		answer.push_back(K);
	}

	return answer;
}
*/


vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;


	return answer;
}

// testCase;
int main() {
	vector<long long> room = { 1,3,4,1,3,1 };
	vector<long long> result = solution(10, room);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	return 0;
}