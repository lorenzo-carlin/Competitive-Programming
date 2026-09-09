#include <iostream>
#include <climits>
using namespace std;

int laurea(int N, int n2, int n4, int n5, int n7, int p2, int p4, int p5, int p7)
{
    if(N <= 0)
        return 0;
    
    int mn = INT_MAX;
    
    if(n2 > 0)
        mn = min(mn, laurea(N-2, n2 - 1, n4, n5, n7, p2, p4, p5, p7)+p2);
    if(n4 > 0)
        mn = min(mn, laurea(N-4, n2, n4 - 1, n5, n7, p2, p4, p5, p7)+p4);
    if(n5 > 0)
        mn = min(mn, laurea(N-5, n2, n4, n5 - 1, n7, p2, p4, p5, p7)+p5);
    if(n7 > 0)
        mn = min(mn, laurea(N-7, n2, n4, n5, n7 - 1, p2, p4, p5, p7)+p7);

    return mn;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N; cin >> N;
    int n2, n4, n5, n7; // numero di mezzi
    int p2, p4, p5, p7; // numero di persone
    cin >> n2 >> p2;
    cin >> n4 >> p4;
    cin >> n5 >> p5;
    cin >> n7 >> p7;

    int ans = laurea(N, n2, n4, n5, n7, p2, p4, p5, p7);
    cout << ans;
}