#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
  ll int t;
  cin>>t;
  while(t--)
  {
      ll int n,even,odd;
      cin>>n>>even>>odd;
     vector<ll int> prime_factors;
     int temp=n;
    for(ll int i=2;i*i<=n;i++)
 	{
 		while(n%i==0)
 		{
 			prime_factors.push_back(i);
 			n=n/i;
 		}
 	}   									//prime factorization
 	if(n>1)
 	{
 		prime_factors.push_back(n);
 	}
     int ans(0);
     int ans2(0);
     for(auto K:prime_factors)
     {
         if(K%2==0)
         {
             ans=ans+even;
         }
         else{
             ans=ans+odd;
         }
     }
     if(temp%2!=0)
     {
         ans2+=odd;
     }
     else{
         ans2+=even;
     }
    cout<<max(ans,ans2)<<'\n';
  }
return 0;
}