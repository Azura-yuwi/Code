//CSES Intro Set;
//Ad Hoc

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int fmap(int& src)
{
    if(src == 1)
    {
        return 1;
    }
    else if(src == 2)
    {
        return 3;
    }
    
    return 2;
}

int smap(int& src)
{
    if(src == 1)
    {
        return 2;
    }
    else if(src == 2)
    {
        return 1;
    }
    
    return 3;
}

int main()
{
    vector<pair<int,int>> tow[17];

    tow[1].pb(mp(1,3));

    for(int i = 2; i < 17; i++)
    {
        for(int j = 0; j < tow[i-1].size(); j++)
        {
            tow[i].pb(mp(fmap(tow[i-1][j].first), fmap(tow[i-1][j].second)));
        }

        tow[i].pb(mp(1,3));

        for(int j = 0; j < tow[i-1].size(); j++)
        {
            tow[i].pb(mp(smap(tow[i-1][j].first), smap(tow[i-1][j].second)));
        }
    }

    int n;
    cin >> n;

    cout << tow[n].size() << endl;

    for(auto i : tow[n])
    {
        cout << i.first << " " << i.second << endl;
    }
}