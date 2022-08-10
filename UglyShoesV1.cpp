#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main()
{
    int n,m; cin >> n >> m;
    vector<int> left;
    vector<int> right;

    for(int i = 0; i < n; i++)
    {
        int a; cin >> a; left.pb(a);
    }

    for(int i = 0; i < m; i++)
    {
        int b; cin >> b; right.pb(b);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    if(n > m)
    {
        swap(left, right);
        swap(n,m);
    }

    if(n == m)
    {
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(abs(left[i] - right[i]), ans);
        }

        cout << ans;

        return 0;
    }


   int small[n]; // <
    int large[n]; // >=
    pair<int,int> smaller;
    pair<int,int> bigger;

    int p = 0;
    int lastp = 0;

    vector<pair<int,int>> carry;

    for(int i = 0; i < n; i++)
    {
        vector<pair<int,int>> pass;

        while(p <= m-n+i && right[p] < left[i])
        {
            p++;
        }

        if(right[p] < left[i]) //can end then
        {
            small[i] = p-1;
            large[i] = p-1;
        }
        else
        {
            small[i] = p-1;
            large[i] = p;
        }

        p++;

        //out << small[i] << " " << large[i] << endl;
        pair<int,int> ns;
        pair<int,int> nb;

        if(i == 0)
        {
            smaller = mp(abs(left[i] - right[small[i]]), small[i]);
            bigger = mp(abs(left[i] - right[large[i]]), large[i]);

            carry.pb(mp(abs(left[i] - right[small[i]]), small[i]));
            carry.pb((mp(abs(left[i] - right[large[i]]), large[i])));
        }
        else
        {
            if(bigger.s < small[i])
            {
                ns = mp(max(min(bigger.f, smaller.f), abs(left[i] - right[small[i]])), small[i]);
            }
            else
            {
                 ns = mp(max(smaller.f, abs(left[i] - right[small[i]])), small[i]);
            }

                 nb = mp(max(min(bigger.f, smaller.f), abs(left[i] - right[large[i]])), large[i]);          
        }

        smaller = ns;
        bigger = nb;
        //p++;
    }

    cout << min(smaller.f, bigger.f);

/*
    int dp[2][m];
    dp[0][0] = abs(left[0] - right[0]);

    for(int j = 1; j < m; j++)
    {
        dp[0][j] = min(dp[0][j-1], abs(left[0] - right[j]));
    }
    
    for(int index = 1; index < n; index++)
    {
        int i = index%2;

        dp[i][index] = max(dp[(i+1)%2][index-1], abs(left[index] - right[index]));

        for(int j = index+1; j < m; j++)
        {
            dp[i][j] = min(dp[i][j-1], max(dp[(i+1)%2][j-1], abs(left[index] - right[j]))); //pair left i with right j
        }
    }

    /*for(int i = 0; i < n; i++)
    {
        for(int j = i; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

   cout << dp[(n-1)%2][m-1];*/
}