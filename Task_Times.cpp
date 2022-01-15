#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
      int n,m,k;
      cin>>n>>m>>k;
      vector<int> topics(n+1);
      vector<int> time(n+1);
      for(int i=1;i<=n;i++)
      {
          cin>>topics[i];
      }
      for(int i=1;i<=n;i++)
      {
          cin>>time[i];
      }
      vector<vector<int>> subject(m+1);
      for(int i=1;i<=n;i++)
      {
          subject[topics[i]].push_back(time[i]);
      }
      for(int i=1;i<=m;i++)
      {
          sort(subject[i].begin(),subject[i].end());
      }
      int total_time(0);
      int marks=0;
      set<pair<int,pair<int,int>>> min_heap;
      for(int i=1;i<=m;i++)
      {
          if(!subject[i].empty())
          {
              int first_topic=subject[i][0];
              int element=1;
              int idx=i;
              min_heap.insert({first_topic,{element,idx}});  
          }
      }  
      while(!min_heap.empty() )
      {
          auto temp=*min_heap.begin();
          int first_time=temp.first;
          int ele=temp.second.first;
          int idx=temp.second.second;
          min_heap.erase(min_heap.begin());
          if(first_time+total_time>k)
          {
              break;
          }
          total_time+=first_time;
          marks++;
          if(ele+1<subject[idx].size())
          {
              int cost1=subject[idx][ele];
              int cost2=subject[idx][ele+1];
              int indices=idx;
              min_heap.insert({cost1+cost2,{ele+2,indices}});
          }
      }
      cout<<marks<<endl;
  }
return 0;
}