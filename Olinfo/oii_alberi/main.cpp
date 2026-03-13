#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll carica(int n, int k, vector<int> a)
{
	vector<ll> pre(n+1, 0), suf(n, 0);
	for(int i = 0; i < n; i++) pre[i+1] = (ll)pre[i] + (ll)a[i];
	for(int i = n-2; i >= 0; i--) suf[i] = (ll)suf[i+1] + (ll)a[i+1] - (ll)a[i] - 1LL;

	ll mn = pre.back();
	for(int i = 0; i < n; i++)
	{
		ll tmp = (ll)a[i] - 1LL + (ll)pre[i] + (ll)suf[i] + (ll)(k+1)*(n-i);
		mn = min(mn, tmp);
	}

    return mn;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int &a: A) cin >> a;

    cout << carica(N, K, A) << endl;

    return 0;
}

#endif

