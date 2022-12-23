#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

int n; 
int n1[26];
int n2[26];
int n3[26];
int eq[26];
bool oc[26];

vector<int> ord;
int rord[26];
vector<int> pos[26];
int carry[27];
bool fin; 

bool evalPos(int get)
{
    bool work = true;

    for(int i = 0; i < pos[get].size(); i++)
    {
        int p = pos[get][i];

        if((eq[n1[p]] + eq[n2[p]] + carry[p+1])%n != eq[n3[p]])
        {
            work = false; break;
        }

        if(p == 0 && (eq[n1[p]] + eq[n2[p]]) >= n)
        {
            work = false;
            break;
        }

        carry[p] = (eq[n1[p]] + eq[n2[p]] + carry[p+1])/n;
    }

    return work; 
}

void search(int at)
{
    if(at == n)
    {
        fin = true; 
        return;
    }

    int p = ord[at];

    for(int i = 0; i < n; i++)
    {
        if(oc[i])
        {
            continue;
        }

        eq[p] = i; oc[i] = true;

        if(evalPos(p))
        {
            search(at+1);
        }

        if(fin)
        {
            return;
        }

        oc[i] = false;
    }
}

int main()
{
    cin >> n; 
    string st1, st2, st3; cin >> st1 >> st2 >> st3;

    for(int i = 0; i < n; i++)
    {
        eq[i] = 0;
        bool oc = false;
        n1[i] = st1[i]-'A';
        n2[i] = st2[i]-'A';
        n3[i] = st3[i]-'A';
    }

    int ind = 0;
    bool ch = false;
    int cH = 0;

    for(int i = n-1; i >= 0; i--)
    {
        ch = false;

        if(eq[n1[i]] == 0)
        {
            eq[n1[i]] = -1; ord.pb(n1[i]); rord[n1[i]] = ind; ind++; ch = true; cH = n1[i];
        }

        if(eq[n2[i]] == 0)
        {
            eq[n2[i]] = -1; ord.pb(n2[i]); rord[n2[i]] = ind; ind++; ch = true; cH = n2[i];
        }

        if(eq[n3[i]] == 0)
        {
            eq[n3[i]] = -1; ord.pb(n3[i]); rord[n3[i]] = ind; ind++; ch = true; cH = n3[i];
        }
        
        if(!ch)
        {
            pos[ord[ind-1]].pb(i);
        }
        else
        {
            pos[cH].pb(i);
        }
    }

    fin = false;
    carry[n] = 0;

    search(0);

    for(int i = 0; i < n; i++)
    {
        cout << eq[i] << " ";
    }
}