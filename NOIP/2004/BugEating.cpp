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
vector<int> pos[26];
vector<int> ord;
bool oc[26];
bool fin;

void evaluate()
{
    int carry = 0;
    bool work = true;

    for(int i = n-1; i >= 0; i--)
    {
        if((eq[n1[i]] + eq[n2[i]] + carry)%n != eq[n3[i]])
        {
            work = false; break;
        }

        carry = (eq[n1[i]] + eq[n2[i]] + carry)/n;
    }

    if(carry == 1)
    {
        work = false;
    }

    if(work)
    {
        fin = true;
    }
}

bool evalPos(int get)
{
    bool work = true;

    for(int p : pos[get])
    {
        if((eq[n1[p]] + eq[n2[p]])%n != eq[n3[p]] && (eq[n1[p]] + eq[n2[p]] + 1)%n != eq[n3[p]])
        {
            work = false;
            break;
        }

        if(p == 0 && (eq[n1[p]] + eq[n2[p]]) >= n)
        {
            work = false;
            break;
        }
    }

    return work; 
}

void search(int p)
{
    if(p == n)
    {
        evaluate();
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(oc[i])
        {
            continue;
        }

        eq[p] = i; oc[i] = true;

        if(evalPos(p))
        {
            search(p+1);
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
        eq[i] = -1;
        bool oc = false;
        n1[i] = st1[i]-'A';
        n2[i] = st2[i]-'A';
        n3[i] = st3[i]-'A';
    }

    for(int i = 0; i < n; i++)
    {
        int get = max(n1[i], max(n2[i], n3[i]));
        pos[get].pb(i);
    }

    fin = false;

    search(0);

    for(int i = 0; i < n; i++)
    {
        cout << eq[i] << " ";
    }
}