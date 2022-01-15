#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(char str[])
{
    if(str[0]=='\0')
    return 0;
    return 1+solve(str+1);
}
void removex(char str[])
{
    if(str[0]=='\0')
        return;
    if(str[0]!='x')
        removex(str+1);
    else{
        int i=1;
        for(;str[i]!='\0';i++)
        {
            str[i-1]=str[i];
        }
        str[i-1]=str[i];
        removex(str);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    char str[100];
    cin>>str;
    cout<<"length is"<<solve(str)<<endl;
    removex(str);
    cout<<str;
    return 0;
}