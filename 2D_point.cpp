#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
        ll n;
        cin >> n;
        ll X_arr[n];
        ll Y_arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> X_arr[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> Y_arr[i];
        }
        map<pair<ll, ll>, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            mp[{X_arr[i], Y_arr[i]}]++;
        }
        if (mp.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }
        ll x = INT_MIN;
        ll y = INT_MIN;
        ll t = 1;
        for (auto k : mp)
        {
            if (k.second > t)
            {
                x = k.first.first;
                y = k.first.second;
                t = k.second;
            }
        }
        if(x==INT_MIN && y==INT_MIN)
        {
                for (ll i = 0; i < n; i++)
                {
                    if (X_arr[i] == Y_arr[i])
                    {
                        x = X_arr[i];
                        y = Y_arr[i];
                    }
                }
        }
        if (x == INT_MIN && y == INT_MIN)
        {
            x = X_arr[0];
            y = Y_arr[0];
        }
        int moves(0);
        for (int i = 0; i < n; i++)
        {
            if (x == X_arr[i] && y == Y_arr[i])
            {
                continue;
            }
            ll xdiff = x - X_arr[i];
            ll ydiff = y - Y_arr[i];
            if (abs(xdiff) == abs(ydiff))
            {
                moves += 1;
            }
            else
            {
                if (xdiff == 0 || ydiff == 0)
                {
                    moves += 1;
                }
                else
                {
                    moves += 2;
                }
            }
        }
        cout << moves << endl;
    }
    return 0;
}