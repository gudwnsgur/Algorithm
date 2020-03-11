#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    int x = (v[0][0]==v[1][0]) ? v[0][0]+v[2][0]-v[1][0] : v[0][0]+v[1][0]-v[2][0];
    int y = (v[0][1]==v[1][1]) ? v[0][1]+v[2][1]-v[1][1] : v[0][1]+v[1][1]-v[2][1];
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}