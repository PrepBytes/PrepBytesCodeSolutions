
//Hero Villain 
//https://mycode.prepbytes.com/problems/maths/DVDALL
//Ankit Surwade


#include<bits/stdc++.h>

using namespace std;
int gcd(int n,int m){
    
    if(n==0)
    return m;
    
    if(m==0)
    return n;
    
    return gcd(m,n%m);
  }
  int main()
  {
    //write your code here
    int t;
    cin>>t;
    while(t--){
      int n,count=0;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++){
      cin>>arr[i];
      }
    int w=0;
    for(int i=0;i<n;i++)
    {
      w=(gcd(w,arr[i]));
    }
    for(int i=1;i<=w;i++){
      if(w%i==0)
      count++;
    }
    cout<<count<<endl;
    }
    
    return 0;
  }
