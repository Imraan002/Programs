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
       ll int n, x;
        cin >> n >> x;
       ll int arr[n], temp[n];
        for (ll int i = 0; i < n; i++)
        {
            cin >> arr[i];
            temp[i] = arr[i];
        }
        sort(arr, arr + n);
        bool ans = true;
        for (ll int i = 0; i < n; i++)
        {
            if (arr[i] != temp[i])
            {
              ll  int dd = n - (i + 1);
               ll int maxx = max(i, dd);
                if (maxx < x)
                {
                    ans = false;
                    break;
                }
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}