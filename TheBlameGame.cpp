#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    int n; ll k; cin >> n >> k;
    int blame[n][n];
    ll cyc[n][n];
    k--;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> blame[i][j]; blame[i][j]--;
            cyc[i][j] = -1;
        }
    }

    //unordered_map<pair<int,int>,int> cyc; //number, cycle position
    vector<int> cycle; //cycle starting from 0 to 1 to so on; (have tail into cycle)

    int blamer = 0; int toBlame = 1;
    ll at = 0;
    //cyc[mp(0,1)] = 0; cycle.pb(0);
    
    while(cyc[blamer][toBlame] == -1)
    {
       // cout << "blamer " << blamer << " toBlame " << toBlame << " at "<< at << endl;
        cyc[blamer][toBlame] = at;
        cycle.pb(blamer); 
        
        if(at == k)
        {
            cout << (blamer+1);
            return 0;
        }

        at++;
        int temp = toBlame;
        toBlame = blame[toBlame][blamer];
        blamer = temp;
    }

    //cout << "out " << endl;

    //blamer, toBlame = start of cycle
    //cout << "blamer " << blamer << " toBlame " << toBlame << " at "<< at << endl;

    ll cycleLength = at - cyc[blamer][toBlame];
    k -= cyc[blamer][toBlame]; //get rid of tail
    k %= cycleLength;

    cout << (cycle[cyc[blamer][toBlame] + k]+1);

}