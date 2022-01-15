#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> dp(65,-1);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int n;
  cin>>n;
    dp[0]=1;
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=2*dp[i-2];
    }
    cout<<dp[n]<<"\n";
return 0;
}