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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll arr[n];
        multiset<int> st;
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
            st.insert(arr[i]);
        }
        ll moves = 0;
        ll ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
             mp[(arr[i] ^ x)]++;
           
            if(st.find((arr[i]^x))!=st.end())
            {
                moves++;
                st.erase(arr[i]);
            }
           
        }
        for (auto k : mp)
        {
            if (k.second > ans)
            {
                ans = k.second;
            }
        }
        cout << ans << " " << moves << endl;
    }
    return 0;
}