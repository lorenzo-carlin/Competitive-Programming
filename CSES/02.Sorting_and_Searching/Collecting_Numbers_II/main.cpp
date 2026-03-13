#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	set<int> s;
	vector<int> pos(n+2);
	vector<int> v(n+2);
	for(int i = 0; i < n; ++i)
	{
		int num; cin >> num;
		pos[num] = i;
		v[i] = num;
	}
	pos[0] = -1;
	pos[n+1] = 1e9;

	// inserimento sbarrette iniziale
	for(int i = 1; i < n; i++)
	{
		if(pos[i+1] < pos[i])
		{
			s.insert(i);
		}
	}

	for(int i = 0, x, y; i < m; ++i)
	{
		cin >> x >> y; x--; y--;
		int a = v[x];
		int b = v[y];
		swap(v[x], v[y]);
		swap(pos[a], pos[b]);

		if(pos[a] > pos[a-1] && s.count(a-1)) s.erase(a-1);
		if(pos[a] < pos[a-1]) s.insert(a-1);
		if(pos[a] > pos[a+1]) s.insert(a);
		if(pos[a] < pos[a+1] && s.count(a)) s.erase(a);

		if(pos[b] > pos[b-1] && s.count(b-1)) s.erase(b-1);
		if(pos[b] < pos[b-1]) s.insert(b-1);
		if(pos[b] > pos[b+1]) s.insert(b);
		if(pos[b] < pos[b+1] && s.count(b)) s.erase(b);

		cout << s.size()+1 << "\n";
		// for(int el: s) cout << el << " ";
		// cout << "\n";
	}
}
