#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

/**********************************************************************************
MAP:
    - associa una chiave ad un valore
    - non permette doppioni
    - gli elementi sono ordinati

MULTIMAP:
    - associa una chiave ad un valore
    - permette doppioni
    - gli elementi sono ordinati
    - attenzione all'erase! (cancella tutti gli elementi con un determinato valore)
**********************************************************************************/

int main()
{
    // dichiarare una map
    map<int,int> mp;

    // modificare i valori di una chiave
    mp.insert(make_pair(2, 3));
    mp[1] = 3;      // crea in automatico la chiave '1'
    mp[0]++;        // la chiave '0' viene settata a 0, quindi diventa 1 con il ++
    mp[-1]--;       // la chiave '-1' viene settata a 0, quindi diventa -1 con il --
    mp[1] = 5;      // sovrascrive il valore della chiave 1

    // rimuovere una chiave
    mp.erase(-1);   // si elimina una chiave!, non il valore

    // sintassi per vedere tutte le chiavi - valori della map (vengono trasformati in pair)
    for(auto el: mp)
    {
        cout << el.first <<  " " << el.second << "\n";
    }

    // verificare se una chiave è presente nella map
    auto it = mp.find(2);
    if(it == mp.end())
    {
        cout << "non è presente\n";
    } else
    {
        cout << "è presente\n";
    }

    // dichiarare una multimap
    multimap<int,int> mmp;

    // inserire elementi nella multimap
    mmp.insert(make_pair(2, 0));
    mmp.insert(make_pair(1, 5));
    mmp.insert(make_pair(1, 3));
    mmp.insert(make_pair(1, 3));

    // rimuovere chiavi della multimap (! vengono eliminate tutte le chiavi con quel valore)
    mmp.erase(1);

    // sintassi per vedere tutte le chiavi-valore della multimap
    for(auto el: mmp)
    {
        cout << el.first << " " << el.second << "\n";
    }

    // altre funzioni:
    // swap(), clear(), find(), count(), lower_bound(), upper_bound()

    // dichiarare una unordered map
    unordered_map<int,int> ump;

    // inserire elementi nella unordered map
    ump[0] = 1;
    ump.insert(make_pair(2, 3));

    // rimuovere una chiave dalla unordered map
    ump.erase(0);

    // sintassi per vedere tutte le chiavi-valore della unordered map
    for(auto el: mmp)
    {
        cout << el.first << " " << el.second << "\n";
    }
}