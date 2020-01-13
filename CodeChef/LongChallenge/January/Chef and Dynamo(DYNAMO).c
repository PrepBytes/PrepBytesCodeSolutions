#include<stdio.h>
#define ll long long int
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll A,B,C,D,E;
        int n,ans;
        scanf("%d",&n);
        scanf("%lld",&A);
        ll k=0,s=1,j=1,i;
        for(i=0;i<n;i++){
             k = 10*k + 9;
             s=s*10;
        }
               ll p=s*2 + A;
               s=s*2 + A;
            printf("%lld\n",s);
           fflush(stdout);
          scanf("%lld",&B);
               C=k-B + 1;
           printf("%lld\n",C);
              fflush(stdout);
           scanf("%lld",&D);
               E=k-D + 1 ;
           printf("%lld\n",E);
              fflush(stdout);
            scanf("%d\n",&ans);
            if(ans == -1)
               exit(1);

    }
}
