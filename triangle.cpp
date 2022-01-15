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
        ll int width, height;
        cin >> width >> height;
        ll int hr1;
        cin >> hr1;
        ll int hr1_min(INT_MAX);
        ll int hr1_max(INT_MIN);
        for (ll int i = 0; i < hr1; i++)
        {
            ll int k;
            cin >> k;
            hr1_max = max(hr1_max, k);
            hr1_min = min(hr1_min, k);
        }
        ll int hr2;
        cin>>hr2;
        ll int hr2_min=INT_MAX;
        ll int hr2_max=INT_MIN;
        for(ll int i=0;i<hr2;i++)
        {
            ll int k;
            cin>>k;
            hr2_max=max(hr2_max,k);
            hr2_min=min(hr2_min,k);
        }
        ll int vr1;
        cin>>vr1;
        ll int vr1_min=INT_MAX;
        ll int vr1_max=INT_MIN;
        for(ll int i=0;i<vr1;i++)
        {
            ll int k;
            cin>>k;
            vr1_max=max(vr1_max,k);
            vr1_min=min(vr1_min,k);
        }
        ll int vr2;
        cin>>vr2;
        ll int vr2_min=INT_MAX;
        ll int vr2_max=INT_MIN;
        for(ll int i=0;i<vr2;i++)
        {
            ll int k;
            cin>>k;
            vr2_max=max(vr2_max,k);
            vr2_min=min(vr2_min,k);
        }
        ll int area_hr1=abs(hr1_max-hr1_min)*height;
        ll int area_hr2=abs(hr2_max-hr2_min)*height;
        ll int area_vr1=abs(vr1_max-vr1_min)*width;
        ll int area_vr2=abs(vr2_max-vr2_min)*width;
        cout<<max(max(area_hr1,area_hr2),max(area_vr1,area_vr2))<<"\n";
    }
    return 0;
}
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
        vector<ll int> arr(n);
        for (ll int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if(arr.size()==1)
        {
            cout<<arr[0]<<"\n";
            continue;
        }
        sort(arr.begin(), arr.end());
            ll int cnt = 0;
            ll int ans=0;
            ll int maxnum=INT_MIN;
            for(ll int i = 0; i < n; i++)
            {
               while(arr[i]%2==0)
               {
                   cnt++;
                   arr[i]/=2;
               }
               ans+=arr[i];
               maxnum=max(maxnum,arr[i]);
            }
            ll int temp=maxnum;
            for(ll int i=0;i<cnt;i++)
            {
                maxnum=maxnum*2;
            }
            ans+=maxnum;
            ans-=temp;
            cout<<ans<<"\n";
           
       
        
    }
    return 0;
}