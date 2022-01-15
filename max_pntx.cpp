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
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, x, y, z;
		cin >> a >> b >> c;
		cin >> x >> y >> z;
		int ans = INT_MIN;
		for (int i = 0; i <= 20; i++)
		{
			for (int j = 0; j <= 20; j++)
			{
				for (int k = 0; k <= 20; k++)
				{
					int total_time = i * a + j * b + k * c;
					if (total_time <= 240)
					{
						ans = max(ans, i * x + j * y + k * z);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}