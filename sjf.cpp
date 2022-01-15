#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> ans;
bool comp(vector<int> a,vector<int> b)
{
    if(a[1]==b[1])
    {
        if(a[2]==b[2])
        {
            return a[0]<b[0];
        }
        else
        {
            return a[2]<b[2];
        }
    }
    else
    {
        return a[1]<b[1];
    }
}
void SJF(vector<vector<int>> arr,int n)
{
    sort(arr.begin(),arr.end(),comp);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({arr[0][2],arr[0][1],arr[0][0]});
    int i=1;
    int time=0;
    while(!pq.empty())
    {
        int burst_time=pq.top()[0];
        int id=pq.top()[2];
        pq.pop();
        ans.push_back(id);
        time+=burst_time;
        while(true)
        {
            if(i<n && arr[i][1]<=time)
            {
                pq.push({arr[i][2],arr[i][1],arr[i][0]});
                i++;
            }
            else
                break;
        }
    }
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
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
   SJF(arr,n);
   for(auto k:ans)
   {
       cout<<k<<" "<<endl;
   }
    return 0;
}