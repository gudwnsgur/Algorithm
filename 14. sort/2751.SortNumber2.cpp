#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;

    int* arr = new int[n];
    int maxNum = 0;
    for(int i=0; i<n ; i++) {
        cin >> arr[i];
        if(arr[i] > maxNum) maxNum = arr[i];
    }
    
    int* count = new int[maxNum];
    for(int i=0; i<maxNum; i++) {
        count[i] = 0;
    }
    for(int i=0; i<n ; i++) {
        count[arr[i]]++;
    }

    for(int i=1 ; i<maxNum ; i++) {
        count[i] += count[i-1];
    } 

    int* sortArr = new int[n];
    for(int i=n-1 ; i>=0 ; i++) {
        sortArr[count[arr[i]]] = arr[i];
        count[arr[i]]--;
    }
        for(int i=0; i<n ; i++) {
        cout << sortArr[i];
    }
    
    return 0;
}