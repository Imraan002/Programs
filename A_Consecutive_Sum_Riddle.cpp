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
  ll int t;
  cin>>t;
  while(t--)
    {
        ll int num;
        cin>>num;
        cout<<-(num-1)<<" "<<num<<" \n";
    }
return 0;
}