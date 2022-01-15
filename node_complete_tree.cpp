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
int height(tree* root)
{
    if(root==NULL)
        return 0;
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}
int total_nodes(tree* root)
{
    if(root==NULL)
        return 0;
    int left=height(root->left)+1;
    int right=height(root->right)+1;
    if(left==right)
    {
        return (1<<left)-1;
    }
    return 1+total_nodes(root->right)+total_nodes(root->left);
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
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    cout<<total_nodes(root);
    return 0;
}