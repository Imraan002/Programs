#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int first_vashya[N];
int last_petya[N];
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
    int arr[n+1];
    for(int i=1;i<n+1;i++)
    {
    	cin>>arr[i];
    }
    int q;
    cin>>q;
    int query[q];
    for(int i=0;i<q;i++)
    {
    	cin>>query[i];
    }
    for(int i=1;i<n+1;i++)
    {
        first_vashya[arr[i]]=i;
        last_petya[arr[i]]=n+1-i;
    }
    int vashya(0),petya(0);
   for(int i=0;i<q;i++)
   {
       vashya+=first_vashya[query[i]];
       petya+=last_petya[query[i]];
   }
   cout<<vashya<<" "<<petya<<"\n";
    return 0;
}