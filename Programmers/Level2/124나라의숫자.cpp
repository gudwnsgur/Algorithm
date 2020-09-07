#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n > 0) {
        if (n % 3 == 0) {
            answer = "4" + answer;
            n = n / 3 - 1;
        }
        else {
            answer = to_string(n % 3) + answer;
            n /= 3;
        }
    }
    return answer;
}