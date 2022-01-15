#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10000;
int arr[N][N];
int fenwick[N][N];
void update(int x,int y,int val)
{
    int xdash=x;
    while(xdash<N)
    {
        int ydash=y;
        while(ydash<N)
        {
            fenwick[xdash][ydash]+=val;
            ydash=ydash+(ydash&-ydash);
        }
        xdash=xdash+(xdash&-xdash);
    }
}
int sum(int x,int y)
{
    int sum=0;                              //2D fenwick_tree
    int xdash=x;
    while(xdash>0)
    {
        int ydash=y;
        while(ydash>0)
        {
            sum+=fenwick[xdash][ydash];
            ydash=ydash-(ydash&-ydash);
        }
        xdash=xdash-(xdash&-xdash);
    }
    return sum;
}
int required_sum(int x1,int y1,int x2,int y2)
{
    int add_area1=sum(x2,y2);
    int remove_area2=sum(x1-1,y2);
    int remove_area3=sum(x2,y1-1);
    int add_area2=sum(x1-1,y1-1);
    return add_area1-remove_area2-remove_area3+add_area2;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            update(i,j,arr[i][j]);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<required_sum(x1,y1,x2,y2)<<endl;
        }
        else{
            int x1,y1,val;
            cin>>x1>>y1>>val;
            update(x1,y1,val);
        }
    }
    return 0;
}