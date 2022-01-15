#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int n,int arr[],int idx,vector<int> ans)
{
    if(idx>=n)
    {
        for(auto k:ans)
        {
            cout<<k<<" ";
        }
        cout<<endl;
        return;
    }
    solve(n,arr,idx+1,ans);
    ans.push_back(arr[idx]);
    solve(n,arr,idx+1,ans);
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
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
vector<int> ans;
solve(n,arr,0,ans);
    return 0;
}