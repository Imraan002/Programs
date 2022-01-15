#include <bits/stdc++.h>
using namespace std;
#define ll long long
int SquareCube(long long int N)
{
 
    int cnt = 0, i = 1;
 
    while (int(pow(i, 6)) <= N) {
        ++cnt;
        ++i;
    }
 
    return cnt;
}
int countCubes(int a, int b)
{
    return (floor(cbrt(b)) - ceil(cbrt(a)) + 1);
}
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
        int cnt=0;
        int ans1=floor(sqrt(n)) - ceil(sqrt(0) + 1);
        int ans2=countCubes(0, n);
        int ans3=SquareCube(n);
        cout<<(ans1+ans2)-ans3<<"\n";
    }
return 0;
}