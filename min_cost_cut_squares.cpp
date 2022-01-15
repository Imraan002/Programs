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
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        m--;
        n--;
        int x[n];
        int y[m];
        for (int i = 0; i < m; i++)
        {
            cin >> y[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        sort(x, x + n, greater<int>());
        sort(y, y + m, greater<int>());
        int hr = 1;
        int vr = 1;
        int ans = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (x[i] > y[j])
            {
                ans += vr * x[i];
                hr++;
                i++;
            }
            else
            {
                ans += hr * y[j];
                vr++;
                j++;
            }
        }
        while (i < n)
        {
            ans += x[i] * vr;
            i++;
        }
        while (j < m)
        {
            ans += y[j] * hr;
            j++;
        }
        cout << ans << endl;
    }
    return 0;
}