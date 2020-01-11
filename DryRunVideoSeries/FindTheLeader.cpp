#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t; 
    // Test case loop
    while(t-->0)
    {
        int n;
        cin>>n;
        int arr[n];
        int i;
        // Taking array as input
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        // Assigning last element as current leader
        int curr_leader=arr[n-1];
        cout<<curr_leader<<" ";
        // Checking each element with the current leader, and updating the leader when required
        for(i=n-2;i>=0;i--)
        {
            if(curr_leader <= arr[i])
            {
                curr_leader=arr[i];
                // Printing the current leader
                cout<<curr_leader<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
