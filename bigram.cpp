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
        int n;
        cin>>n;
        string arr[n-2];
        for(int i=0;i<n-2;i++)
        {
            cin>>arr[i];
        }
        string word;
        for(int i=0;i<=n-4;i++)
        {
            if(word[word.size()-1]!=arr[i][0])
            {
                word+=arr[i][0];
            }
            if(word[word.size()-1]!=arr[i][0])
            {
                word+=arr[i+1][1];
            }
            
        }
        cout<<word<<"\n";
    }
return 0;
}