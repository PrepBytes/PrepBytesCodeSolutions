#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int p;
        cin>>p;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        long long count=0;
        int rem=p;
        int flag=0;
        vector<int> res;
        for(int i=n-1;i>=0;i--)
        {
            if(rem==0 || rem<0)
            {
                for(int j=i;j>=0;j--)
                    res.push_back(0);
                break;
            }


            if(rem%arr[i]==0)
            {
                if(i!=0) {
                    res.emplace_back((rem / arr[i]) - 1);
                   // count += ((rem / arr[i]) - 1);
                    rem = rem - arr[i] * ((rem / arr[i]) - 1);
                } else{
                    cout<<"NO"<<"\n";
                    flag=1;
                    break;
                }
            }
            else
            {
                if(i!=0)
                {
                    res.emplace_back((rem/arr[i])+1);
                    //count+= (rem/arr[i]);
                    rem = rem - arr[i]*(rem/arr[i]+1);
                }
                else
                {
                    res.emplace_back((rem/arr[i])+1);
                    //count+=(rem/arr[i])+1;
                }
            }
        }
        //cout<<count<<"\n";
        if(flag==0) {
            cout<<"YES ";
            for (int i = res.size() - 1; i >= 0; i--) {
                cout << res[i] << " ";
            }
            cout << "\n";
        }

    }
    return 0;
}
