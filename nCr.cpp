#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000;
int dp[N][N];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,r;
    cin>>n>>r;
    for(int i=0;i<N;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N && i>=j;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    cout<<dp[n][r];
    return 0;
}