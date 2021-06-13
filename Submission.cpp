#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

set<int> visited;
int main()
{
    //freopen("../street_layout_4.txt", "r", stdin);
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    queue<pair<int, int>> q; // loc, risk
    int station;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &station);
        station--;
        q.push({station, 0});
        visited.insert(station);
    }
    int count = 0;
    while (!q.empty())
    {
        int curr = q.front().first;
        int risk = q.front().second;
        q.pop();
        for (int d : {-1, 1})
        {
            if (curr + d < 0 || curr + d >= l) continue;
            if (visited.count(curr + d) == 0)
            {
                count++;
                visited.insert(curr + d);
                if (count == m)
                {
                    printf("%d", risk + 1);
                    return 0;
                }
                q.push({curr + d, risk + 1});
            }
        }
    }
    return 0;
}