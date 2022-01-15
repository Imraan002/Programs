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
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      string str;
      cin>>str;
      map<int,int>mp;
      for(int i=0;i<n;i++)
      {
          mp[i+1]=str[i];
      }
      int ans(0);
      for(int i=str.length()-1;i>=0;i--)
      {
          for(int j=9;j>=0;j--)
          {
              if(mp.find(abs(str[i]-j))!=mp.end())
              {
                  ans++;
              }
          }
      }
      cout<<ans<<"\n";
  }
return 0;
}