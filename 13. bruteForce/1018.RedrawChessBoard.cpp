#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 50;
string chess[MAX];
int N, M;
string whiteFirst[8] = {
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"}
};
string blackFirst[8] = {
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"}    
};
int countWhiteFirst(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            if (chess[i][j] != whiteFirst[i-y][j-x]) {
                cnt++;
            }
        }
    }
    return cnt;
}
int countBlackFirst(int y, int x) {
    int cnt = 0;
    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            if (chess[i][j] != blackFirst[i-y][j-x]) {
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> chess[i];
    }
    int result = 99999999;
    for (int i = 0; i+7 < N; i++) {
        for (int j = 0; j+7 < M; j++) {
            result = min(result, min(countWhiteFirst(i,j), countBlackFirst(i,j)));
        }
    }
    cout << result <<endl;
    return 0;
}


