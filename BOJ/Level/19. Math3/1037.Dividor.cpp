#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int *arr = new int[n];
    int min= 1000001, max=1;
    
    for(int i=0; i<n ; i++ ) {
        cin >> arr[i];
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max ) max = arr[i];
    }
    cout << min*max ;
    return 0;
}