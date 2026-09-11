#include <vector>
#include <iostream>
#include <map>
#include <array>
#include <set>
#include <queue>

using namespace std;

array<int, 4> dx{+1,-1, 0, 0};
array<int, 4> dy{ 0, 0,+1,-1};

void solve(){
	int p; cin >> p;
	int n; cin >> n;
	int m; cin >> m;

	auto inside = [&](int x, int y) -> bool {
		return 1 <= x && x <= n && 1 <= y && y <= m;
	};

	vector<array<int, 2>> pts(p);
	vector<set<int>> danno(n+1);

	for (auto& [x, y] : pts) {
		cin >> x >> y;
		danno[x].insert(y);
	}

	queue<array<int, 2>> Q;
	vector<map<int, int>> dist(n+1);
	for (auto [x, y] : pts) {
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inside(nx, ny) && !danno[nx].count(ny)) {
				Q.push({x, y});
				dist[x][y] = 1;
				break;
			}
		}
	}
	
	while (!Q.empty()) {
		auto [x, y] = Q.front();
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inside(nx, ny) && danno[nx].count(ny) && dist[nx][ny] == 0) {
				dist[nx][ny] = dist[x][y] + 1;
				Q.push({nx, ny});
			}
		}
	}


	int ans = 1e9;
	for (auto [x, y] : pts) {
		bool loc_max = true;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inside(nx, ny) && danno[nx].count(ny) && dist[nx][ny] > dist[x][y]) {
				loc_max = false;
			}
		}
		if (loc_max) {
			ans = min(ans, dist[x][y]);
		}
	}
	cout << ans - 1 << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

