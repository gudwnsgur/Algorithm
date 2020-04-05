#include <iostream>
using namespace std;

int n, m;
int arr[9]; // 1~8  사용
bool visited[9]; // 1~8  사용

void dfs(int length) 
{
	// 정답이 될 수 있다면 출력
	if (length == m) {
		for (int i = 0; i < m; i++) 
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	} 

	// 정답이 될수 없을 때 ( 길이가 덜 참 )
	for (int i = 1; i <= n; i++) // 1~n 
	{
		if (!visited[i])	// i 를 방문하지 않았다면
		{
			arr[length] = i;	
			visited[i] = true;	

			dfs(length + 1); 

			visited[i] = false; 
		}
	}

}
int main() {
	cin >> n >> m;
	dfs(0);

	return 0;
}