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
int maxpath(tree* root,int &maxi)
{
    if(root==NULL)
        return 0;
    int lans=max(0,maxpath(root->left,maxi));
    int rans=max(0,maxpath(root->right,maxi));
    maxi=max(maxi,lans+rans+root->data);
    return root->data+max(lans,rans);

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
    root->left->right=new tree(6);
    int maxi=INT_MIN;
    int ans= maxpath(root,maxi);
    cout<<maxi;
    return 0;
}