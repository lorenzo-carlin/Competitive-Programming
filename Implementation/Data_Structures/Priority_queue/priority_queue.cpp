#include <queue>
using namespace std;

int main()
{
    // DICHIARAZIONE
    priority_queue<int> pq;

    // AGGIUNTA ELEMENTO
    pq.push(17);

    // RIMOZIONE ELEMENTO PIU' GRANDE
    pq.pop();

    // ACCESSO ALL'ELEMENTO PIU' GRANDE
    int mx = pq.top();
}