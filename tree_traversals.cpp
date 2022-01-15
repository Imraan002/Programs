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
void solve(tree* root)
{
	 if(root==NULL)
	 	return;
	 stack<pair<tree*,int>> st; 
        st.push({root, 1}); 
        while(!st.empty()) {
            auto it = st.top(); 
            st.pop();  
            if(it.second == 1) {
                pre.push_back(it.first->data); 
                it.second++; 
                st.push(it); 

                if(it.first->left != NULL) {
                    st.push({it.first->left, 1}); 
                }
            }
            else if(it.second == 2) {
                in.push_back(it.first->data); 
                it.second++; 
                st.push(it); 

                if(it.first->right != NULL) {
                    st.push({it.first->right, 1}); 
                }
            }
            else {
                post.push_back(it.first->data); 
                
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
    root->left->left = new tree(4);
    root->left->left->left = new tree(5);
    root->left->left->right = new tree(6);
    root->right->left = new tree(7);
    root->right->right = new tree(8);
    root->right->left->right = new tree(9);
    root->right->right->left = new tree(10);
   solve(root);
   cout<<"Preorder-> ";
   for(auto k:pre)
   {
   		
   		cout<<k<<" ";
   }
   cout<<endl;
      cout<<"Inorder-> ";
   for(auto k:in)
   {
   		
   		cout<<k<<" ";
   }
   cout<<endl;
   	cout<<"Postorder-> ";
      for(auto k:post)
   {
   		
   		cout<<k<<" ";
   }
   cout<<endl;
    return 0;
}