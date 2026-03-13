#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 6e5+5;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n, q; cin >> n >> q;
	vector<int> v(n);
	vector<bool> pres(MAXN, false);
	for(auto &i: v) cin >> i;
	vector<vector<int>> adj(MAXN);
	for(int i = 0; i < n; ++i)
	{
		int c = v[i];
		pres[c] = true;
		for(int j = 0; j < 20; j++)
		{
			if(c == (1 << j)) continue;
			if(c & (1 << j))
			{
				adj[1 << j].push_back(c);
				adj[c].push_back(1 << j);
			}
		}
	}

	vector<vector<int>> dist(20, vector<int> (MAXN, 1e9));
	for(int i = 0; i < 20; ++i)
	{
		// nodo, nodo da cui arrivo
		queue<pair<int,int>> q;
		dist[i][1 << i] = 0;
		for(int el: adj[1 << i]) q.push({el, (1 << i)});
		while(!q.empty())
		{
			int nodo = q.front().first;
			int from = q.front().second;
			q.pop();

			if(dist[i][nodo] <= dist[i][from]) continue;

			if(pres[from]) dist[i][nodo] = dist[i][from]+1;
			else dist[i][nodo] = dist[i][from];

			// if((from & (from -1)) == 0) dist[i][nodo] = dist[i][from];
			// else dist[i][nodo] = dist[i][from]+1;

			for(int el: adj[nodo]) q.push({el, nodo});
		}
	}

	/*
	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 20; ++j)
		{
			int tmp = (dist[i][j] == 1e9) ? (-1) : (dist[i][j]);
			cout << tmp << "\t";
		}
		cout << "\n";
	}
	*/

	for(int i = 0, a, b; i < q; ++i)
	{
		cin >> a >> b;
		a--; b--;
		// a = 1
		// b = 2
		int A = v[a]; // 3
		int B = v[b]; // 16
					  // dist[1]
					  //

		if((A & (A - 1)) == 0)
		{
			int tmp = (dist[log2(A)][B] != 1e9) ? (dist[log2(A)][B]) : (-1);
			cout << tmp << "\n";
		} else if((B & (B - 1)) == 0)
		{
			int tmp = (dist[log2(B)][A] != 1e9) ? (dist[log2(A)][B]) : (-1);
			cout << tmp << "\n";
		} else
		{
			int mn = 1e9;
			for(int i = 0; i < 20; ++i)
			{
				mn = min(mn, dist[i][A]+dist[i][B]+1);
			}
			cout << mn << "\n";
		}
	}
}
