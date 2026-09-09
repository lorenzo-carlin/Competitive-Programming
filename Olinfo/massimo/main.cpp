#include <vector>
using namespace std;

int trova_massimo(int N, vector<int> V) {
    int mx = -1000;
    for(int i = 0; i < N; i++)
    {
        if(V[i] > mx)
        {
            mx = V[i];
        }
    }
    return mx;
}
