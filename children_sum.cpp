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
void print_tree(tree* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    print_tree(root->left);
    print_tree(root->right);
}
void children_sum(tree* root)
{
    if(root==NULL)
        return;
    int child=0;
    if(root->left!=NULL)
    {
        child+=root->left->data;
    }
    if(root->right!=NULL)
    {
        child+=root->right->data;
    }
    if(child>root->data)
    {
        root->data=child;
    }
    else{
        if(root->left)
            {
                root->left->data=root->data;
            }
        if(root->right)
        {
            root->right->data=root->data;
        }
    }
    children_sum(root->left);
    children_sum(root->right);
    int total=0;
    if(root->left)
    {
        total+=root->left->data;
    }
    if(root->right)
    {
        total+=root->right->data;
    }
    if(root->left || root->right)
    {
        root->data=total;
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
    tree *root = new tree(40);
    root->left = new tree(10);
    root->right = new tree(20);
    root->left->left = new tree(2);
    root->left->right = new tree(5);
    root->right->left = new tree(30);
    root->right->right = new tree(40);
    print_tree(root);
    cout<<endl;
    children_sum(root);
    print_tree(root);
    return 0;
}