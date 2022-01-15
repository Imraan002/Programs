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
    	vector<int> arr(n);
    	
    	for(int i=0;i<n;i++)
    	{
    		if(i==n-1)
            {
                arr[i]=n;
            }
            else{
                arr[i]=(n-(i+1));
            }
            
    	}
    	for(int i=0;i<n;i++)
    	{
    		cout<<arr[i]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}