#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);
    
    if(answer==sqrt(n)) return pow(sqrt(n)+1,2);
    else return -1;
}