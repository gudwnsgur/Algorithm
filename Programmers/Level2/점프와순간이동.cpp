#include <iostream>
using namespace std;

int solution(int n)
{
    int w = 0;
    while (n > 0)
    {
        w += n % 2;
        n /= 2;
    }
    return w;
}