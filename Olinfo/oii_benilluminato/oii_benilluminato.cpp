#include <vector>
#include <set>
#include <iostream>
using namespace std;

int illumina(int N, int M, vector<int> H, vector<int> A, vector<int> B, vector<int> L) {
    int ans = 0;
	vector<bool> vertici(N, true), archi(M, true);

    for(int i = 0; i < M; i++)
    {
        if(L[i] >= (H[A[i]] + H[B[i]]))                     // caso verde
        {
            if(vertici[A[i]])
            {
                vertici[A[i]] = false;
                ans++;
            }
            if(vertici[B[i]])
            {
                vertici[B[i]] = false;
                ans++;
            }
            archi[i] = false;
        } else if(L[i] < H[A[i]] && L[i] < H[B[i]])         // caso rosso
        {
            archi[i] = false;
        }
    }

    for(int i = 0; i < M; i++)
    {
        if(!archi[i]) continue;

        if(L[i] >= H[A[i]] && L[i] < H[B[i]])        // caso 2a
        {
            if(vertici[A[i]])
            {
                vertici[A[i]] = false;
                ans++;
            }
            archi[i] = false;
        } else if(L[i] < H[A[i]] && L[i] >= H[B[i]])        // caso 2b
        {
            if(vertici[B[i]])
            {
                vertici[B[i]] = false;
                ans++;
            }
            archi[i] = false;
        }
    }

    vector<vector<pair<int,int>>> adj(N);
    for(int i = 0; i < M; i++)
    {
        if(!archi[i]) continue;

        adj[A[i]].push_back({B[i], i});
        adj[B[i]].push_back({A[i], i});
    }

    int m, n;
    set<pair<int,int>> s;
    vector<bool> vis(M, false);

    auto dfs = [&] (auto dfs, int v) -> void
    {
        vertici[v] = false;
        n++;
        for(auto [u, idx]: adj[v])
        {
            if(!vis[idx])
            {
                vis[idx] = true;
                m++;
            }
            if(!vertici[u]) continue;
            dfs(dfs, u);
        }
    };

    for(int i = 0; i < N; i++)
    {
        n = 0; m = 0;
        if(vertici[i])
        {
            dfs(dfs, i);
            if(m > n-1) ans += n;
            else ans += (n-1);
        }
    }

    return ans;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {
	int N; cin >> N;
	int M; cin >> M;

	vector<int> H(N);
	for (int i = 0; i < N; ++i)
		cin >> H[i];

	vector<int> A(M), B(M), L(M);
	for (int i = 0; i < M; ++i)
		cin >> A[i] >> B[i] >> L[i];

	cout << illumina(N, M, H, A, B, L) << "\n";
}

#endif
