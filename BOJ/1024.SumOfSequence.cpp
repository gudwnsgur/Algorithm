#include <iostream>
using namespace std;

int main()
{
	int L;
	int N;
	cin >> N >> L;

	while (L <= 100)
	{
		if ((L % 2 == 0 && (N / L) - (L / 2) + 1 < 0) ||
			(L % 2 != 0 && (N / L) - (L / 2) < 0))
		{
			L = -1;
			break;
		}
		else if (L % 2 == 0 && ((double)N / L - N / L == 0.5)) break;
		else if (L % 2 != 0 && (N % L == 0)) break;

		L++;
	}

	if (L == -1 || L > 100) cout << "-1";

	else {
		int i = (N / L) - (L / 2);
		if (L % 2 == 0) i++;

		for (; i <= (N / L) + (L / 2); i++) cout << i << ' ';
	}

	return 0;
}