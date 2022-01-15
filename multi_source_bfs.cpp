#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
int arr[N][N];
int vis[N][N];
int level[N][N];
int n,m;
void reset()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis[i][j]=0;
            level[i][j]=0;
        }
    }
}
bool is_valid(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m;
}
vector<pair<int,int>> movements={
    {0,1},{0,-1},{-1,0},{1,0},{-1,-1},{1,1},{-1,1},{1,-1}
};
int bfs()
{
    queue<pair<int,int>> qu;
    int max_ele=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            max_ele=max(max_ele,arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==max_ele)
            {
                qu.push({i,j});
                vis[i][j]=1;
            }
        }
    }
    while(!qu.empty())
    {
        pair<int,int> pr=qu.front();
        qu.pop();
        for(auto move:movements)
        {
            int x_child=move.first+pr.first;
            int y_child=move.second+pr.second;
            if(!vis[x_child][y_child] && is_valid(x_child,y_child)==true)
            {
                level[x_child][y_child]=level[pr.first][pr.second]+1;
                vis[x_child][y_child]=1;
                qu.push({x_child,y_child});
            }
            else
            {
                continue;
            }
        }

    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans=max(ans,level[i][j]);
        }
    }
    return ans;
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
      cin>>n>>m;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              cin>>arr[i][j];
          }
      }
      reset();
      cout<<bfs()<<"\n";
  }
return 0;
}