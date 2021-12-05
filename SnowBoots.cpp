//USACO Gold 2018 February

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");

    int n,b; fin >> n >> b;

    int val[n];
    
    for(int i = 0; i < n; i++)
    {
        fin >> val[i];
    }

    int q[b];

    using Q = pair<pair<int,int>, int>;
    priority_queue<Q, vector<Q>, greater<Q>> queries;

    for(int i = 0; i < b; i++)
    {
        int a,c; fin >> a >> c;
        queries.push(mp(mp(c,a), i));  
    } 

    int dp[n];
    
    dp[n-1] = 0;

    for(int i = n-2; i >= 0; i--)
    {
        dp[i] = max(dp[i+1], val[i]);
    }

    while(!queries.empty() && queries.top().first.first == 1)
    {
        if(queries.top().first.second >= dp[0])
        {
            q[queries.top().second] = 1;
        }
        else
        {
            q[queries.top().second] = 0;
        }

        queries.pop();
    }

    for(int s = 2; s < n; s++)
    {
        using T = pair<int,int>;
        priority_queue<T, vector<T>, greater<T>> pq; 
        
        for(int i = n-1; i >= 0; i--)
        {
            if(i >= n-s)
            {
                dp[i] = val[i];
            }
            else
            {
                while(pq.top().second - s > i)
                {
                    pq.pop();
                }

                dp[i] = min(dp[i], max(pq.top().first, val[i]));
            }

            pq.push(mp(dp[i], i));
        }

        while(!queries.empty() && queries.top().first.first == s)
        {
            if(queries.top().first.second >= dp[0])
            {
                q[queries.top().second] = 1;
            }
            else
            {
                q[queries.top().second] = 0;
            }

            queries.pop();
        }
    }


    for(int i = 0; i < b; i++)
    {
        fout << q[i] << endl;
    }
   

}