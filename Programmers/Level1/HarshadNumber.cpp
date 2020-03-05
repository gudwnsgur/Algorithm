#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int n=0, tmp=x;
    
    do {
        n += tmp%10;
        tmp /= 10;
    }while(tmp>0);
    
    return !(x%n);
}