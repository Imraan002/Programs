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
int balanced(tree* root)
{
    if(root==NULL)
        return 0;
    int ldepth=balanced(root->left);
    if(ldepth==-1)
        return -1;
    int rdepth=balanced(root->right);
        if(rdepth==-1)
        return -1;
    if(abs(ldepth-rdepth)>1)
        return -1;
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
    root->left->left=new tree(4);
    root->left->right=new tree(5);
    
    int res=balanced(root);
    if(res==-1)
        cout<<"not balanced"<<endl;
    else 
        cout<<"balanced"<<endl;

    return 0;
}