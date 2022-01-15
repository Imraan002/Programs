#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
vector<int> tree[N];
//vector<int> subtree_sum[N];
int subtree_sum[N];
void dfs(int vertex, int par)
{
    subtree_sum[vertex] += vertex;
    for (int child : tree[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
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
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    return 0;
    return 0;
}