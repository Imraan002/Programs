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
        vector<pair<ll int, ll int>> arr;
        for (ll int i = 0; i < n; i++)
        {
            ll int x;
            cin >> x;
            arr.push_back({x, i + 1});
        }
        priority_queue<pair<ll int, ll int>, vector<pair<ll int, ll int>>> qu;
        for (ll int i = 0; i < n; i++)
        {
            if (arr[i].first == 0)
                continue;
            qu.push(arr[i]);
        }
        vector<pair<ll int, ll int>> ans;
        while(qu.size()>=2)
        {
            auto temp1=qu.top();
            qu.pop();
            auto temp2=qu.top();
            qu.pop();
            temp1.first-=1;
            temp2.first-=1;
            ans.push_back({temp2.second,temp1.second});
            if(temp1.first!=0)
            {
                qu.push(temp1);
            }
            if(temp2.first!=0)
            {
                qu.push(temp2);
            }
        }
        cout<<ans.size()<<"\n";
        for(auto k:ans)
        {
            cout<<k.first<<" "<<k.second<<" \n";
        }
    }
    return 0;
}