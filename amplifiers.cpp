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
    	int n;
    	cin>>n;
    	int arr[n];
    	for(auto &k:arr)
    	{
    		cin>>k;
    	}
    	int ones=0;
    	for(int i=0;i<n;i++)
    	{
    		if(arr[i]==1)
    			ones++;
    	}
    	sort(arr,arr+n,greater<int>());
    	for(int i=0;i<ones;i++)
    	{
    		cout<<"1"<<" ";
    	}
    	if(n-ones==2 && arr[0]==3 && arr[1]==2)
    	{
    		cout<<"2 3"<<endl;
    		continue;
    	}
    	for(int i=0;i<n-ones;i++)
    	{
    		cout<<arr[i]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}