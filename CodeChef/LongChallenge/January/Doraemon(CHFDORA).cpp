#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int N, M;
        scanf("%d %d", &N, &M);
        int arr[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        int count=N*M;
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<M-1;j++)
            {
                int min1=min(N-1-i,M-1-j);
                int min2=min(i,j);
                int min3= min(min1,min2)+1;
                for(int k=1;k<min3;k++)
                {
                    if(arr[i][j-k]==arr[i][j+k] && arr[i-k][j]==arr[i+k][j])
                        count +=1;
                    else
                        break;
                }
            }
        }
        printf("%d\n",count);


    }
}
