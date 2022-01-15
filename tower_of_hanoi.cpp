#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int n,char src,char hlpr,char dest)
{
    if(n==0)
    return;
    if(n==1)
    {
        cout<<"move from "<<src<<" to "<<dest<<endl;
        return;
    }
    solve(n-1,src,dest,hlpr);
    cout<<"move from "<<src<<" to "<<dest<<endl;
    solve(n-1,hlpr,src,dest);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    solve(n,'A','B','C');
    return 0;
}