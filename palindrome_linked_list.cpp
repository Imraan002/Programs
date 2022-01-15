#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    char data;
    node *next;
    node(char val)
    {
        this->data = val;
        this->next = NULL;
    }
};
node* reverse_linked_list(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;                            //using recursion
    node* newnode=reverse_linked_list(head->next);
    head->next->next=head;
    head->next=NULL;
    return newnode;                        
}
node* find_middle(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    node* slow=head;
    node* fast=head;
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return slow;
    }
        
}
bool palindrome(node* head)
{
    if(head==NULL || head->next==NULL)
        return true;
    node* middle=find_middle(head);
    node* newhead=reverse_linked_list(middle->next);
    bool ans=true;
    while(newhead!=NULL)
    {
        if(head->data!=newhead->data)
        {
            ans=false;
            break;
        }
        head=head->next;
        newhead=newhead->next;
    }
    return ans;
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
    node *node1 = new node('a');
    node *node2 = new node('b');
    node *node3 = new node('b');
    node *node4 = new node('a');
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
  //  node4->next=node5;
    bool ans=palindrome(head);
    if(ans)
        cout<<"Palindrome\n";
    else
        cout<<"Not Palindrome\n";
     return 0;
}