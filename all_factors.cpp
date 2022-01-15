#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int arr[N];
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }
    for (int i = 2; i * i < N; i++)
    {
        if (arr[i] == i)
        {
            for (int j = i * 2; j < N; j = j + i)
            {
                if (arr[j] == j)
                {
                    arr[j] = i;
                }
            }
        }
    }
    int n;
    cin >> n;
    vector<int> ans;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        while (n > 1)
        {
            ans.push_back(arr[n]);
            n = n / arr[n];
        }
    }
    int cnt = 1;
    int res = 1;
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] == ans[i - 1])
        {
            cnt++;
        }
        else
        {
            res*= (cnt + 1);
            cnt = 1;
        }
    }
    res*=  (cnt + 1);
    cout<<res<<endl;
    return 0;
}