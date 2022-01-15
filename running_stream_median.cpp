#include<bits/stdc++.h>
using namespace std;
#define ll long long
 priority_queue<int,vector<int>> maxpq;
priority_queue<int,vector<int>,greater<int>> minpq;
void add(int n)
{

    if(maxpq.empty()==true || n<maxpq.top())
    {
        maxpq.push(n);
    }
    else {
        minpq.push(n);
    }
    if(maxpq.size()>minpq.size()+1)
    {
        minpq.push(maxpq.top());
        maxpq.pop();
    }
    else if(maxpq.size()<minpq.size())
    {
        maxpq.push(minpq.top());
        minpq.pop();
    }
}
float findmedian()
{
    if(maxpq.size()==minpq.size())
    {
        return (maxpq.top()+minpq.top())/2.0;
    }
    else return maxpq.top();
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   
   add(6);
   cout<<findmedian()<<endl;
    add(3);
   cout<<findmedian()<<endl;
   add(7);
   cout<<findmedian()<<endl;
   add(5);
   cout<<findmedian()<<endl;
   add(9);
   cout<<findmedian()<<endl;
    return 0;
}