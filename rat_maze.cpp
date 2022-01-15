#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int vis[N][N];
string str;
char direction[2]={'R','U'};
bool isvalid(vector<vector<int>> &maze,int x,int y)
{
    if(!vis[x][y] && x>=0  &&  y<maze[0].size())
        return true;
    else
        return false;
}
void solve(vector<vector<int>> &arr ,int x1,int y1,int x2,int y2)
{
    if((x1==x2 && y1==y2) || x1<0 ||  y1>arr[0].size() || x1<x2 || y1>y2) 
    {
        cout<<str<<endl;
        return;
    }
      
    int dx[]={0,-1};
    int dy[]={1,0};
    for(int i=0;i<2;i++)
    {
        int x=x1+dx[i];
        int y=y1+dy[i];
        if(isvalid(arr,x,y))
        {
            vis[x][y]=1;
            str.push_back(direction[i]);
            solve(arr,x,y,x2,y2);
            vis[x][y]=0;
            str.pop_back();
        }
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
vector<vector<int>> maze(n,vector<int> (n,0));
int srcx,srcy,destx,desty;
cin>>srcx>>srcy>>destx>>desty;
solve(maze,srcx,srcy,destx,desty);
    return 0;
}