#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4;
ll mod1=1e9+6;
ll mod2=1e9+7;
int dp[N][N];
ll fast_power(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%mod1;
        }
        a=(a*a)%mod1;
        b=b>>1;
    }
    return ans;
}
int calculate(int arr[],int n,int k)
{
    sort(arr,arr+n);
    ll total=dp[n-1][k-1];
    ll valid;
    int ans[n];
    int res=1;
    for(int i=1;i<=n/2;i++)
    {
        ll maxcnt=0;
        ll mincnt=0;
        if(i>=k-1)
        {
            maxcnt=dp[i][k-1];
        }
        if(n-1-i>=k-1)
        {
            mincnt=dp[n-1-i][k-1];
        }
       
        valid=(total-maxcnt+mod1)%mod1;
        valid=(valid-mincnt+mod1)%mod1;
        ans[i]=valid;
        ans[n-1-i]=valid;
    }
    for(int i=1;i<n-1;i++)
    {
        ll temp=fast_power(arr[i],ans[i]);
        cout<<temp<<endl;
        res=(res*temp)%mod2;
    }
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=0;i<N;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;i>=j && j<N;j++)
        {
            if(i>=j)
            {
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]);
            }
        }
    }
   int n,k;
   cin>>n>>k;
   int arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   cout<<calculate(arr,n,k);
    return 0;
}