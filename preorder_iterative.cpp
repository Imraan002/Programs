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
void preorder(tree *root)
{
    if (root == NULL)
        return;
    stack<tree*>st;
    st.push(root);
    while(!st.empty())
    {
        tree* temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL)
        {
            st.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            st.push(temp->left);
        }
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
    preorder(root);
    return 0;
}