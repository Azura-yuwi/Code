//CSES Sorting and Searching

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;
    
    pair<int, bool> ts[2*n];

    for(int i = 0; i < n; i++)
    {
        int a,b; cin >> a >> b;
        ts[2*i] = {a, false};
        ts[2*i +1] = {b, true};
    }

    sort(ts, ts+2*n);

    int ppl = 0;
    int mxppl = 0;

    for(int i = 0; i < 2*n; i++)
    {
        if(ts[i].second) ppl--;
        else ppl++;

        mxppl = max(mxppl, ppl);
    }

    cout << mxppl; 
}