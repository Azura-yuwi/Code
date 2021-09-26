//USACO Guide BFS
// haven't really figured out why doesn't work

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair

int main() {
    int n;
    cin >> n;
    
    int bfs[n];
    int dfs[n];
    int atdfs[n+1];
    
    for(int i = 0; i < n; i++)
    {
        cin >> bfs[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        cin >> dfs[i];
        atdfs[dfs[i]] = i;
    }
    
    vector<pair<int,int>> lyr[n];
    lyr[0].pb(mp(0, 1));
    int layer = 1;
    int point = 1;
    int bfr = 0;
    
    vector<pair<int,int>> edges;
    
    for(int i = 1; i < n; i++)
    {
        //cout << bfs[i] << " " << atdfs[bfs[i]] << " " << layer << " " << point << endl;
        
        if(atdfs[bfs[i]] < point) 
        { 
            layer++; bfr = 0;
        }
        
        lyr[layer].pb(mp(atdfs[bfs[i]], bfs[i]));
        
        point = atdfs[bfs[i]];
        
        while(bfr < (int)lyr[layer-1].size() && lyr[layer-1][bfr].first < point)
        {
            bfr++;
        }
        
        if(bfr == 0)
        {
            cout << -1; return 0;
        }
        
        bfr--;
        edges.pb(mp(lyr[layer-1][bfr].second, bfs[i]));
    }
    
    cout << edges.size() << endl;
    
    for(pair<int,int> get : edges)
    {
        cout << get.first << " " << get.second << endl;
    }
    
    return 0;
}