#include <bits/stdc++.h>
using namespace std;
#define ll long long
 ll int mod=1e9+7;
ll int binary_expo(ll int a,ll int b)
{
    ll int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}
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
      ll int n,k;
      cin>>n>>k;
      ll int ans(0);
      for(int i=0;i<(int)log2(k)+1;i++)
      {
          if(k&(1<<i))
          {
              ans+=binary_expo(n,i);
          }
      }
      cout<<ans%mod<<"\n";
      
  }
return 0;
}