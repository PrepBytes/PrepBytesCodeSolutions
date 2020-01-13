#include<stdio.h>
#define ll long long int
int main()
{
   ll N,Q;
   scanf("%lld %lld",&N,&Q);
   int arr[N+2],i,j;
   for(i=1;i<=N;i++)
    scanf("%d",&arr[i]);

    ll L,R,m_inc,m_dec;
    int max_inc[N+2],sum_inc[N+2];
    int max_dec[N+2],sum_dec[N+2];
    //max_inc[1]=0,max_dec[1]=0,sum_inc[1]=0,sum_dec[1]=0;
    for(i=0;i<N+2;i++)
       max_inc[i]=0,max_dec[i]=0,sum_inc[i]=0,sum_dec[i]=0;
    //maximal increasing subsequence
    for(i=2;i<=N;i++){
        if(arr[i-1] < arr[i])
            max_inc[i]=1;
        else
             max_inc[i]=0;
    }
    for(i=1;i<N;i++){
        if(max_inc[i]==0 && max_inc[i+1]==1)
            sum_inc[i+1]=1;
        if(max_inc[i]==1 && max_inc[i+1]==0)
            max_inc[i]=-1;
    }
    for(i=2;i<=N;i++)
        sum_inc[i]+=sum_inc[i-1];

    //maximal decreasing subsequences
    for(i=2;i<=N;i++){
        if(arr[i-1] > arr[i])
            max_dec[i]=1;
        else
            max_dec[i]=0;
     }

    for(i=1;i<N;i++){
        if(max_dec[i]==0 && max_dec[i+1]==1)
            sum_dec[i+1]=1;
        if(max_dec[i]==1&&max_dec[i+1]==0)
            max_dec[i]=-1;
    }
    for(i=2;i<=N;i++)
        sum_dec[i]+=sum_dec[i-1];

    while(Q--){
      scanf("%lld %lld",&L,&R);
        m_inc=sum_inc[R]-sum_inc[L];
        m_dec=sum_dec[R]-sum_dec[L];
        if(max_inc[L]==1)
            m_inc++;
        if(max_dec[L]==1)
            m_dec++;
          if(m_inc==m_dec)
            printf("YES\n");
          else
            printf("NO\n");
   }
}
