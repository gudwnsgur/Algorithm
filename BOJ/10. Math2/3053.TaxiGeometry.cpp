#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double radius;
    cin >> radius;
    
    printf("%.6f\n", radius*radius*M_PI);
    printf("%.6f\n", radius*radius*2);
	return 0;
}
