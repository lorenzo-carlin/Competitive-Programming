#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k; cin >> n >> k;
	stack<int> dx, sx;
	for(int i = 0, a; i < n; ++i)
	{
		cin >> a;
		sx.push(a);
	}
	dx.push(-1);
	for(int i = 0; i < n; ++i)
	{
		dx.push(sx.top());
		sx.pop();
	}
	sx.push(0);

	while(k--)
	{
		while(sx.top() <= dx.top())
		{
			sx.push(dx.top());
			dx.pop();
		}
		sx.pop();
	}

	while(!sx.empty())
	{
		dx.push(sx.top());
		sx.pop();
	}
	dx.pop();

	while(dx.size() > 1)
	{
		cout << dx.top() << " ";
		dx.pop();
	}
	cout << "\n";
}
