#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        int max = -1;
        bool correct = true;
        for (int j = 0; j < skill.size(); j++) {
            char ch = skill[j]; // j 번째 스킬트리 
            int pos = find(skill_trees[i].begin(), skill_trees[i].end(), ch) - skill_trees[i].begin();

            if (max > pos)  correct = false;
            max = pos;
        }

        if (correct) answer++;
    }

    return answer;
}
int main() {
    vector<string> st = { "BACDE", "CBADF", "AECB", "BDA"};
    string skill = "CBD";
    cout << solution(skill, st);

    return 0;
}