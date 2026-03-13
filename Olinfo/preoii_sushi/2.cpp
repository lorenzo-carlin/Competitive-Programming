#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define f first
#define s second

int sushi(int n, int b, vector<int> a)
{
    vector<bool> vis(b+1, false);
    deque<pair<int,int>> v;
    for(auto &el : a)
    {
        v.push_back({el, 1});
        vis[el] = true;
    }
    while(!vis[b])
    {
        for(auto el : a)
        {
            if(v.front().f+el < b && !vis[v.front().f+el])
            {
                vis[v.front().f+el] = true;
                v.push_back({v.front().f+el, v.front().s+1});
                // cout << v.back().f << " " << v.back().s << "\n";
            } else if(v.front().f+el == b) return v.front().s+1;
        }
        v.pop_front();
    }
    return -1;
}

int main() {

	int N, B;
	cin >> N >> B;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << sushi(N, B, A) << endl;

	return 0;
}