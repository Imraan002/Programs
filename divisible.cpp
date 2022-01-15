#include<bits/stdc++.h>
using namespace std;
#define ll long long
int find_dig(int n)
{
	int res=0;
	while(n)
	{
		res++;
		n=n/10;
	}
	return res;
}
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
        if(find_dig(n)==n && n%3==0 && n%9!=0)
        {
            cout<<n<<endl;
            continue;
        }
        else{
            int res=find_dig(n);
            while(res!=n)
            {
                n=n*9;
                res=find_dig(n);
            }
        }
        cout<<n-3<<endl;
    }   
    return 0;
}
    