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
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        deque<int> even, odd;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                odd.push_back(i);
            }
            else
            {
                even.push_back(i);
            }
        }
        auto oddt=odd.begin();
        auto event=even.begin();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2!=0)
            {
               if(!even.empty())
               {
                   ans+=(arr[i]+*event)%2;
                   event++;
                   even.pop_front();
               }
               else{
                   ans+=(arr[i]+*oddt)%2;
                   oddt++;
                   odd.pop_front();
               }
            }
            else{
                if(!odd.empty())
                {
                    ans+=(arr[i]+*oddt)%2;
                   oddt++;
                   odd.pop_front();
                }
                else{
                    ans+=(arr[i]+*event)%2;
                    event++;
                    even.pop_front();
                }
            }
            
        }
        cout<<ans<<endl;
    }

    return 0;
}