#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int x,y,gcd;
    node(int a,int b,int t)
    {
        x=a;
        y=b;
        gcd=t;
    }
};
node extended_euclid(int a,int b)
{
    if(b==0)
    {                                                         //   Ax + By =gcd(A,B)
        return  node(1,0,a);
    }
    node nxt=extended_euclid(b,a%b);
    return node(nxt.y,nxt.x-a/b*nxt.y,nxt.gcd);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a,b;
    cin>>a>>b;
   node ans= extended_euclid(a,b);
   cout<<"x = "<<ans.x<<"   "<<"y = "<<ans.y;
    return 0;
}