#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "수";
    for(int i=1; i<n; i++) {
        if(i%2 != 0 ) answer += "박";
        else answer += "수";
    }
    return answer;
}