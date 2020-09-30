//https://mycode.prepbytes.com/problems/maths/ARRMW
//Solution By Ankit Surwade in C++ language

#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
ll fact(ll x){
  ll facto=1;
  for(ll j=1;j<=x;++j){
    facto*=j;
  }
  return facto;
}
ll ncr(ll n, ll r) 
{ 

	
	ll ans = 1; 

	for (ll i = 1; i <= r; i += 1) { 

	
		ans *= (n - r + i); 
		ans /= i; 
	} 
	return ans; 
} 


ll totalWays(ll X, ll Y, ll M, ll W) 
{ 
	return ((ncr(M, X) * ncr(W, Y) )*fact(X+Y)); 
} 

int main() 
{ 
  ll t;
  cin>>t;
  while(t--){
	
ll M,W,X,Y;
cin>>M>>W>>X>>Y;
	cout << totalWays(X, Y, M, W)<<endl; 
}
	return 0; 
} 
