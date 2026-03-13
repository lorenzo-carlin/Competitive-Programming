#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v;
stack<int> s;
vector<int> p;

int solve(int v)
{
	if(p[v] == v) return v;
	else return p[v] = solve(p[v]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	if(n == 1)
	{
		cout << 0 << "\n";
		return 0;
	}

	v.resize(n);
	for(ll &i: v) cin >> i;

	p.resize(n);
	p[0] = 0;
	p[n-1] = n-1;

	s.push(0);
	for(int i = 1; i < n-1; ++i)
	{
		if(v[i] - v[i-1] <= v[i+1] - v[i])
		{
			while(s.top() > 0 && v[s.top()] - v[s.top()-1] <= v[i+1] - v[s.top()])
			{
				s.pop();
			}
			p[i] = s.top();
		}
		s.push(i);
	}

	while(!s.empty()) s.pop();
	s.push(n-1);
	for(int i = n-2; i >= 1; i--)
	{
		if(v[i] - v[i-1] > v[i+1] - v[i])
		{
			while(s.top() < n-1 && v[s.top()+1] - v[s.top()] < v[s.top()] - v[i-1])
			{
				s.pop();
			}
			p[i] = s.top();
		}
		s.push(i);
	}

	for(int i = 0; i < n; ++i)
	{
		cout << n-1-solve(i) << " ";
	}
	cout << "\n";
}
