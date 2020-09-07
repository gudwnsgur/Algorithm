#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm> 

using namespace std;

bool compare(pair<double, int> a, pair<double,int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<double, int>>  failureRate;

    for (int i = 1; i <= N ; i++) {
        int noClear = 0, arriver = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] >= i) arriver++;
            if (stages[j] == i) noClear++;
        }
        cout << arriver << ' ' << noClear << endl;
        if (arriver == 0) failureRate.push_back(make_pair(0,i));
        else failureRate.push_back(make_pair((double)noClear/arriver, i));
    }

    sort(failureRate.begin(), failureRate.end(), compare);
    for (int i = N-1; i >= 0; i--)
        answer.push_back(failureRate[i].second);
    return answer;
}