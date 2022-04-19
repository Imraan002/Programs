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
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      string str;
      cin>>str;
      multiset<char>st;
      for(auto k:str)
      {
          st.insert(k);
      }
      for(auto t:st)
      {
          cout<<t;
      }
      cout<<"\n";
      st.clear();
  }
return 0;
}