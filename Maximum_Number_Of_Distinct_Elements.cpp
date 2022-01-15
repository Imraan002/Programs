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
    cin >> t;
    while (t--)
    {
        ll int n;
        cin >> n;
        ll int brr[n];
        ll int cnt(0);
        map<ll int, ll int> mp;
        for (ll int i = 0; i < n; i++)
        {
            cin >> brr[i];
            mp[brr[i]]++;
        }
        vector<ll int> arr;

      for(ll int i=0;i<n;i++)
      {
          arr.push_back(abs(brr[i]-mp[brr[i]]));
          mp[brr[i]]--;
      }
      for(auto k:arr)
      {
          cout<<k<<" ";
      }
      cout<<"\n";
    }
    return 0;
}