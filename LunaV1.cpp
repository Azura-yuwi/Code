#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

//bit
// remove current value then add new value

vector<int> bit;
int sz;

void upd(int i, int v)
{
    for(; i <= sz; i += i&(-i))
    {
        bit[i] += v;
    }
}

int query(int i)
{
    int sum = 0;
    for(; i > 0; i -= i&(-i))
    {
        sum += bit[i];
    }
    return sum;
}

int main()
{
    //ifstream fin("test.in");

    int n; cin >> n;
    bit.assign(2*n+1, 0);
    sz = 2*n+1; //cout << sz << endl;

    int end[n];
    int v[2*n+1];

    for(int i = 1; i <= 2*n; i++)
    {
        cin >> v[i]; v[i]--; end[v[i]] = i;
    }

    ll swap = 0;

    for(int i = 1; i <= 2*n; i++)
    {
        if(end[v[i]] != -1)
        {
            swap += query(end[v[i]]) - query(i);
            upd(end[v[i]], 1);
            end[v[i]] = -1;
        }
    }

    cout << swap+n << endl;
}