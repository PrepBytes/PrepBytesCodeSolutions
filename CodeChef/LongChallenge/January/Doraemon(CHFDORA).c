#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int N, M;
        scanf("%d %d", &N, &M);
        int arr[N][M],i,j;
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        int count=N*M,min1,min2,min3,k;
        for(i=1;i<N-1;i++)
        {
            for(j=1;j<M-1;j++)
            {
                if(N-1-i < M-1-j)
                   min1=N-1-i;
                else
                   min1=M-1-j;

                if(i<j)
                   min2=i;
                else
                   min2=j;

               if(min1 < min2)
                 min3=min1 + 1;
               else
                    min3=min2 + 1;
                for(k=1;k < min3; k++)
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
