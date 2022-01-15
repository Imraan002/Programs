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
int width(tree *root)
{
    int ans = INT_MIN;
    queue<pair<tree *, int>> qu;
    qu.push({root, 0});
    while (!qu.empty())
    {
        auto temp = qu.front();
        int minimum = temp.second;
        int size = qu.size();
        tree *node = temp.first;
        int first;
        int last;
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                first = qu.front().second;
            }
            if(i==size-1)
            {
                last=qu.front().second;
            }
           if(qu.front().first->left!=NULL)
           {
                qu.push({qu.front().first->left,2*qu.front().second-minimum+1});
           }
           if(qu.front().first->right!=NULL)
           {
                qu.push({qu.front().first->right,2*qu.front().second-minimum+2});
           }
            qu.pop();
        }
        ans=max(ans,last-first+1);
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
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
     root->left->left = new tree(4);
    // root->left->left->left = new tree(5);
    // root->left->left->right = new tree(6);
    // root->right->left = new tree(7);
     root->right->right = new tree(8);
    // root->right->left->right = new tree(9);
    // root->right->right->left = new tree(10);
    cout << width(root);
    return 0;
}