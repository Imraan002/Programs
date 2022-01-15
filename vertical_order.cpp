#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> res;
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
void vertical_order(tree* root)
{
    if(root==NULL)
        return;
    map<int,map<int,multiset<int>>> mp;
    queue<pair<tree*,pair<int,int>>> qu;
    qu.push({root,{0,0}});
    while(!qu.empty())
    {
        auto temp=qu.front();
        qu.pop();
        int x=temp.second.first;
        int y=temp.second.second;
        mp[x][y].insert(temp.first->data);
        if(temp.first->left!=NULL)
        {
            qu.push({temp.first->left,{x-1,y+1}});
        }
        if(temp.first->right!=NULL)
        {
            qu.push({temp.first->right,{x+1,y+1}});
        }
    }
    for(auto n:mp)
    {
        vector<int> arr;
        for(auto t:n.second)
        {
            arr.insert(arr.end(),t.second.begin(),t.second.end());
        }
        res.push_back(arr);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(10);
    root->left->left->right = new tree(5);
    root->left->left->right->right = new tree(6);
    root->right->left = new tree(9);
    root->right->right = new tree(10);
    vertical_order(root);
    for(auto k:res)
    {
        for(auto temp:k)
        {
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    return 0;
}