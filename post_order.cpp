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
void solve(tree *root)
{
    if (root == NULL)
        return;
    stack<tree *> st;
    tree *cur = root;
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            tree *node = st.top()->right;
            if (node == NULL)
            {
                node=st.top();
                cout << st.top()->data << " ";
                st.pop();
                while (!st.empty() && node == st.top()->right)
                {
                    node = st.top();
                    st.pop();
                    cout << node->data << " ";
                }
            }
            else
            {
                cur = node;
            }
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
    solve(root);
    return 0;
}