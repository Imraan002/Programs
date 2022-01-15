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
      int n,m,k;
      cin>>n>>m>>k;
      int arr[n];
      for(int i=0;i<n;i++)
      {
          cin>>arr[i];
      }
      int ans=0;
      int cnt=0;
      int t=0;
      for(int i=0;i<n;i++)
      {
          if(arr[i]==1)
          {
              t++;
          }
      }
      if(t==n)
      {
          cout<<100<<"\n";
          continue;
      }
      for(int i=0;i<m;i++)
      {
          if(arr[i]!=1)
          {
              cnt=1;
              break;
          }
      }     
      if(cnt==0)
      {
          ans+=k;
      }
      cout<<ans<<"\n";
  }
return 0;
}