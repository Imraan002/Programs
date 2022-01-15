#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arr[]={1,1,10,100,1000,10000,100000,1000000};
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);           
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int x,y;
    x=arr[c];
    y=arr[c];
    while(x<arr[a])
    {
        x=x*2;
    }
    while(y<arr[b])
    {
        y=y*3;
    }
    cout<<x<<" "<<y<<" "<<__gcd(x,y)<<endl;
    return 0;
}