#include <iostream>
using namespace std; 
#define DIV_NUM 10007
#define NK_MAX 1000 + 1 

int main() {
    int N, K; scanf("%d %d", &N, &K);
    int dp[NK_MAX][NK_MAX] = { 0 };
    for(int n_row = 1; n_row <= N; n_row++){
        for (int k_col = 0; k_col <= N; k_col++) {
            if (n_row == k_col || k_col == 0) {
                dp[n_row][k_col] = 1; continue;
            }
            dp[n_row][k_col] = (dp[n_row - 1][k_col] + dp[n_row - 1][k_col - 1]) % DIV_NUM;
        }
    }
    printf("%d", dp[N][K]);
    return 0;
}
