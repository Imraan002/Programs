#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    int ans=0;
    while(pq.size()>1)
    {
        int one=pq.top();
        pq.pop();
        int two=pq.top();
        pq.pop();
        ans+=one+two;
        pq.push(one+two);
    }
    cout<<ans<<endl;
    return 0;
}