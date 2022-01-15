#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100006];
int solve(string str)
{
    dp[0]=1;
    for(int i=1;i<str.length();i++)
    {
        if(str[i-1]=='0' && str[i]=='0')
        {
            dp[i]=0;
        }
        else if(str[i-1]!='0' && str[i]=='0')
        {
            if(str[i-1]=='1' || str[i-1]=='2')
            {
                dp[i]=(i<=2?1:dp[i-2]);
            }
            else{
                dp[i]=0;
            }
        }
        else if(str[i-1]=='0' && str[i]!='0')
        {
            dp[i]=dp[i-1];
        }
        else{
            if(stoi(str.substr(i-1,2)) <= 26)
            {
                dp[i]=dp[i-1]+(i<=2?1:dp[i-2]);
            }
            else{
                dp[i]=dp[i-1];
            }
        }
    }
    return dp[str.size()-1];
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    string str;
    cin>>str;
    cout<<solve(str);
    return 0;
}