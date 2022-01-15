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
bool findsym(tree* node1,tree* node2)
{
    if(node1==NULL || node2==NULL)
    {
        return node1==node2;
    }
    if(node1->data!=node2->data)
        return false;
    return findsym(node1->left,node2->right)&& findsym(node1->right,node2->left);
}
bool issymmetric(tree* root)
{
    if(root==NULL)
        return false;
    else
        return findsym(root->left,root->right);
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
    root->right = new tree(2);
    root->left->left = new tree(3);
    root->right->right = new tree(3);
    root->left->right = new tree(4);
  //  root->right->left = new tree(4);
    bool res=issymmetric(root);
    if(res==true)
        cout<<"symmetric"<<endl;
    else
        cout<<"not symmetric"<<endl;
    return 0;
}