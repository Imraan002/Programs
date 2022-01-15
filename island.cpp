#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int s,n,m;
    cin>>s>>n>>m;
    int days=s-(s/7);
    int total_food=days*n;
    int required=s*m;
    if(total_food>=required)
    {
        cout<<"yes"<<" ";
        if(required%n!=0)
        {
            cout<<required/n+1;
        }
        else{
            cout<<required/n;
        }
    }
    else
    {
        cout<<"no";
    }
    return 0;
}