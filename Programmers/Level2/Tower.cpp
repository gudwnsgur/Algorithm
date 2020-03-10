#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for(int i= heights.size()-1 ; i>=0 ; i--) {
        int j=i-1;
        for(; j>=0; j--) {
            if(heights[i]<heights[j]) {
                answer.push_back(j+1);
                break;
            }
        }
        if(j<0) answer.push_back(0);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}