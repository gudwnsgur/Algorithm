#include <iostream>
using namespace std;

int n, m;
int arr[9]; // 1~8  사용

void dfs(int length) 
{
	if (length == m) {
		for (int i = 0; i < m; i++) 
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	} 

	for (int i = 1; i <= n; i++)  
	{
			arr[length] = i;	
			dfs(length + 1); 
	}

}
int main() {
	cin >> n >> m;
	dfs(0);

	return 0;
}