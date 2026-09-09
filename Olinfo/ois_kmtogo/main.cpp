#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> occ(10, 0);

void conta(int i)
{
	string a = to_string(i);
	for(char c: a) occ[c-'0']++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for(int i = n; i > 0; i --) conta(i);

	for(int el: occ) cout << el << " ";
	cout << "\n";
}
