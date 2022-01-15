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
bool identical(tree *root1, tree *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;
    else if (root1 != NULL && root2 != NULL)
        return (root1->data == root2->data) && identical(root1->left, root2->left) && identical(root1->right, root2->right);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tree *root1 = new tree(1);
    root1->left = new tree(2);
    root1->right = new tree(3);
    tree *root2 = new tree(1);
    root2->left = new tree(2);
    root2->right = new tree(3);
    bool res = identical(root1, root2);
    if (res == true)
        cout << "identical" << endl;
    else
        cout << "Not identical" << endl;
    return 0;
}