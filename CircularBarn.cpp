//USACO Gold 2016 February

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");

    int n; fin >> n;

    int v[n];
    for(int i = 0; i < n; i++)
    {
        fin >> v[i];
    }

    int start = 0;

    for(int i = 0; i < n; i++)
    {
        int at = 0;
        int num = v[i];

        while(at < n && num > at)
        {
            at++;
            num += v[(at+i)%n];
        }

        if(at == n)
        {
            start = i;
            break;
        }
    }

    ll en = 0;
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++)
    {
        q.push(mp(v[(start+i)%n], i));

        while(q.front().first == 0)
        {
            q.pop();
        }

        en += pow((q.front().second - i), 2);
        q.front().first = q.front().first - 1;
    }

    fout << en;
}