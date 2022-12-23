#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    int n; cin >> n;

    int val[n];   
    int ldp[n];
    int rdp[n];

    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    ldp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        ldp[i] = i; //kick all

        for(int j = 0; j < i; j++)
        {
            if(val[j] < val[i]) { ldp[i] = min(ldp[i], ldp[j] + (i-j-1)); }
        }
    }

    rdp[n-1] = 0;

    for(int i = n-2; i >= 0; i--)
    {
        rdp[i] = (n-i-1);

        for(int j = n-1; j > i; j--)
        {
            if(val[i] > val[j]) {rdp[i] = min(rdp[i], rdp[j] + (j-i-1));}
        }
    }

    int ans = 100;

    for(int i = 0; i < n; i++)
    {
        ans = min(ans, ldp[i] + rdp[i]);
        //cout << i << " " << ldp[i] << " " << rdp[i] << endl;
    }

    cout << ans;

}