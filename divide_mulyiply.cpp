
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
        vector<ll int> arr(n);
        for (ll int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if(arr.size()==1)
        {
            cout<<arr[0]<<"\n";
            continue;
        }
        sort(arr.begin(), arr.end());
            ll int cnt = 0;
            ll int ans=0;
            ll int maxnum=INT_MIN;
            for(ll int i = 0; i < n; i++)
            {
               while(arr[i]%2==0)
               {
                   cnt++;
                   arr[i]/=2;
               }
               ans+=arr[i];
               maxnum=max(maxnum,arr[i]);
            }
            ll int temp=maxnum;
            for(ll int i=0;i<cnt;i++)
            {
                maxnum=maxnum*2;
            }
            ans+=maxnum;
            ans-=temp;
            cout<<ans<<"\n";
           
       
        
    }
    return 0;
}