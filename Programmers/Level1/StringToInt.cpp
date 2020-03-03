#include <string>
#include <sstream>

using namespace std;

int solution(string s) {
	int answer;
    
	stringstream ss(s);
	ss >> answer;
	return answer;
} 