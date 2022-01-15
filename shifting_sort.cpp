#include <bits/stdc++.h>
using namespace std;
#define ll long long
void shift(vector<int> &arr, int l, int r, int d)
{

    for (int i = 0; i < d; i++)
    {
        int var = arr[l];
        for (int i = l + 1; i <= r; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[r] = var;
    }
}
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
        vector<int> arr(n);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = {arr[i], i};
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[i])
                {
                    p = {arr[j], j};
                    break;
                }
            }  
            if (p.first != arr[i])
            {
                shift(arr, p.second, i, i - p.second);
                vector<int> temp(3);
                temp.push_back(p.second + 1);
                temp.push_back(i + 1);
                temp.push_back(i - p.second);
                ans.push_back(temp);
            }
        }
        cout << ans.size() << endl;
        for (auto k : ans)
        {
            for (auto t : k)
            {
                if(t!=0)
                    cout<<t<<" ";
            }
            cout << endl;
        }
    }
    return 0;
}