#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	int cnt = n - 1;
	for (int i = 1; i < 2 * n; i++)	{
		for (int j = 1; j < 2 * n; j++)		
        {
			if (j >= n - cnt && j <= n + cnt)
				cout << "*";
			else if (j < n - cnt)
				cout << " ";
		}
        
		if (i < n) cnt--;
		else cnt++;
		cout << "\n";
	}
}