#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int s,w1,w2,w3;
        scanf("%d %d %d %d",&s,&w1,&w2,&w3);
        int sum=w1+w2+w3;
        if(s>=sum)
            printf("1\n");
        else
        {
            int sum1=w1+w2;
            int sum2 = w2+w3;
            if(sum1<=s|| sum2<=s)
                printf("2\n");
            else
                printf("3\n");
        }
    }
    return 0;
}
