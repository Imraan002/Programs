#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
bool vis[N];
vector<int> graph[N];
void dfs(int vertex)
{
    cout<<vertex<<" ";
    vis[vertex]=true;
    for(int child:graph[vertex])
    {
        if(!vis[child])
        {
            dfs(child);
        }                                                               //dfs in  graph
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int v,e;
  cin>>v>>e;
  for(int i=0;i<e;i++)
  {
      int u,v;
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
  }
  dfs(0);
return 0;
}