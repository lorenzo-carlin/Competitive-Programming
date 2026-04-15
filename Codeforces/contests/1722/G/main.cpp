#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fillin(int i, int j, vector<int> &A, vector<int> &B)
{
	int st1 = 16;
	int st2 = (1 << 17);

	for(; i < A.size(); i++)
	{
		A[i] = st1;
		st1++;
	}
	for(; j < B.size(); j++)
	{
		B[j] = st2;
		st2++;
	}
}

void solve()
{
	int n; cin >> n;
	int a = (n+1)/2;
	int b = n/2;

	vector<int> A(a);
	vector<int> B(b);

	if(n == 3)
	{
		cout << "2 1 3\n";
		return;
	}

	if(a % 2 == 0 && b % 2 == 0)
	{
		fillin(0, 0, A, B);
	} else if(a % 2 == 1 && b % 2 == 0)
	{
		A[0] = 2;
		A[1] = 3;
		A[2] = 4;
		B[0] = 0;
		B[1] = 5;
		fillin(3, 2, A, B);
	} else if(a % 2 == 0 && b % 2 == 1)
	{
		A[0] = 1;
		A[1] = 3;
		A[2] = 5;
		A[3] = 7;
		B[0] = 2;
		B[1] = 4;
		B[2] = 6;
		fillin(4, 3, A, B);
	} else
	{
		A[0] = 2;
		A[1] = 3;
		A[2] = 4;
		B[0] = 1;
		B[1] = 8;
		B[2] = 12;
		fillin(3, 3, A, B);
	}

	for(int i = 0; i < n; ++i)
	{
		if(i % 2 == 0) cout << A[i/2] << " ";
		else cout << B[i/2] << " ";
	}
	cout << "\n";
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
}
