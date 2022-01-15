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
void burn_tree(tree* root,tree* target)
{
    find_parent(root);
    qu.push(target);
    vis[target]=true;
    int time(0);
    while(!qu.empty())
    {
        int size=qu.size();
        bool flag=0;
        for(int i=0;i<size;i++)
        {
           
            auto temp=qu.front();
            qu.pop();
            if(temp->left && !vis[temp->left]){
                qu.push(temp->left);
                vis[temp->left]=true;
                flag=1;
            }
            if(temp->right && !vis[temp->right])
            {
                qu.push(temp->right);
                vis[temp->right]=true;
                flag=1;
            }
            if(par[temp] && !vis[par[temp]])
            {
                qu.push(par[temp]);
                vis[par[temp]]=true;
                flag=1;
            }
            if(flag==1)
            {
                time++;
            }

        }
    }
    cout<<time;
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
    root->left->left->right = new tree(7);
    root->right->left = new tree(5);
    root->right->right = new tree(6);
    burn_tree(root,root);
 
    return 0;
}