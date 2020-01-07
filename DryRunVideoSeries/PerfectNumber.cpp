#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; // variable for storing test cases
    cin>>t; // initialize test case variable
    
    // start test case loop
    while(t--){
    
        // variable n to store the input, sum and rem for calculation
        int sum=0,n,rem;
        cin>>n;
        
        //loop to get all the factors except the number itself and add them
        for(int i=1; i<n; i++){
            rem=n%i;
            if(rem==0){
                sum=sum+i;
            }
        }
        
        //cout<<"sum= "<<sum<<endl;  debugging statement
        
        //if the sum is equal to n, print true else false
        if(sum==n)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}
