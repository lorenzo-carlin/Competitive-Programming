#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Matrix = array<array<ll,3>,3>;
using Array = array<ll,3>;

constexpr ll mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    map<ll,pair<bool,bool>> mp;
    for(int i = 0, a, b; i < m; i++)
    {
        cin >> b >> a; a--; b--;
        if(a-b == 1) mp[a].first = true;
        else mp[a].second = true;
    }

    Matrix T_0 = {{{1,1,1}, {1,0,0}, {0,1,0}}};
    Matrix T_1 = {{{0,1,1}, {1,0,0}, {0,1,0}}};
    Matrix T_2 = {{{1,0,1}, {1,0,0}, {0,1,0}}};
    Matrix T_3 = {{{0,0,1}, {1,0,0}, {0,1,0}}};

    auto printM = [&] (Matrix A) -> void
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
    };

    auto printA = [&] (Array A) -> void
    {
        for(int i = 0; i < 3; i++)
            cout << A[i] << " ";
        cout << "\n";
    };

    auto multiplication = [&] (Matrix A, Matrix B) -> Matrix
    {
        Matrix C;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                C[i][j] = 0;
                for(int k = 0; k < 3; k++)
                {
                    C[i][j] += (A[i][k]*B[k][j]);
                    C[i][j] %= mod;
                }
            }
        }
        return C;
    };

    auto multiplication1 = [&] (Matrix A, Array B) -> Array
    {
        Array C;
        for(int i = 0; i < 3; i++)
        {
            C[i] = 0;
            for(int k = 0; k < 3; k++)
            {
                C[i] += (A[i][k]*B[k]);
                C[i] %= mod;
            }
        }
        return C;
    };

    auto fast_exp = [&] (auto fast_exp, Matrix base, ll exp) -> Matrix
    {
        if(exp == 0) return {{1,0,0},{0,1,0},{0,0,1}};
        if(exp == 1) return base;
        Matrix ans = fast_exp(fast_exp, base, exp/2);
        ans = multiplication(ans, ans);
        if(exp & 1) ans = multiplication(ans, base);
        return ans;
    };

    Array T = {1, 0, 0};
    int cur = 0;
    while(mp.upper_bound(cur) != mp.end())
    {
        auto it = mp.upper_bound(cur);
        int nxt = (*it).first;
        cout << "nxt: " << nxt << "\n";
        T = multiplication1(fast_exp(fast_exp, T_0, nxt-cur-1), T);
        printA(T);
        if((*it).second.first && (*it).second.second) T = multiplication1(T_3, T);
        else if((*it).second.first) T = multiplication1(T_1, T);
        else T = multiplication1(T_2, T);
        printA(T);
        cur = nxt;
    }

    printA(T);

    T = multiplication1(fast_exp(fast_exp, T_0, n-cur-1), T);

    cout << T[0] << "\n";
}
