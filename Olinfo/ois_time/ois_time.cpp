#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h0, h1, m0, m1; cin >> h0 >> m0 >> h1 >> m1;
    int htot = 0, mtot = 0;
    int tmp = h0;
    while((tmp%24) != h1)
    {
        htot++;
        tmp++;
    }
    if(h0 == h1 && m0 > m1)
    {
        htot = 23;
        mtot = 60-(m0-m1);
    } else
    {
        if(m1 < m0)
        {
            htot--;
            mtot = 60-(m0-m1);
        } else
        {
            mtot += m1-m0;
        }
    }
    cout << htot << " " << mtot;
    return 0;
}