#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, l;
    cin >> n >> m >> l;

    int dist[l] = {0};
    queue<int> q;
    int station;

    for(int i = 0; i < n; i++)
    {
        cin >> station;
        station--;
        dist[station] = 1;
        q.push(station);
    }

    int count = 0;
    bool done = false;
    while(!q.empty() && !done)
    {
        int curr = q.front();
        q.pop();

        for(int d : {-1, 1})
        {
            if(curr + d < 0 || curr + d >= l)
            {
                continue;
            }

            if(dist[curr+d]==0)
            {
                count++;
                dist[curr+d] = dist[curr]+1;

                if(count == m)
                {
                    cout << (dist[curr+d]-1) << endl;
                    done = true;
                    break;
                }

                q.push(curr+d);
            }
        }
    }

    return 0;
}
