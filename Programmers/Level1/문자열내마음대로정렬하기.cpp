#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int num;

bool compare(string a, string b) {
	if (a[num] == b[num]) return a < b;
	return a[num] < b[num];
}

vector<string> solution(vector<string> strings, int n) {
	num = n;
	sort(strings.begin(), strings.end(), compare);
	return strings;
} 