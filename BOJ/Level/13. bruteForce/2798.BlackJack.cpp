#include <iostream>
using namespace std;
int main ( ) {
    int N, M;
    int result=0;
    int* card;

    cin >> N >> M;
    
    card = new int[N];
    for(int i=0; i<N ; i++) 
        cin >> card[i];
    
    for (int i = 0; i < N-2; i++)
        for (int j = i + 1; j < N-1; j++)
            for (int k = j + 1; k < N; k++)
                if (card[i] + card[j] + card[k] <= M && M-(card[i] + card[j] + card[k]) < M-result)
                    result = card[i] + card[j] + card[k];

    cout << result;
    return 0;
}