#include <vector>
using namespace std;


vector<int> solution(vector<int> numbers) {
	bool result[201] = { false, };
	vector<int> answer;

	for (int i = 0; i < numbers.size() - 1; i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			result[numbers[i] + numbers[j]] = true;
		}
	}
	for (int i = 0; i < 200; i++) {
		if (result[i]) answer.push_back(i);
	}
	return answer;
}