#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int n, b;
int mx = 1e9;
vector<int> v, t;
map<int,int> mp;

void solve(int curr)
{
    if(curr == b)
    {
        mx = min(mx, -(*mp.begin()).first);
        return;
    }
    if(curr > b) return;
    
    for(int i = 0; i < n; ++i)
    {
        mp[-t[i]]--;
        t[i]++;
        mp[-t[i]]++;
        solve(curr+v[i]);
        mp[-t[i]]--;
        if(mp[-t[i]] == 0) mp.erase(-t[i]);
        t[i]--;
        mp[-t[i]]++;
    }

}

int sushi(int N, int B, vector<int> A)
{
	n = N, b = B, v = A;
    t.resize(n, 0);
    mp[0] = n;

    solve(0);

    if(mx == 1e9) mx = -1;
    return mx;
}

int main() {
	// se preferisci leggere e scrivere da file
	// ti basta decommentare le seguenti due righe:

	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N, B;
	cin >> N >> B;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << sushi(N, B, A) << endl;

	return 0;
}
