#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
ll int find_dig_sum(ll int num)
{
	ll int sum=0;
	while(num)
	{
		sum+=num%10;
		num=num/10;
	}
	return sum;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
 	ll int t;
 	cin>>t;
 	while(t--)
 	{
 		 ll int L,R;
         cin>>L>>R;
         ll int temp=find_dig_sum(L);
         L=L-(temp%3);
         L=L+3;
         ll int cnt=(R-L)/3;
        //  for(ll int i=L;i<=R;i=i+3)
        //  {
        //      cnt++;
        //  }
         cout<<cnt<<endl;

 	}   
    return 0;
}