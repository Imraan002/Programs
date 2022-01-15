#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> ans;
vector<vector<int>> solution(int arr[],int n,vector<int> ans)
{
    vector<vector<int>> res;
    for(int i=0;i<(1<<n);i++)
    {
        ans.clear();
        for(int j=5;j>=0;j--)
        {
            if((i>>j)&1)
            {
                ans.push_back(arr[j]);
            }
        }
        res.push_back(ans);
    }
    return res;
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
   vector<vector<int>> res=solution(arr,n,ans);
   for(auto k:res)
   {
    for(auto t:k)
    {
        cout<<t<<" ";
    }
    cout<<endl;
   }
    return 0;
}