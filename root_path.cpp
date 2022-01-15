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
bool findpath(tree* root,int node)
{
    if(root==NULL)
        return false;
    vec.push_back(root->data);
    if(root->data==node)
        return true;
    if(findpath(root->left,node)|| findpath(root->right,node))
        return true;
    vec.pop_back();
    return false;
}
bool path(tree* root,int node)
{
    if(root==NULL || node==-1)
        return false;   
    bool res=findpath(root,node);
    return res;
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
    root->left->right->right = new tree(7);
   bool res= path(root,4);
   if(res==false)
    {
        cout<<"no path";
        return 0;
    }
    for(auto k:vec)
    {
        cout<<k<<" ";
    }

    return 0;
}