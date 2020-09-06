#include <string>
#include <vector>
using namespace std;
string week[7] = {"THU", "FRI", "SAT" , "SUN", "MON", "TUE", "WED",  };
int day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
	int result = 0;
	while (a--) result += day[a-1];
	return week[(result+b)%7];
}

