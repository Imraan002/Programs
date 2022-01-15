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
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        multiset<int> even;
        multiset<int> odd;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
            {
                even.insert(x);
            }
            else
            {
                odd.insert(x);
            }
        }
        int flag = 0;
        vector<int> arr(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (flag == 0)
            {
                if (!odd.empty())
                {
                    arr[i] = *odd.begin();
                    odd.erase(odd.begin());
                }
                else
                {
                    arr[i] = *even.begin();
                    even.erase(even.begin());
                }
                flag = 1;
            }
            else
            {
                if (!odd.empty())
                {
                    arr[i] = *odd.begin();
                    odd.erase(odd.begin());
                }
                else
                {
                    arr[i] = *even.begin();
                    even.erase(even.begin());
                }
                flag = 0;
            }
        }
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += abs(arr[i] - arr[i + 1]);
        }
        if (sum % 2 == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            for (auto k : arr)
            {
                cout << k << " ";
            }
            cout << endl;
        }
    }
    return 0;
}