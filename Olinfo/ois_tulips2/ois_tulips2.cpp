#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int up, down, left, right, a, b;
	cin >> a >> b; left = a; up = b;
	cin >> a >> b; right = a;
	cin >> a >> b; down = b;
	cin >> a >> b;

	int n; cin >> n;
	int acuti, ottusi, ans = 0;
	array<int,3> v;
	while(n--)
	{
		cin >> a >> b;
		acuti = 0, ottusi = 0;

		v = {(left-right)*(left-right), (a-right)*(a-right)+(b-up)*(b-up), (a-left)*(a-left)+(b-up)*(b-up)};
		sort(begin(v), end(v));
		if(v[2] > v[0] + v[1]) ottusi++;
		if(v[2] < v[0] + v[1]) acuti++;

		v = {(up-down)*(up-down), (a-right)*(a-right)+(b-up)*(b-up), (a-right)*(a-right)+(b-down)*(b-down)};
		sort(begin(v), end(v));
		if(v[2] > v[0] + v[1]) ottusi++;
		if(v[2] < v[0] + v[1]) acuti++;

		v = {(left-right)*(left-right), (a-right)*(a-right)+(b-down)*(b-down), (a-left)*(a-left)+(b-down)*(b-down)};
		sort(begin(v), end(v));
		if(v[2] > v[0] + v[1]) ottusi++;
		if(v[2] < v[0] + v[1]) acuti++;

		v = {(up-down)*(up-down), (a-left)*(a-left)+(b-down)*(b-down), (a-left)*(a-left)+(b-up)*(b-up)};
		sort(begin(v), end(v));
		if(v[2] > v[0] + v[1]) ottusi++;
		if(v[2] < v[0] + v[1]) acuti++;

		if(ottusi == 2 && acuti == 2) ans++;
	}

	cout << ans << "\n";
}
