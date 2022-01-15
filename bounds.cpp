#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
int arr[]={3,6,1,8,9};
sort(arr,arr+5);
auto it=lower_bound(arr,arr+5,9);
cout<<*it;	
cout<<"\n";
set<int> st;
st.insert(3);
st.insert(6);
st.insert(2);
auto itt=st.lower_bound(2);
cout<<*itt;
return 0;
}