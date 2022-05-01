#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int x; cin >> x;
    pair<string,string> same[x];

    for(int i = 0; i < x; i++)
    {
        string a,b; cin >> a >> b;
        same[i] = mp(a,b);
    }

    int y; cin >> y;
    pair<string, string> dif[y];
    
    for(int i = 0; i < y; i++)
    {
        string a,b; cin >> a >> b;
        dif[i] = mp(a,b);
    }

    map<string, int> group;
    int g; cin >> g;

    for(int i = 0; i < g; i++)
    {
        string a,b,c; cin >> a >> b >> c;
        group[a] = i;
        group[b] = i;
        group[c] = i;
    }

    int ans = 0;

    for(int i = 0; i < x; i++)
    {
        if(group[same[i].f] != group[same[i].s])
        {
            ans++;
        }
    }

    for(int i = 0; i < y; i++)
    {
        if(group[dif[i].f] == group[dif[i].s])
        {
            ans++;
        }
    }

    cout << ans;
}