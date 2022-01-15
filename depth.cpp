#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> pre;
vector<int> in;
vector<int> post;
struct tree{
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
int depth(tree* root)
{
    if(root==NULL)
        return 0;
    int ldepth=depth(root->left);
    int rdepth=depth(root->right);
    return max(ldepth,rdepth)+1;
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
    root->left->left = new tree(4);
    root->left->left->left = new tree(5);
    root->left->left->right = new tree(6);
    root->right->left = new tree(7);
    root->right->right = new tree(8);
    root->right->left->right = new tree(9);
    root->right->right->left = new tree(10);
    cout<<depth(root);

    return 0;
}