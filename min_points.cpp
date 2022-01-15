#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int x;
    int y;
};
vector<pair<int,int>> points;
vector<vector<int>> mtrx;
node parent[500][500];
int Size[500][500];
void make(int x,int y)
{
    parent[x][y].x=x;
    parent[x][y].y=y;
    Size[x][y]=1;
}
node find(int x,int y)
{
    node temp;
    if(parent[x][y].x==x && parent[x][y].y==y)
        {
            temp.x=x;
            temp.y=y;
            return temp;
        }
    temp=find(parent[x][y].x,parent[x][y].y);
    parent[x][y].x=temp.x;
    parent[x][y].y=temp.y;
    return temp;
 }
void Union(int x1,int y1,int x2,int y2)
{
    auto a=find(x1,y1);
    auto b=find(x2,y2);
    if(a.x!=b.x || a.y!=b.y)
    {
        if(Size[a.x][a.y]<Size[b.x][b.y])
            {
                swap(a,b);
            }
        parent[b.x][b.y].x=a.x;
        parent[b.x][b.y].y=a.y;
        Size[a.x][a.y]+=Size[b.x][b.y];
    }
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
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int cost=abs(points[i].first-points[j].first)+abs(points[i].second-points[j].second);
            vector<int> temp;
            temp.push_back(cost);
            temp.push_back(points[i].first);
            temp.push_back(points[i].second);
            temp.push_back(points[j].first);
            temp.push_back(points[j].second);
            mtrx.push_back(temp);

        }
    }
    sort(mtrx.begin(),mtrx.end());
    for(int i=0;i<n;i++)
    {
        make(abs(points[i].first),abs(points[i].second));
    } 
    int total_cost=0;
    for(auto k:mtrx)
    {
        int wt=k[0];
        int x1=k[1];
        int y1=k[2];
        int x2=k[3];
        int y2=k[4];
        if(parent[x1][y1].x==parent[x2][y2].x && parent[x1][y1].y==parent[x2][y2].y)continue;
        Union(x1,y1,x2,y2);
        total_cost+=wt;
    }
     cout<<total_cost<<"\n";
    return 0;
}