#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[13]{0, };
int answer=0;

bool promising(int length, int n) {
    for(int i=0; i<length-1; i++) {
        if(arr[i] == arr[length-1]) return false;
        if((length-1)-i == arr[length-1]-arr[i] ||
            i-(length-1) == arr[length-1]-arr[i]) return false;
    }
    return true;
}

void dfs(int length, int n) {
    if(promising(length,n)) {
        if(length==n) {
            answer++;
            for(int i=0; i<n; i++) cout << arr[i];
            cout << endl;
            return ;
        }
        for(int i=1; i<=n ; i++) {
            arr[length]=i;
            dfs(length+1, n);
        }
    }
}

int solution(int n) {
    dfs(0,n);
    return answer;
} 