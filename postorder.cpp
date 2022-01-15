#include <bits/stdc++.h>
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
void postorder(tree *root)
{
    if (root == NULL)
        return;
    stack<tree *> st1,st2;
   st1.push(root);
   while(!st1.empty())
   {
       tree* temp=st1.top();
       st1.pop();
       st2.push(temp);
       if(temp->left!=NULL)
       {
           st1.push(temp->left);
       }
       if(temp->right!=NULL)
       {
           st1.push(temp->right);
       }
   }
   while(!st2.empty())
   {
       cout<<st2.top()->data<<" ";
       st2.pop();
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
    root->left->left->left = new tree(5);
    root->left->left->right = new tree(6);
    root->right->left = new tree(7);
    root->right->right = new tree(8);
    root->right->left->right = new tree(9);
    root->right->right->left = new tree(10);
    postorder(root);
    return 0;
}