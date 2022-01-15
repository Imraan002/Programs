#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool comp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first>p2.first;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x;
        cin>>n>>m>>x;
        int temp;
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(make_pair(temp,i+1));
        }
        sort(arr.begin(),arr.end(),comp);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(arr[i].first>=m || ans.size()<x)
            {
                ans.push_back(arr[i].second);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<" ";
        for(auto k:ans)
        {
            cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}