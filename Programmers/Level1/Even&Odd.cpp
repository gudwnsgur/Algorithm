#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return (num==0||num%2==0) ? "Even" : "Odd";
}