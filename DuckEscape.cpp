#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair


int main()
{
    ofstream fout ("duck.out");
    ifstream fin ("duck.in");

    int n,q,k,d;
    fin >> n >> q >> k >> d;
    //cin >> n >> q >> k >> d;

    int duck[n];
    
    for(int i = 0; i < n; i++)
    {
        fin >> duck[i];
        //cin >> duck[i];
    }

    sort(duck, duck+n, greater<int>());

    int on = 0;
    int need = 0;

    while(on < n)
    {
        need += (max(d-duck[on], 0)/k);

        if(max(d-duck[on], 0) % k != 0)
        {
            need++;
        }

        //cout << on << " " << duck[on] << " " << need << endl;

        if(need > q)
        {
            break;
        }

        on++;
    }

    //cout << (on);

    fout << on;

}
