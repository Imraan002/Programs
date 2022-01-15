#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int multiple_cnt[N];
int hash_cnt[N];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
   		int x;
   		cin>>x;
   		hash_cnt[x]++;
   }
   for(int i=1;i<N;i++)
   {
   	for(int j=i;j<N;j+=i)
   	{
   		multiple_cnt[i]+=hash_cnt[j];
   	}
   }
   int t;
   cin>>t;
   while(t--)
   {
   		
        int p, q;
        cin >> p >> q;
        ll int ans = multiple_cnt[p] + multiple_cnt[q];
        ll int lcm = (p * q) / __gcd(p, q);
        if (lcm < N)
        {
            ans = ans - multiple_cnt[lcm];
        }
        cout << ans << endl;
   }
    return 0;
}