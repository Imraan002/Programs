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
 	int n;
 	cin>>n;
 	vector<int> ans;
 	for(int i=2;i*i<=n;i++)
 	{
 		while(n%i==0)
 		{
 			ans.push_back(n/i);
 			n=n/i;
 		}
 		if(n>1)
 		{
 			ans.push_back(n);
 		}
 	}   
 	for(auto k:ans)
 	{
 		cout<<k;
 	}
    return 0;
}