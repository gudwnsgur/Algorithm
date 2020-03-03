#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(string s) {
    sort(s.begin(), s.end());

    return ( (s.size() == 4 || s.size() == 6 ) &&
              s.back() <= '9' && s.front() >= '0' );
}