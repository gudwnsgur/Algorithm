#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        vector<char> compare;

        for (int k = 0; k < skill_trees[i].size(); k++) {
            for (int j = 0; j < skill.size(); j++) {
                if (skill[j] == skill_trees[i][k]) {
                    char tmp = skill[j];
                    compare.push_back(tmp);
                }
            }
        }
        bool check = true;;
        for (int c = 0; c < compare.size(); c++) {
            if (skill[c] != compare[c]) {
                check = false;
            }
        }
        if (check)answer++;
    }

    return answer;
}