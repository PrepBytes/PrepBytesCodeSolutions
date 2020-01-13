#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int s,w1,w2,w3;
        cin>>s>>w1>>w2>>w3;
        int count=0,diff=w1+w2+w3;
        if(s>=diff)
            cout<<"1"<<endl;
        else
        {
            int diff1=w1+w2;
            int diff2=w2+w3;
            if(diff1<=s || diff2<=s)
                cout<<"2"<<endl;
            else
                cout<<"3"<<endl;
        }
    }
    return 0;
}
