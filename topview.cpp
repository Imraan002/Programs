#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct tree
{
    int data;
    tree *left;
    tree *right;
    tree(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void topview(tree *root)
{
    if (root == NULL)
        return;
    queue<pair<tree *, int>> qu;
    map<int, int> mp;
    qu.push({root, 0});
    while (!qu.empty())
    {
        auto temp = qu.front();
        qu.pop();
        int node = temp.first->data;
        int vertical = temp.second;
        if (mp.find(vertical) == mp.end())
        {
            mp[vertical] = node;
        }
        if (temp.first->left != NULL)
        {
            qu.push({temp.first->left, vertical - 1});
        }
        if (temp.first->right != NULL)
        {
            qu.push({temp.first->right, vertical + 1});
        }
    }
    for (auto k : mp)
    {
        cout << k.second << " ";
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
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->left->right->left = new tree(6);
    root->right->right = new tree(7);
    topview(root);
    return 0;
}