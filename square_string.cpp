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
      string str;
      cin>>str;
      
      if(str.size()%2!=0)
      {
          cout<<"no\n";
          continue;
      }
      else{
          int i=0;
          int j=str.size()/2;
          bool ans=true;
          while(i<str.size()/2 && j<str.size())
          {
             if(str[i]!=str[j])
             {
                 ans=false;
                 break;
             }
              i++;j++;
          }
          if(ans==true)
          {
              cout<<"yes\n";
          }
          else{
              cout<<"no\n";
          }
      }
  }
return 0;
}