#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int data;
    node *next;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
void traverse(node* head)
{
   if(head==NULL)
    return;
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node* reverse_linked_list(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;                            //using recursion
    node* newnode=reverse_linked_list(head->next);
    head->next->next=head;
    head->next=NULL;
    return newnode;                        
}
node* reverse_iterative(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    node* prev=NULL;
    node* cur=head;
    
   while(cur!=NULL)
   {
     node* nxxt=cur->next;
      cur->next=prev;
      prev=cur;
      cur=nxxt;
   }
   return prev;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *head;
    node *node1 = new node(1);
    node *node2 = new node(2);
    node *node3 = new node(3);
    node *node4 = new node(4);
    node *node5 = new node(5);
    head=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    traverse(head);
    cout<<endl;
    node* newhead=reverse_iterative(head);
    traverse(newhead);
    return 0;
}