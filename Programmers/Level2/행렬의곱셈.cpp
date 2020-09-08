#include <string>
#include <vector>

using namespace std;
int matrix[100][100] = { 0, };

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	int N = arr1.size(), M = arr2.size(), L = arr2[0].size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) {
			int result = 0;
			for (int k = 0; k < M; k++) {
				result += arr1[i][k] * arr2[k][j];
			}
			matrix[i][j] = result;
		}
	}
	for (int i = 0; i < N; i++) {
		vector<int> col;
		for (int j = 0; j < L; j++) {
			col.push_back(matrix[i][j]);
		}
		answer.push_back(col);
	}
	return answer;
}