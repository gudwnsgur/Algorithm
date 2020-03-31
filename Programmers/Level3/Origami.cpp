#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n)
{
	vector<int> answer;
	vector<pair<int, string>> dp;

	string str = "0";
	dp.push_back(make_pair(1, "0"));    // n=1 초기화

	for (int i = 2, j=2; i <= n; i++, j*=2) {
		str = dp.back().second + '0' + dp.back().second;
		str[j / 2 + j -1] = '1';
		dp.push_back(make_pair(i, str));
	} // n-1 값 이용
    
	for (int i = 0; i < str.size(); i++) answer.push_back(str[i] - 48);
	return answer;
}