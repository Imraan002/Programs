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
void flatten(tree *root)
{
    stack<tree *> st;
    st.push(root);
    while (!st.empty())
    {
        tree *node = st.top();
        st.pop();
        if (node->right)
        {
            st.push(node->right);
        }
        if (node->left)
        {
            st.push(node->left);
        }
        if (!st.empty())
            node->right = st.top();
        node->left = NULL;
    }
}
void traverse(tree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    traverse(root->left);
    traverse(root->right);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(5);
    root->left->left = new tree(3);
    root->left->right = new tree(4);
    root->right->right = new tree(6);
    root->right->right->left = new tree(7);
    flatten(root);
    traverse(root);
    return 0;
}