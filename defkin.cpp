#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
        int w,h,n;
        cin>>w>>h>>n;
        vector<int> a;
        vector<int> b;
        a.push_back(0);
        b.push_back(0);
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
        }
        a.push_back(w+1);
        b.push_back(h+1);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int maxx=0;
        int maxy=0;
        for(int i=0;i<a.size()-1;i++)
        {
            maxx=max(maxx,a[i+1]-a[i]-1);
            maxy=max(maxy,b[i+1]-b[i]-1);
        }
        cout<<maxx*maxy<<endl;
    }
    return 0;
}