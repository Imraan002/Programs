#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool comp(pair<int,int> a,pair<int,int> b)
{
    return a.first<b.first;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back({x,i+1});
    }
    int k;
    cin>>k;
    sort(arr.begin(),arr.end(),comp);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int price=arr[i].first;
        int stock=arr[i].second;
        if(price*stock<=k)
        {
            res+=stock;
            k-=price*stock;
        }
        else{
            
            res+=k/price;
            k-=(k/price)*price;
        }
    }
    cout<<res;
    return 0;
}