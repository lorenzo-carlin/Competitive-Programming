#include <deque>
using namespace std;

int main()
{
    // DICHIARAZIONE
    deque<int> d(15, 0);

    // AGGIUNTA VALORE IN TESTA - O(1)
    d.push_front(10);

    // AGGIUNTA VALORE IN CODA - O(1)
    d.push_back(7);

    // RIMOZIONE VALORE IN TESTA - O(1)
    d.pop_front();

    // RIMOZIONE VALORE IN CODA - O(1)
    d.pop_back();

    // AGGIUNTA VALORE IN UNA QUALSIASI POSIZIONE (ad es. 3°) - O(N)
    d.insert(d.begin()+3, 15);

    // RIMOZIONE VALORE IN UNA QUALSIASI POSIZIONE (ad es. 3°) - O(N)
    d.erase(d.begin()+3);

    // SVUOTAMENTO DELLA QUEUE - O(N)
    d.clear();

    // PRIMO ELEMENTO - O(1)
    int first = d.front();

    // ULTIMO ELEMENTO - O(1)
    int last = d.back();

    // ELEMENTO IN QUALSIASI POSIZIONE (ad es. 2°)
    int second = d[1];
}