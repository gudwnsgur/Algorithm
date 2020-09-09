#include <string>
#include <vector>

using namespace std;

int dp[501][501]{ 0, };

int solution(vector<vector<int>> triangle) 
{
    for(int i=0; i<triangle.size() ; i++) {
        for (int j = 0; j <= i; j++) { 

			if (i == 0) dp[0][0] = triangle[0][0];
			else {
				if (j == 0) dp[i][j] = triangle[i][j] + dp[i - 1][j];
				else if (j == i) dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
				else {
					dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
				}
			}
		}
    }
    int cost = -1;
	for (int i = 0; i < triangle.size(); i++) 
		cost = max(cost, dp[triangle.size() - 1][i]);
    
    return cost;
}