#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C, a, b, c; cin >> A >> B >> C >> a >> b >> c;
	cout << abs(A-a) + abs(B-b) + abs(C-c) << "\n";
}
