#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n,m; cin >> n >> m;
    vector<int> v;

    for(int i = 0; i < n; i++)
    {
        int get; cin >> get; v.pb(get);
    } 

    sort(v.begin(), v.end());
    int dist = INT_MAX;
    int ans = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        int p = n-1;

        for(int j = i+1; j < n; j++)
        {
            int tag = m - v[i] - v[j]; 
            if(tag < 0) continue;

            int p = lower_bound(v.begin(), v.end(), tag) - v.begin(); //v[p] >= tag

            if(p < j+1) continue;

            if(p != n) 
            {
                if(dist > abs(v[p] - tag))
                {
                    dist = abs(v[p] - tag);
                    ans = v[i] + v[j]+ v[p];
                }
                else if(dist == abs(v[p] - tag))
                {
                    ans = min(ans, v[i] + v[j]+ v[p]);
                }
            }
            
            if(p != j+1)
            {
                p--;

                if(dist > abs(v[p] - tag))
                {
                    dist = abs(v[p] - tag);
                    ans = v[i] + v[j]+ v[p];
                }
                else if(dist == abs(v[p] - tag))
                {
                    ans = min(ans, v[i] + v[j]+ v[p]);
                }
            }
        }
    }

    cout << ans << endl;
}