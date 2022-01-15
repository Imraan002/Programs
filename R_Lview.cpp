#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> leftqu;
vector<int> rightqu;
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
void rightview(tree* root, int level)
{
    if(root==NULL)
        return;
    if(level==rightqu.size())
    {
        rightqu.push_back(root->data);
    }
    rightview(root->right,level+1);
    rightview(root->left,level+1);
}
void leftview(tree* root, int level)
{
    if(root==NULL)
        return;
    if(level==leftqu.size())
    {
        leftqu.push_back(root->data);
    }
    leftview(root->left,level+1);
    leftview(root->right,level+1);
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
    cout<<"right-view-->";
    rightview(root,0);
    for(auto k:rightqu)
    {
        cout<<k<<" ";
    }
    cout<<endl;
    cout<<"left-view-->";
    leftview(root,0);
    for(auto k:leftqu)
    {
        cout<<k<<" ";
    }
    
    return 0;
}