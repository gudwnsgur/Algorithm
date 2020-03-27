#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq; 


    int min = 0, pqSize = 0;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i].front() == 'I') {
            string s = "";
            for (int j = 2; j < operations[i].size(); j++) {
                s += operations[i][j];
            }
            dq.push_back(stoi(s));
            pqSize++;

            sort(dq.begin(), dq.end());
        }
        else if (pqSize && operations[i].front() == 'D') {
            if (operations[i][3] == '1') dq.pop_front();
            else dq.pop_back(); 
            pqSize--;
        }
    }
    for (int i = 0; i < dq.size(); i++) cout << dq.at(i) << ' ';

    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }

    answer.push_back(dq.back());
    answer.push_back(dq.front());
    return answer;

}