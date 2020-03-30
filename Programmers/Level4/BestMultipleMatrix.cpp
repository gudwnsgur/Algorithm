// not finished
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	if (a.back() == b.back())
		return a.front() < b.front();
	return a.back() > b.back();
}

int solution(vector<vector<int>> matrix_sizes) {
	int answer = 0;
	sort(matrix_sizes.begin(), matrix_sizes.end(), cmp);

	for (int i = 0; i < matrix_sizes.size(); i++) {
		cout << matrix_sizes[i][0] << ' ' << matrix_sizes[i][1] << endl;
	}
	for (int i = 0; i < matrix_sizes.size(); i++) {
		for (int j = i + 1; j < matrix_sizes.size(); j++) {
			if (matrix_sizes[i].back() == matrix_sizes[j].front()) {
				answer += matrix_sizes[i].front() * matrix_sizes[i].back() * matrix_sizes[j].back();
				matrix_sizes[j].front() = matrix_sizes[i].front();
				break;
			}
			else if (matrix_sizes[i].front() == matrix_sizes[j].back()) {
				answer += matrix_sizes[i].front() * matrix_sizes[i].back() * matrix_sizes[j].front();
				matrix_sizes[j].back() = matrix_sizes[i].back();
				break;
			}
		}
	}
	
	return answer;
}

int main() {
	vector<vector<int>> testCase1 = { {5,3},{3,10},{10,6},{6,3},{3,5} };
	cout << "sol : " << solution(testCase1) << endl;

	vector<vector<int>> testCase2 = { {5,3},{10,6},{3,10}};
	cout << "sol : " << solution(testCase2) << endl;

	return 0;
}