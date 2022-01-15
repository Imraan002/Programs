#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> vec;
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
void zigzag(tree* root)
{
    if(root==NULL)
    return;
    bool lefttoright=true;
    queue<tree*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        int size=qu.size();
        vector<int> temp;
        for(int i=0;i<size;i++)
        {
            tree* node=qu.front();
            temp.push_back(node->data);
            qu.pop();
            if(node->left!=NULL)
            {
                qu.push(node->left);
            }
            if(node->right!=NULL)
            {
                qu.push(node->right);
            }
        }
        if(lefttoright==false)
        {
            reverse(temp.begin(),temp.end());
        }
        lefttoright=!lefttoright;
        vec.push_back(temp);
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
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);
    zigzag(root);
    for(auto k:vec)
    {
        for(auto t:k)
        {
            cout<<t<<" ";
        }
        cout<<endl;
    }
    return 0;
}