#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int ans = brown/2 - 2;
    int depth;
    for(int i=1; i<=ans/2 ;i++) {
        if(i*(ans-i) == red) {
            depth = i;
            break;
        }
    }
    answer.push_back((ans-depth)+2);  
    answer.push_back(depth+2);
    return answer;
}