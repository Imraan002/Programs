#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
    int n,a;
    cin>>n>>a;
    if(n==0)
        {
            cout<<0<<endl;
            continue;
        }
    else if(n==1)
    {
        cout<<a<<endl;
        continue;
    }
    int ans=1;
    for(int i=2;i<n;i++)
    {
        if(n/(i*i)==0)
        {
           ans=i-1;
            break;
        }
    }
    cout<<ans*a<<endl;
}
    return 0;
}