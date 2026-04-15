#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int x;
    int y;
};

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cell A, B, C; cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        int sol = 1;
        if(B.y >= A.y && C.y >= A.y)
        {
            sol += (abs(A.y - min(B.y, C.y)));
        } else if(B.y <= A.y && C.y <= A.y)
        {
            sol += (abs(A.y - max(B.y, C.y)));
        }
        if(B.x >= A.x && C.x >= A.x)
        {
            sol += (abs(A.x - min(B.x, C.x)));
        } else if(B.x <= A.x && C.x <= A.x)
        {
            sol += (abs(A.x - max(B.x, C.x)));
        }
        cout << sol << "\n";
    }
}
