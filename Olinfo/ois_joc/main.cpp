#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;

constexpr int MAXN = 20;
constexpr ll INF = 1e18;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	int initialSet = 0;
	for(int i = 0; i < n; ++i)
	{
		int val; cin >> val;
		if(val == 1)
		{
			initialSet += (1 << i);
		}
	}

	vector<int> processi(n, (1 << n)-1);
	for(int i = 0; i < n; ++i)
	{
		int t; cin >> t;
		while(t--)
		{
			int num; cin >> num;
			num--;
			processi[i] -= (1 << num);
		}
	}

	vector<ll> dist((1 << n), INF);
	queue<pair<ll,int>> pq;
	pq.push({0, initialSet});

	while(!pq.empty())
	{
		ll d = -pq.front().first;
		int v = pq.front().second;
		pq.pop();

		if(dist[v] <= d) continue;
		dist[v] = d;

		for(int i = 0; i < n; ++i)
		{
			if((v & (1 << i)) == 0)
			{
				int tmp = v & processi[i];
				tmp += (1 << i);
				if(d+1 < dist[tmp])
				{
					pq.push({-(d+1), tmp});
				}
			}
		}
	}

	int target = (1 << (k-1));

	cout << dist[target] << "\n";
}
