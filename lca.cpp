#include<bits/stdc++.h>
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
tree* lca(tree* root,int p,int q)
{
    if(root==NULL || root->data==p || root->data==q)
    {
        return root;
    }
    tree* left=lca(root->left,p,q);
    tree* right=lca(root->right,p,q);
    if(left && right)
        return root;
    else if(left)
        return left;
    else
        return right;
       

}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->right->left = new tree(4);
    root->right->right = new tree(5);
    root->right->left->left = new tree(8);
    root->right->right->left = new tree(6);
    root->right->right->right-new tree(7);
    tree* node=lca(root,2,3);
    cout<<node->data;
    return 0;
}