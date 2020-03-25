#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n==1 || s==1 || n>s)  {
        answer.push_back(-1);
        return answer;
    }
    int dividor = s/n, remainder = s%n, i=0;
    for(; i<n-remainder ;i++) answer.push_back(dividor);
    for(; i<n; i++) answer.push_back(dividor+1);

    return answer;
}