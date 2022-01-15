#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
queue<tree*> qu;
unordered_map<tree*,tree*> par;
unordered_map<tree*,bool> vis;
void find_parent(tree* root)
{
    if(root==NULL)
        return;
    if(root->left){
        par[root->left]=root;
    }
    if(root->right){
        par[root->right]=root;
    }
    find_parent(root->left);
    find_parent(root->right);
}
void nodes_k_dist(tree* root,tree* target,int dist)
{
    find_parent(root);
    qu.push(target);
    vis[target]=true;
    int cur=0;
    while(!qu.empty())
    {
        int size=qu.size();
        if(cur++==dist)
        {
            break;
        }
        for(int i=0;i<size;i++)
        {
            auto temp=qu.front();
            qu.pop();
            if(temp->left && !vis[temp->left]){
                qu.push(temp->left);
                vis[temp->left]=true;
            }
            if(temp->right && !vis[temp->right])
            {
                qu.push(temp->right);
                vis[temp->right]=true;
            }
            if(par[temp] && !vis[par[temp]])
            {
                qu.push(par[temp]);
                vis[par[temp]]=true;
            }

        }
    }
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
    root->left->left=new tree(5);
    root->left->right=new tree(6);
    root->right->left=new tree(7);
    root->right->right=new tree(8);
    nodes_k_dist(root,root->left->left,2);
    while(!qu.empty())
    {
        cout<<qu.front()->data<<" ";
        qu.pop();
    }
    return 0;
}