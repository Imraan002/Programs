#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isfeasible(ll int arr[],ll int n,ll int mid,ll int H)
{
    ll int ans=0;
    if(mid&1)
    {
         ll int d=mid/2;
         ans=(d+1)*arr[n-1]+d*arr[n-2];
    }
    else
    {   ll int d=mid/2;
        ans=d*arr[n-1]+d*arr[n-2];
    }
    if(H-ans>0)
        return false;
    else
        return true;
}
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
        ll int n, H;
        cin >> n >> H;
        ll int arr[n];
        for (ll int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
       if(H<=arr[n-1])
       {
           cout<<1<<"\n";
           continue;
       }
       sort(arr,arr+n);
        ll int low = 0;
        ll int high = H;
        while (high - low > 1)
        {
            ll int mid = low + (high - low) / 2;
            if (isfeasible(arr,n,mid,H))
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        if (isfeasible(arr,n,low,H))
            cout << low << "\n";
        else
            cout << high << "\n";
          
    }
    return 0;
}