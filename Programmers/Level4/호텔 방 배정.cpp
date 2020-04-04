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

/*  2. 효율성 시간초과

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	map<long long, long long> m;
	for (int i = 0; i < room_number.size(); i++) {
		long long node = room_number[i];

		if (m[node] != 0) {
			while (m[node] != 0) {
				node = m[node] + 1;
			}
		} // map에 node값이 존재하면 해당 노드의 value+1 값 확인

		m[node] = node;
		answer.push_back(node);
	}
	return answer;
}

*/


// 시간초과
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	map<long long, long long> m;
	for (int i = 0; i < room_number.size(); i++) {
		long long node = room_number[i];

		if (m[node] != 0) {
			while (m[node] != 0) {
				node = m[node] + 1;
			}
		} // map에 node값이 존재하면 해당 노드의 value+1 값 확인

		m[node] = node;
		m[room_number[i]] = node;
		answer.push_back(node);
	}
	return answer;
}

// testCase;
int main() {
	vector<long long> room = { 1,3,4,1,3,1,1,3,100,2,6,1,2,3,6,1,1,1,1 };
	vector<long long> result = solution(10, room);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	return 0;
}