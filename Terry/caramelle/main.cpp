#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Funzione che restituisce l'MCD dei due numeri a e b
ll MCD(ll a, ll b)
{
	if(b == 0) return a;
	else return MCD(b, a%b);
}

// Funzione che restituisce l'mcm dei due numeri a e b
ll mcm(ll a, ll b)
{
	return (a * b) / MCD(a, b);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t; cin >> t;
	for(int x = 1; x <= t; x++)
	{
		// IDEA: la soluzione è l'mcm di tutti gli n valori
		int n; cin >> n;
		ll sol = 1;
		int a;
		for(int i = 0; i < n; i++)
		{
			cin >> a;
			sol = mcm(sol, a);
		}
		cout << "Case #" << x << ": " << sol << "\n";
	}
}


