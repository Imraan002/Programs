#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> vec;
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
bool is_leaf(tree *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;
    else
        return false;
}
void left_boundary(tree *root)
{
    if (root == NULL)
        return;
    if (!is_leaf(root))
    {
        vec.push_back(root->data);
    }
    if (root->left != NULL)
    {
        left_boundary(root->left);
    }
    else
    {
        left_boundary(root->right);
    }
}
void right_boundary(tree *root)
{
    vector<int> temp;
    if (root == NULL)
        return;
    if (!is_leaf(root))
    {
        temp.push_back(root->data);
    }
    if (root->right != NULL)
    {
        right_boundary(root->right);
    }
    else
    {
        right_boundary(root->left);
    }
    reverse(temp.begin(), temp.end());
    for (auto k : temp)
    {
        vec.push_back(k);
    }
}

void leaves(tree* root)
{
    if(root==NULL)
    {
        return;
    }
    if(is_leaf(root))
    {
        vec.push_back(root->data);
    }
    leaves(root->left);
    leaves(root->right);
}
void bounded_traversal(tree *root)
{
    if (root == NULL)
        return;
    if (!is_leaf(root))
        vec.push_back(root->data);
    left_boundary(root->left);
    leaves(root);
    right_boundary(root->right);
     
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
    root->right->left = new tree(6);
    root->right->right = new tree(7);
    bounded_traversal(root);
    for(auto k:vec)
    {
        cout<<k<<" ";
    }
    return 0;
}