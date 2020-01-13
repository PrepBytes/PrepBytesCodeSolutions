#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    for(int i=1;i<n+1;i++)
        cin>>arr[i];
    int IncRange[n+1];
    for(int i=0;i<n+1;i++) IncRange[i]=0;
    unordered_set<int> range;
    for(int i=2;i<n+1;i++)
    {
        if(arr[i-1]<arr[i] && (i+1==n+1||arr[i]>arr[i+1])) {
            IncRange[i]++;
            range.insert(i);
        }
    }
    for(int i=2;i<n+1;i++)
        IncRange[i]=IncRange[i]+IncRange[i-1];
    int DecRange[n+1];
    for(int i=0;i<n+1;i++) DecRange[i]=0;
    for(int i=2;i<n+1;i++)
    {
        if(arr[i-1]>arr[i]&&(i+1==n+1||arr[i]<arr[i+1])) {
            DecRange[i]++;
            range.insert(i);
        }

    }
    for(int i=2;i<n+1;i++)
        DecRange[i]=DecRange[i]+DecRange[i-1];

    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        if(range.count(r)==1)
        {
            int incValue = IncRange[r]-IncRange[l];
            int decValue= DecRange[r]-DecRange[l];
            if(incValue==decValue)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            if(arr[r]>arr[r-1])
            {
                if(IncRange[r]-IncRange[l]+1 == DecRange[r]-DecRange[l])
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
            else
            {
                if(arr[r]<arr[r-1])
                {
                    if(IncRange[r]-IncRange[l]==DecRange[r]-DecRange[l]+1)
                        cout<<"YES"<<endl;
                    else
                        cout<<"NO"<<endl;
                }
            }
        }

    }
    return 0;
}
