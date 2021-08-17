//CSES Sorting and Searching

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        pq.push(mp(b,a));
    }

    int ans = 0;
    int end = 0;

    while(!pq.empty())
    {
        int en, st; tie(en, st) = pq.top();
        pq.pop();
        //cout << "START " << st << " END" << en << endl;
        if(st >= end)
        {
            ans++;
            end = en;
        }
    }

    cout << ans;
}