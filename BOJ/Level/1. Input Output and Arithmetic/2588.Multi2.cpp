#include <iostream>
using namespace std;

int main () {
    int num1, num2;
    int num2_unit, num2_tens, num2_hunds;
    cin >> num1;
    cin >> num2;

    num2_unit = num2%10;
    num2_tens = (num2/10)%10;
    num2_hunds = num2/100;

    cout << num1 * num2_unit << endl;
    cout << num1 * num2_tens << endl;
    cout << num1 * num2_hunds << endl;
    cout << num1*num2;
    return 0;
}