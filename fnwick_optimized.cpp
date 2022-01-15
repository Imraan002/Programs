#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+6;
int fenwick[N];
int prefix[N];
void update(int idx,int val)
{
    while(idx<=N)
    {
        fenwick[idx]+=val;
        idx=idx+(idx&-idx);
    }
}
int sum(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=fenwick[idx];
        idx=idx-(idx&-idx);
    }
    return sum;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<N;i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    for(int i=1;i<N;i++)
    {
        fenwick[i]=prefix[i]-prefix[i-(i&-i)];      //fenwick tree build in O(n) 
    }
cout<<sum(4)<<endl;
update(2,4);
cout<<sum(4)<<endl;
    return 0;
}