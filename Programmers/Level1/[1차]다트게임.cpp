#include <string>
#include <math.h>
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

int solution(string dartResult) {

    vector<pair<int, char>> option;

    int scoreIndex = 0, bonusIndex = 0;
    int score[3]{ 0,0,0 };
    char bonus[3];

    for (int i = 0; i < dartResult.size(); i++) 
    {
        if (isdigit(dartResult[i]) && dartResult[i + 1] != '0') 
             score[scoreIndex++] = dartResult[i] - 48;

        else if (isdigit(dartResult[i])) {
            score[scoreIndex++] = 10;
            i++; 
        }
        // 점수 검사 ( 0~10 )

        if (dartResult[i] == 'D' || dartResult[i] == 'S' || dartResult[i] == 'T')
            bonus[bonusIndex++] = dartResult[i];
        // 보너스 검사 (D, S, T)

        if (dartResult[i] == '#' || dartResult[i] == '*') 
            option.push_back(make_pair(scoreIndex-1, dartResult[i]));
        // 옵션 검사 (#, *)
    }

    for (int i = 0; i < 3; i++) {
        score[i] = pow(score[i], bonus[i] == 'S' ? 1 : bonus[i] == 'D' ? 2 : 3);
        if (!(option.empty()) && option.front().first == i) {
            cout << option.front().first << ' ' << option.front().second << endl;
            if (option.front().second == '#') score[i] *= -1;
            else {score[i - 1] *= 2; score[i] *= 2; }
            option.erase(option.begin());
        }
    }
    return score[0] + score[1] + score[2];
}
