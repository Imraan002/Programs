#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n;
    cin>>n;
    while(true)
    {
        ll arr[n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        vector<pair<ll,ll>> buy;
        vector<pair<ll,ll>> sell;
        for(ll i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                buy.push_back({arr[i],i});
            }
            else 
            {
                sell.push_back({arr[i],i});
            }
        }
        ll i(0),j(0);
        ll ans=0;
        while(i<buy.size() && j<sell.size())
        {
            ll x=min(buy[i].first,-sell[j].first);
            buy[i].first-=x;
            sell[j].first+=x;
            ll diff=abs(buy[i].second-sell[j].second);
            ans+=x*diff;
            if(buy[i].first==0)
            {
                i++;
            }
            if(sell[j].first==0)
            {
                j++;
            }
          
        }
          cout<<ans<<endl;
            cin>>n;
            if(n==0)
            break;
    }
    return 0;
}