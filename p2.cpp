#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll results[30];
int T, n, m;

void dfs(vector<vector<int>>& paths, vector<int>& nodes, int node, int value)
{
    if (nodes[node] != -1) {
        return;
    }

    nodes[node] = value;

    for (int next : paths[node])
    {
        if (nodes[next] == -1) {
            dfs(paths, nodes, next, value);
        }
    }

    return;
}

void solve(int index)
{
    cin >> n >> m;

    vector<vector<int>> paths(n);

    for (int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        paths[s].push_back(t);
        paths[t].push_back(s);
    }

    vector<int> nodes(n);
    vector<int> groups[n];
    for (int i = 0; i < n; i++)
    {
        nodes[i] = -1;
    }

    dfs(paths, nodes, 0, 0);

    if (nodes[n-1] == 0) {
        results[index] = 0;
        return;
    }

    dfs(paths, nodes, n-1, n-1);

    for (int i = 0; i < n; i++)
    {
        if (nodes[i] == -1) {
            dfs(paths, nodes, i, i);
        }

        groups[nodes[i]].push_back(i);
    }

    vector<int> start;
    vector<int> end;
    vector<int> empty;

    int mapping[n];

    for (int i = 0; i < n; i++)
    {
        if (nodes[i] == 0) {
            start.push_back(i);
        }
        else if (nodes[i] == n-1) {
            end.push_back(i);
        }
        else
        {
            empty.push_back(i);
            mapping[i] = empty.size()-1;
        }
    }

    results[index] = LLONG_MAX;

    int p1 = 0;
    int p2 = 0;

    while (p1 < start.size() && p2 < end.size())
    {
        ll distance = ((ll)start[p1] - end[p2]) * (start[p1] - end[p2]);

        results[index] = min(results[index], distance);

        if (start[p1] < end[p2]) {
            p1++;
        }
        else {
            p2++;
        }
    }

    if (empty.size() == 0)
    {
        return;
    }

    ll dist1[empty.size()];

    p1 = 0;
    for (int i = 0; i < empty.size(); i++)
    {
        dist1[i] = LLONG_MAX;
        while (p1 < start.size() && start[p1] < empty[i]) 
        {
            p1++;
        }

        if (p1 == start.size()) {
            p1--;
        }

        ll distance = LLONG_MAX;
        if (p1 < start.size())
        {
            distance = ((ll)start[p1] - empty[i]) * (start[p1] - empty[i]);
            dist1[i] = min(dist1[i], distance);
        }

        if (p1 > 0)
        {
            distance = ((ll)start[p1-1] - empty[i]) * (start[p1-1] - empty[i]);
            dist1[i] = min(dist1[i], distance);
        }

    }

    ll dist2[empty.size()];

    p2 = 0;
    for (int i = 0; i < empty.size(); i++)
    {
        dist2[i] = LLONG_MAX;
        while (p2 < end.size() && end[p2] < empty[i]) 
        {
            p2++;
        }

        if (p2 == end.size()) {
            p2--;
        }

        ll distance = LLONG_MAX;
        if (p2 < end.size())
        {
            distance = (end[p2] - empty[i]) * (end[p2] - empty[i]);
            dist2[i] = min(dist2[i], distance);
        }

        if (p2 > 0)
        {
            distance = (end[p2-1] - empty[i]) * (end[p2-1] - empty[i]);
            dist2[i] = min(dist2[i], distance);
        }
    }

    for(int i = 1; i < n-1; i++)
    {
        if(groups[i].size() == 0)
        {
            continue;
        }
        
        for(int j = 0; j < groups[i].size(); j++)
        {
            for(int k = 0; k < groups[i].size(); k++)
            {
                results[index] = min(results[index], dist1[mapping[groups[i][j]]] + dist2[mapping[groups[i][k]]]);
            }
        }
    }
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i);    
    }
    
    for (int i = 0; i < T; i++)
    {
        cout << results[i] << endl;
    }

    return 0;
}