#include <string>
#include <sstream>

using namespace std;

int solution(string s) {
	int answer;
    
	stringstream ss(s);
	ss >> answer;
    //same as :  answer=stoi(s);

	return answer;
} 