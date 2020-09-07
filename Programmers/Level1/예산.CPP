#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(),d.end());

    for(answer = 0;answer <d.size();answer++){
        if(budget < d[answer]) break;
        budget -= d[answer];
    }

    return answer;
}