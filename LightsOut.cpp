//USACO Guide String Hashing

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll p = 229;
const ll mod = 1e9 + 7;
ll hsh[203]; 

ll compute(int a, int b, ll power)
{
    //cout << "COMPUTE " << a << " to " << b << hsh[b+1] << " " << hsh[a] << endl;
    return (hsh[b] - (hsh[a]*power)%mod + mod)%mod;
}

int main()
{
    ofstream fout ("lightsout.out");
    //ifstream fin ("lightsout.in");
    ifstream fin ("test1.in");
    int n;
    fin >> n;
    //cin >> n;

    int x[n+2];
    int y[n+2];

    for(int i = 0; i < n; i++)
    {
        fin >> x[i];
        //cin >> x[i];
        fin >> y[i];
        //cin >> y[i];

        x[i] += 100000;
        y[i] += 100000;
    }

    x[n] = x[0];
    x[n+1] = x[1];
    y[n] = y[0];
    y[n+1] = y[1];

    // length + dir + length + dir ... so on
    ll distace[n+1];
    ll directions[n+1];
    directions[0] = 0;
    distace[0] = 0;
    ll totalD = 0;
    hsh[0] = 0;

    for(int i = 1; i <= n; i++)
    {
       cout << "ENTER 1st loop at " << i << endl;

        ll dist = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        totalD += dist;
        distace[i] = distace[i-1] + dist;

        //cout << "DISTANCE " << distace[i] << " " << dist << endl;

        //cout << x[i] << " " << x[i+1] << " " << y[i] << " " << y[i+1] << endl;
        //cout << (x[i+1] - x[i]) << " " << (y[i+1] - y[i]) << endl;

        ll dir = ((x[i+1] - x[i])*(y[i] - y[i-1]));

        ///cout << "DIRECTION PRELIMINARY " << dir << endl;

        if(dir == 0)
        {
            dir = ((y[i+1] - y[i])*(x[i] - x[i-1]));
            //cout << "DIRECTION PRELIMINARY " << dir << endl;
            dir /= (abs(y[i+1] - y[i])*abs(x[i] - x[i-1]));
        }
        else 
        {
            dir /= (abs(x[i+1] - x[i])*abs(y[i] - y[i-1]));
        }

        //cout << " DIRECTION SECOND STEP " << dir << endl;

        dir *= 100;
        dir += 103; //prev should be +-1; make all positive
        directions[i] = dir;

        cout << "DIRECTION " << dir << endl;
        
        hsh[i] = ((p*p*hsh[i-1])%mod) + ((p*dist)%mod) + dir;

        //cout << "FIRST HASH DONE" << endl;

        hsh[i] %= mod;

       cout << "HASH " << hsh[i] << endl;
    }

    int end = 2;
    ll powmods[203];
    powmods[0] = 1;
    powmods[1] = p*p;

    ll realize[n+1];

    for(int i = 1; i < n; i++)
    {
        //if(i == end)
        //{
            //end++;
        //}
        end = i+1;

        while(end < n) // n == 0 == end/exit
        {
            ll toCheck = compute(i, end, powmods[end-i]);
            ll length = end-i;
            bool uniq = true;

            for(int j = i+1; j < n-length; j++) // only need to check until end is n-1, if end = n that would differ it from others
            {
                if(compute(j, j + length, powmods[length]) == toCheck)
                {
                    uniq = false;
                    break;
                }
            }

            if(uniq)
            {
                break;
            }
            else
            {
                end++;
                powmods[length+1] = (powmods[length]*p*p)%mod;
            }
        }

        realize[i] = end;
    } 

    ll dmax = 0;

    for(int i = 1; i < n; i++)
    {
        //cout << i << " " << realize[i] << endl;
        ll distdark = distace[realize[i]] - distace[i] + min(distace[realize[i]], distace[n] - distace[realize[i]]);
        ll distlight = min(distace[i], totalD - distace[i]);

        dmax = max(dmax, distdark - distlight);

    }

    fout << dmax;
    cout << dmax;
}