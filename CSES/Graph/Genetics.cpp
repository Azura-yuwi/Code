//USACO Guide String Hashing

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll p = 9973;
const ll mod = 1e9 + 7;
ll hsh[4100];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    ll pow = 1;
    
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        hsh[i] = 0;

        for(int j = 0; j < m; j++)
        {
            hsh[i] = hsh[i];
        }

    }
}