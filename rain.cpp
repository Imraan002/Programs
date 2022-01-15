#include<bits/stdc++.h>
using namespace std;
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
        int n,d,h;
        cin>>n>>d>>h;
        int arr[n];
        int sum=0;
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                sum=sum+arr[i];
            }
            else
            {
                if(sum<d)
                {
                    sum=0;
                }
                else{
                    sum=sum-d;
                }
            }
            if(sum>h)
            {
                ans=true;
                break;
            }
            
        }
        if(ans==true)
             cout<<"yes"<<endl;
        else
             cout<<"no"<<endl;
    }
    return 0;
}