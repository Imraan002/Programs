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
    int ans=0;
    priority_queue<long long,vector<long long>,greater<long>> pq;
    for(int i=0;i<n;i++)
    {
       pq.push(arr[i]);
    }
    while(pq.size()>1)
    {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        ans+=x+y;
        pq.push(x+y);
    }
    cout<<ans<<endl;
    return 0;
}