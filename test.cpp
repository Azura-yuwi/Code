#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ofstream fout ("windows.out");
    ifstream fin ("windows.in");

    int n, k;
    fin >> n >> k;
    //cin >> n >> k;

    int dirt[n];

    for(int i = 0; i < n; i++)
    {
        //cin >> dirt[i];
        fin >> dirt[i];
    }

    sort(dirt, dirt+n);

    int cul = 0;

    for(int i = 0; i < n; i++)
    {
        cul += dirt[i];

        if(cul > k)
        {
            //cout << i; 
            fout << i;
            return 0;
        }
    }

    //cout << n;
    fout << n;
}