#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long a;
        cin>>a;
        long long val = (long long)pow(10,n)-1;
        long long s=2*val+a+2;
        cout<<s<<endl;
        long long b;
        cin>>b;
        long long c=s-(a+b)-val-1;
        cout<<c<<endl;
        long long d;
        cin>>d;
        long long e= s- (a+b+c+d);
        cout<<e<<endl;
        int result;
        cin>>result;
        if(result==-1)
            exit(0);
        fflush(stdin);
    }
    return 0;
}
