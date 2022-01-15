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
    int s, d;
    cin >> s >> d;
    string str;
    if (9 * d < s)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (int i = d; i >= 1; i--)
    {
        while (s > 9)
        {
            str = '9'+str;
            s -= 9;
            i--;
        }
        if (i == 1)
        {
            str= to_string(s)+str;
            break;
        }
        str=to_string(s-1)+str;
        i--;
        while (i > 1)
        {
            str= '0'+str;
            i--;
        }
        str= '1'+str;
    }
    cout << str << endl;
    return 0;
}